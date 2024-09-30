#include "get_next_line.h"

int	main(void)
{
	t_list	*t_test;

	t_test = ft_lstnew("hallo");
	printf("%s", t_test->content);
	free(t_test->content);
	free(t_test);
	return (0);
}
