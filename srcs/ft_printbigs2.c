/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbigs2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 10:02:38 by lcharvol          #+#    #+#             */
/*   Updated: 2017/01/21 10:21:40 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				ft_conv_dec(char *bin)
{
	int			dec;
	int			i;

	i = 0;
	dec = 0;
	while (bin[i])
	{
		if (bin[i] == '1')
			dec = dec * 2 + 1;
		else if (bin[i] == '0')
			dec *= 2;
		i++;
	}
	return (dec);
}

char			*ft_get_oct2(int i, int i2, char *new, char *str)
{
	if (i == 2)
	{
		i = 15;
		while (i++ < 24)
		{
			new[i2] = str[i];
			i2++;
		}
	}
	else if (i == 3)
	{
		i = 23;
		while (i++ < 32)
		{
			new[i2] = str[i];
			i2++;
		}
	}
	new[i2] = '\0';
	return (new);
}

char			*ft_get_oct(char *str, int i)
{
	char		*new;
	int			i2;

	new = ft_strnew(9);
	i2 = 0;
	if (i == 0)
	{
		i = -1;
		while (i++ < 7)
		{
			new[i2] = str[i];
			i2++;
		}
	}
	else if (i == 1)
	{
		i = 7;
		while (i++ < 15)
		{
			new[i2] = str[i];
			i2++;
		}
	}
	return (ft_get_oct2(i, i2, new, str));
}

int				ft_convert_int(char *str, int nb, t_env *e)
{
	int			i;
	int			nb2;

	i = -1;
	if (nb == 1)
		while (++i < 2)
		{
			e->str = ft_get_oct(str, i);
			nb2 = ft_fuck_the_norm2(nb2, e);
		}
	else if (nb == 2)
		while (++i < 3)
		{
			e->str = ft_get_oct(str, i);
			nb2 = ft_fuck_the_norm2(nb2, e);
		}
	else if (nb == 3)
		while (++i < 4)
		{
			e->str = ft_get_oct(str, i);
			nb2 = ft_fuck_the_norm2(nb2, e);
		}
	else
		return (-1);
	return (i);
}

char			*ft_complete(char *str2, char *bits)
{
	int			i;
	int			i2;
	char		*new;

	new = ft_strdup(str2);
	i = ft_strlen(bits) - 1;
	i2 = ft_strlen(new) - 1;
	while (i >= 0)
		if (new[i2] != 'x')
			i2--;
		else
		{
			new[i2] = bits[i];
			i2--;
			i--;
		}
	while (i2 >= 0)
	{
		if (new[i2] == 'x')
			new[i2] = '0';
		i2--;
	}
	return (new);
}
