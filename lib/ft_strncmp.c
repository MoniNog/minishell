/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoguei <monoguei@student.lausanne42.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:27:05 by lylrandr          #+#    #+#             */
/*   Updated: 2025/02/28 09:34:53 by monoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp_end(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	if (ft_strlen(s1) == (int)n)
	{
		while (s1[i] && s2[i] && n > 1)
		{
			if (s1[i] != s2[i])
				return ((unsigned char)s1[i] - (unsigned char)s2[i]);
			i++;
			n--;
		}
		return (0);
	}
	else
		return (-1);
}
