/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:45:11 by slepetit          #+#    #+#             */
/*   Updated: 2022/09/17 21:59:12 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
struct sigaction {
	void       (*sa_handler)(int);
	sigset_t   sa_mask;
	int        sa_flags;
	void       (*sa_sigaction)(int, siginfo_t *, void *);
}
*/

int	main(void)
{
	sigset_t			sigset;
	struct sigaction	act;

	sigemptyset(&sigset);
	ft_putnbr(getpid());
	return (0);
}
