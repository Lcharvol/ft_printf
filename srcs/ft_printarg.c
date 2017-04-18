/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printarg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 06:12:13 by lcharvol          #+#    #+#             */
/*   Updated: 2017/01/21 10:45:09 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int					ft_undef(t_env *e)
{
	e->pres = ft_stock_pres(e->type);
	e->large = ft_stock_large(e->type) - 1 - e->pres;
	if (ft_cherch_flag(e->type, '0') == 2)
	{
		e->pres = e->large;
		e->large = 0;
	}
	ft_print_large(e->large);
	ft_print_pres(e->pres);
	return (e->large + e->pres);
}

int					ft_fuck_the_norm2(int nb2, t_env *e)
{
	nb2 = ft_conv_dec(e->str);
	free(e->str);
	e->str = NULL;
	write(1, &(nb2), 1);
	return (nb2);
}

int					ft_printbigc(va_list ap, t_env *e)
{
	wchar_t			c;
	unsigned int	nb;
	int				i;
	int				count;

	i = 0;
	count = 0;
	e->lenstr = 0;
	e->pres = ft_stock_pres(e->type);
	c = va_arg(ap, wchar_t);
	nb = c + 0;
	e->str2 = ft_itoa_basebigs(nb, 2);
	e->lenstr = ft_strlen(e->str2);
	count += ft_printbigs2(e, c);
	i++;
	return (count);
}

int					ft_print_arg2(va_list ap, t_env *e, char format, int count)
{
	if (format == 'c')
		count += ft_printc(ap, e, 0);
	else if (format == '%')
		count += ft_printpercent(e);
	else if (format == 'C')
		count += ft_printbigc(ap, e);
	else if (format == 'x')
		count += ft_printx(ap, e, 0, 0);
	else if (format == 'X')
		count += ft_printx(ap, e, 0, 1);
	else if (format == 'o')
		count += ft_printo(ap, e, 0);
	else if (format == 'O')
		count += ft_printo(ap, e, 2);
	else if (format == 'u')
		count += ft_printu(ap, e, 0);
	else if (format == 'U')
		count += ft_printu(ap, e, 2);
	else if (ft_isalpha(format) == 0 && format != '%')
		count += ft_undef(e);
	return (count);
}

int					ft_print_arg(va_list ap, t_env *e)
{
	char			format;
	int				i;
	char			*tmp;
	int				count;

	i = 0;
	tmp = "%";
	while (e->type[i])
		i++;
	count = 0;
	format = e->type[i - 1];
	if (ft_strcmp(e->type, tmp) == 0 || format == ' ')
		return (0);
	if (format == 'p')
		count += ft_printx(ap, e, 8, 3) + 2;
	else if (format == 'd' || format == 'i')
		count += ft_printd(ap, e, 0);
	else if (format == 'D')
		count += ft_printd(ap, e, 2);
	else if (format == 's')
		count += ft_prints(ap, e, 0);
	else if (format == 'S')
		count += ft_printbigs(ap, e);
	return (ft_print_arg2(ap, e, format, count));
}
