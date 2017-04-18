/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 00:57:24 by lcharvol          #+#    #+#             */
/*   Updated: 2017/01/19 13:53:50 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*ft_stock_type2(int i, int i2, char *type, const char *str)
{
	while (i2 < i)
	{
		type[i2] = str[i2];
		i2++;
	}
	type[i] = '\0';
	return (type);
}

char		*ft_stock_type(const char *str)
{
	int		i;
	int		i2;
	char	*type;

	i = 1;
	i2 = -1;
	type = (char *)malloc(sizeof(char) * 100);
	while (str[i] == '.' || ft_isnumber(str[i]) || ft_isalpha(str[i]) ||
		ft_isflag(str[i], str[i - 1]) || str[i] == '%')
	{
		i++;
		if (ft_is_a_type(str[i - 1]) == 1)
			break ;
		if (ft_is_a_type(str[i - 1]) != 1 && ft_isalpha(str[i - 1]) &&
			ft_is_a_flag2(str[i - 1]) == 0)
		{
			while (++i2 < i - 1)
				type[i2] = str[i2];
			type[i] = 'k';
			type[i + 1] = '\0';
			return (type);
		}
	}
	return (ft_stock_type2(i, i2, type, str));
}

t_env		*ft_print_type(const char *format, int i, va_list ap, t_env *p)
{
	int		tmp;

	p->ret = 0;
	tmp = ft_type_len(format + i);
	p->type = ft_stock_type(format + i);
	p->ret += ft_print_arg(ap, p);
	return (p);
}

int			ft_print(va_list ap, const char *format)
{
	int		i;
	int		count;
	int		len;
	t_env	*p;

	i = 0;
	count = 0;
	p = (t_env *)malloc(sizeof(*p));
	while (format[i])
		if (ft_in_or_not(format, i) == 1 && format[i])
		{
			p = ft_print_type(format, i, ap, p);
			count += p->ret;
			len = ft_type_len(format + i);
			while (len--)
				i++;
		}
		else if (ft_in_or_not(format, i) == 0 && format[i])
		{
			count++;
			ft_putchar(format[i++]);
		}
		else if (ft_in_or_not(format, i) == -1)
			i++;
	return (count);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	int		result;

	va_start(ap, format);
	result = ft_print(ap, format);
	return (result);
}
