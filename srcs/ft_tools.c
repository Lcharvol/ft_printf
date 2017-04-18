/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 06:33:40 by lcharvol          #+#    #+#             */
/*   Updated: 2017/01/13 10:39:29 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_stock_lennb(long long nb)
{
	int	lennb;

	if (nb < -9223372036854775807)
		return (20);
	if (nb == -2147483648)
		return (10);
	lennb = 0;
	if (nb < 0)
	{
		lennb++;
		nb *= -1;
	}
	while (nb >= 1)
	{
		nb /= 10;
		lennb++;
	}
	if (lennb == 0)
		lennb = 1;
	return (lennb);
}

void	ft_putnbr2(long long nb)
{
	if (nb < -9223372036854775807)
	{
		ft_putstr("9223372036854775808");
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		if (nb < -9)
			ft_putnbr((nb / 10) * -1);
		ft_putnbr((nb % 10) * -1);
		return ;
	}
	if (nb > 9)
		ft_putnbr2(nb / 10);
	ft_putchar('0' + (nb % 10));
}

int		ft_isnumber(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int		ft_verif_in(const char *str, int i)
{
	if (ft_isflag(str[i], str[i - 1]))
		i++;
	while (ft_isnumber(str[i]))
		i++;
	if (str[i] == '.')
		i++;
	while (ft_isnumber(str[i]))
		i++;
	while (ft_isalpha(str[i]))
		i++;
	return (i);
}

int		ft_in_or_not(const char *str, int i)
{
	int	i2;
	int	count;

	i2 = 0;
	count = 0;
	if (str[i] == '%' && (str[i + 1] == '\0' || str[i + 1] == '\n'))
		return (-1);
	while (str[i2] && i2 <= i)
	{
		if (str[i2] == '%' && count == 0 && i2 <= i)
			count = 1;
		if ((ft_isalpha(str[i2]) || str[i2] == '%') && count == 1 && i2 <= i)
		{
			if (i2 == i)
				return (1);
			count = 0;
		}
		i2++;
	}
	if (str[i] == ' ' && count == 1)
		return (-1);
	if (count == 0)
		return (0);
	return (1);
}
