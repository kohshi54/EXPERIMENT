#include <stdio.h>
#include <stdlib.h>
char	*ft_strnjoin(char const *s1, char const *s2, size_t n);

int	main(void)
{
	printf("expected: abc, output: %s\n", ft_strnjoin("a", "bc", 2));
	printf("expected: adef, output: %s\n", ft_strnjoin("a", "bcde", 3));
	printf("expected: adefghi, output: %s\n", ft_strnjoin("abc", "def", 5));
	printf("expected: abc, output: %s\n", ft_strnjoin(NULL, "abc", 3));
	printf("expected: abc, output: %s\n", ft_strnjoin(NULL, NULL, 3));
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

char    *ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	char	*p;
	char	*head;

	// if (!s1 || !s2)
	//     return (NULL);
	p = malloc(ft_strlen(s1) + n + 1);
	printf("input: %zu, nbytes mallocated: %zu\n", n, ft_strlen(s1) + n + 1);
	if (!p)
    	return (NULL);
	head = p;
	if (s1)
		while (*s1)
    		*p++ = *s1++;
	if (s2)
		while (*s2 && n--)
			*p++ = *s2++;
	*p = '\0';
	return (head);
}
