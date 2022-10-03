/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:45:11 by slepetit          #+#    #+#             */
/*   Updated: 2022/10/03 20:59:59 by slepetit         ###   ########.fr       */
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

void	ft_reset(char **msg, int **connect)
{
	free(*msg);
	*connect = 0;
}

void	ft_protect(char **str)
{
	if (!*str)
	{
		*str = malloc(sizeof(char));
		if (!*str)
			exit(EXIT_FAILURE);
	}
}

void	ft_binary(int sig, int *connect)
{
	static char	*msg;
	static char	*tmp;
	static int	binary;
	static int	bit;

	ft_protect(&msg);
	ft_protect(&tmp);
	if (sig == SIGUSR1)
		binary |= 1;
	bit++;
	if (bit == 8)
	{
		tmp[0] = binary;
		ft_strjoin(msg, tmp);
		if (binary == '\0')
		{
			ft_putstr(msg);
			ft_reset(&msg, &connect);
		}
		binary = 0;
		bit = 0;
	}
	else
		binary <<= 1;
}

void	ft_handler_server(int sig, siginfo_t *info, void *ignore)
{
	static int	connect;

	if (connect == 0)
		kill(info->si_pid, SIGUSR1);
	else
	{
		ft_binary(sig, &connect);
		kill(info->si_pid, SIGUSR1);
	}
	connect++;
}

int	main(void)
{
	sigset_t			signal;
	struct sigaction	action;

	sigemptyset(&signal);
	sigaddset(&signal, SIGUSR2);
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = &ft_handler_server;
	ft_putnbr(getpid());
	ft_putstr("\n");
	sigaction(SIGUSR2, &action, NULL);
	sigaction(SIGUSR1, &action, NULL);
	while (1)
		pause();
	return (0);
}
