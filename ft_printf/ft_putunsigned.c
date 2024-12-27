/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bout <mel-bout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:54:04 by mel-bout          #+#    #+#             */
/*   Updated: 2024/06/28 14:54:37 by mel-bout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int n)
{
	unsigned int	base;
	int				count;

	base = 10;
	count = 0;
	if (n >= base)
		count += ft_putunsigned(n / base);
	count += ft_putchar(n % base + '0');
	return (count);
}
