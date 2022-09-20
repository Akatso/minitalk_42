/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:48:55 by slepetit          #+#    #+#             */
/*   Updated: 2022/09/15 17:46:10 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(char *s);
size_t	ft_putchar(char c);
size_t	ft_putstr(char *s);
size_t	ft_putnbr(long int nb);
int		ft_atoi(const char *nptr);

#endif
