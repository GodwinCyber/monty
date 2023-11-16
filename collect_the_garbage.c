#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * grbage_collectr - performs the full suite of
 * cleanups needed to be done just before the interpreter exits.
 */
void grbage_collectr(void)
{
	free(globals.linebuffer);
	free(globals.instruct_array);
	if (globals.stk_top)
		free_stk(globals.stk_top);
	fclose(globals.fp);
}
