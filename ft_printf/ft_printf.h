/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bout <mel-bout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:13:12 by mel-bout          #+#    #+#             */
/*   Updated: 2024/06/28 15:15:01 by mel-bout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_ptraddress(void *format);
int		ft_puthexa(unsigned int n, char format);
int		ft_putstr(char const *s);
size_t	ft_strlen(const char *s);
int		ft_putchar(char c);
int		ft_putnbr(long nbr);
int		ft_putunsigned(unsigned int n);
char	*ft_strrchr(const char *s, int c);

#endif
