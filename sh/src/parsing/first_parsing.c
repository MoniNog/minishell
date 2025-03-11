/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoguei <monoguei@student.lausanne42.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:39:34 by lylrandr          #+#    #+#             */
/*   Updated: 2025/03/11 21:39:27 by monoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**first_parsing(char *input)
{
	int		i;
	int		j;
	char	**array;

	i = 0;
	j = 1;
	while (input[i])
	{
		if (input[i] == '|' || input[i] == '<' || input[i] == '>')
			j++;
		i++;
	}
	j++;
	array = malloc(sizeof(char *) * (j + 1));
	if (!array)
		return (NULL);
	array[j] = NULL;
	return (fill_tab(input, array));
}

int	word_len(char *input)
{
	int	i;

	i = 0;
	while (input[i] && input[i] != '|' && input[i] != '>' && input[i] != '<')
		i++;
	return (i);
}

void	if_operator(char *input, char **array, int *k, int i)
{
	int	j;
	int	len;

	j = 0;
	len = 0;
	while (input[*k + len] == '|' || input[*k + len] == '<'
			|| input[*k + len] == '>')
		len++;
	array[i] = malloc(sizeof(char) * (len + 1));
	if (!array[i])
	{
		perror("malloc");
		return ;
	}
	while (input[*k] == '|' || input[*k] == '<' || input[*k] == '>')
	{
		array[i][j] = input[*k];
		j++;
		(*k)++;
	}
	array[i][j] = '\0';
}

void	if_n_op(char *input, char **array, int *k, int *i)
{
	int	j;

	j = 0;
	while (input[*k] && input[*k] != '|' && input[*k] != '>'
		&& input[*k] != '<')
	{
		array[*i][j] = input[*k];
		(j)++;
		(*k)++;
	}
	array[*i][j] = '\0';
}

char	**fill_tab(char *input, char **array)
{
	int	i;
	int	k;
	int	len;

	i = 0;
	k = 0;
	while (input[k])
	{
		len = word_len(&input[k]);
		if (input[k] == '|' || input[k] == '<' || input[k] == '>')
			if_operator(input, array, &k, i);
		else
		{
			array[i] = malloc(sizeof(char) * (len + 1));
			if (!array[i])
				return (NULL);
			if_n_op(input, array, &k, &i);
		}
		i++;
	}
	array[i] = NULL;
	return (array);
}
