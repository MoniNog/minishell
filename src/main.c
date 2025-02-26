/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:05:13 by monoguei          #+#    #+#             */
/*   Updated: 2025/02/26 17:03:32 by lylrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*read_input(const char *prompt)
{
	readline(prompt);
	return ("hello");
}

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		printf("%s\n", read_input(av[1]));
	}
	return 0;
}
