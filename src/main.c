/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoguei <monoguei@lausanne42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:05:13 by monoguei          #+#    #+#             */
/*   Updated: 2025/02/26 17:42:01 by monoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"



void	read_input(const char *prompt)
{
	char *line = readline(prompt);
	char **splited_line;

	splited_line = ft_split(line, ' ');

	int i = 0;
	while(splited_line[i])
	{
		printf("%s", splited_line[i]);
		i++;
	}
	printf("nombre de mots : %i\n", i);
	return ;
}

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		read_input(av[1]);
	}
	return 0;
}
