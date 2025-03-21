/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoguei <monoguei@student.lausanne42.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 09:59:39 by monoguei          #+#    #+#             */
/*   Updated: 2025/03/18 17:05:10 by monoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

// fonction permettant didentifier si l-option "-n" est present dans l'input
// bool	op_n(char *input)
// {
// 	if (ft_strchr(input, ' ') != '\0')
// 		if
// }

// input, char** doit se terminer par NULL	ou fournir la taille du tableau en arg.
void	b_echo(t_input *input)
{
	while(input->next->type == T_ARG)
	{
		ft_putstr_fd(input->next->token, 1);
		if (!input->next->next)
			write(1, "\n", 1);
		input->next = input->next->next;
	}
	
}

// [ ] gestion plusieurs n
// [ ] adapter avec token CMD_ARG et CMD
// [ ] commenter la fonction !