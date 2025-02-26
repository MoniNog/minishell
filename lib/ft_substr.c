/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:00:09 by lylrandr          #+#    #+#             */
/*   Updated: 2025/02/26 15:23:11 by lylrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ifneg(char const *s, unsigned int start)
{
	unsigned int	i;
	unsigned int	j;
	char			*str;

	j = 0;
	i = ft_strlen(s);
	if (start >= i)
	{
		str = malloc(sizeof(char) * 1);
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	i -= start;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	while (j < i)
	{
		str[j] = s[start + j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

static char	*fillstr(char const *s, unsigned int start, size_t len, char *str)
{
	size_t	i;

	i = 0;
	while (i < (unsigned int)len)
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	j;

	j = ft_strlen(s);
	if (len > j)
	{
		str = ifneg(s, start);
		return (str);
	}
	if (start >= j)
	{
		str = malloc(sizeof(char) * 1);
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str = fillstr(s, start, len, str);
	return (str);
}
