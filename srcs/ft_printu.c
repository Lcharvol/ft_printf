/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 23:51:52 by lcharvol          #+#    #+#             */
/*   Updated: 2017/01/18 14:20:09 by lcharvol         ###   ########.fr       */
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

char			*ft_itoa_baseu(unsigned long long int nbr, int base,
	char *retour)
{
	int			nb;
	int			i;
	char		tab[17];

	ft_strcpy(tab, "0123456789abcdef");
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

int				ft_printu3(t_env *e)
{
	if (e->flagminus < 0)
		e->flagminus = 0;
	if (e->large < 0)
		e->large = 0;
	ft_print_large(e->large);
	e->large += ft_printflagsu(e->type, e->nb2);
	ft_print_pres(e->pres);
	if ((e->nb2 == 0 && (e->pres > 1 || ft_stock_pres(e->type) == -10)) ||
			(e->nb2 == 0 && (ft_cherch_flag(e->type, '#') == 1)))
	{
		ft_putchar('0');
		e->pres++;
	}
	ft_putstr(e->str2);
	ft_print_flagminus(e->flagminus);
	free(e->str2);
	e->str2 = NULL;
	return (e->large + e->pres + e->lennb + e->flagminus);
}

int				ft_printu2(t_env *e)
{
	e->lennb = ft_strlen(e->str2);
	if (e->str2 == 0)
		e->lennb = 1;
	e->flagminus = 0;
	if (((ft_cherch_flag(e->type, '0') == 2 && ft_cherch_flag(e->type, '-')
		!= 3) || (ft_cherch_flag(e->type, '0') == 2 &&
		ft_cherch_flag(e->type, '-') != 3)) && ft_stock_pres(e->type) == -10)
	{
		e->pres = e->large;
		e->large = 0;
	}
	if (ft_cherch_flag(e->type, '-') == 3 || ft_cherch_flag(e->type, '-') == 3)
	{
		e->flagminus = e->large;
		e->large = 0;
	}
	return (ft_printu3(e));
}

int				ft_printu(va_list ap, t_env *e, int flag2)
{
	if (flag2 == 0)
		flag2 += ft_flag2(e->type);
	e->nb2 = ft_verifx(ap, flag2);
	e->str2 = malloc(sizeof(char) * (compte(e->nb2, 10) + 1));
	e->str2 = ft_itoa_baseu(e->nb2, 10, e->str2);
	e->pres = 0;
	e->large = 0;
	e->type = e->type;
	e->flag2 = flag2;
	e->lennb = ft_strlen(e->str2);
	if (e->nb2 == 0)
		e->lennb = 1;
	e->pres = ft_stock_pres(e->type);
	if (e->nb2 == 0 && e->pres == 0)
		e->lennb = 0;
	if ((e->pres <= e->lennb && e->nb2 != 0) || e->pres < 0)
		e->pres = 0;
	if (e->pres > e->lennb)
		e->pres -= e->lennb;
	e->large = ft_stock_large(e->type) - e->lennb - e->pres -
		ft_useflag(e->type, e->nb2);
	if (ft_cherch_flag(e->type, '#') == 1)
		e->large -= 1;
	return (ft_printu2(e));
}
