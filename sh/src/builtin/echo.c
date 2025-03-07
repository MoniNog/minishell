/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoguei <monoguei@student.lausanne42.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 09:59:39 by monoguei          #+#    #+#             */
/*   Updated: 2025/03/07 09:42:39 by monoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../minishell.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../../../lib/libft.h"

typedef struct s_data
{
	char		**input;// ligne de commande
	// t_env		*env;// tableau envp
	int			exit_status;
}				t_data;

void	b_echo(char **input)
{
	int	i;

	i = 0;
	while(input[i])
	{
		ft_putstr_fd(input[i], 1);
		i++;
	}
}

int	main(void)
{
	t_data	*data;
	char	**input;


	input[0] = "Elise";
	input[1] = "a";
	input[2] = "raison\n";

	data = malloc(sizeof(t_data));
	data->input = input;
    
	b_echo(data->input);
    
	return (0);
}