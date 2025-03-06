/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:28:30 by lylrandr          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/03/04 13:56:03 by lylrandr         ###   ########.fr       */
=======
/*   Updated: 2025/03/06 17:16:39 by lylrandr         ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

<<<<<<< HEAD
//void	first_word(char *input, char **env)
//{
//	char	*split_input;
//
//	split_input = ft_split(input, ' ');
//	if (ft_strncmp(input[0], "<", 1) == 0 || ft_strncmp(input[0], ">", 1) == 0
//		|| ft_strncmp(input[0], "|", 1) == 0 || ft_strncmp(input[0], ">>",
//			2) == 0 || ft_strncmp(input[0], "<<", 2) == 0)
//		operator_token(input[0], input);
//	else if (!is_cmd(input, env))
//	{
//		printf("minishell: command not found: %s\n", split_input);
//		exit(127);
//	}
//	else
//		word_token(input, env);
//}
// CHANGER POUR SECOND_PARSING
//void	*read_input(char *input, char **env)
//{
//	int	i;
//
//	i = 0;
//	if (!input)
//		return ;
//	while (input[i])
//	{
//		if (ft_strncmp(input[i], "<", 1) == 0 || ft_strncmp(input[i], ">",
//				1) == 0 || ft_strncmp(input[i], "|", 1) == 0
//			|| ft_strncmp(input[i], ">>", 2) == 0 || ft_strncmp(input[i], "<<",
//				2) == 0)
//			operator_token(input[i], input);
//		else
//		{
//			if (input[i] == '"' || input[i] == '\'')
//				quote_token(input, i);
//			else if (input[i] == '$')
//				env_token(input, i);
//			else
//				word_token(input[i], env, i);
//		}
//		i++;
//	}
//}


=======
void	first_word(char **input, char **env)
{
	if (ft_strncmp(input[0], "<", 1) == 0 || ft_strncmp(input[0], ">", 1) == 0
		|| ft_strncmp(input[0], ">>", 2) == 0 || ft_strncmp(input[0], "<<",
			2) == 0)
		//		operator_token(input[0]);
		printf("operateur?\n");
	else if (!is_cmd(input[0], env))
	{
		printf("minishell: command not found: %s\n", input[0]);
		exit(127);
	}
	else
		//		word_token(input[0]);
		printf("else");
}

void	tokenize(char **input)
{
	int		i;
	t_token	*tail;
	t_token	*head;
	t_token	*new_node;

	i = 1;
	tail = malloc(sizeof(t_token));
	if (!tail)
		exit(1);
	tail->token = input[0];
	tail->prev = NULL;
	tail->next = NULL;
	while (input[i])
	{
		new_node = malloc(sizeof(t_token));
		if (!new_node)
			exit(1);
		new_node->token = input[i];
		new_node->prev = tail;
		new_node->next = NULL;
		tail->next = new_node;
		tail = new_node;
	}
}

t_token_type	get_token_type(char *token)
{
	if (ft_strncmp(token, "|", 1) == 0)
		return (T_PIPE);
	else if (ft_strncmp(token, "<", 1) == 0 || ft_strncmp(token, ">", 1) == 0
		|| ft_strncmp(token, ">>", 2) == 0 || ft_strncmp(token, "<<", 2) == 0)
		return(T_OP);
	else if (token[0] == '$')
		return (T_ENV);
	return (T_CMD);
}
>>>>>>> main
