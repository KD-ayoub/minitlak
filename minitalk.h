/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akadi <akadi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 19:53:49 by akadi             #+#    #+#             */
/*   Updated: 2022/02/23 15:33:48 by akadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <sys/types.h>
# include <signal.h>
# include <string.h>
# include <stdlib.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int n);
int		ft_atoi(char *str);
void	handl(int sig);
int		send(char msg, int pid);
int		get_character(char **av, int pid);
void	hendler(int seg, siginfo_t *info, void *c);
#endif
