/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahne <cdahne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:40:35 by cdahne            #+#    #+#             */
/*   Updated: 2024/06/14 14:46:07 by cdahne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Repeated calls (e.g., using a loop) to get_next_line() function read
the text or file pointed to by the file descriptor, one line at a time -
including '\n' except if end of file/text is reached.
If there is nothing else to read or if an error occurrs, it returns NULL.*/

#include "get_next_line.h"

// clear whole linked list except for first node.
// fill first node with \0 and set next node to NULL.
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

// calculate length of line to output and allocate enough memory
// fill line by parsing t_remainder
// adding len-times characters from buffer
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
	while (temp)
	{
		ft_memmove(line + linelen, temp->content, ft_strlen(temp->content));
		linelen += ft_strlen(temp->content);
		temp = temp->next;
	}
	ft_memmove(line + linelen, buffer, len);
	return (line);
}

// Parse buffer searching for '\n'.
// If no '\n' occurs, it copies buffer into a new node of t_remainder
// OR creates and outputs a line if the end of file is reached.
// If '\n' occurs, it creates and outputs a line containing all characters
// including '\n' and updates t_remainder with remaining characters.
char	*ft_parse_buffer(char *buffer, t_list *t_remainder, size_t chr_read)
{
	char			*line;
	static char		*nodecontent;
	long long int	len;

	len = ft_strchr(buffer, '\n') - buffer;
	if (len < 0 && chr_read == BUFFER_SIZE)
	{
		line = NULL;
		nodecontent = (char *) ft_calloc(chr_read + 1, sizeof(char));
		ft_memmove(nodecontent, buffer, chr_read);
		ft_lstadd_back_new(&t_remainder, nodecontent);
	}
	else if (len < 0 && chr_read < BUFFER_SIZE)
	{
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

// Check if remainder contains '\n'.
// Creates and outputs a line in that case and updates t_remainder.
char	*ft_check_remainder(t_list *t_remainder)
{
	char	*line;
	char	*linebreak;
	size_t	len;

	len = 0;
	linebreak = ft_strchr(t_remainder->content, '\n');
	if (!linebreak)
		return (NULL);
	len = linebreak - t_remainder->content + 1;
	line = ft_calloc(len + 1, sizeof(char));
	ft_memmove(line, t_remainder->content, len);
	ft_memmove(t_remainder->content, linebreak + 1, BUFFER_SIZE - len);
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
	t_remainder.content = nodeone;
	line = ft_check_remainder(&t_remainder);
	while (!line)
	{
		buffer = (char *) ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		chr_read = read(fd, buffer, BUFFER_SIZE);
		if (chr_read < 0 || chr_read > BUFFER_SIZE
			|| (chr_read == 0 && !*t_remainder.content && !t_remainder.next))
		{
			free(buffer);
			ft_clear_remainder(&t_remainder);
			return (NULL);
		}
		line = ft_parse_buffer(buffer, &t_remainder, chr_read);
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
	//fd = open("files/read_error.txt", O_RDONLY);
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
	//close(fd);
	//fd = open("files/read_error.txt", O_RDONLY);
	//line = get_next_line(fd);
	//printf("line:\n%s\n", line);
	//free(line);
	return (0);
}*/
