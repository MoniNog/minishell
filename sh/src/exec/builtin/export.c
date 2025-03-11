// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   export.c                                           :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: monoguei <monoguei@student.lausanne42.c    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/03/10 10:35:45 by monoguei          #+#    #+#             */
// /*   Updated: 2025/03/11 21:39:49 by monoguei         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../../../minishell.h"

// //voir avec parsing pour name valid selon syntaxe
// // Par exemple :

// // Nom de variable (name) : MY_VAR_1 (lettres, chiffres, underscore, ne commence pas par un chiffre)
// // Valeur (value) : Hello_World123 (lettres, chiffres, underscores, espaces possibles)

// bool	no_option(char *builtin)
// {
// 	// voir avec parsing pour que cmd avec et sans option soit differencier
// }

// void	swap_node(t_env );

// void	find_next_node(t_env *current)
// {
// 	int	i;
// 	int j;
// 	t_env head;

// 	head = current;
// 	i = 0;
// 	j = 0;
// 	while (current)
// 	{
// 		if (current->name[i] > current->next->name[j])
// 			swap_node(current->name, current->next->name);
// 		else if (current->name[i] <= current->next->name[j])
		
// 		current = current->next;
// 	}
// }

// void	export(t_data *data)
// {
// 	t_env	*current;

// 	data->env = current;
// 	if (no_option((data->input->cmd) == TRUE))
// 	{
// 		ft_putstr_fd("export -x", 1);
// 		find_next_node(current);
// 		//parcourir env, afficher dans ordre alphabetique dans le terminal
// 	}// HELP ELISE
// }