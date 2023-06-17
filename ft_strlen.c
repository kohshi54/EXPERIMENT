#include <stdio.h>
#include <unistd.h>
size_t  ft_strlen(const char *s);

int main(void)
{
	printf("expected: 5, output: %zu\n", ft_strlen("abcde"));
	printf("expected: 0, output: %zu\n", ft_strlen(""));
	printf("expected: 0, output: %zu\n", ft_strlen("\0"));
	printf("expected: 3, output: %zu\n", ft_strlen("abc"));
	printf("expected: 1, output: %zu\n", ft_strlen("\n"));
	printf("expected: 6, output: %zu\n", ft_strlen("abcde\n"));
	printf("expected: 0, output: %zu\n", ft_strlen(NULL));
	return (0);
}

size_t  ft_strlen(const char *s)
{
   size_t  count;

   if (!s)
       return (0);
   count = 0;
   while (*s++)
       count++;
   return (count);
}