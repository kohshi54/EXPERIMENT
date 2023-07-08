#include "gc.h"

void	ft_free(void *ptr)
{
	printf("freed pointer %p\n", ptr);
	free(ptr);
}

void	*ft_malloc(size_t size, t_list *list)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	ft_lstadd_back(&list, ft_lstnew(ptr));
	printf("malloced %p\n", ptr);
	return (ptr);
}

void	free_all_mallocated_area(t_list *list)
{
	t_list	*tmplist;

	while (list)
	{
		tmplist = list;
		list = list->next;
		ft_lstdelone(tmplist, ft_free);
	}
}

int main(void)
{
	t_list *list;
	char *p1;
	char *p2;

	list = ft_lstnew(NULL);
	p1 = ft_malloc(sizeof(char) * 4, list);
	p1[0] = 'a';
	p1[1] = 'b';
	p1[2] = 'c';
	p1[3] = '\0';
	p2 = ft_malloc(sizeof(char) * 4, list);
	p2[0] = 'd';
	p2[1] = 'e';
	p2[2] = 'f';
	p2[3] = '\0';
	free_all_mallocated_area(list);
	system("leaks -q garbage");
	return (0);
}