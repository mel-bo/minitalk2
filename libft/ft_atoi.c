/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bout <mel-bout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 18:01:05 by mel-bout          #+#    #+#             */
/*   Updated: 2024/05/07 11:44:56 by mel-bout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	convert(const char *str, int signe)
{
	int		i;
	long	buff;
	long	res;

	i = 0;
	buff = 0;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - 48;
		if (buff > res && signe > 0)
			return (-1);
		else if (buff > res && signe < 0)
			return (0);
		buff = res;
		i++;
	}
	return (res * signe);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	signe;

	i = 0;
	signe = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	return (convert(str + i, signe));
}
/*#include <stdio.h>
#include <limits.h>
int main(void)
{
	printf("%d\n", ft_atoi("9223372036854775"));
	printf("%d\n", atoi("9223372036854775"));
	return (0);
}*/