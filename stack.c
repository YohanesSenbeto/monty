#include "monty.h"
#include <string.h>

void cust_free_stack(stack_t **cust_stack);
int initialize_cust_stack(stack_t **cust_stack);
int determine_mode(stack_t *cust_stack);

/**
 * cust_free_stack - Releases memory used by a custom_stack.
 * @cust_stack: A pointer to the top (stack) or
 *                bottom (queue) of a custom_stack.
 */
void cust_free_stack(stack_t **cust_stack)
{
	stack_t *temp = *cust_stack;

	while (*cust_stack)
	{
		temp = (*cust_stack)->next;
		free(*cust_stack);
		*cust_stack = temp;
	}
}

/**
 * initialize_cust_stack - Sets up a cust_stack with initial
 *                          stack and end queue nodes.
 * @cust_stack: A pointer to an uninitialized cust_stack.
 *
 * Return: If an error occurs - EXIT_FAILURE.
 *         Otherwise - EXIT_SUCCESS.
 */
int initialize_cust_stack(stack_t **cust_stack)
{
	stack_t *cs;

	cs = malloc(sizeof(stack_t));
	if (cs == NULL)
		return (malloc_error());

	cs->n = STACK;
	cs->prev = NULL;
	cs->next = NULL;

	*cust_stack = cs;

	return (EXIT_SUCCESS);
}

/**
 * determine_mode - Checks if a cust_stack linked list is in stack or queue mode.
 * @cust_stack: A pointer to the top (stack) or bottom (queue)
 *                of a cust_stack linked list.
 *
 * Return: If the cust_stack is in stack mode - STACK (0).
 *         If the cust_stack is in queue mode - QUEUE (1).
 *         Otherwise - 2.
 */
int determine_mode(stack_t *cust_stack)
{
	if (cust_stack->n == STACK)
		return (STACK);
	else if (cust_stack->n == QUEUE)
		return (QUEUE);
	return (2);
}

