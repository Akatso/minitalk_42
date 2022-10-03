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
size_t	ft_putstr(char *s);
size_t	ft_putnbr(long int nb);
char	*ft_strjoin(const char *s1, const char *s2);
int		ft_atoi(const char *nptr);
void	ft_handler(int sig, siginfo_t *info, void *ignore);
void	ft_binary(int sig, int *connect);
void	ft_protect(char **str);
void	ft_free(char **msg, int *connect);
void	ft_handler(void);
void	ft_send(int sig, siginfo_t *info, void *ignore);

#endif
