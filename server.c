/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:45:11 by slepetit          #+#    #+#             */
/*   Updated: 2022/09/27 18:46:23 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
 *	struct sigaction {
 *		void       (*sa_handler)(int);
 *		sigset_t   sa_mask;
 *		int        sa_flags;
 *		void       (*sa_sigaction)(int, siginfo_t *, void *);
 *	}
 */

void	ft_handler(int sig, siginfo_t *info, void *ignore)
{
	ft_putstr("Server send signal\n");
	if (sig == SIGUSR1)
		ft_putstr("SIGUSR1\n");
	else if (sig == SIGUSR2)
		ft_putstr("SIGUSR2\n");
	usleep(100000);
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	sigset_t			signal;
	struct sigaction	action;

	sigemptyset(&signal);
	sigaddset(&signal, SIGUSR2);
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = &ft_handler;
	ft_putnbr(getpid());
	ft_putstr("\n");
	sigaction(SIGUSR2, &action, NULL);
	sigaction(SIGUSR1, &action, NULL);
	while (1)
		pause();
	return (0);
}