#ifndef MAIN_HEADER
#define MAIN_HEADER

typedef __SIZE_TYPE__ size_t;
int _putchar(int);
void print_name(char *name, void (*f)(char *));
void array_iterator(int *array, size_t size, void (*action)(int));
int int_index(int *array, int size, int (*cmp)(int));

#endif

