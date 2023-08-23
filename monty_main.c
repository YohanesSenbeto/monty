#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char **cust_op_tokens = NULL;

/**
 * cust_main - the entry point for Unique Monty Interpreter
 *
 * @cus_arg_count: the count of arguments provided to the program
 * @cust_arg_values: pointer to an array of cust_arg_count char pointers to arguments
 *
 * Return: (EXIT_SUCCESS) on success, (EXIT_FAILURE) on error
 */
int cust_main(int cust_arg_count, char **cust_arg_values)
{
    FILE *cust_script_file = NULL;
    int cust_exit_code = EXIT_SUCCESS;

    if (cust_arg_count != 2)
        return (cust_usage_error());
    cust_script_file = fopen(cust_arg_values[1], "r");
    if (cust_script_file == NULL)
        return (cust_fopen_error(cust_arg_values[1]));
    cust_exit_code = cust_run_monty(cust_script_file);
    fclose(cust_script_file);
    return (cust_exit_code);
}

