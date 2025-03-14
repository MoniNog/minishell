/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoguei <monoguei@student.lausanne42.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:19:52 by monoguei          #+#    #+#             */
/*   Updated: 2025/03/14 16:54:14 by monoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// vérifie si un entier est un caractère alphabetiquenumerique
int	ft_isalpha(int c);
int	ft_isdigit(int c);

int	ft_isalnum(int c)
{
	if (!(ft_isdigit(c) || ft_isalpha(c)))
		return (0);
	return (1);
}
