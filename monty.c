#include "monty.h"
#include <string.h>

void cust_free_tokens(void);
unsigned int cust_token_array_length(void);
int cust_is_empty_line(char *text, char *delimiters);
void (*cust_get_op_function(char *operation))(cust_stack_t**, unsigned int);
int cust_execute_monty(FILE *script_file);

/**
 * cust_free_tokens - Clears the global cust_op_toks array of strings.
 */
void cust_free_tokens(void)
{
	size_t index = 0;

	if (cust_op_toks == NULL)
		return;

	for (index = 0; cust_op_toks[index]; index++)
		free(cust_op_toks[index]);

	free(cust_op_toks);
}

/**
 * cust_token_array_length - Computes the length of the existing cust_op_toks.
 *
 * Return:the Length of  current cust_op_toks (as an unsigned int).
 */
unsigned int cust_token_array_length(void)
{
	unsigned int length = 0;

	while (cust_op_toks[length])
		length++;
	return (length);
}

/**
 * cust_is_empty_line - Checks if a provided line contains only delimiters.
 * @text: A pointer to the line to be checked.
 * @delimiters: A string containing delimiter characters.
 *
 * Return: If the line comprises solely of delimiters - 1.
 *         Otherwise - 0.
 */
int cust_is_empty_line(char *text, char *delimiters)
{
	int i, j;

	for (i = 0; text[i]; i++)
	{
		for (j = 0; delimiters[j]; j++)
		{
			if (text[i] == delimiters[j])
				break;
		}
		if (delimiters[j] == '\0')
			return (0);
	}

	return (1);
}

/**
 * cust_get_op_function - Matches an operation with its corresponding function.
 * @operation: The operation to match.
 *
 * Return: A pointer to the corresponding function.
 */
void (*cust_get_op_function(char *operation))(cust_stack_t**, unsigned int)
{
	instruction_t cust_operations[] = {
		{"push", cust_monty_push},
		{"pall", cust_monty_pall},
		{"pint", cust_monty_pint},
		{"pop", cust_monty_pop},
		{"swap", cust_monty_swap},
		{"add", cust_monty_add},
		{"nop", cust_monty_nop},
		{"sub", cust_monty_sub},
		{"div", cust_monty_div},
		{"mul", cust_monty_mul},
		{"mod", cust_monty_mod},
		{"pchar", cust_monty_pchar},
		{"pstr", cust_monty_pstr},
		{"rotl", cust_monty_rotl},
		{"rotr", cust_monty_rotr},
		{"stack", cust_monty_stack},
		{"queue", cust_monty_queue},
		{NULL, NULL}
	};
	int i;

	for (i = 0; cust_operations[i].operation; i++)
	{
		if (strcmp(operation, cust_operations[i].operation) == 0)
			return (cust_operations[i].function);
	}

	return (NULL);
}

/**
 * cust_execute_monty - Primary function for executing a cust Monty bytecode script.
 * @script_file: File descriptor for an open Monty bytecode script.
 *
 * Return: EXIT_SUCCESS upon success, corresponding error code upon failure.
 */
int cust_execute_monty(FILE *script_file)
{
	cust_stack_t *cust_stack = NULL;
	char *current_line = NULL;
	size_t line_length = 0, exit_status = EXIT_SUCCESS;
	unsigned int line_number = 0, previous_tok_len = 0;
	void (*operation_function)(cust_stack_t**, unsigned int);

	if (cust_initialize_stack(&cust_stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (getline(&current_line, &line_length, script_file) != -1)
	{
		line_number++;
		cust_op_toks = cust_strtok(current_line, DELIMITERS);
		if (cust_op_toks == NULL)
		{
			if (cust_is_empty_line(current_line, DELIMs))
				continue;
			cust_free_stack(&cust_stack);
			return (malloc_error());
		}
		else if (cust_op_toks[0][0] == '#') /* Comment line */
		{
			cust_free_tokens();
			continue;
		}
		operation_function = cust_get_op_function(cust_op_toks[0]);
		if (operation_function == NULL)
		{
			cust_free_stack(&cust_stack);
			exit_status = cust_unknown_op_error(cust_op_toks[0], line_number);
			cust_free_tokens();
			break;
		}
		previous_tok_len = cust_token_array_length();
		operation_function(&cust_stack, line_number);
		if (cust_token_array_length() != previous_tok_len)
		{
			if (cust_op_toks && cust_op_toks[previous_tok_len])
				exit_status = atoi(cust_op_toks[previous_tok_len]);
			else
				exit_status = EXIT_FAILURE;
			cust_free_tokens();
			break;
		}
		cust_free_tokens();
	}
	cust_free_stack(&cust_stack);

	if (current_line && *current_line == 0)
	{
		free(current_line);
		return (malloc_error());
	}

	free(current_line);
	return (exit_status);
}

