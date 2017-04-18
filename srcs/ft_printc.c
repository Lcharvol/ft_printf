/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 19:06:27 by lcharvol          #+#    #+#             */
/*   Updated: 2016/12/16 19:06:28 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_printc2(t_env *e)
{
	e->pres = 0;
	if (ft_cherch_flag(e->type, '0') == 2)
	{
		e->pres = e->large;
		e->large = 0;
	}
	if (ft_cherch_flag(e->type, '-') == 3)
	{
		e->flagminus = e->large;
		e->large = 0;
	}
	ft_print_large(e->large);
	if (e->pres < 0)
		e->pres = 0;
	ft_print_pres(e->pres);
	if (e->c)
		ft_putchar(e->c);
	if (!(e->c))
		ft_putchar('\0');
	ft_print_flagminus(e->flagminus);
	e->pres = ft_stock_large(e->type);
	e->pres += (e->pres == 0) ? 1 : 0;
	return (e->pres);
}

int			ft_printc(va_list ap, t_env *e, int flag2)
{
	if (flag2 == 0)
		flag2 = ft_flag2(e->type);
	e->flag2 = flag2;
	if (flag2 == 2)
		return (ft_printbigc(ap, e));
	e->c = ft_verifc(ap, e->flag2);
	e->flagminus = 0;
	e->large = ft_stock_large(e->type);
	e->large = e->large - 1;
	if (e->large < 0)
		e->large = 0;
	return (ft_printc2(e));
}
