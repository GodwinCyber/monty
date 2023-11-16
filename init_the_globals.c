#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * init_the_globals - gives definitions to variables in the globals_t struct.
 */
void init_the_globals(void)
{
	globals.linenumber = 0;
	globals.stk_top = NULL;
	globals.instruct_array = NULL;
	globals.linebuffer = NULL;
	globals.fp = NULL;
	globals.oparg = 0;
}
