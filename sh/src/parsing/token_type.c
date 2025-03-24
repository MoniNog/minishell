/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:51:39 by lylrandr          #+#    #+#             */
/*   Updated: 2025/03/19 18:43:18 by lylrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

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

void	replace_token(t_input *token, char *value)
{
	int		new_len;
	t_input	*new_token;

	new_len = ft_strlen(value);
	if (!token->token)
		return;
	new_token = cat_token(token, value, new_len);
	if (!new_token)
		return;
	token->token = new_token->token;
	free(new_token);
}


void	get_exit_code(void)
{
	printf("get exit code");
}

void	replace_env_value(t_input *token, int i)
{
	char	*var_name;
	char	*var_value;
	int		j = 0;

	i++;
	if (token->token[i] == '?')
		get_exit_code();
	while (ft_isalnum(token->token[i + j]) || token->token[i + j] == '_')
		j++;
	var_name = malloc(sizeof(char) * (j + 1));
	if (!var_name)
		exit(1);
	ft_strlcpy(var_name, &token->token[i], j + 1);
	var_value = getenv(var_name);
	if (!var_value)
		var_value = "";
	replace_token(token, var_value);
	free(var_name);
}


void	is_env_var(t_input *input)
{
	int		i;
	t_input	*curr;

	curr = input;
	while (curr)
	{
		if (curr->type != T_SQUOTE)
		{
			i = 0;
			while (curr->token[i])
			{
				if (curr->token[i] == '$')
					replace_env_value(curr, i);
				i++;
			}
		}
		curr = curr->next;
	}
}

void	replace_token_value(t_input *token, char *new_value)
{
	free(token->token);
	token->token = ft_strdup(new_value);
}
