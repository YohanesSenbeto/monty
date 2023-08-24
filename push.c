#include "monty.h"

/**
 * push - to pushes an element to the stack
 * @stack: A double pointer to the top of the stack
 * @line: A line number of the current opcode
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line)
{
	char *arg = strtok(NULL, DELIMS);
	int n;

	if (arg == NULL || _isdigit(arg) == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line);
		exit(EXIT_FAILURE);
	}
	n = atoi(arg);

	add_node(stack, n);
}

/**
 * _isdigit - to checks if a string contain only digits
 * @str: A string to check
 *
 * Return: 1 if true, 0 if false
 */
int _isdigit(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		if (str[i] == '-' && i == 0)
			continue;
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}

/**
 * add_node - adds new node at the beginning of a stack_t list
 * @head: A double pointer to the top of the stack
 * @n: A value of the new node
 *
 * Return: void
 */
void add_node(stack_t **head, const int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->prev = NULL;
	new->next = *head;
	if (*head != NULL)
		(*head)->prev = new;
	*head = new;
}

