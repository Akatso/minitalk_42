/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:48:55 by slepetit          #+#    #+#             */
/*   Updated: 2022/10/09 22:53:08 by slepetit         ###   ########.fr       */
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
int		ft_reverse(int binary);
void	ft_handler_server(int sig, siginfo_t *info, void *ignore);
void	ft_binary(int sig, int *connect);
void	ft_protect(char **str);
void	ft_reset(char **msg, char **tmp, int *binary, int *bit);
void	ft_handler_client(void);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_send(int sig, siginfo_t *info, void *ignore);
char	*ft_strjoin(char *s1, char *s2);

#endif
