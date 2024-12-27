/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bout <mel-bout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 19:48:05 by mel-bout          #+#    #+#             */
/*   Updated: 2024/12/27 21:16:03 by mel-bout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_kill(pid_t server, int sig)
{
	if (kill(server, sig) < 0)
	{
		write(2, "kill failed\n", 13);
		exit (EXIT_FAILURE);
	}
}

void	send_string(char c, pid_t server)
{
	int	bit;

	bit = 0;
	while (bit < CHAR_BIT)
	{
		if (c & (0x80 >> bit))
			ft_kill(server, SIGUSR2);
		else
			ft_kill(server, SIGUSR1);
		bit++;
		usleep(545);
	}
}

void	sigaction_client(int sig, void	*handler)
{
	struct sigaction	sa;

	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	if (sigaction(sig, &sa, NULL))
		exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	pid_t	server;
	char	*string;
	int		n;

	n = 0;
	if (ac != 3)
	{
		write(2, "il faut 3 argument\n", 20);
		exit (EXIT_FAILURE);
	}
	server = ft_atoi(av[1]);
	string = av[2];
	while (*string && n < 9998)
	{
		send_string(*string++, server);
		n++;
	}
	send_string('\0', server);
	exit (EXIT_SUCCESS);
}
