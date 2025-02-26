/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:34:00 by lylrandr          #+#    #+#             */
/*   Updated: 2025/02/26 15:23:43 by lylrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*createstr(char const *s, size_t len, size_t i)
{
	char	*str;
	size_t	n;

	n = 0;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (n != len)
	{
		str[n] = s[i];
		i++;
		n++;
	}
	str[n] = '\0';
	return (str);
}

static int	cword(char const *s, char c)
{
	size_t	i;
	size_t	count;
	int		j;

	i = 0;
	j = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && j == 0)
		{
			count++;
			j = 1;
		}
		if (s[i] == c)
			j = 0;
		i++;
	}
	return (count);
}

static char	**ifone(char const *s, char c)
{
	size_t	len;
	size_t	i;
	size_t	ii;
	char	**tab;

	len = 0;
	i = 0;
	tab = (char **)malloc(sizeof(char *) * 2);
	if (!tab)
		return (NULL);
	while (s[i] == c)
		i++;
	ii = i;
	while (s[ii] != c && s[ii++])
		len++;
	tab[0] = createstr(s, len, i);
	tab[1] = NULL;
	return (tab);
}

static char	**filltab(char const *s, char c, char **tab, size_t count)
{
	size_t	u;
	size_t	j;
	size_t	len;
	size_t	i;
	size_t	ii;

	u = 0;
	j = 0;
	i = 0;
	while (u < count)
	{
		if (s[i] != c && j == 0)
		{
			ii = i;
			len = 0;
			while (s[ii] != c && s[ii++])
				len++;
			tab[u++] = createstr(s, len, i);
			j = 1;
		}
		if (s[i] == c)
			j = 0;
		i++;
	}
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	size_t	count;
	char	**tab;

	count = cword(s, c);
	if (count == 1)
	{
		tab = ifone(s, c);
		return (tab);
	}
	tab = (char **)malloc(sizeof(char *) * (count + 1));
	if (!tab)
		return (NULL);
	tab = filltab(s, c, tab, count);
	tab[count++] = NULL;
	return (tab);
}
/*
#include <stdio.h>
#include <stdlib.h>

int main() {
    char *input = "lorem ipsum dolor sit ame.";
    char delimiter = ' ';
    char **tabstr;
    int i = 0;

    tabstr = ft_split(input, delimiter);

    if (!tabstr) {
        printf("Erreur lors de la séparation.\n");
        return 1;
    }

    while (tabstr[i] != NULL) {
        printf("%s\n", tabstr[i]);
        free(tabstr[i]);
        i++;
    }

    free(tabstr);
    return 0;
}*/
