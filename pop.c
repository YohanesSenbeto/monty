#include "monty.h"

/**
 * pop - to removes the top element of the stack
 * @stack: a double pointer to the top of the stack
 * @line: a line number of the current opcode
 *
 * Return: void
 */
void pop(stack_t **stack, unsigned int line)
{
	stack_t *tempo;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line);
		exit(EXIT_FAILURE);
	}

	tempo = *stack;
	*stack = (*stack)->next;
	free(tempo);
}
