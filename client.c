/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:45:03 by slepetit          #+#    #+#             */
/*   Updated: 2022/09/20 23:09:01 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_convert(void)
{

}

void	ft_handler(void)
{
	sigset_t			signal;
	struct sigaction	action;

	sigemptyset(&signal);
	sigaddset(&signal, SIGUSR1);
	action.sa_sigaction = &ft_convert();
}

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	kill(ft_atoi(av[1]), SIGUSR1);
	ft_handler();
	return (0);
}
