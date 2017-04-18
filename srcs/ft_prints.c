/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 09:00:01 by lcharvol          #+#    #+#             */
/*   Updated: 2016/12/08 09:00:02 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_stock_pres_str(char *str)
{
	int		pres;
	int		point;
	int		i;

	i = 0;
	point = 0;
	pres = 0;
	while (str[i++])
	{
		if (str[i] == '.')
		{
			point = 1;
			break ;
		}
	}
	if (point == 1)
	{
		i++;
		if (ft_isnumber(str[i]))
			pres += ft_atoi((const char *)str + i);
	}
	else
		return (-1);
	return (pres);
}

int			ft_prints3(t_env *e)
{
	while (e->str[e->i] && e->pres > 0)
	{
		ft_putchar(e->str[e->i]);
		e->pres--;
		e->i++;
	}
	ft_print_flagminus(e->flagminus);
	if (e->flagminus < e->pres)
		e->flagminus = 0;
	return (e->i + e->flagminus + e->pres);
}

int			ft_prints2(t_env *e)
{
	e->i = 0;
	e->pres2 = 0;
	e->flagminus = 0;
	if (e->large < 0)
		e->large = 0;
	if (ft_cherch_flag(e->type, '0') == 2 && ft_cherch_flag(e->type, '-') != 3)
	{
		e->pres2 = e->large;
		e->large = 0;
	}
	if (ft_cherch_flag(e->type, '-') == 3)
	{
		e->flagminus = e->large;
		e->large = 0;
	}
	ft_print_large(e->large);
	ft_print_pres(e->pres2);
	return (ft_prints3(e) + e->pres2 + e->large);
}

int			ft_prints(va_list ap, t_env *e, int flag2)
{
	if (flag2 == 0)
		flag2 = ft_flag2(e->type);
	if (flag2 == 2)
		return (ft_printbigs(ap, e));
	e->str = ft_verifs(ap, flag2);
	if (!(e->str) && ft_stock_pres(e->type) == -10)
	{
		ft_putstr("(null)");
		return (6);
	}
	if (e->str == NULL)
		e->str = "";
	e->pres = 0;
	e->large = 0;
	e->lenstr = ft_strlen(e->str);
	e->pres = ft_stock_pres_str(e->type);
	if (e->pres == -1)
		e->pres = e->lenstr;
	e->large = ft_stock_large(e->type);
	if (e->pres >= e->lenstr)
		e->pres = e->lenstr;
	e->large -= e->pres;
	return (ft_prints2(e));
}
