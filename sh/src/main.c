/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid Date        by              +#+  #+#    #+#             */
/*   Updated: 2025/03/11 16:44:11 by lylrandr         ###   ########.fr       */
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

void	kind_of_token(char *input)
{
	if (ft_strncmp_end((const char *)input, "echo", 4) == 0)
	{
		printf("\n%s = cmd\n", input);
		//		echo(input);
	}
	else if (ft_strncmp_end((const char *)input, "cd", 2) == 0)
		printf("\n%s = cmd\n", input);
	else if (ft_strncmp_end((const char *)input, "pwd", 3) == 0)
		printf("\n%s = cmd\n", input);
	else if (ft_strncmp_end((const char *)input, "exit", 4) == 0)
		printf("\n%s = cmd\n", input);
	else if (ft_strncmp_end((const char *)input, "env", 3) == 0)
		printf("\n%s = cmd\n", input);
	else if (ft_strncmp_end((const char *)input, "export", 6) == 0)
		printf("\n%s = cmd\n", input);
	else if (ft_strncmp_end((const char *)input, "unset", 5) == 0)
		printf("\n%s = cmd\n", input);
	else
		printf("%s = arg\n\n", input);
}

//void	display_input(char **splited_line)
//{
//	int	i;
//
//	i = 0;
//	while (splited_line[i])
//	{
//		printf("splited_line[%d]: %s\n", i, splited_line[i]);
//		kind_of_token(splited_line[i]);
//		i++;
//	}
//	printf("nombre de mots : %i\n", i);
//}

// Fonction qui imprime le type d'un seul token (comme précédemment)
void	print_token_type(t_token *token)
{
	if (!token)
	{
		printf("Token is NULL\n");
		return ;
	}
	switch (token->type)
	{
	case T_CMD:
		printf("Token type: T_CMD\n");
		break ;
	case T_ARG:
		printf("Token type: T_ARG\n");
		break ;
	case T_FILE:
		printf("Token type: T_FILE\n");
		break ;
	case T_ENV:
		printf("Token type: T_ENV\n");
		break ;
	case T_OP:
		printf("Token type: T_OP\n");
		break ;
	case T_PIPE:
		printf("Token type: T_PIPE\n");
		break ;
	case T_CMD_ARG:
		printf("Token type: T_CMD_ARG\n");
		break;
	default:
		printf("Unknown token type\n");
		break ;
	}
}

// Fonction pour imprimer tous les types dans une liste chaînée de tokens
void	print_all_token_types(t_token *head)
{
	t_token	*current;

	current = head;
	if (!current)
	{
		printf("No tokens in the list\n");
		return ;
	}
	while (current)
	{
		print_token_type(current);
		current = current->next;
	}
}

char	*get_user_input(const char *prompt)
{
	char	*line;

	line = readline(prompt);
	if (!line)
	{
		fprintf(stderr, "Error reading line\n");
		return (NULL);
		return (NULL);
	}
	printf("Input line: %s\n", line);
	return (line);
}

int	main(int ac, char **av, char **env)
{
	char	*input;
	char	**splited_input;
	t_token	*head;
	(void)ac;
	(void)av;

	head = NULL;
	input = get_user_input("minishell> ");
	splited_input = parse_input(input);
	head = tokenize(splited_input);
	first_word(splited_input, env);
	print_all_token_types(head);
//	display_input(splited_input);
	cleanup_memory(input, splited_input);
	return (0);
}
