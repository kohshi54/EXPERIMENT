#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	char *p = malloc(5);
	p[0] = 'a';
	p[1] = 'b';
	p[2] = 'c';
	p[3] = 'd';
	p[4] = 'e';
	// char *p2 = ++p;
	free(++p); // pointer being freed was not allocated
	return (0);
}

// POINTER BEING FREED MUST BE THE RETURNED POINTER FROM MALLOC.
// THE POINTER IN THE RANGE CANNOT BE FREED SEPARATELY.