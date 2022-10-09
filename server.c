/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:45:11 by slepetit          #+#    #+#             */
/*   Updated: 2022/10/09 20:22:30 by slepetit         ###   ########.fr       */
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

int	ft_reverse(int binary)
{
	int	reverse;
	int	bit;

	reverse = 0;
	bit = 0;
	while (bit < 8)
	{
		if (binary >> bit & 1)
			reverse |= 1;
		else
			reverse |= 0;
		if (bit != 7)
			reverse <<= 1;
		bit++;
	}
	return (reverse);
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
	if (bit < 7)
		binary <<= 1;
	bit++;
	if (bit == 8)
	{
		tmp[0] = ft_reverse(binary);
		msg = ft_strjoin(msg, tmp);
		if (binary == '\0')
		{
			ft_putstr(msg);
			ft_reset(&msg, &tmp, &connect);
			bit = 0;
			binary = 0;
			return ;
		}
	}
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
