#include <stdio.h>
#include <stdlib.h>
size_t	ft_strchr_nl(const char *s);
char *get_right(char *line);
size_t	ft_strlen(const char *s);
size_t	ft_strlen_c(const char *s, const char target);

int main(void)
{
	char *save = malloc(sizeof(char) * (6 + 1));
	save[0] = 'a';
	save[1] = 'b';
	save[2] = 'c';
	save[3] = '\n';
	save[4] = 'd';
	save[5] = 'e';
	save[6] = '\0';
	save = get_right(save);
	printf("save: %s\n", save);
	// free(save);
	return (0);
}

char *get_right(char *save)
{
	char	*p_head;
	char	*s_head;
	char	*p;
	size_t	right_len;

	right_len = ft_strlen_c(save, '\0') - ft_strlen_c(save, '\n');
	p = malloc(sizeof(char) * (right_len + 1));
	if (!p)
	{
		free(save);
		return (NULL);
	}
	p_head = p;
	s_head = save;
	save = &save[ft_strlen_c(save, '\n')];
	while (right_len--)
		*p++ = *save++;
	free(s_head);
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

// size_t	ft_strchr_nl(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i])
// 		if (s[i++] == '\n')
// 			return (i);
// 	return (0);
// }

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