/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoguei <monoguei@student.lausanne42.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:35:45 by monoguei          #+#    #+#             */
/*   Updated: 2025/03/13 17:21:15 by monoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

//voir avec parsing pour name valid selon syntaxe
// Par exemple :

// Nom de variable (name) : MY_VAR_1 (lettres, chiffres, underscore, ne commence pas par un chiffre)
// Valeur (value) : Hello_World123 (lettres, chiffres, underscores, espaces possibles)

// bool	no_option(char *builtin)
// {
// 	// voir avec parsing pour que cmd avec et sans option soit differencier
// }

// t_env		*sort_env(t_env* data, char *(*cmp)(char, char))
// {

// 	t_env	*tmp;
// 	int		swap;

// 	tmp = data;
// 	while (data->next)
// 	{
// 		if ((*cmp)(data->name, data->next->name) == 0)
// 		{
// 			swap = data->name;
// 			data->name = data->next->name;
// 			data->next->name = swap;
// 			data = tmp;
// 		}
// 		else
// 			data = data->next;
// 	}
// 	data = tmp;
// }
t_env	*ft_varlast(t_env *var)
{
	t_env	*var_last;

	if (!var)
		return (0);
	var_last = var;
	while (var_last->next)
		var_last = var_last->next;
	return (var_last);
}

void	ft_varadd_back(t_env **var, t_env *new1)
{
	t_env	*var_last;

	if (!new1)
		return ;
	var_last = ft_varlast(*var);
	if (!var_last)
		*var = new1;
	else
		var_last->next = new1;
}


void	b_export(t_data *data)
{
	// t_env	*current;
	t_env	*new;

	// data->env = current;
	// if (no_option((data->input->cmd) == TRUE))
	// {
	// 	ft_putstr_fd("export -x", 1);
	// 	while(current)
	// 	{
	// 		ft_putstr_fd(current->name, 1);
	// 		ft_putendl_fd(current->value, 1);
	// 		current = current->next;
	// 	}
	// 	//parcourir env, afficher dans ordre alphabetique dans le terminal
	// }// HELP ELISE
	// else
	{
		new = create_env_var(data->input CMD);
		ft_varadd_back((t_env **)data->env, (t_env *)new);
	}
}
export NAME=Lylah

data->token->next->token