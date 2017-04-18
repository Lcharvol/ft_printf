/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbigs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 08:57:46 by lcharvol          #+#    #+#             */
/*   Updated: 2017/01/22 15:11:47 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int			compte(unsigned long nbr, int base)
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

char				*ft_itoa_basebigs(unsigned long long nbr, int base)
{
	char			*retour;
	int				nb;
	int				i;
	char			tab[17];

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

int					ft_printbigs3(char *str, t_env *e, int i, int i2)
{
	e->str3 = ft_complete(str, e->str2);
	ft_convert_int(e->str3, i2, e);
	return (i);
}

int					ft_printbigs2(t_env *e, wchar_t c)
{
	int				count;

	count = 0;
	if (e->lenstr <= 7)
	{
		write(1, &(c), 1);
		count += 1;
	}
	else if (e->lenstr <= 11)
		count += ft_printbigs3("110xxxxx10xxxxxx", e, 2, 1);
	else if (e->lenstr > 11 && e->lenstr <= 16)
		count += ft_printbigs3("1110xxxx10xxxxxx10xxxxxx", e, 3, 2);
	else
		count += ft_printbigs3("11110xxx10xxxxxx10xxxxxx10xxxxxx", e, 4, 3);
	return (count);
}

int					ft_printbigs(va_list ap, t_env *e)
{
	wchar_t			*str;

	e->pres = 0;
	e->flagminus = 0;
	str = va_arg(ap, wchar_t *);
	if (str == NULL)
		ft_putstr("(null)");
	if (str == NULL)
		return (6);
	e->large = ft_stock_large(e->type) - ft_wstrlen(str);
	e->large = (e->large < 0) ? 0 : e->large;
	if (ft_cherch_flag(e->type, '0') == 2)
		e->pres = e->large;
	if (ft_cherch_flag(e->type, '0') == 2)
		e->large = 0;
	if (ft_cherch_flag(e->type, '-') == 3)
	{
		e->flagminus = e->large;
		e->large = 0;
	}
	ft_printbigs4(e, str);
	ft_print_flagminus(e->flagminus);
	return (e->count + e->large + e->pres + e->flagminus);
}
