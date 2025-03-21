// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   exit.c                                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: monoguei <monoguei@student.lausanne42.c    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/03/07 09:21:29 by monoguei          #+#    #+#             */
// /*   Updated: 2025/03/14 08:38:58 by monoguei         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../../../minishell.h"
// #include <stdlib.h>
// #include <stdio.h>
// #include <unistd.h>

// typedef struct s_data
// {
// 	char		**input;// ligne de commande
// 	// t_env		*env;// tableau envp
// 	int			exit_status;
// }				t_data;

// void	b_exit(t_data *data)
// {
// 	if (no_arg)
// 		"exit";
// 		exit(0);
// 	else if (more than 1 arg)
// 		`bash: exit: too many arguments`;
// 		exit_status = 1; // on ne quitte pas le programme 
// 	else 
// 		if num 
// 			exit(n % 256);
// 		else
// 			`bash: exit: 42abc: numeric argument required`;
// 			exit(255);

// 	// cleanup_memory(data->input);
// 	printf("exit\n");
// 	exit(0);
// }
// int	main(void)
// {
// 	t_data *data;

// 	data = malloc(sizeof(t_data));

// 	b_exit(data);

// 	return (0);
// }

// [ ] a coder...