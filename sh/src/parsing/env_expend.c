/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_expend.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:51:39 by lylrandr          #+#    #+#             */
/*   Updated: 2025/03/26 15:15:59 by lylrandr         ###   ########.fr       */
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

char	*extract_var_name(const char *str, int *i)
{
	int len = 0;
	char *name;

	if (str[*i] == '?')
	{
		(*i)++;
		return ft_strdup("?");
	}
	while (ft_isalnum(str[*i + len]) || str[*i + len] == '_')
		len++;
	name = ft_substr(str, *i, len);
	*i += len;
	return name;
}

char	*expand_token_string(const char *src)
{
	int i = 0;
	char *result = ft_calloc(1, sizeof(char));
	char *tmp;
	char *var_name;
	char *var_value;

	while (src[i])
	{
		if (src[i] == '$')
		{
			i++;
			if (!src[i] || (!ft_isalnum(src[i]) && src[i] != '_' && src[i] != '?'))
			{
				// cas de $ tout seul => on l'ajoute tel quel
				tmp = ft_strjoin(result, "$");
				free(result);
				result = tmp;
				continue;
			}
			var_name = extract_var_name(src, &i);
			var_value = getenv(var_name);
			if (!var_value)
				var_value = "";
			tmp = ft_strjoin(result, var_value);
			free(result);
			result = tmp;
			free(var_name);
		}
		else
		{
			char tmp_str[2] = {src[i], 0};
			tmp = ft_strjoin(result, tmp_str);
			free(result);
			result = tmp;
			i++;
		}
	}
	return result;
}

void	replace_env_value(t_input *token)
{
	char *expanded;

	expanded = expand_token_string(token->token);
	//FREE ?
	token->token = expanded;
}

void is_env_var(t_input *input)
{
	t_input *curr = input;

	while (curr)
	{
		if (curr->type != T_SQUOTE)
			replace_env_value(curr);
		curr = curr->next;
	}
}

