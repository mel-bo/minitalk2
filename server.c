/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bout <mel-bout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 19:48:07 by mel-bout          #+#    #+#             */
/*   Updated: 2024/12/27 21:14:01 by mel-bout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int sig, siginfo_t *info, void *more_info)
{
	static char	c;
	static int	bit;
	static char	string[BUFFER_SIZE];
	static int	i;

	(void)more_info;
	if (sig == SIGUSR2)
		c |= (0x80 >> bit);
	else if (sig == SIGUSR1)
		c &= ~(0x80 >> bit);
	bit++;
	if (bit == CHAR_BIT)
	{
		bit = 0;
		if (c == '\0')
		{
			string[i] = '\0';
			i = 0;
			ft_printf("%s\n", string);
			return ;
		}
		string[i] = c;
		i++;
	}
}

void	sigaction_handler(int sig, void *signal_handler)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_handler = signal_handler;
	sigemptyset(&sa.sa_mask);
	if (sigaction(sig, &sa, NULL) < 0)
		exit(EXIT_FAILURE);
}

int	main(void)
{
	ft_printf("SERVER PID: %d\n", getpid());
	sigaction_handler(SIGUSR1, signal_handler);
	sigaction_handler(SIGUSR2, signal_handler);
	while (1)
		pause();
	exit(EXIT_SUCCESS);
}
