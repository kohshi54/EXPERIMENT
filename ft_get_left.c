#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
char *get_left(char *save);
size_t	ft_strchr_nl(const char *s);
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
	char *line = get_left(save);
	printf("save: %s\n", line);
	return (0);
}

char *get_left(char *save)
{
	size_t	read_byte;
	char	*p;
	char	*head;

	read_byte = ft_strlen_c(save, '\n');
	p = malloc(sizeof(char) * (read_byte + 1));
	if (!p)
	{
		free(save);
		return (NULL);
	}
	head = p;
	while (read_byte--)
		*p++ = *save++;
	*p = '\0';
	return (head);
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
