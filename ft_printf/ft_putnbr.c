/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bout <mel-bout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:01:09 by mel-bout          #+#    #+#             */
/*   Updated: 2024/06/28 15:01:43 by mel-bout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbr_len(long nbr)
{
	int	count;

	count = 1;
	if (nbr < 0)
	{
		nbr = -nbr;
		count = 2;
	}
	while (nbr >= 10)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

int	ft_putnbr(long nbr)
{
	int	nbr_len;

	nbr_len = 0;
	nbr_len = ft_nbr_len(nbr);
	if (nbr < 0)
	{
		nbr = -nbr;
		ft_putchar('-');
	}
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	ft_putchar(nbr % 10 + '0');
	return (nbr_len);
}
