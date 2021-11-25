/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_basediu.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:11:08 by wmonacho          #+#    #+#             */
/*   Updated: 2021/11/25 17:02:18 by wmonacho         ###   ########lyon.fr   */
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
	if (!ptr)
		return (NULL);
	if (ptr == NULL)
		return (NULL);
	return (ptr);
}

int	ft_putnbr_basediu(int nbr, char *base_to)
{
	char	*ptr;
	int		i;
	int		j;

	ptr = ft_taille(nbr, 10, &i);
	if (!ptr)
		return (-1);
	j = i;
	if (nbr < 0)
	{
		ptr[0] = '-';
		nbr = -nbr;
	}
	ptr[j] = '\0';
	j--;
	while (nbr >= 10)
	{
		ptr[j] = base_to[nbr % 10];
		nbr = nbr / 10;
		j--;
	}
	ptr[j] = base_to[nbr % 10];
	ft_putstr_fd(ptr, 1);
	return (i);
}
