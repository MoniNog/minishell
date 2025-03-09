/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoguei <monoguei@student.lausanne42.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 09:59:39 by monoguei          #+#    #+#             */
/*   Updated: 2025/03/07 14:13:22 by monoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

// fonction permettant didentifier si l-option "-n" est present dans l'input
// bool	op_n(char *input)
// {
// 	if (ft_strchr(input, ' ') != '\0')
// 		if
// }

// input, char** doit se terminer par NULL	ou fournir la taille du tableau en arg.
void	b_echo(char **input)
{
	int	i;

	i = 0;
	while(input[i])
	{
		ft_putstr_fd(input[i], 1);
		i++;
		if (!input[i])
			write(1, "\n", 1);
		else
		{
			// if(op_n == TRUE)
				write(1, " ", 1);
		}
	}
	
}
