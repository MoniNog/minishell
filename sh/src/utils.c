/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoguei <monoguei@student.lausanne42.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:07:22 by lylrandr          #+#    #+#             */
/*   Updated: 2025/03/21 21:13:24 by monoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/// @brief first cleanup memory function
/// @param line 
/// @param splited_line 
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


// copie colle avec malloc ET ajoute = a la fin

/// @brief copy src (malloc) and add `=` at the end (for linked list `t_env`)
/// @param src 
/// @return copied `str=`
char	*ft_strdup_equal(const char *src)
{
	int		i;
	int		len;
	char	*dest;

	i = 0;
	len = ft_strlen(src);
	dest = (char *) malloc((len + 2) * sizeof(char));
	if (!dest)
		return (NULL);
	while (src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '=';
	dest[i] = 0;
	return (dest);
}

/// @brief Concat str dest+src mod moni for export
/// @param dest NAME=
/// @param src value
/// @return total lenght (src + dest)
size_t	ft_strcat(char *dest, const char *src)
{
	size_t	src_len;
	size_t	dest_len;
	size_t	i;
	size_t	size;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	size = src_len + dest_len;
	i = 0;
	if (size <= dest_len)
		return (src_len + size);
	while (src[i] != 0 && (dest_len + i) < (size - 1))
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	if (size > 0)
		dest[dest_len + i] = 0;
	return (dest_len + src_len);
}

/// @brief compare name of buil-in with input, 
/// @param s1 built-in
/// @param s2 input
/// @param n number of char expected
/// @return ret 0 if s1 = s2, ret -1 if n_lenght != built-in, ret >0 s1 != s2
int	ft_strncmp_end(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	if (ft_strlen(s1) == n)
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

// duplicated (malloc), return cpy
char	*ft_strdup(const char *src)
{
	int		i;
	int		len;
	char	*dest;

	i = 0;
	len = ft_strlen(src);
	dest = (char *) malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
