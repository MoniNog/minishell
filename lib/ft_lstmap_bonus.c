/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afloras <afloras@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:59:07 by afloras           #+#    #+#             */
/*   Updated: 2024/01/27 15:59:08 by afloras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_src;
	t_list	*lst_new;
	t_list	*lst_final;
	void	*temp_content;

	if (!lst || !f || !del)
		return (0);
	lst_src = lst;
	lst_final = 0;
	while (lst_src)
	{
		temp_content = (*f)(lst_src->content);
		lst_new = ft_lstnew(temp_content);
		if (!lst_new)
		{
			(*del)(temp_content);
			ft_lstclear(&lst_final, del);
			return (0);
		}
		ft_lstadd_back(&lst_final, lst_new);
		lst_src = lst_src->next;
	}
	return (lst_final);
}
