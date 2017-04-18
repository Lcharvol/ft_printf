/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 08:50:06 by lcharvol          #+#    #+#             */
/*   Updated: 2017/01/18 14:18:35 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				ft_printd4(t_env *e)
{
	e->less = 0;
	if (e->nb < 0)
		e->less = 1;
	e->large += ft_printflagsd(e->type, e->less);
	if (e->nb < 0 && ft_cherch_flag(e->type, '0') != 2)
	{
		ft_putchar('-');
		e->nb *= -1;
	}
	ft_print_pres(e->pres);
	if ((ft_cherch_flag(e->type, '0') == 2 && e->nb < 0))
		e->nb *= -1;
	if (e->nb == 0 && ft_stock_pres(e->type) == 0)
	{
		ft_putchar(' ');
		ft_print_flagminus(e->flagminus);
		return (e->large + e->pres + e->lennb + e->flagminus);
	}
	ft_putnbr2(e->nb);
	ft_print_flagminus(e->flagminus);
	return (e->large + e->pres + e->lennb + e->flagminus);
}

int				ft_printd3(t_env *e)
{
	e->flagminus = 0;
	if (ft_cherch_flag(e->type, '-') == 3)
	{
		e->flagminus = e->large;
		e->large = 0;
	}
	ft_print_large(e->large);
	return (ft_printd4(e));
}

int				ft_printd2(t_env *e)
{
	if (e->pres <= e->lennb)
		e->pres = 0;
	if (e->pres > e->lennb)
	{
		e->pres -= e->lennb;
		if (e->nb < 0)
			e->pres++;
	}
	e->large = e->large - e->lennb - e->pres - ft_useflag(e->type, e->nb);
	if (e->large < 0)
		e->large = 0;
	if (ft_cherch_flag(e->type, '0') == 2 && ft_stock_pres(e->type)
			<= e->lennb && ft_cherch_flag(e->type, '-') != 3)
	{
		e->pres = e->large;
		e->large = 0;
	}
	if (e->large < 0)
		e->large = 0;
	return (ft_printd3(e));
}

int				ft_printd(va_list ap, t_env *e, int flag2)
{
	if (flag2 == 0)
		flag2 = ft_flag2(e->type);
	e->flag2 = flag2;
	e->nb = ft_verifd(ap, e->flag2);
	e->pres = 0;
	e->large = 0;
	if (e->nb == -2147483648)
	{
		ft_putchar('-');
		ft_putnbr2(2147483648);
		return (11);
	}
	e->lennb = ft_stock_lennb(e->nb);
	e->pres = ft_stock_pres(e->type);
	e->large = ft_stock_large(e->type);
	if (e->pres == 0 && e->nb == 0 && e->large == 0)
		return (0);
	if ((ft_cherch_flag(e->type, '0') == 2 && e->nb < 0))
		ft_putchar('-');
	return (ft_printd2(e));
}
