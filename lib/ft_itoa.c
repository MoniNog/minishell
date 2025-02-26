/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:51:17 by lylrandr          #+#    #+#             */
/*   Updated: 2025/02/26 15:24:00 by lylrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	length(int n)
{
	int	size;

	size = 0;
	if (n < 0)
	{
		n *= -1;
		size++;
	}
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static char	*intmin(char *str)
{
	int		i;
	char	*s;

	i = 0;
	s = "-2147483648";
	str = malloc(sizeof(char) * 12);
	if (!str)
		return (NULL);
	while (i < 12)
	{
		str[i] = s[i];
		i++;
	}
	return (str);
}

static char	*ifzero(char *str)
{
	str = malloc(sizeof(char) * 2);
	if (!str)
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

static char	*fillstr(int n, char *str, int size)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	str[size] = '\0';
	i = size - 1;
	while (n != 0)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		size;

	size = length(n);
	str = NULL;
	if (n == 0)
	{
		str = ifzero(str);
		return (str);
	}
	if (n == -2147483648)
	{
		str = intmin(str);
		return (str);
	}
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	str = fillstr(n, str, size);
	return (str);
}
