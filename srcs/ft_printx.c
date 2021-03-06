/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 08:50:06 by lcharvol          #+#    #+#             */
/*   Updated: 2017/01/18 14:14:44 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		compte(unsigned long nbr, int base)
{
	int			ret;

	ret = 0;
	while (nbr != 0)
	{
		nbr /= base;
		ret++;
	}
	return (ret);
}

char			*ft_itoa_basex(unsigned long long nbr, int base, int maj)
{
	char		*retour;
	int			nb;
	int			i;
	char		tab[17];

	if (maj == 0 || maj == 3)
		ft_strcpy(tab, "0123456789abcdef");
	if (maj == 1)
		ft_strcpy(tab, "0123456789ABCDEF");
	nb = compte(nbr, base);
	retour = malloc(sizeof(int) * nb + 1);
	i = 1;
	while (nbr != 0)
	{
		retour[nb - i] = tab[nbr % base];
		nbr /= base;
		i++;
	}
	retour[nb] = '\0';
	return (retour);
}

int				ft_printx3(t_env *e)
{
	e->flagminus = 0;
	if (ft_cherch_flag(e->type, '-') == 3)
	{
		if (e->large >= 0)
			e->flagminus = e->large;
		e->large = 0;
	}
	e->large = (e->large < 0) ? 0 : e->large;
	ft_print_large(e->large);
	e->large += ft_printflagsx(e->type, e->nb2, e->maj);
	if (e->flag2 == 8)
		ft_putstr("0x");
	if ((e->maj == 4 || e->maj == 10) && (ft_stock_pres(e->type) > 0 ||
				ft_stock_pres(e->type) == -10))
		ft_putchar('0');
	if (e->pres < 0)
		e->pres = 0;
	ft_print_pres(e->pres);
	ft_putstr(e->str2);
	ft_print_flagminus(e->flagminus);
	free(e->str2);
	e->str2 = NULL;
	return (e->large + e->pres + e->lennb + e->flagminus);
}

int				ft_printx2(t_env *e)
{
	if (e->pres > e->lennb)
		e->pres -= e->lennb;
	e->large = ft_stock_large(e->type) - e->lennb - e->pres -
		ft_useflag(e->type, e->nb2);
	if (e->flag2 == 8)
		e->large -= 2;
	if (ft_cherch_flag(e->type, '#') == 1)
		e->large -= 2;
	if (ft_cherch_flag(e->type, '0') == 2 && ft_stock_pres(e->type) == -10 &&
		ft_cherch_flag(e->type, '-') != 3)
	{
		e->pres = e->large;
		e->large = 0;
	}
	return (ft_printx3(e));
}

int				ft_printx(va_list ap, t_env *e, int flag2, int maj)
{
	flag2 = (flag2 == 0) ? ft_flag2(e->type) : flag2;
	e->nb2 = ft_verifx(ap, flag2);
	e->flag2 = flag2;
	e->maj = maj;
	e->str2 = ft_itoa_basex(e->nb2, 16, maj);
	e->lennb = ft_strlen(e->str2);
	if (e->nb2 == 0)
		e->lennb = 1;
	e->pres = ft_stock_pres(e->type);
	if (e->pres == -10 && e->nb2 == 0)
		e->maj = 4;
	if (e->nb2 == 0 && e->pres == 0)
		e->lennb = 0;
	if (e->pres <= e->lennb)
		e->pres = 0;
	if (e->maj == 3 && e->nb2 == 0)
		e->maj = 10;
	return (ft_printx2(e));
}
