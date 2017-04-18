/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pres_and_large.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 06:51:25 by lcharvol          #+#    #+#             */
/*   Updated: 2016/12/08 06:52:22 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_large(int large)
{
	while (large > 0)
	{
		ft_putchar(' ');
		large--;
	}
}

void	ft_print_pres(int pres)
{
	if (pres > 0)
	{
		while (pres > 0)
		{
			ft_putchar('0');
			pres--;
		}
	}
}

int		ft_stock_pres(char *str)
{
	int pres;
	int point;
	int i;
	int count;

	i = 0;
	count = ft_count_point(str);
	point = 0;
	pres = 0;
	while (str[i++])
		if (str[i] == '.')
		{
			point = 1;
			while (str[i + 1] == '.')
				i++;
			break ;
		}
	if (point == 1)
	{
		i++;
		if (ft_isnumber(str[i]))
			pres += ft_atoi((const char *)str + i);
	}
	pres = (point == 0) ? -10 : pres;
	return (pres);
}

int		ft_stock_large(char *str)
{
	int large;
	int point;
	int i;

	i = 0;
	point = 0;
	large = 0;
	while (str[i])
	{
		if (str[i] == '.')
		{
			point = 1;
			break ;
		}
		if (ft_isnumber(str[i]) && str[i] != '0')
			break ;
		i++;
	}
	if (point == 1)
		return (0);
	if (ft_isnumber(str[i]))
		large += ft_atoi((const char *)str + i);
	return (large);
}
