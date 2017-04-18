/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 11:55:50 by lcharvol          #+#    #+#             */
/*   Updated: 2017/01/14 07:42:03 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printflagsd(char *str, int less)
{
	int	i;
	int	space;
	int	plus;
	int	count;

	count = 0;
	i = 0;
	space = 0;
	plus = 0;
	while (str[i] && (!(ft_isalpha(str[i]))))
	{
		if (ft_isflag(str[i], str[i - 1]) == 4)
			plus = 1;
		if (ft_isflag(str[i], str[i - 1]) == 5)
			space = 1;
		i++;
	}
	if (space == 1 && plus == 0 && less == 0)
		count += ft_printflagsd2(0);
	if (((space == 1 && plus == 1) || (plus == 1 && space == 0)) && less == 0)
		count += ft_printflagsd2(1);
	return (count);
}

int		ft_printflagso2(int diese, int nb, int space, int plus)
{
	int	count;

	count = 0;
	if (diese == 1 && nb != 0)
	{
		ft_putstr("0");
		count += 1;
	}
	if (space == 1 && plus == 0)
		count--;
	if (plus == 1)
		count--;
	return (count);
}

int		ft_printflagso(char *str, int nb)
{
	int	i;
	int	space;
	int	plus;
	int	diese;

	diese = 0;
	i = 0;
	space = 0;
	plus = 0;
	while (str[i] && (!(ft_isalpha(str[i])) || !(ft_isnumber(str[i]))))
	{
		if (ft_isflag(str[i], str[i - 1]) == 4)
			plus = 1;
		if (ft_isflag(str[i], str[i - 1]) == 5)
			space = 1;
		if (ft_isflag(str[i], str[i - 1]) == 1)
			diese = 1;
		i++;
	}
	return (ft_printflagso2(diese, nb, space, plus));
}

int		ft_printflagsu(char *str, int nb)
{
	int	space;
	int	plus;
	int	count;
	int	diese;

	diese = 0;
	count = 0;
	space = 0;
	plus = 0;
	if (ft_cherch_flag(str, '+') == 4)
		plus = 1;
	if (ft_cherch_flag(str, ' ') == 5)
		space = 1;
	if (ft_cherch_flag(str, '#') == 1)
		diese = 1;
	if (diese == 1 && nb != 0)
	{
		ft_putstr("0");
		count += 1;
	}
	return (count);
}

void	ft_printflags(char *str)
{
	int	i;
	int	space;
	int	plus;

	i = 0;
	space = 0;
	plus = 0;
	while (str[i] && (!(ft_isalpha(str[i])) || !(ft_isnumber(str[i]))))
	{
		if (ft_isflag(str[i], str[i - 1]) == 4)
			plus = 1;
		if (ft_isflag(str[i], str[i - 1]) == 5)
			space = 1;
		i++;
	}
	if (space == 1 && plus == 0)
		ft_putchar(' ');
	if ((space == 1 && plus == 1) || (plus == 1 && space == 0))
		ft_putchar('+');
}
