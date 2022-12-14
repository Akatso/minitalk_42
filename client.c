/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:45:03 by slepetit          #+#    #+#             */
/*   Updated: 2022/10/19 18:08:34 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*g_str;

void	ft_send(int sig, siginfo_t *info, void *ignore)
{
	static int	i;
	static int	bit;

	(void)sig;
	(void)ignore;
	if (g_str[i])
	{
		if (g_str[i] >> bit & 1)
			kill(info->si_pid, SIGUSR1);
		else
			kill(info->si_pid, SIGUSR2);
		bit++;
		if (bit == 8)
		{
			bit = 0;
			i++;
		}
	}
	else if (g_str[i] == '\0')
	{
		kill(info->si_pid, SIGUSR2);
		bit ++;
		if (bit == 8)
			exit(EXIT_SUCCESS);
	}
}

void	ft_handler_client(void)
{
	sigset_t			signal;
	struct sigaction	action;

	sigemptyset(&signal);
	sigaddset(&signal, SIGUSR1);
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = &ft_send;
	sigaction(SIGUSR1, &action, NULL);
	while (1)
		pause();
}

int	main(int ac, char **av)
{
	g_str = av[2];
	if (ac != 3)
	{
		ft_putstr("Error with arguments\n");
		exit(EXIT_FAILURE);
	}
	if (kill(ft_atoi(av[1]), SIGUSR1) < 0)
	{
		ft_putstr("Error PID\n");
		exit(EXIT_FAILURE);
	}
	ft_handler_client();
	return (0);
}
