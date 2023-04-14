#include <stdio.h>
#include <stdlib.h>
void ft_free(char *s1);
void ft_free2(char **s1);
void my_func(char *s1);
void my_func2(char **s1);

int main(void)
{
	char *p = malloc(sizeof(char) * (2 + 1));
	p[0] = 'a';
	p[1] = 'b';
	p[2] = '\0';
	printf("before free ptr: %p\n", p); // 0x600001ec4040
	printf("before free: %s\n", p);     // ab
	ft_free(p);
	printf("after free ptr: %p\n", p);  // 0x600001ec4040
	printf("after free: %s\n", p);      // @???s?

	printf("-----\n");
	char *p2 = malloc(sizeof(char) * (2 + 1));
	p2[0] = 'a';
	p2[1] = 'b';
	p2[2] = '\0';
	printf("before free ptr: %p\n", p2); // 0x600001ec4040
	printf("before free: %s\n", p2);     // ab
	ft_free2(&p2);
	printf("after free ptr: %p\n", p2);  // 0x0
	printf("after free: %s\n", p2);      // (null)

	printf("-----\n");
	char *p3 = malloc(sizeof(char) * (2 + 1));
	p3[0] = 'a';
	p3[1] = 'b';
	p3[2] = '\0';
	printf("before free ptr: %p\n", p3); // 0x600001ec4040
	printf("before free: %s\n", p3);     // ab
	my_func(p3);
	printf("after free ptr: %p\n", p3);  // 0x600001ec4040
	printf("after free: %s\n", p3);      // @??Qf?

	printf("-----\n");
	char *p4 = malloc(sizeof(char) * (2 + 1));
	p4[0] = 'a';
	p4[1] = 'b';
	p4[2] = '\0';
	printf("before free ptr: %p\n", p4); // 0x600001ec4040
	printf("before free: %s\n", p4);     // ab
	my_func2(&p4);
	printf("after free ptr: %p\n", p4);  // 0x0
	printf("after free: %s\n", p4);      // (null)
	return (0);
}

// 関数先でもfreeすれば呼び出しもとでもfree()されてる。
// freeしてもポインタがヌルになるわけではない
// 関数の呼び出し先で、ポインタにアドレスをセットしても、呼び出し元では変わらない。
void ft_free(char *s1)
{
	free(s1);
	s1 = NULL;
}

// 関数先でポインタのアドレスをセットしたい時はダブルポインタで受け取る。
void ft_free2(char **s1)
{
	free(*s1);
	*s1 = NULL;
}

// 値渡しでポインタを渡し、その関数先でさらにポインタを参照渡しで渡しても大元でのポインタのアドレスは変わらない。
void my_func(char *s1)
{
	ft_free2(&s1);
}

// 参照渡しなら関数先の関数先でもポインタのアドレスを変更できる。
void my_func2(char **s1)
{
	ft_free2(s1);
}

// __attribute__((destructor))
// static void destructor() {
// 	system("leaks -q a.out");
// }
