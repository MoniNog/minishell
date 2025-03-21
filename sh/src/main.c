/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoguei <monoguei@student.lausanne42.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:05:13 by monoguei          #+#    #+#             */
/*   Updated: 2025/03/21 10:52:36 by monoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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


int	main(int ac, char **av, char **envp)
{
	char	*input;
	char	**splited_input;
	t_input	*head;

	(void)ac;
	(void)av;
	(void)envp;
	init_signals();
	while (1)
	{
		input = get_user_input("minishell> ");
		splited_input = parse_input(input);
		print_tokens(splited_input);
		head = tokenize(splited_input);
		first_word(splited_input, envp);
		// tester_env(envp);// init_env doit etre place dans le main
		// tester_cd(envp);
		// b_echo(input);
		print_all_token_types(head);
		b_pwd();
		restore_terminal();
		cleanup_memory(input, splited_input);
		init_signals();
	}
	return (0);
}
