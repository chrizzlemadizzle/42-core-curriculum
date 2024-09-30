#include "get_next_line.h"

char	*ft_output_list(t_list *list)
{
	char	*line;
	t_list	*temp;
	size_t	linelen;

	linelen = 0;
	temp = list;
	while (temp)
	{
		if(temp->content != NULL)
			linelen += ft_strlen(temp->content);
		temp = temp->next;
		printf("linelen: %zu\n", linelen);
	}
	line = (char *) malloc(linelen * sizeof(char));
	temp = list;
	linelen = 0;
	while(temp)
	{
		if(temp->content != NULL)
		{
			ft_memcpy(line + linelen, temp->content, ft_strlen(temp->content));
			linelen += ft_strlen(temp->content);
		}
		temp = temp->next;
	}
	return (line);
}

void	ft_del(char **content)
{
	free(content);
}

void	ft_clear_list(t_list *list)
{
	t_list	*tmp;
	t_list	*entry;

	entry = list->next;
	while (entry != NULL)
	{
		tmp = entry->next;
		ft_del(&entry->content);
		//free(entry);
		entry = tmp;
	}
	list->next = NULL;
	return ;
}

void	ft_fill_list(t_list *list, char *s1, char *s2, char *s3)
{
	printf("pointer to listhead: %p\n", list);
	ft_lstadd_back(&list, ft_lstnew(ft_strdup(s1)));
	ft_lstadd_back(&list, ft_lstnew(ft_strdup(s2)));
	ft_lstadd_back(&list, ft_lstnew(ft_strdup(s3)));
	return ;
}

void	ft_list(void)
{
	static t_list	t_test;
	char	*line;
	char	*s1 = "hallo";
	char	*s2 = "gallo";
	char	*s3 = "ballo";

	ft_print_list(&t_test);
	ft_fill_list(&t_test, s1, s2, s3);
	ft_print_list(&t_test);
	ft_fill_list(&t_test, s1, s2, s3);
	ft_print_list(&t_test);
	ft_clear_list(&t_test);
	ft_print_list(&t_test);
	ft_fill_list(&t_test, s1, s2, s3);
	ft_print_list(&t_test);
	line = ft_output_list(&t_test);
	printf("line: %s\n", line);
	free(line);
	ft_clear_list(&t_test);
}

int	main(void)
{
	ft_list();
	return (0);
}
