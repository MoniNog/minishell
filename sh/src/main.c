/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:05:13 by monoguei          #+#    #+#             */
/*   Updated: 2025/04/02 17:19:43 by lylrandr         ###   ########.fr       */
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

void	do_exec(t_input *head, char *env_path)
{
	exec_pipe(head, env_path);
}

t_input	*do_parsing(t_input *head, char **splited_input)
{
//	print_tokens(splited_input);
	head = tokenize(splited_input);
//	print_all_token_types(head);
	is_env_var(head);
//	print_token_list(head);
	return (head);
}

int	main(int ac, char **av, char **envp)
{
	char	*input;
	char	**splited_input;
	char	*env_path;
	t_input	*head;

	(void)ac;
	(void)av;
	(void)envp;
	init_signals();
	while (1)
	{
		input = get_user_input("minishell> ");
		splited_input = parse_input(input);
		env_path = get_env_path(envp);
		head = do_parsing(head, splited_input);
		do_exec(head, env_path);
		restore_terminal();
		cleanup_memory(input, splited_input);
		init_signals();
	}
	return (0);
}
