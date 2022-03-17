/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akadi <akadi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 19:39:32 by akadi             #+#    #+#             */
/*   Updated: 2022/02/24 14:05:21 by akadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include "minitalk.h"

void	hendler(int seg, siginfo_t *info, void *c)
{
	static pid_t	client_pid;
	static char		p;
	static int		i;

	(void)c;
	if (client_pid != 0 && client_pid != info -> si_pid)
	{
		i = 0;
		p = 0;
		write(1, "\n", 1);
	}
	p = (p << 1) | (seg & 1);
	i++;
	if (i == 8)
	{
		if (p == 0)
			kill(client_pid, SIGUSR1);
		write (1, &p, 1);
		p = 0;
		i = 0;
	}
	client_pid = info -> si_pid;
}

int	main(int ac, char **av)
{
	pid_t				pid;
	struct sigaction	sig;

	(void)av;
	pid = getpid();
	if (pid < 0)
		return (EXIT_FAILURE);
	sig.sa_sigaction = &hendler;
	sig.sa_flags = SA_RESTART;
	if (ac != 1)
	{
		write(1, "too much parameters", 19);
		return (EXIT_FAILURE);
	}
	ft_putnbr(pid);
	write(1, "\n", 1);
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
	return (0);
}
