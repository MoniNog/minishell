/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoguei <monoguei@student.lausanne42.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:28:30 by lylrandr          #+#    #+#             */
/*   Updated: 2025/03/18 17:03:13 by monoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

bool	is_builtin(char *cmd)
{
	if (ft_strncmp(cmd, "echo", 5) == 0 || ft_strncmp(cmd, "cd", 3) == 0
		|| ft_strncmp(cmd, "pwd", 4) == 0 || ft_strncmp(cmd, "export", 7) == 0
		|| ft_strncmp(cmd, "unset", 6) == 0 || ft_strncmp(cmd, "env", 4) == 0
		|| ft_strncmp(cmd, "exit", 5) == 0)
		return (true);
	return (false);
}


void	first_word(char **input, char **env)
{
	if (ft_strncmp(input[0], "<", 1) == 0 || ft_strncmp(input[0], ">", 1) == 0
		|| ft_strncmp(input[0], ">>", 2) == 0 || ft_strncmp(input[0], "<<",
			2) == 0)
		//		operator_token(input[0]);
		printf("operateur?\n");
	else if (is_builtin(input[0]) == TRUE)
			// tester_echo();
			printf("lily et seven") ;
	// b_echo((t_input *)input);
	else if (!is_cmd(input[0], env))
		{
			printf("minishell: command not found: %s\n", input[0]);
			// exit(127);
		}
	else
	{
		//		word_token(input[0]);
		printf("cmd\n");
//		head->type = T_CMD;
	}
}

t_input	*tokenize(char **input)
{
	int		i;
	t_input	*tail;
	t_input	*head;
	t_input	*new_node;
	t_input	*current;

	i = 1;
	tail = malloc(sizeof(t_input));
	if (!tail)
		exit(1);
	tail->token = input[0];
	tail->prev = NULL;
	tail->next = NULL;
	head = tail;
	while (input[i])
	{
		new_node = malloc(sizeof(t_input));
		if (!new_node)
			exit(1);
		new_node->token = input[i];
		new_node->prev = tail;
		new_node->next = NULL;
		tail->next = new_node;
		tail = new_node;
		i++;
	}
	current = head;
	while (current)
	{
		current->type = get_token_type(current, current->token);
		current = current->next;
	}
	is_cmd_arg(head);
	return (head);
}

t_token_type	get_token_type(t_input *token, char *input)
{
	if (ft_strncmp(input, "|", 1) == 0)
		return (T_PIPE);
	else if (input[0] == '\'')
		return (T_SQUOTE);
	else if (input[0] == '"')
		return (T_DQUOTE);
	else if (ft_strncmp(input, "<", 1) == 0 || ft_strncmp(input, ">", 1) == 0
		|| ft_strncmp(input, ">>", 2) == 0 || ft_strncmp(input, "<<", 2) == 0)
		return(T_OP);
	else if (input[0] == '$')
		return (T_ENV);
	else if (token->prev != NULL && token->prev->type == T_OP)
		return (T_FILE);
	else if (token->prev != NULL && (token->prev->type == T_CMD || token->prev->type == T_ARG
			|| token->prev->type == T_ENV))
		return (T_ARG);
	return (T_CMD);
}

void	is_cmd_arg(t_input *token)
{
	t_input	*curr;

	curr = token;
	while (curr)
	{
		if (curr->type == T_CMD && curr->next && curr->next->type == T_ARG)
			curr->type = T_CMD_ARG;
		curr = curr->next;
	}
}
