/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 04:56:34 by lcharvol          #+#    #+#             */
/*   Updated: 2017/01/14 05:36:55 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

unsigned long long int			ft_verifx(va_list ap, int flag2)
{
	unsigned long long int		nb;

	nb = 0;
	if (flag2 == 0)
		nb = va_arg(ap, unsigned int);
	else if (flag2 == 1)
		nb = va_arg(ap, unsigned long long int);
	else if (flag2 == 2)
		nb = va_arg(ap, unsigned long int);
	else if (flag2 == 3)
		nb = (unsigned char)va_arg(ap, int);
	else if (flag2 == 4)
		nb = (unsigned short int)va_arg(ap, int);
	else if (flag2 == 5)
		nb = va_arg(ap, uintmax_t);
	else if (flag2 == 6)
		nb = va_arg(ap, size_t);
	else if (flag2 == 8)
		nb = va_arg(ap, unsigned long int);
	return (nb);
}

long long int					ft_verifd(va_list ap, int flag2)
{
	long long int				nb;

	nb = 0;
	if (flag2 == 0)
		nb = va_arg(ap, int);
	else if (flag2 == 1)
		nb = va_arg(ap, long long int);
	else if (flag2 == 2)
		nb = va_arg(ap, long int);
	else if (flag2 == 3)
		nb = (signed char)va_arg(ap, int);
	else if (flag2 == 4)
		nb = (short int)va_arg(ap, int);
	else if (flag2 == 5)
		nb = va_arg(ap, intmax_t);
	else if (flag2 == 6)
		nb = va_arg(ap, size_t);
	return (nb);
}

char							*ft_verifs(va_list ap, int flag2)
{
	char						*str;

	flag2++;
	str = va_arg(ap, char *);
	return (str);
}

char							ft_verifc(va_list ap, int flag2)
{
	unsigned char				c;
	long long int				nb;

	if (flag2 == 0)
		nb = va_arg(ap, int);
	if (flag2 == 5)
		nb = va_arg(ap, wint_t);
	c = nb + 0;
	return (c);
}
