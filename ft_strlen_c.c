#include <stdio.h>
#include <stdlib.h>
size_t	ft_strlen_c(const char *s, const char target);

int main(void)
{
	printf("expected: 4, ret: %zu\n", ft_strlen_c("abcde", 'd'));
	printf("expected: 4, ret: %zu\n", ft_strlen_c("abc\nde", '\n'));
	printf("expected: 6, ret: %zu\n", ft_strlen_c("abc\nde", '\0'));
	printf("expected: 0, ret: %zu\n", ft_strlen_c("abc\nde", 'k'));
	printf("expected: 0, ret: %zu\n", ft_strlen_c(NULL, 'k'));
	printf("expected: 0, ret: %zu\n", ft_strlen_c(NULL, '\0'));
	return (0);
}

size_t	ft_strlen_c(const char *s, const char target)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		if (s[i++] == target)
			return (i);
	if (s[i] == target)
		return (i);
	return (0);
}