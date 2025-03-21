/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoguei <monoguei@student.lausanne42.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 21:11:35 by moni              #+#    #+#             */
/*   Updated: 2025/03/21 11:16:51 by monoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


/// @brief create a cpy (malloc) of a str, modified by function f
/// @param s str to cpy and mod
/// @param f function to apply. 'char 	*f(unsigned int a, char c);'
/// @return str modified. returns NULL if error
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*s2;
	size_t	i;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	s2 = malloc(ft_strlen(s) + 1);
	while (s[i])
	{
		s2[i] = f(i, s[i]);
		i++;
	}
	s2[i] = 0;
	return (s2);
}
