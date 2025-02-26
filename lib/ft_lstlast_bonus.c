/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afloras <afloras@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:58:54 by afloras           #+#    #+#             */
/*   Updated: 2024/01/27 15:58:55 by afloras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*lst_last;

	if (!lst)
		return (0);
	lst_last = lst;
	while (lst_last->next)
		lst_last = lst_last->next;
	return (lst_last);
}
