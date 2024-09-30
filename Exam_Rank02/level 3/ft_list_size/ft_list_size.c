#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int	size = 0;
	t_list	*node;

	node = begin_list;

	while (node)
	{
		size++;
		node = node->next;
	}
	return (size);
}

int	main(void)
{
	t_list	node1;
	t_list	node2;
	t_list	node3;
	t_list	node4;

	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = NULL;
	printf("%i", ft_list_size(&node1));
	return (0);
}
