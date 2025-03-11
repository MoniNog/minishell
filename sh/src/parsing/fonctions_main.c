/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoguei <monoguei@student.lausanne42.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:09:38 by monoguei          #+#    #+#             */
/*   Updated: 2025/03/11 21:45:13 by monoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

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
