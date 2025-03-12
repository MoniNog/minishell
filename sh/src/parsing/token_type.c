/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:51:39 by lylrandr          #+#    #+#             */
/*   Updated: 2025/03/12 14:39:16 by lylrandr         ###   ########.fr       */
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
