/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:51:39 by lylrandr          #+#    #+#             */
/*   Updated: 2025/03/06 17:44:12 by lylrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	word_token(char *input, char **env, int i)
{
	if(is_cmd(input, env))
	{
		is_arg();
		exec_cmd(input, env);
	}
	else
		make_file(input);
}

void	operator_token(char token, char *input, int i)
{
	if (strncmp(token, '|', 1) == 0)
		is_valid_pipe(input);
	else
		is_valid_redirect(input);
}

void	env_token(char *input, int i)
{
	WordType type;
	char	*token;
	int		j;

	j = 0;
	while ((input[i] >= 'A' && input[i] <= 'Z') || input[i] == '_')
		j++;
	if (j == 0)

	token = malloc(sizeof(char) * (j + 1));
	j = 0;
	i++;
	if (input[i] == '?')
		return_exit_code();
	else
	{
		while ((input[i] >= 'A' && input[i] <= 'Z') || input[i] == '_')
		{
			token[j] = input[i];
			i++;
			j++;
		}
		token[j] = '\0';
		type = ENV;
	}
}

void	string_token(char *input, int i)
{

}

int	is_cmd(char *token, char **env)
{
	char	*path;
	char	*executable;

	path = ft_get_env_path(env);
	if (!path)
		return (0);
	executable = ft_get_path(path, token);
	free(path);
	if (executable)
	{
		free(executable);
		return (1);
	}
	return (0);
}
