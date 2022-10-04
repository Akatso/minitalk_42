/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:48:55 by slepetit          #+#    #+#             */
/*   Updated: 2022/10/04 19:12:45 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *s);
size_t	ft_putnbr(long int nb);
int		ft_putstr(char *s);
int		ft_putchar(char c);
int		ft_atoi(const char *nptr);
void	ft_handler_server(int sig, siginfo_t *info, void *ignore);
void	ft_binary(int sig, int *connect);
void	ft_protect(char **str);
void	ft_reset(char **msg, int **connect);
void	ft_handler_client(void);
void	ft_send(int sig, siginfo_t *info, void *ignore);
void	ft_reverse(int binary);
char	*ft_strjoin(char *s1, char *s2);

#endif
