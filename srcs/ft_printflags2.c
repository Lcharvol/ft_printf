/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printflags2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 07:42:46 by lcharvol          #+#    #+#             */
/*   Updated: 2017/01/14 07:43:57 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_flagminus(int nb)
{
	if (nb < 0)
		nb *= -1;
	while (nb-- != 0)
		ft_putchar(' ');
}

int		ft_printflagsd2(int nb)
{
	if (nb == 0)
		ft_putchar(' ');
	if (nb == 1)
		ft_putchar('+');
	return (1);
}

int		ft_printflagsx2(int diese, unsigned long long nb, int maj, int var[2])
{
	int count;
	int space;
	int plus;

	count = 0;
	space = var[0];
	plus = var[1];
	if (diese == 1 && nb != 0)
	{
		if (maj == 0)
			ft_putstr("0x");
		if (maj == 1)
			ft_putstr("0X");
		count += 2;
	}
	return (count);
}

int		ft_printflagsx(char *str, unsigned long long nb, int maj)
{
	int	i;
	int	space;
	int	plus;
	int	diese;
	int var[2];

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
	var[0] = space;
	var[1] = plus;
	return (ft_printflagsx2(diese, nb, maj, var));
}
