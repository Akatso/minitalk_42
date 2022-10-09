/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:59:59 by slepetit          #+#    #+#             */
/*   Updated: 2022/10/09 22:38:58 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	nbr;
	int	neg;

	i = 0;
	nbr = 0;
	neg = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\f'
		|| nptr[i] == '\v' || nptr[i] == '\r' || nptr[i] == '\n')
		i++;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		neg = 1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nbr = nbr * 10 + nptr[i] - 48;
		i++;
	}
	if (neg == 1)
		nbr = nbr * -1;
	return (nbr);
}

size_t	ft_putnbr(long int nb)
{
	size_t	count;
	int		i;
	int		tab[20];

	count = 0;
	i = 0;
	if (nb < 0)
	{
		count = ft_putstr("-");
		nb *= -1;
	}
	if (nb == 0)
		count = ft_putstr("0");
	while (nb > 0)
	{
		tab[i++] = nb % 10;
		nb /= 10;
	}
	count += i;
	i--;
	while (i >= 0)
		ft_putchar(tab[i--] + 48);
	return (count);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*dest;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	dest = malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	dest[i] = 0;
	return (dest);
}
