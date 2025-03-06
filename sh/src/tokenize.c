/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:28:30 by lylrandr          #+#    #+#             */
/*   Updated: 2025/03/06 17:47:54 by lylrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
