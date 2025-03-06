/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoguei <monoguei@student.lausanne42.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:51:39 by lylrandr          #+#    #+#             */
/*   Updated: 2025/03/06 08:49:16 by monoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

//void	word_token(char *token)
//{
//
//}

//void	operator_token(char *token)
//{
//
//}

//void	env_token(char *token)
//{
//
//}

//void	string_token(char *token)
//{
//
//}

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
