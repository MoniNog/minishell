/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoguei <monoguei@student.lausanne42.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:28:30 by lylrandr          #+#    #+#             */
/*   Updated: 2025/03/07 08:17:58 by monoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/// @brief 
/// @param input 
/// @param env 
void	first_word(char **input, char **env)
{
	if (ft_strncmp(input[0], "<", 1) == 0 || ft_strncmp(input[0], ">",
			1) == 0 || ft_strncmp(input[0], ">>", 2) == 0
		|| ft_strncmp(input[0], "<<", 2) == 0)
//		operator_token(input[0]);
		printf("operateur?\n");
	else if (!is_cmd(input[0], env))
	{
		printf("minishell: command not found: %s\n", input[0]);
		// exit(127);
	}
	else
//		word_token(input[0]);
		printf("else than cmd or op\n");
}

// void	read_input(char **input, char **env)
//{
//	int	i;
//
//	i = 0;
//	if (!input)
//		return ;
//	while (input[i])
//	{
//		if (ft_strncmp(&input[i], "<", 1) == 0 || ft_strncmp(&input[i], ">",
//				1) == 0
//			|| ft_strncmp(&input[i], "|", 1) == 0 || ft_strncmp(&input[i], ">>",
//					2) == 0
//			|| ft_strncmp(&input[i], "<<", 2) == 0)
//			operator_token(&input[i]);
//		else
//		{
//			if (input[i] == '"' || input[i] == '\'')
//				quote_token(&input[i]);
//			else if (input[i] == '$')
//				env_token(&input[i]);
//			else
//				word_token(&input[i]);
//		}
//		i++;
//	}
//}
//
