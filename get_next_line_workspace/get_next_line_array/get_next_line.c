/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahne <cdahne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:40:35 by cdahne            #+#    #+#             */
/*   Updated: 2024/06/05 16:12:49 by cdahne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_create_line(char **remainder, char *buffer, char *linebreak)
{
	size_t	remlen;
	size_t	linelen;
	char	*line;

	remlen = ft_strlen(remainder);
	//printf("remlen: %zu\n", remlen);
	linelen = remlen + linebreak - buffer + 1;
	//printf("linelen: %zu\n", linelen);
	line = (char *) malloc(linelen * sizeof(char));
	ft_memcpy(line, remainder, remlen);
	ft_memcpy(line + remlen, buffer, linebreak - buffer + 1);
	return (line);
}

char	*ft_parse_buffer(char *buffer, char	**remainder, size_t len)
{
	char	*line;
	char	*linebreak;

	linebreak = ft_strchr(buffer, '\n');
	if (!linebreak)
	{
		line = (char *) malloc(BUFFER_SIZE * sizeof(char));
		ft_memcpy(, buffer, len);
	}
	else
	{
		line = ft_create_line(remainder, buffer, linebreak);
		ft_lstclear(remainder);
		ft_lstadd_back(remainder, ft_lstnew(ft_memcpy(remainder, linebreak + 1, BUFFER_SIZE - (linebreak - buffer))));
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char			*r_buf;
	static char		*remainder;
	char			*line;
	size_t			chr_read;

	if (fd < 0)
		return (NULL);
	printf("\nnew get_next_line function call\n");
	line = NULL;
	while (!line)
	{
		r_buf = (char *) malloc(BUFFER_SIZE);
		if (!r_buf)
			return (NULL);
		printf("new read into buffer\n");
		chr_read = read(fd, r_buf, BUFFER_SIZE);
		printf("chr_read: %zu\n", chr_read);
		printf("current r_buf:\n%s\n", r_buf);
		printf("current remainder:\n%s\n", remainder);
		line = ft_parse_buffer(r_buf, remainder, chr_read);
		printf("new remainder:\n%s\n", remainder);
		free(r_buf);
	}
	return (line);
}

int	main(void)
{
	int	fd;

//toDo: check lstclear
	fd = open("files/read_error.txt", O_RDONLY);
	//fd = open("files/empty.txt", O_RDONLY);
	if (fd == -1)
		return (0);
	// printf("line:\n%s\n", get_next_line(fd));
	// printf("line:\n%s\n", get_next_line(fd));
	// printf("line:\n%s\n", get_next_line(fd));
	// printf("line:\n%s\n", get_next_line(fd));
	//printf("line:\n%s\n", get_next_line(fd));
	close(fd);
	return (0);
}
