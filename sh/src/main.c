/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:05:13 by monoguei          #+#    #+#             */
/*   Updated: 2025/03/12 14:49:31 by lylrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	cleanup_memory(char *line, char **splited_line)
{
	int	j;

	free(line);
	j = 0;
	while (splited_line[j])
	{
		free(splited_line[j]);
		j++;
	}
	free(splited_line);
}
// // implique quon sait deja que cest une c
// // int	is_a_builtin(char *cmd)

// int	kind_of_token(char *input)
// {
// 	if (ft_strncmp_end((const char *)input, "echo", 4) == 0)
// 	{
// 		printf("\n%s = cmd\n", input);
// 		echo(input);
// 		return (0);
// 	}
// 	else if (ft_strncmp_end((const char *)input, "cd", 2) == 0)
// 	{
// 		printf("\n%s = cmd\n", input);
// 		return (0);
// 	}
// 	else if (ft_strncmp_end((const char *)input, "pwd", 3) == 0)
// 	{
// 		printf("\n%s = cmd\n", input);
// 		return (0);
// 	}
// 	else if (ft_strncmp_end((const char *)input, "env", 3) == 0)
// 	{
// 		printf("\n%s = cmd\n", input);
// 		return (0);
// 	}
// 	else if (ft_strncmp_end((const char *)input, "export", 6) == 0)
// 	{
// 		printf("\n%s = cmd\n", input);
// 		return (0);
// 	}
// 	else if (ft_strncmp_end((const char *)input, "unset", 5) == 0)
// 	{
// 		printf("\n%s = cmd\n", input);
// 		return (0);
// 	}
// 	else // pas forcement arg, peut etre path/bin
// 		printf("%s = arg\n\n", input);
// 	return (1);
// }

// void	execution(char *splited_line, char *argv, char **envp)
// {
// 	if (kind_of_token(splited_line) == 1)
// 	{
// 		printf("execve");
// 		execve(splited_line, (char * const *)argv, envp);
// 	}
// 	return ;
// }

// void	display_input(char **splited_line)
// {
// 	int	i;

// 	i = 0;
// 	printf("splited_line[%d]: %s\n", i, splited_line[i]);
// 	// execution(splited_line[i], splited_line[i + 1], environ->envp);
// 	sleep(1);
// }

// char	**split_input(char *line)
//{
//	char	**splited_line;
//
//	splited_line = ft_split(line, ' ');
//	if (!splited_line)
//	{
//		fprintf(stderr, "Error splitting line\n");
//		free(line);
//		return (NULL);
//	}
//	return (splited_line);
//}

char	*get_user_input(const char *prompt)
{
	char	*line;

	line = readline(prompt);
	if (!line)
	{
		fprintf(stderr, "Error reading line\n");
		return (NULL);
	}
	add_history(line);
	return (line);
}

int	tester_echo(void)
{
	char	**input;

	// t_data	*data;
	input = malloc(sizeof(char *) * 4);
	input[0] = "Elise";
	input[1] = "a";
	input[2] = "raison";
	input[3] = NULL;
	b_echo(input);
	free(input);
	return (0);
}

int	tester_pwd(void)
{
	b_pwd();
	return (0);
}

void	tester_env(char **envp)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	init_env(data, envp);
}

void	tester_cd(char **envp)
{
	char	**input;
	t_data	*data;

	data = malloc(sizeof(t_data));
	input = malloc(sizeof(char *) * 3);
	input[0] = "cd";
	input[1] = "src";
	input[2] = NULL;
	init_env(data, envp);
	b_pwd();
	b_cd(data, input[1]);
	b_pwd();
	free(input);
}

int	main(int ac, char **av, char **envp)
{
	char	*input;
	char	**splited_input;
	t_token	*head;

	(void)ac;
	(void)av;
	(void)envp;
	// Uncomment and use the following lines if needed
	init_signals();
	while (1)
	{
		input = get_user_input("minishell> ");
		splited_input = parse_input(input);
		head = tokenize(splited_input);
		first_word(splited_input, envp);
		print_all_token_types(head);
		// display_input(splited_input);
		restore_terminal();
			// problème de double affichage du prompt suite à ctrl +/ lors d'une exécution
		cleanup_memory(input, splited_input);
		init_signals();
	}
	tester_env(envp);
	tester_cd(envp);
	return (0);
}
