/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: figarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:12:37 by figarcia          #+#    #+#             */
/*   Updated: 2025/01/11 21:23:51 by figarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*update_data_buffer(char *data_buffer)
{
	int		i;
	int		j;
	char	*new_data_buffer;

	i = 0;
	while (data_buffer[i] != '\0' && data_buffer[i] != '\n')
		i++;
	if (!data_buffer[i])
		return (free(data_buffer), NULL);
	new_data_buffer = ft_calloc(sizeof(char), (ft_strlen(data_buffer) - i + 1));
	i++;
	j = 0;
	while (data_buffer[i] != '\0')
		new_data_buffer[j++] = data_buffer[i++];
	new_data_buffer[j] = '\0';
	free(data_buffer);
	return (new_data_buffer);
}

char	*extract_line(char *data_buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!data_buffer[i])
		return (NULL);
	while (data_buffer[i] != '\0' && data_buffer[i] != '\n')
		i++;
	line = ft_calloc(sizeof(char), (i + 2));
	i = 0;
	while (data_buffer[i] != '\0' && data_buffer[i] != '\n')
	{
		line[i] = data_buffer[i];
		i++;
	}
	if (data_buffer[i] == '\n')
		line[i] = '\n';
	return (line);
}

/* --- aux function -- */
char	*concat_and_free(char *data_buffer, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(data_buffer, buffer);
	if (!temp)
	{
		free(buffer);
		free(data_buffer);
		return (NULL);
	}
	free(data_buffer);
	return (temp);
}

char	*read_file(int fd, char *data_buffer)
{
	char	*buffer;
	int		bytes_read;

	if (!data_buffer)
		data_buffer = ft_calloc(1, 1);
	buffer = ft_calloc(sizeof(char), BUFFER_SIZE +1);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			free(data_buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		data_buffer = concat_and_free(data_buffer, buffer);
		if (ft_strchr(data_buffer, '\n'))
			break ;
	}
	free(buffer);
	return (data_buffer);
}

char	*get_next_line(int fd)
{
	static char	*data_buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	data_buffer = read_file(fd, data_buffer);
	if (!data_buffer)
		return (NULL);
	line = extract_line(data_buffer);
	data_buffer = update_data_buffer(data_buffer);
	return (line);
}
