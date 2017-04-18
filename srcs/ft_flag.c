/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 12:44:25 by lcharvol          #+#    #+#             */
/*   Updated: 2016/12/09 12:44:27 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_doflag(char c, int nb)
{
	if (c == '+' && nb >= 0)
		return (1);
	if (c == ' ' && nb >= 0)
		return (1);
	return (0);
}

int		ft_isflag(char c, char b)
{
	if (c == '#')
		return (1);
	if (c == '0' && !(b >= 49 && b <= 57))
		return (2);
	if (c == '-')
		return (3);
	if (c == '+')
		return (4);
	if (c == ' ')
		return (5);
	return (0);
}

int		ft_cherch_flag(char *str, char c)
{
	int i;

	i = 0;
	while (ft_isflag(str[i], str[i - 1]) != ft_isflag(c, str[i - 1])
		&& str[i])
		i++;
	return (ft_isflag(str[i], str[i - 1]));
}

int		ft_useflag(char *str, int nb)
{
	int i;
	int ret;

	i = 1;
	ret = 0;
	while (ft_isflag(str[i], str[i - 1]) == 5 && ft_isflag(str[i + 1],
		str[i]) == 5)
		i++;
	if (ft_isflag(str[i], str[i - 1]) == 5 && ft_isflag(str[i + 1],
		str[i]) == 4)
		return (ft_doflag(str[i + 1], nb));
	while (str[i])
	{
		if (ft_isflag(str[i], str[i - 1]) != 0)
			ret += ft_doflag(str[i], nb);
		i++;
	}
	return (ret);
}
