/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akadi <akadi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:10:39 by akadi             #+#    #+#             */
/*   Updated: 2022/02/23 15:25:23 by akadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include "minitalk.h"

int	send(char msg, int pid)
{
	int	i;
	int	b;

	i = 7;
	b = 0;
	while (i >= 0)
	{
		b = (msg >> i) & 1;
		kill(pid, SIGUSR1 + b);
		usleep(800);
		i--;
	}
	return (0);
}

int	get_character(char **av, int pid)
{
	int		i;
	char	*msg;

	i = 0;
	msg = av[2];
	while (msg[i] != '\0')
	{
		send(msg[i], pid);
		i++;
	}
	send(msg[i], pid);
	return (0);
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid <= 0)
		{
			write (1, "Error", 5);
			exit(1);
		}
		get_character(av, pid);
	}
	else
		write(1, "Error", 5);
	exit(0);
}
