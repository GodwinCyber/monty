#include "monty.h"

/**
 * handler_realloc - handles reallocation of memory to string_array.
 * @i: the value of the index tracking the number of elements in string_array.
 * @string_array: address of a double pointer previously allocated memory.
 * @bsize: the unit memory size for string_array.
 * @old_bsize: address of variable storing the buffer's prev size.
 * @bsize_total: address of the variable
 * representing the total size of the string_array buffer.
 */
void handler_realloc(char ***string_array, int i, int bsize, int *old_bsize,
		int *bsize_total)
{
	char **tmporary, **tmporary2;

	(void)tmporary2;
	tmporary2 = *string_array;
	if (i >= (*bsize_total / bsize))
	{
		*old_bsize = *bsize_total;
		*bsize_total += bsize;
		tmporary = realloc(*string_array, *bsize_total);
		if (!tmporary)
		{
			fprintf(stderr, "Error: malloc failed\n");
			free(globals.linebuffer);
			free(globals.instruct_array);
			if (globals.stk_top)
				free_stk(globals.stk_top);
			fclose(globals.fp);
			exit(EXIT_FAILURE);
		}

		*string_array = tmporary;
	}
}
