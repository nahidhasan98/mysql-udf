/*
 * Nahid Hasan
 * mysql UDF
 * 25 Jun, 2022
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Item_result
{
    STRING_RESULT,
    REAL_RESULT,
    INT_RESULT,
    ROW_RESULT
};

typedef struct st_udf_args
{
    unsigned int arg_count;     // number of arguments
    enum Item_result *arg_type; // pointer to item_result
    char **args;                // pointer to arguments
    unsigned long *lengths;     // length of string args
    char *maybe_null;           // 1 for maybe_null args
} UDF_ARGS;

typedef struct st_udf_init
{
    char maybe_null;          // 1 if func can return NULL
    unsigned int decimals;    // for real functions
    unsigned long max_length; // for string functions
    char *ptr;                // free ptr for func data
    char const_item;          // 0 if result is constant
} UDF_INIT;

_Bool run_cmd_init(UDF_INIT *initid, UDF_ARGS *args, char *message)
{
    unsigned int i = 0;

    if (args->arg_count == 1 && args->arg_type[i] == STRING_RESULT)
    {
        return 0;
    }
    else
    {
        strcpy(message, "Expected exactly one string type parameter");
        return 1;
    }
}

void run_cmd_deinit(UDF_INIT *initid)
{
}

char *run_cmd(UDF_INIT *initid, UDF_ARGS *args, char *result, unsigned long *length, char *is_null, char *error)
{
    FILE *pipe;
    char line[1024];
    unsigned long outlen, linelen;

    result = malloc(1);
    outlen = 0;

    pipe = popen(args->args[0], "r");

    while (fgets(line, sizeof(line), pipe) != NULL)
    {
        linelen = strlen(line);
        result = realloc(result, outlen + linelen);
        strncpy(result + outlen, line, linelen);
        outlen = outlen + linelen;
    }
    pclose(pipe);

    if (!(*result) || result == NULL)
    {
        *is_null = 1;
    }
    else
    {
        result[outlen] = 0x00;
        *length = strlen(result);
    }

    return result;
}