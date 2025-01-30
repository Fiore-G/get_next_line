/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: figarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:06:47 by figarcia          #+#    #+#             */
/*   Updated: 2024/12/19 17:00:39 by figarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>  //para funcion ssize_t y size_t

char	*get_next_line(int fd);
/*      ---- utils ----        */
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);
void	*ft_calloc(size_t num_elements, size_t size_of_element);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
