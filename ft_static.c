#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	static char	*str;

	printf("str: %p\n", str); // str: 0x0 // static の初期ポインタはヌル
	free(str); // ヌルなのでfree()しても何も起こらない
	str = malloc(sizeof(char) * (2 + 1));
	str[0] = 'a';
	str[1] = 'b';
	str[2] = '\0';
	printf("str: %p\n", str); // str: 0x60000259c040
	printf("str: %s\n", str); // str: "ab"
	free(str);
	printf("str: %p\n", str); // str: 0x60000259c040 // free()したからといってポインタがヌルになるとは限らない
	printf("str: %s\n", str); // @?(h? /// ゴミ
	return (0);
}

__attribute__((destructor))
static void destructor() {
	system("leaks -q a.out");
}