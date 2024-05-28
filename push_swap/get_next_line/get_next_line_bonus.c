/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychbily <ychbily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 21:22:33 by ychbily           #+#    #+#             */
/*   Updated: 2023/12/19 21:22:35 by ychbily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*buf[OPEN_MAX];
	char		*line;
	int			readed;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(buf[fd]), buf[fd] = NULL, NULL);
	line = malloc((size_t)BUFFER_SIZE + 1);
	if (!line)
		return (free(buf), free(line), buf[fd] = NULL, NULL);
	readed = 1;
	while (readed > 0)
	{
		readed = read(fd, line, BUFFER_SIZE);
		if (readed == -1)
			return (free(buf[fd]), NULL);
		line[readed] = '\0';
		buf[fd] = ft_append(buf[fd], line);
		if (new_ln(buf[fd]))
			break ;
	}
	if (line)
		free(line);
	line = NULL;
	return (ft_line(&buf[fd]));
}
