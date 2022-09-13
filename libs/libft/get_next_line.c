/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 22:14:42 by vangirov          #+#    #+#             */
/*   Updated: 2022/05/07 13:45:47 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

static int	ft_read(int fd, char *buff, int size)
{
	int	rd;

	rd = read(fd, buff, size);
	buff[rd] = '\0';
	return (rd);
}

static char	*ft_concat(char *line, char *nonl_buff)
{
	char	*newline;

	newline = ft_strjoin(line, nonl_buff);
	free(line);
	return (newline);
}

static char	*ft_get_tail(char *line, char *buff)
{
	size_t	len;
	char	*tail;
	char	*rest;

	rest = ft_strchr(buff, '\n');
	if (!rest)
		return (ft_concat(line, buff));
	rest++;
	len = rest - buff;
	tail = (char *)malloc(sizeof(char) * len + 1);
	ft_strlcpy(tail, buff, len + 1);
	len = ft_strlen(rest);
	ft_memmove(buff, rest, len + 1);
	line = ft_concat(line, tail);
	free(tail);
	return (line);
}

char	*get_next_line(int fd, char **to_fill)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		rd;

	if (fd < 0)
		return (NULL);
	line = (char *)malloc(1);
	line[0] = '\0';
	while (!ft_strchr(buff, '\n'))
	{
		line = ft_concat(line, buff);
		rd = ft_read(fd, buff, BUFFER_SIZE);
		if (!rd && line[0])
			break ;
		if (rd < 1)
		{
			free(line);
			return (NULL);
		}
	}
	line = ft_get_tail(line, buff);
	*to_fill = line;
	return (line);
}

// #define BUFFER_SIZE 1

// #include <fcntl.h>
// #include <stdio.h>

// int	main()
// {
// 	int		fd;
// 	char	*ret;

// 	printf("===============================================================\n");
// 	fd = open("text", O_RDONLY);
// 	// for (int i = 0; (ret = get_next_line(fd)) && i <= 22; i++)
// 	while ((ret = get_next_line(fd)))
// 	{
// 		printf(">>>>>>>>>>>>>>>> %s", ret);
// 		free(ret);
// 	}
// 	free(ret);
// 	close(fd);
// 	return (0);
// }