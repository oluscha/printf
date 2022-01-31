/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 22:19:47 by lschwart          #+#    #+#             */
/*   Updated: 2021/12/21 22:19:59 by lschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putminus(long int *nb)
{
	write(1, "-", 1);
	*nb = -1 * (*nb);
	return (1);
}

int	ft_printnbr(int n)
{
	long int	nb;
	char		nbr[12];
	int			i;
	int			j;

	i = 0;
	j = 0;
	nb = (long int) n;
	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (nb < 0)
		j = ft_putminus(&nb);
	while (nb)
	{
		nbr[i] = '0' + nb % 10;
		nb = nb / 10;
		i++;
	}
	j = j + i;
	while ((--i) >= 0)
		write(1, &nbr[i], 1);
	return (j);
}
