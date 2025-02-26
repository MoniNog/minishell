/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:35:37 by lylrandr          #+#    #+#             */
/*   Updated: 2024/10/21 16:23:54 by lylrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	l;
	size_t	j;

	i = 0;
	l = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char *)haystack + i);
	while (haystack[j] && i < len)
	{
		l = 0;
		i = j;
		while (haystack[i] == needle[l] && i < len && haystack[i] && needle[l])
		{
			i++;
			l++;
		}
		if (needle[l] == '\0')
			return ((char *)(haystack + i - l));
		j++;
	}
	return (0);
}
