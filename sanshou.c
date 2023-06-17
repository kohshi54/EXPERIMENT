#include <stdio.h>

void func(int num)
{
	*(&num) = *(&num) + 1;
}

int main(void)
{
	int num = 0;
	func(num);
	printf("%d", num);
	return (0);
}