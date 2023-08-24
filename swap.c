#include "monty.h"

/**
* swap - A swaps the top two elements of the stack
* @stack: A double pointer to the top of the stack
* @line: the line number of the current opcode.
*
* Return: void
*/
void swap(stack_t **stack, unsigned int line) {
	int tempo;

	if (*stack == NULL || (*stack)->next == NULL) {
		fprintf(stderr, "L%u: can't swap, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	tempo = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tempo;
}


