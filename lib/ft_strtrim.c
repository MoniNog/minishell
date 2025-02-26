/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:49:26 by lylrandr          #+#    #+#             */
/*   Updated: 2024/10/21 17:08:01 by lylrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static int	firsttrim(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (set[j])
	{
		if (s1[i] == set[j])
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

static int	endtrim(char const *s1, char const *set, int i)
{
	int	j;

	i -= 1;
	j = 0;
	while (set[j] && i > 0)
	{
		if (s1[i] == set[j])
		{
			i--;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		t;
	char	*str;

	t = firsttrim(s1, set);
	i = ft_strlen(s1);
	j = 1 + endtrim(s1, set, i);
	if (((int)j - (int)t) < 0)
	{
		str = malloc(sizeof(char) * 1);
		str[0] = '\0';
		return (str);
	}
	str = malloc(sizeof(char) * (j - t + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (t <= j)
		str[i++] = s1[t++];
	i -= 1;
	str[i] = '\0';
	return (str);
}
/*
#include <stdio.h>
int	main()
{
	char s1[] = "";
	char set[] = "cdef";
	printf("%s\n", ft_strtrim(s1, set));
}*/
