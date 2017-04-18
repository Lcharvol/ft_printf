/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 11:56:01 by lcharvol          #+#    #+#             */
/*   Updated: 2017/01/18 14:22:04 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	compte(unsigned long nbr, int base)
{
	int		ret;

	ret = 0;
	while (nbr != 0)
	{
		nbr /= base;
		ret++;
	}
	return (ret);
}

char		*ft_itoa_baseol(unsigned long long int nbr, int base)
{
	char	*retour;
	int		nb;
	int		i;
	char	tab[17];

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

int			ft_printol3(t_env *e)
{
	ft_print_large(e->large);
	e->large += ft_printflagso(e->type, e->nb);
	ft_print_pres(e->pres);
	if ((e->nb == 0 && (e->pres > 1 || ft_stock_pres(e->type) == -10)) ||
			(e->nb == 0 && ft_cherch_flag(e->type, '#') == 1))
	{
		ft_putchar('0');
		if (ft_stock_pres(e->type) != -10)
			e->pres++;
	}
	ft_putstr(e->str2);
	ft_print_flagminus(e->flagminus);
	return (e->large + e->pres + ft_useflag(e->type, e->nb) + e->lennb +
			e->flagminus);
}

int			ft_printol2(t_env *e)
{
	e->flagminus = 0;
	if (ft_cherch_flag(e->type, '#') == 1)
		e->large -= 1;
	if ((ft_cherch_flag(e->type, '0') == 2 && ft_cherch_flag(e->type, '-') != 3)
		&& ft_stock_pres(e->type) == -10)
	{
		e->pres = e->large;
		e->large = 0;
	}
	if (ft_cherch_flag(e->type, '-') == 3)
	{
		e->flagminus = e->large;
		e->large = 0;
	}
	if (e->flagminus < 0)
		e->flagminus = 0;
	if (e->large < 0)
		e->large = 0;
	return (ft_printol3(e));
}

int			ft_printol(t_env *e)
{
	e->str2 = ft_itoa_baseol(e->nb, 8);
	e->lennb = ft_strlen(e->str2);
	if (e->nb == 0)
		e->lennb = 1;
	e->pres = ft_stock_pres(e->type);
	if (e->nb == 0 && e->pres == 0)
		e->lennb = 0;
	if (e->pres <= e->lennb && e->nb != 0)
		e->pres = 0;
	if (e->pres > e->lennb)
		e->pres -= e->lennb;
	if (e->pres < 0)
		e->pres = 0;
	e->large = ft_stock_large(e->type) - e->lennb - e->pres -
		ft_useflag(e->type, e->nb);
	return (ft_printol2(e));
}
