/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:58:51 by lylrandr          #+#    #+#             */
/*   Updated: 2025/03/17 15:03:08 by lylrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	is_open_quotes(char *input)
{
	int	i;
	int	quote;
	int	dquote;

	i = 0;
	quote = 0;
	dquote = 0;
	while (input[i])
	{
		if (input[i] == '"')
			dquote++;
		if (input[i] == '\'')
			quote++;
		i++;
	}
	if (dquote % 2 != 0)
	{
		printf("missing one dquote\n");
		exit(0); //CHANGER POUR NE PAS SORTIR DE MINISHELL MAIS JUSTE DE LA COMMANDE
	}
	else if (quote % 2 != 0)
	{
		printf("missing one quote\n");
		exit(0);
	}
}


