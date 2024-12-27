/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptraddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bout <mel-bout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:08:08 by mel-bout          #+#    #+#             */
/*   Updated: 2024/06/28 15:08:10 by mel-bout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print(unsigned long nbr, const char *base)
{
	int	count;

	count = 0;
	if (nbr >= ft_strlen(base))
		count += ft_print(nbr / ft_strlen(base), base);
	count += ft_putchar(base[nbr % ft_strlen(base)]);
	return (count);
}

int	ft_ptraddress(void *format)
{
	unsigned long	n;
	const char		*base;
	int				count;

	count = 0;
	n = (unsigned long)format;
	base = "0123456789abcdef";
	count = ft_putstr("0x");
	count += ft_print(n, base);
	return (count);
}
