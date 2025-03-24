/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:58:51 by lylrandr          #+#    #+#             */
/*   Updated: 2025/03/24 16:21:09 by lylrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	remove_quotes(t_input *head)
{
	t_input	*curr;
	char	*new;

	curr = head;
	printf("im here");
	while (curr)
	{
		if (curr->type == T_SQUOTE || curr->type == T_DQUOTE)
		{
			new = handle_quoted_token(curr->token);
			if (!new)
				return ;
			free(curr->token);
			curr->token = new;
		}
		curr = curr->next;
	}
}


