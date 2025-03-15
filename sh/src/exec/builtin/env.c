/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoguei <monoguei@student.lausanne42.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:13:15 by monoguei          #+#    #+#             */
/*   Updated: 2025/03/14 17:35:06 by monoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

void	b_env(t_data *data)
{
	// t_env *current;
	
	// current = (t_env *)data->env;
	// while (current)
	// {
	// 	printf("%s=%s\n", current->name, current->value);// ft_str_fd plutot ?
	// 	current = current->next;
	// }

	int i = 0;
	while (data->copy_env[i])
	{
		printf("%s\n", data->copy_env[i]);
		i++;
	}
}