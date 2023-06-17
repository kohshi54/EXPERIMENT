#include <stdio.h>
#include <stdlib.h>
size_t	ft_strlen(const char *s);
char	*ft_strnjoin2(char *s1, char *s2, size_t n);

// #include <stdio.h>
// #include <stdlib.h>

// #define LEAK_DETECT
// #ifdef LEAK_DETECT
// #include "leakdetect.h"
// #define init leak_detect_init
// #define malloc(s) leak_detelc_malloc(s, __FILE__, __LINE__) 
// #define free leak_detect_free
// #define check leak_detect_check
// #else
// #define init() 
// #define check()
// #endif


int main(void)
{
	char		*line;
	char		*p;

	// init();

	line = NULL;
	// tmp = ft_strnjoin(line, "a", 1);
	// free(line);
	// line = tmp;
	p = malloc(sizeof(char) * (2 + 1));
	// p = "ab"; << これはmalloc()で確保したメモリ領域じゃない、別の領域のアドレスをpにセットしているのでfree()しようとするとエラーが出る。
	p[0] = 'a';
	p[1] = 'b';
	p[2] = '\0';
	printf("p: %s\n", p);
	line = ft_strnjoin2(line, p, 1);
	printf("line: %s\n", line);
	// check();
	return (0);
}

char	*ft_strnjoin2(char *s1, char *s2, size_t n)
{
	char	*p;
	char	*p_head;
	char	*s1_head;
	char	*s2_head;

	p = malloc(ft_strlen_c(s1, '\n') + n + 1);
	if (!p)
	{
		free(s1);
		return (NULL);
	}
	p_head = p;
	s1_head = s1;
	if (s1)
		while (*s1)
			*p++ = *s1++;
	free(s1_head);
	s2_head = s2;
	if (s2)
		while (*s2 && n--)
			*p++ = *s2++;
	free(s2_head);
	*p = '\0';
	return (p_head);
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

// size_t	ft_strlen(const char *s)
// {
// 	size_t	count;

// 	if (!s)
// 		return (0);
// 	count = 0;
// 	while (*s++)
// 		count++;
// 	return (count);
// }

__attribute__((destructor))
static void destructor() {
    system("leaks -q a.out");
}