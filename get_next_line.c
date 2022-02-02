/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 19:44:43 by tterribi          #+#    #+#             */
/*   Updated: 2022/01/21 10:33:21 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER_SIZE 1000
/*
* The goal of this project is to create the function get_next_line.c which, when called in a loop,
* will then allow the available text in the file descriptor to be read one line at a time until the end of the file.
* The program must compile with the flag-D BUFFER_SIZE=xx which will be used as the buffer size for the read calls
*in get_next_line.
*/

// legge un bite per volta della riga del file descriptor e salva il tutto in una variabile poi mandata in output in modo
// ottenere l'output desiderato dal progetto
char	get_line(int fd)
{
	char	*buffer;
	int		bytes;
	char	*backup;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (bytes && !strchr(fd, "\n"))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
		backup = ft_strjoin(backup, buffer);
	}
	free(buffer);
	return (backup);
}

char	*get_next_line(int fd)
{
	char	*line;
	char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	backup = get_line(fd);
	return (line);
}
//test main
/*
int	main(void)
{
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;
	char	*line;

	fd1 = open("tests/test.txt", O_RDONLY);
	fd2 = open("tests/test2.txt", O_RDONLY);
	fd3 = open("tests/test3.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd2);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd3);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}*/
