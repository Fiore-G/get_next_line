/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: figarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:15:42 by figarcia          #+#    #+#             */
/*   Updated: 2025/01/11 21:50:39 by figarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	if (!str)
		return (NULL);
	while (*str != '\0')
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	return (NULL);
}

void	*ft_calloc(size_t num_elements, size_t size_of_element)
{
	size_t	total_size;
	size_t	i;
	void	*ptr;
	char	*temp_ptr;

	total_size = num_elements * size_of_element;
	ptr = malloc(total_size);
	temp_ptr = (char *)ptr;
	i = 0;
	if (num_elements > 0 && size_of_element > 0
		&& total_size / num_elements != size_of_element)
		return (NULL);
	if (ptr == NULL)
		return (NULL);
	while (i < total_size)
	{
		temp_ptr[i] = 0;
		i++;
	}
	return (ptr);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*concat;
	int		i;
	int		j;
	int		total_size;

	i = 0;
	total_size = ft_strlen(s1) + ft_strlen(s2);
	concat = malloc((total_size + 1) * sizeof(char));
	if (!concat || !s1 || !s2)
		return (NULL);
	while (s1[i])
	{
		concat[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		concat[i++] = s2[j++];
	concat[total_size] = '\0';
	return (concat);
}
