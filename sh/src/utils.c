/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:07:22 by lylrandr          #+#    #+#             */
/*   Updated: 2025/03/17 16:14:45 by lylrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i < n && (s1[i] || s2[i]))
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

int	while_quotes(char *input, int i)
{
	if (input[i] == '\'')
	{
		i++;
		while (input[i] != '\'')
			i++;
	}
	else if (input[i] == '"')
	{
		i++;
		while (input[i] != '"')
			i++;
	}
	while (input[i + 1] != ' ' && input[i + 1] != '|' && input[i + 1] != '<'
		&& input[i + 1] != '>' && input[i + 1])
		i++;
	return (i);
}

void	fill_quotes(int len, char *input, char **array, int **i, int start)
{
	int	j;

	j = 0;
	while (j < len)
	{
		array[**i][j] = input[start + j];
		j++;
	}
	array[**i][j] = '\0';
}

void	if_quotes(char *input, char **array, int *k, int *i)
{
	char	quote;
	int		start;
	int		len;

	quote = input[*k];
	start = *k;
	(*k)++;
	while (input[*k] && input[*k] != quote)
		(*k)++;
	if (input[*k] == quote)
		(*k)++;
	while (input[*k] && input[*k] != ' ' && input[*k] != '|' && input[*k] != '<'
		&& input[*k] != '>' && input[*k] != ';' && input[*k] != '&'
		&& input[*k] != '(' && input[*k] != ')')
		(*k)++;
	len = *k - start;
	array[*i] = malloc(sizeof(char) * (len + 1));
	if (!array[*i])
		return ;
	fill_quotes(len, input, array, &i, start);
}

char	**malloc_second_parsing(int len)
{
	char	**tab_token;

	tab_token = malloc(sizeof(char *) * (len + 1));
	if (!tab_token)
		return (NULL);
	tab_token[len] = NULL;
	return (tab_token);
}
