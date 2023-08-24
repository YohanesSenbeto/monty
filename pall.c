#include "monty.h"

/**
* pall - print all of values on the stack, starting from the top of the stack
* @stack: double pointer to a top of the stack
* @line: A line number of the current opcode
*
* Return: void
*/
void pall(stack_t **stack, unsigned int line) {
	stack_t *tempo;

	(void) line;

	tempo = *stack;
	while (tempo != NULL) {
		printf("%d\n", tempo->n);
		tempo = tempo->next;
	}
}


