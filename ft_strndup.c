#include <stdio.h>
#include <stdlib.h>
size_t	ft_strlen(const char *s);
char	*ft_strndup(const char *s1, size_t n);

int main(void)
{
	char *ret;
	printf("ret: %s\n", ret = ft_strndup("abcde", 3));
	free(ret);
	printf("ret: %s\n", ret = ft_strndup("abcde", 5));
	free(ret);
	return (0);
}

char	*ft_strndup(const char *s1, size_t n)
{
	char	*p;
	char	*head;

	p = malloc(sizeof(char) * (n + 1));
	if (!p)
		return (NULL);
	head = p;
	while (*s1 && n--)
		*p++ = *s1++;
	*p = '\0';
	return (head);
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

// __attribute__((destructor))
// static void destructor() {
// 	system("leaks -q a.out");
// }