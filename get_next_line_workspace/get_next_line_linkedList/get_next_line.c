/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahne <cdahne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:40:35 by cdahne            #+#    #+#             */
/*   Updated: 2024/06/13 17:16:32 by cdahne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// double check ft_memmove

#include "get_next_line.h"

void	ft_clear_remainder(t_list *t_remainder)
{
	t_list	*tmp;
	t_list	*entry;
	size_t	n;

	entry = t_remainder->next;
	while (entry != NULL)
	{
		tmp = entry->next;
		free(entry->content);
		free(entry);
		entry = tmp;
	}
	t_remainder->next = NULL;
	n = 0;
	while (n < BUFFER_SIZE)
		t_remainder->content[n++] = '\0';
	return ;
}

char	*ft_create_line(t_list *t_remainder, char *buffer, size_t len)
{
	char	*line;
	size_t	linelen;
	t_list	*temp;

	linelen = 0;
	temp = t_remainder;
	while (temp)
	{
		linelen += ft_strlen(temp->content);
		temp = temp->next;
	}
	linelen += len;
	line = (char *) ft_calloc(linelen + 1, sizeof(char));
	temp = t_remainder;
	linelen = 0;
	while(temp)
	{
		ft_memmove(line + linelen, temp->content, ft_strlen(temp->content));
		linelen += ft_strlen(temp->content);
		temp = temp->next;
	}
	ft_memmove(line + linelen, buffer, len);
	return (line);
}

char	*ft_parse_buffer(char *buffer, t_list *t_remainder, size_t chr_read)
{
	char		*line;
	//char		*linebreak;
	static char	*nodecontent;
	long int	len;

	//linebreak = ft_strchr(buffer, '\n');
	len = ft_strchr(buffer, '\n') - buffer;
	//printf("len to nl in buffer: %li\n", len);
	if (len < 0 && chr_read == BUFFER_SIZE)
	{
		line = NULL;
		nodecontent = (char *) ft_calloc(chr_read + 1, sizeof(char));
		ft_memmove(nodecontent, buffer, chr_read);
		ft_lstadd_back_new(&t_remainder, nodecontent);
	}
	else if (len < 0 && chr_read < BUFFER_SIZE)
	{
		//linebreak = buffer + len;
		line = ft_create_line(t_remainder, buffer, chr_read);
		ft_clear_remainder(t_remainder);
	}
	else
	{
		line = ft_create_line(t_remainder, buffer, len + 1);
		ft_clear_remainder(t_remainder);
		ft_memmove(t_remainder->content, buffer + len + 1, chr_read - len - 1);
	}
	return (line);
}

char	*ft_check_remainder(t_list *t_remainder)
{
	char	*line;
	char	*linebreak;
	size_t	len;

	len = 0;
	linebreak = ft_strchr(t_remainder->content, '\n');
	if (!linebreak)
		return (NULL);
	else
	{
		//printf("newline in remainder!!!\n");
		//printf("current remainder:\n");
		//ft_print_list(t_remainder);
		len = linebreak - t_remainder->content + 1;
		line = ft_calloc(len + 1, sizeof(char));
		ft_memmove(line, t_remainder->content, len);
		//t_remainder->content = linebreak + 1;
		ft_memmove(t_remainder->content, linebreak + 1, BUFFER_SIZE - len);
		//printf("new remainder:\n");
		//ft_print_list(t_remainder);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char			*buffer;
	static t_list	t_remainder;
	static char		nodeone[BUFFER_SIZE + 1];
	char			*line;
	long int		chr_read;

	if (fd < 0)
		return (NULL);
	//printf("\nnew get_next_line function call\n");
	t_remainder.content = nodeone;
	line = NULL;
	while (!line)
	{
		line = ft_check_remainder(&t_remainder);
		if (line)
			return (line);
		buffer = (char *) ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buffer)
			return (NULL);
		//printf("new read into buffer\n");
		chr_read = read(fd, buffer, BUFFER_SIZE);
		//printf("chr_read: %zu\n", chr_read);
		if (chr_read < 0)
		{
			free(buffer);
			ft_clear_remainder(&t_remainder);
			break ;
		}
		else if (chr_read > BUFFER_SIZE || (chr_read == 0 && !*t_remainder.content && !t_remainder.next))
		{
			free(buffer);
			break ;
		}
		else
			line = ft_parse_buffer(buffer, &t_remainder, chr_read);
		//printf("current buffer:\n%s\n", buffer);
		//printf("current remainder:\n");
		//ft_print_list(&t_remainder);
		//printf("new remainder:\n");
		//ft_print_list(&t_remainder);
		free(buffer);
	}
	return (line);
}
/*
int	main(void)
{
	int	fd;
	char	*line;
	size_t	lines;

	//fd = 1000;
	fd = open("files/read_error.txt", O_RDONLY);
	//fd = open("files/empty.txt", O_RDONLY);
	//fd = open("files/nl", O_RDONLY);
	//fd = open("files/41_no_nl", O_RDONLY);
	//fd = open("files/41_with_nl", O_RDONLY);
	//fd = open("files/1char.txt", O_RDONLY);
	//fd = open("files/lines_around_10.txt", O_RDONLY);
	//fd = open("files/empty.txt", O_RDONLY);
	//fd = open("files/giant_line_nl.txt", O_RDONLY);
	//fd = open("files/giant_line.txt", O_RDONLY);
	lines = 2;
	while(lines--)
	{
		line = get_next_line(fd);
		printf("line:\n%s\n", line);
		free(line);
	}
	close(fd);
	//fd = open("files/read_error.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("line:\n%s\n", line);
	free(line);
	return (0);
}*/
