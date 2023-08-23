#include "monty.h"

void cust_monty_add(cust_stack_t **cust_stack, unsigned int cust_line_num);
void cust_monty_sub(cust_stack_t **cust_stack, unsigned int cust_line_num);
void cust_monty_div(cust_stack_t **cust_stack, unsigned int cust_line_num);
void cust_monty_mul(cust_stack_t **cust_stack, unsigned int cust_line_num);
void cust_monty_mod(cust_stack_t **cust_stack, unsigned int cust_line_num);

/**
 * cust_monty_add - Add a top two values of a cust_stack_t linked list.
 * @cust_stack: the pointer to the top mode node of a cust_stack_t linked list.
 * @cust_line_num: A current working line of number a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top, and the top value is removed.
 */
value from the top of
 *                  a cust_stack_t linked list by the top value.
 * @cust_stack: a pointer that to the top mode node of a cust_stack_t linked list.
 * @cust_line_num: The current working line number of the Monty bytecodes file.
 * /
 
 void cust_monty_add(cust_stack_t **cust_stack, unsigned int cust_line_num)
 
{
	if ((*cust_stack)->next == NULL || (*cust_stack)->next->next == NULL)
	{
		set_cust_op_tok_error(short_stack_error(cust_line_num, "add"));
		return;
	}

	(*cust_stack)->next->next->n += (*cust_stack)->next->n;
	cust_monty_pop(cust_stack, cust_line_num);
}

/**
 * cust_monty_sub - Subtracts the second 
 * Description: a result is stored in the second value node
 *              from the top, and the top value is removed.
 */
void cust_monty_sub(cust_stack_t **cust_stack, unsigned int cust_line_num)
{
	if ((*cust_stack)->next == NULL || (*cust_stack)->next->next == NULL)
	{
		set_cust_op_tok_error(short_stack_error(cust_line_num, "sub"));
		return;
	}

	(*cust_stack)->next->next->n -= (*cust_stack)->next->n;
	cust_monty_pop(cust_stack, cust_line_num);
}

/**
 * cust_monty_div - Divides the second value from the top of
 *                  a cust_stack_t linked list by the top value.
 * @cust_stack: the pointer is to the top mode node of a cust_stack_t linked list.
 * @cust_line_num: The current working line number of a Monty bytecodes file.
 *
 * Description: a result is stored in the second value node
 *              from the top, and the top value is removed.
 */
void cust_monty_div(custom_stack_t **cust_stack, unsigned int cust_line_num)
{
	if ((*cust_stack)->next == NULL || (*cust_stack)->next->next == NULL)
	{
		set_cust_op_tok_error(short_stack_error(cust_line_num, "div"));
		return;
	}

	if ((*cust_stack)->next->n == 0)
	{
		set_cust_op_tok_error(div_error(cust_line_num));
		return;
	}

	(*cust_stack)->next->next->n /= (*cust_stack)->next->n;
	cust_monty_pop(cust_stack, cust_line_num);
}

/**
 * cust_monty_mul - Multiplies the second value from the top of
 *                  a cust_stack_t linked list by the top value.
 * @cust_stack: A pointer that the top mode node of a cust_stack_t linked list.
 * @cust_line_num: The current working cust_line number of a Monty bytecodes file.
 *
 * Description: a is result stored in the second values node
 *              from the top, and the top value is removed.
 */
void cust_monty_mul(cust_stack_t **cust_stack, unsigned int cust_line_num)
{
	if ((*cust_stack)->next == NULL || (*cust_stack)->next->next == NULL)
	{
		set_cust_op_tok_error(short_stack_error(cust_line_num, "mul"));
		return;
	}

	(*cust_stack)->next->next->n *= (*cust_stack)->next->n;
	cust_monty_pop(cust_stack, cust_line_num);
}
/**
 * cust_monty_mod - Computes the modulus of the second value from the
 *                  top of a cust_stack_t linked list by the top value.
 * @cust_stack: A pointer to the top mode node of a cust_stack_t linked list.
 * @cust_line_num: The current working cust_line_number of a Monty bytecodes file.
 *
 * Description: a result is stored in the second value node
 *              from the top, and the top value is removed.
 */
void cust_monty_mod(cust_stack_t **cust_stack, unsigned int cust_line_num)
{
	if ((*cust_stack)->next == NULL || (*cust_stack)->next->next == NULL)
	{
		set_cust_op_tok_error(short_stack_error(cust_line_num, "mod"));
		return;
	}

	if ((*cust_stack)->next->n == 0)
	{
		set_cust_op_tok_error(div_error(cust_line_num));
		return;
	}

	(*cust_stack)->next->next->n %= (*cust_stack)->next->n;
	cust_monty_pop(cust_stack, cust_line_num);
}

