/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:45:03 by slepetit          #+#    #+#             */
/*   Updated: 2022/09/28 19:46:31 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
 *	struct sigaction {
 *		void		(*sa_handler)(int);
 *		sigset_t	sa_mask;
 *		int			sa_flags;
 *		void		(*sa_sigaction)(int, siginfo_t *, void *);
 *	}
 */

char	*g_str;

void	ft_send(int sig, siginfo_t *info, void *ignore)
{
	ft_putstr("Client send signal\n");
	usleep(10000);
	//convert algo
	kill(info->si_pid, SIGUSR1);
}

void	ft_handler(void)
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
		ft_putstr("Error with arguments");
		exit(EXIT_FAILURE);
	}
	if (kill(ft_atoi(av[1]), SIGUSR1) < 0)
	{
		ft_putstr("Error PID");
		exit(EXIT_FAILURE);
	}
	ft_handler();
	return (0);
}
