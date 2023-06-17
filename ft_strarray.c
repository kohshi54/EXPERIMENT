#include <unistd.h>

int	main(int argc, char *argv[])
{
	size_t	i;
	char	*p;
	size_t	count;

	if (argc < 3)
		return (0);
	count = atoi(argv[1]);
	i = 0;
	p = malloc(sizeof(char *) * (count + 1));
	while (i < count)
		*p++ = argv[i + 2];
	*p = NULL;
	return (0);
}