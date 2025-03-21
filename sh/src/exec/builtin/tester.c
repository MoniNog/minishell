// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   tester.c                                           :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: monoguei <monoguei@student.lausanne42.c    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/03/11 21:11:06 by monoguei          #+#    #+#             */
// /*   Updated: 2025/03/21 10:53:26 by monoguei         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../../../minishell.h"

// int	tester_pwd(void)
// {
// 	b_pwd();

// 	return (0);
// }

// void tester_env(char **envp)
// {
// 	t_data *data;
// 	data = malloc(sizeof(t_data));

// 	init_env(data, envp);
// 	b_env(data);
// }

// int	tester_echo(void)
// {
// 	char	**input;

// 	// t_data	*data;
// 	input = malloc(sizeof(char *) * 4);
// 	input[0] = "Elise";
// 	input[1] = "a";
// 	input[2] = "raison";
// 	input[3] = NULL;
// 	b_echo(input);
// 	free(input);
// 	return (0);
// }

// int	tester_pwd(void)
// {
// 	b_pwd();
// 	return (0);
// }

// void	tester_env(char **envp)
// {
// 	t_data	*data;

// 	data = malloc(sizeof(t_data));
// 	init_env(data, envp);
// 	// b_env(data);
// }

// void	tester_cd(char **envp)	// Uncomment and use the following lines if needed

// {
// 	char	**input;
// 	t_data	*data;

// 	data = malloc(sizeof(t_data));
// 	input = malloc(sizeof(char *) * 3);
// 	input[0] = "cd";
// 	input[1] = "src";
// 	input[2] = NULL;
// 	init_env(data, envp);
// 	b_pwd();
// 	b_cd(data, input[1]);
// 	b_pwd();
// 	free(input);
// }

// void tester_cd(char **envp)
// {
// 	char	**input;
// 	t_data	*data;
// 	data = malloc(sizeof(t_data));

// 	input = malloc(sizeof(char *) * 3);

// 	input[0] = "cd";
// 	input[1] = "src";
// 	input[2] = NULL;

// 	init_env(data, envp);
// 	// b_pwd();
// 	// b_cd(data, input[1]);
// 	b_pwd();

// 	free(input);
// }


// int	tester_echo(void)
// {
// 	// t_data	*data;
// 	char	**input;

// 	input = malloc(sizeof(char *) * 4);

// 	input[0] = "Elise";
// 	input[1] = "a";
// 	input[2] = "raison";
// 	input[3] = NULL;
	
// 	b_echo(input);

// 	free(input);
	
// 	return (0);
// }
