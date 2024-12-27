/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bout <mel-bout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 21:14:14 by mel-bout          #+#    #+#             */
/*   Updated: 2024/12/27 21:14:15 by mel-bout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# define _GNU_SOURCE
# define CHAR_BIT __CHAR_BIT__
# define BUFFER_SIZE 10000

# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/types.h>

void	ft_kill(pid_t server, int sig);
void	sigaction_handler(int sig, void *signal_handler);
void	signal_handler(int sig, siginfo_t *info, void *more_info);

#endif