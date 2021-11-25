/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Xxconvert_basexX.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:14:15 by wmonacho          #+#    #+#             */
/*   Updated: 2021/11/25 17:02:23 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_taille(long nbr, int blen, int *i)
{
	int		minus;
	char	*ptr;

	minus = 0;
	if (nbr < 0)
	{
		minus = 1;
		nbr = -nbr;
	}
	*i = 0;
	while (nbr >= blen)
	{
		nbr = nbr / blen;
		(*i)++;
	}
	(*i)++;
	*i = *i + minus;
	ptr = malloc(sizeof(char) * (*i + 1));
	if (ptr == NULL)
		return (NULL);
	return (ptr);
}

int	ft_xxconvert_basexx(int nbr, char *base_to)
{
	char	*ptr;
	int		i;
	int		j;

	ptr = ft_taille(nbr, 16, &i);
	if (ptr == NULL)
		return (-1);
	j = i;
	if (nbr < 0)
	{
		ptr[0] = '-';
		nbr = -nbr;
	}
	ptr[j] = '\0';
	j--;
	while (nbr >= 16)
	{
		ptr[j] = base_to[nbr % 16];
		nbr = nbr / 16;
		j--;
	}
	ptr[j] = base_to[nbr % 16];
	ft_putstr_fd(ptr, 1);
	return (i);
}
