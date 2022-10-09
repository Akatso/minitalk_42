/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 21:09:10 by slepetit          #+#    #+#             */
/*   Updated: 2022/10/09 22:58:51 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putstr(char *s)
{
	return (write(1, s, ft_strlen(s)));
}

void	ft_reset(char **msg, char **tmp, int *binary, int *bit)
{
	ft_putstr(*msg);
	free(*msg);
	free(*tmp);
	*msg = NULL;
	*tmp = NULL;
	*bit = 0;
	*binary = 0;
}

void	ft_protect(char **str)
{
	if (*str == NULL)
	{
		*str = malloc(sizeof(char) * 2);
		*(str[0]) = 0;
	}
}
