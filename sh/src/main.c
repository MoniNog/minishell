/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid Date        by              +#+  #+#    #+#             */
/*   Updated: 2025/03/07 17:15:56 by lylrandr         ###   ########.fr       */
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

void	display_input(char **splited_line)
{
	int	i;

	i = 0;
	while (splited_line[i])
	{
		printf("splited_line[%d]: %s\n", i, splited_line[i]);
		kind_of_token(splited_line[i]);
		i++;
	}
	printf("nombre de mots : %i\n", i);
}

//char	**split_input(char *line)
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

//char	**split_input(char *line)
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

// Fonction qui imprime le type d'un seul token (comme précédemment)
void print_token_type(t_token *token)
{
    if (!token)
    {
        printf("Token is NULL\n");
        return;
    }

    switch (token->type)
    {
        case T_CMD:
            printf("Token type: T_CMD\n");
            break;
        case T_ARG:
            printf("Token type: T_ARG\n");
            break;
        case T_FILE:
            printf("Token type: T_FILE\n");
            break;
        case T_ENV:
            printf("Token type: T_ENV\n");
            break;
        case T_OP:
            printf("Token type: T_OP\n");
            break;
        case T_PIPE:
            printf("Token type: T_PIPE\n");
            break;
        default:
            printf("Unknown token type\n");
            break;
    }
}

// Fonction pour imprimer tous les types dans une liste chaînée de tokens
void print_all_token_types(t_token *head)
{
	t_token *current = head;

	if (!current)
	{
		printf("No tokens in the list\n");
		return;
	}
	while (current)
	{
		print_token_type(current);  // Affiche le type du token actuel
		current = current->next;    // Passe au token suivant
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

int main()
{
	char	*input;
	char	**splited_input;
	t_token	*head = NULL;

	input = get_user_input("minishell> ");
	splited_input = parse_input(input);
	head = tokenize(splited_input);
	print_all_token_types(head);
	display_input(splited_input);
	cleanup_memory(input, splited_input);
	return (0);
}
