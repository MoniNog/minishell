/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoguei <monoguei@student.lausanne42.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:07:22 by lylrandr          #+#    #+#             */
/*   Updated: 2025/03/17 18:56:27 by monoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	cleanup_memory(char *line, char **splited_line)
{
	int	j;

	free(line);
	j = 0;
	while (splited_line[j])
	{
		free(splited_line[j]);
		j++;
	}
	free(splited_line);
}

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

void	fill_quotes(int len, char *input, char **array, int **i, int k)
{
	int		j;
	char	quote;

	j = 0;
	quote = input[k];
	while (j < len)
	{
		if (input[k] != quote)
		{
			array[**i][j] = input[k];
			j++;
		}
		k++;
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
