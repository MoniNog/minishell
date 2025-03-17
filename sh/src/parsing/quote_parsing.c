/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:58:51 by lylrandr          #+#    #+#             */
/*   Updated: 2025/03/17 17:50:19 by lylrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_open_quotes(char *input)
{
	int	i;
	int	in_dquote;
	int	in_squote;

	i = 0;
	in_dquote = 0;
	in_squote = 0;
	while (input[i])
	{
		if (input[i] == '"' && !in_squote)
			in_dquote = !in_dquote;
		else if (input[i] == '\'' && !in_dquote)
			in_squote = !in_squote;
		i++;
	}
	if (in_dquote || in_squote)
		return (1);
	return (0);
}
