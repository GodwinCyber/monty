#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <sys/types.h>
#include <stddef.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>


#define ps(x) (printf("%s\n", (x)))
#define pd(x) (printf("%d\n", (x)))
#define plu(x) (printf("%lu", (x)))

/* text output colors */
#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define PURPLE "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"
#define RESET "\033[0m"


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef void (*opfunc)(stack_t **, unsigned int);

/**
 * struct oplist_s - opcode instructions list
 * @opstruct: pointer to an instruction_t struct for an opcode
 * @prev: points to the previous list item
 * @next: points to the next list item
 *
 * Description: doubly-linked list of instruction_t structures
 * to enable efficient searching of the right opcode function to call.
 */
typedef struct oplist_s
{
	instruction_t *opstruct;
	struct oplist_s *prev;
	struct oplist_s *next;
} oplist_t;

/**
 * struct globals_s - data structure for storing
 * variables that are needed to have global behaviours.
 * @linenumber: an int.
 * @linebuffer: a string.
 * @instruct_array: a NULL-terminated array of strings.
 * @stk_top: program's stack.
 * @fp: pointer to FILE type.
 * @oparg: int for storing arguments to the push opcode.
 */
typedef struct globals_s
{
	unsigned int linenumber;
	char *linebuffer;
	char **instruct_array;
	stack_t *stk_top;
	FILE *fp;
	int oparg;
} globals_t;
extern globals_t globals;

ssize_t getline(char **lineptr, size_t *n, FILE *stream);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);

/* helper functions */
void handler_realloc(char ***string_array, int i, int bsize, int *old_bsize,
		int *bsize_total);
void *realloc3(void *ptr, unsigned int old_size, unsigned int new_size);
char **str_array(char *string, const char *delimiter);
size_t stack_length(const stack_t *stack_top);
char *_memset(char *s, char b, unsigned int n);
void _memncpy(void *dest, void *src, unsigned int n);
opfunc find_opfunction(char *opstring);
void perform_operation(char *instruct_array[]);
void init_the_globals(void);
void free_stk(stack_t *stack_top);

int isintinger(char *string);
void grbage_collectr(void);


/* instruction function prototypes */
void push(stack_t **stack_top, unsigned int n);
void pall(stack_t **stack_top, unsigned int n __attribute__((unused)));
void pint(stack_t **stack_top, unsigned int n);
void pop(stack_t **stack_top, unsigned int n __attribute__((unused)));
void swap(stack_t **stack_top, unsigned int n);
void add(stack_t **stack_top, unsigned int n);
void nop(stack_t **stack_top, unsigned int n);

void sub(stack_t **stack_top, unsigned int n);
void sub(stack_t **head, unsigned int n);
void div_(stack_t **stack_top, unsigned int n);
void mul(stack_t **stack_top, unsigned int n);
void mul(stack_t **head, unsigned int n);
void mod(stack_t **head, unsigned int n);
void pchar(stack_t **stack_top, unsigned int n);
void pchar(stack_t **head, unsigned int n);
void pstr(stack_t **stack_top, unsigned int n);
void pstr(stack_t **head, unsigned int n);
void rotl(stack_t **stack_top, unsigned int n);
void rotl(stack_t **head, unsigned int n);
void rotr(stack_t **stack_top, unsigned int n);
void rotr(stack_t **head, unsigned int n);
void stack_(stack_t **stack_top, unsigned int n);
void stack_(stack_t **head, unsigned int n);
void queue(stack_t **stack_top, unsigned int n);
void queue(stack_t **head, unsigned int n);

/* queue-mode specific function */
void push_queue(stack_t **stack_top, unsigned int n);

#endif
