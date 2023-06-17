#include <stdio.h>
#include <stdlib.h>
char	*ft_strdup(const char *s1);
char	*ft_strndup(const char *s1, size_t n);

int main(void)
{
	printf("expected: abcde, output: %s\n", ft_strdup("abcde"));
	// printf("expected: , output: %s\n", ft_strdup(NULL)); segfault
	printf("expected: , output: %s\n", ft_strdup(""));
	printf("---------------\n");
	printf("expected: abcde, output: %s\n", ft_strndup("abcde", 5));
	printf("expected: abc, output: %s\n", ft_strndup("abcde", 3));
	printf("expected: abcde, output: %s\n", ft_strndup("abcde", 8));
	// printf("expected: , output: %s\n", ft_strndup(NULL, 2)); segfault
	printf("expected: , output: %s\n", ft_strndup("", 2));

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

size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int count;

	count = ft_strlen(src);
	if (dstsize == 0)
		return (count);
	while (dstsize-- > 1 && *src)
		*dst++ = *src++;
	*dst = '\0';
	return (count);
}

char	*ft_strdup(const char *s1)
{
	char	*p;
	char	*head;

	p = malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!p)
    	return (NULL);
	head = p;
	while (*s1)
		*p++ = *s1++;
	// ft_strlcpy(p, s1, ft_strlen(s1) + 1);
	return (head);
}

char	*ft_strndup(const char *s1, size_t n)
{
	char	*p;
	char	*head;

	p = malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!p)
    	return (NULL);
	head = p;
	while (*s1 && n--)
		*p++ = *s1++;
	return (head);
}