/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afloras <afloras@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:58:08 by afloras           #+#    #+#             */
/*   Updated: 2024/01/27 15:58:10 by afloras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*lst_temp;

	if (!lst || !f)
		return ;
	lst_temp = lst;
	while (lst_temp)
	{
		(*f)(lst_temp->content);
		lst_temp = lst_temp->next;
	}
}
