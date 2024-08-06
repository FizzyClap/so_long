/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roespici <roespici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:10:33 by roespici          #+#    #+#             */
/*   Updated: 2024/06/27 15:02:34 by roespici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_fill_buffer(int fd, char *buffer, char *container)
{
	int		bytes_read;

	buffer[0] = 0;
	bytes_read = 1;
	while (!ft_strchr_gnl(buffer, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		buffer[bytes_read] = '\0';
		if (!container)
		{
			if (bytes_read == 0)
				return (NULL);
			container = ft_strdup_gnl(buffer);
		}
		else
			container = ft_strjoin_gnl(container, buffer);
		if (!container)
			return (NULL);
	}
	return (container);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*container;
	char		*line;
	char		*temp;
	int			len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	container = NULL;
	container = ft_fill_buffer(fd, buffer, container);
	if (!container)
		return (NULL);
	len = ft_strchr_gnl(container, '\n') - container + 1;
	line = ft_substr_gnl(container, 0, len);
	temp = ft_substr_gnl(container, len, ft_strlen_gnl(container) - len);
	free(container);
	container = temp;
	if (container[0] == '\0')
	{
		free(container);
		container = NULL;
	}
	return (line);
}
