#include <stdio.h>
#include <unistd.h>
size_t  ft_strchr_nl(const char *s);
size_t  ft_strchr_nl2(const char *s, int c);
size_t	ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
size_t	ft_strchr2(char *s, int c);

int	main(void)
{
	printf("expected: 1, output: %zu\n", ft_strchr_nl("\n"));
	printf("expected: 2, output: %zu\n", ft_strchr_nl("a\n"));
	printf("expected: 3, output: %zu\n", ft_strchr_nl("ab\n"));
	printf("expected: 4, output: %zu\n", ft_strchr_nl("abc\n"));
	printf("expected: 6, output: %zu\n", ft_strchr_nl("abcde\n"));
	printf("expected: 4, output: %zu\n", ft_strchr_nl("abc\nde"));
	printf("expected: 0, output: %zu\n", ft_strchr_nl("abcde"));
	printf("expected: 0, output: %zu\n", ft_strchr_nl(""));

	// printf("expected: segfault, output: %zu\n", ft_strchr_nl(NULL));
	printf("-----\n");
	printf("expected: 1, output: %zu\n", ft_strchr("\n", '\n'));
	printf("expected: 2, output: %zu\n", ft_strchr("a\n", '\n'));
	printf("expected: 3, output: %zu\n", ft_strchr("ab\n", '\n'));
	printf("expected: 4, output: %zu\n", ft_strchr("abc\n", '\n'));
	printf("expected: 6, output: %zu\n", ft_strchr("abcde\n", '\n'));
	printf("expected: 4, output: %zu\n", ft_strchr("abc\nde", '\n'));
	printf("expected: 0, output: %zu\n", ft_strchr("abcde", '\n'));
	printf("expected: 0, output: %zu\n", ft_strchr("", '\n'));
	printf("expected: 0, output: %zu\n", ft_strchr(NULL, '\n'));

	printf("----\n");
	printf("expected: 1, output: %zu\n", ft_strchr("\n", '\0'));
	printf("expected: 2, output: %zu\n", ft_strchr("a\n", '\0'));
	printf("expected: 3, output: %zu\n", ft_strchr("ab\n", '\0'));
	printf("expected: 4, output: %zu\n", ft_strchr("abc\n", '\0'));
	printf("expected: 6, output: %zu\n", ft_strchr("abcde\n", '\0'));
	printf("expected: 6, output: %zu\n", ft_strchr("abc\nde", '\0'));
	printf("expected: 5, output: %zu\n", ft_strchr("abcde", '\0'));
	printf("expected: 0, output: %zu\n", ft_strchr("", '0'));
	printf("expected: 0, output: %zu\n", ft_strchr(NULL, '\0'));

	printf("----\n");
	printf("expected: 1, output: %zu\n", ft_strlen("\n"));
	printf("expected: 2, output: %zu\n", ft_strlen("a\n"));
	printf("expected: 3, output: %zu\n", ft_strlen("ab\n"));
	printf("expected: 4, output: %zu\n", ft_strlen("abc\n"));
	printf("expected: 6, output: %zu\n", ft_strlen("abcde\n"));
	printf("expected: 6, output: %zu\n", ft_strlen("abc\nde"));
	printf("expected: 5, output: %zu\n", ft_strlen("abcde"));
	printf("expected: 0, output: %zu\n", ft_strlen(""));
	printf("expected: 0, output: %zu\n", ft_strlen(NULL));

	printf("-----\n");
	printf("expected: 1, output: %zu\n", ft_strchr2("\n", '\n'));
	printf("expected: 2, output: %zu\n", ft_strchr2("a\n", '\n'));
	printf("expected: 3, output: %zu\n", ft_strchr2("ab\n", '\n'));
	printf("expected: 4, output: %zu\n", ft_strchr2("abc\n", '\n'));
	printf("expected: 6, output: %zu\n", ft_strchr2("abcde\n", '\n'));
	printf("expected: 4, output: %zu\n", ft_strchr2("abc\nde", '\n'));
	printf("expected: 0, output: %zu\n", ft_strchr2("abcde", '\n'));
	printf("expected: 0, output: %zu\n", ft_strchr2("", '\n'));
	printf("expected: 0, output: %zu\n", ft_strchr2(NULL, '\n'));

	printf("----\n");
	printf("expected: 1, output: %zu\n", ft_strchr2("\n", '\0'));
	printf("expected: 2, output: %zu\n", ft_strchr2("a\n", '\0'));
	printf("expected: 3, output: %zu\n", ft_strchr2("ab\n", '\0'));
	printf("expected: 4, output: %zu\n", ft_strchr2("abc\n", '\0'));
	printf("expected: 6, output: %zu\n", ft_strchr2("abcde\n", '\0'));
	printf("expected: 6, output: %zu\n", ft_strchr2("abc\nde", '\0'));
	printf("expected: 5, output: %zu\n", ft_strchr2("abcde", '\0'));
	printf("expected: 0, output: %zu\n", ft_strchr2("", '0'));
	printf("expected: 0, output: %zu\n", ft_strchr2(NULL, '\0'));
	return (0);
}

// RETURN THE NUMBER OF BYTES TO NEWLINE INCLUDING NEWLINE ITSELF
size_t	ft_strchr_nl(const char *s)
{
   size_t	i;

   i = 0;
   while (s[i])
       if (s[i++] == '\n')
           return (i);
   return (0);
}

size_t  ft_strchr_nl2(const char *s, int c)
{
   size_t  count;

   count = 0;
   while (*s)
   {
       if (*s == (char)c)
           return (count);
       s++;
       count++;
   }
   if (*s == (char)c)
       return (count);
   return (0);
}

size_t	ft_strchr(const char *s, int c)
{
	size_t  i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		if (s[i++] == (char)c)
			return (i);
	if (s[i] == (char)c)
		return (i);
	return (0);
}

size_t	ft_strchr2(char *s, int c)
{
	char	*head;

	if (!s)
		return (0);
	head = s;
	while (*s)
	{
		if (*s++ == (char)c)
			return (s - head);
		// s++;
	}
	if (*s == (char)c)
		return (s - head);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	if (!s)
		return (0);
	count = 0;
	while (*s++)
		count++;
	return (count);
}
