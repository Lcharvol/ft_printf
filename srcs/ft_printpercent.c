/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpercent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 13:19:38 by lcharvol          #+#    #+#             */
/*   Updated: 2016/12/15 13:25:22 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int					ft_printbigs4(t_env *e, wchar_t *str)
{
	unsigned int	nb;

	e->i = 0;
	e->count = 0;
	ft_print_pres(e->pres);
	ft_print_large(e->large);
	while (str[e->i])
	{
		nb = str[e->i] + 0;
		e->str2 = ft_itoa_basebigs(nb, 2);
		e->lenstr = ft_strlen(e->str2);
		e->count += ft_printbigs2(e, str[(e->i)++]);
		free(e->str2);
		e->str2 = NULL;
	}
	return (e->count);
}

int					ft_wcharlen(wint_t wc)
{
	size_t			j;

	j = 1;
	if (wc <= 0x7F)
		return (j);
	if (wc > 0x1FFFFF)
		return (-1);
	while (1)
	{
		if (!(wc >>= 6))
			break ;
		j++;
	}
	return (j);
}

int					ft_wstrlen(wchar_t *str)
{
	int				result;

	result = 0;
	while (*str)
		result += ft_wcharlen(*str++);
	return (result);
}

void				ft_printflagspercent(char *str)
{
	if (ft_cherch_flag(str, '+') == 4)
		ft_putchar('+');
}

int					ft_printpercent(t_env *e)
{
	e->flagminus = 0;
	e->large = 0;
	e->pres = 0;
	e->large = ft_stock_large(e->type) - 1;
	e->large = (e->large < 0) ? 0 : e->large;
	if (ft_cherch_flag(e->type, '0') == 2 &&
		ft_cherch_flag(e->type, '-') != 3)
	{
		e->pres = e->large;
		e->large = 0;
	}
	if (ft_cherch_flag(e->type, '-') == 3)
		e->flagminus = e->large;
	if (ft_cherch_flag(e->type, '-') == 3)
		e->large = 0;
	ft_print_large(e->large);
	ft_printflagspercent(e->type);
	ft_print_pres(e->pres);
	ft_putchar('%');
	ft_print_flagminus(e->flagminus);
	return (e->large + e->flagminus + e->pres + 1);
}
