/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_environment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoguei <monoguei@student.lausanne42.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:00:48 by monoguei          #+#    #+#             */
/*   Updated: 2025/03/17 19:01:52 by monoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// HELP ELISE
t_env *create_env_var(char *env_var)
{
	// NAME '\0' Seven
	t_env	*env;
	char	*delimiter;

	env = malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	delimiter = ft_strchr(env_var, '=');// si pas de '=' renvoie NULL
	if (delimiter)
	{
		*delimiter = '\0';
		env->name = ft_strdup(env_var);
		env->value = ft_strdup(delimiter + 1);
		*delimiter = '=';
	}
	else
	{
		env->name = ft_strdup(env_var);
		env->value = NULL;
	}
	env->next = NULL;
	return (env);
}

t_env *convert_envp(char **envp)
{
	int		i;
	t_env	*head;
	t_env	*current;
	t_env	*new_node;

	i = 0;
	head = NULL;
	current = NULL;
	while(envp[i])
	{
		new_node = create_env_var(envp[i]);
		if (!new_node)
			return (NULL);
		if (!head)
		{
			head = new_node;
			current = head;
		}
		else
		{
			current->next = new_node;
			current = current->next;
		}
		i++;
	}
	return (head);
}

void init_env(t_data *data, char **envp)
{
	data->env = (t_env **)convert_envp(envp);
}

// [ ] decomposer ligne par ligne sur papier -> schema de la vue densemble de la fonction 
// [ ] comprendre
// [ ] reecrire 
// [ ] commenter les protypes de la libft
