/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_firstarg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 06:47:10 by lcharvol          #+#    #+#             */
/*   Updated: 2016/12/06 06:47:12 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_verif_arg2(const char *s)
{
	int i;

	i = 0;
	while (s[i++])
	{
		if (s[i] == '.' && s[i - 1] == '.' && s[i - 2] == '%')
			return (1);
		if (s[i] == '.' && s[i - 1] == '.' && ft_isnumber(s[i - 2]) &&
			s[i - 3] == '%')
			return (1);
	}
	return (0);
}

int		ft_verif_arg1(const char *s)
{
	int	i[3];

	i[0] = 0;
	while (s[i[0]++])
	{
		if (s[++i[0]] == '%')
		{
			while (s[i[0]++] && (s[i[0]++] != '%' || s[i[0]++] != '\n'))
			{
				i[2] = 1;
				if (s[i[0]] == ' ' && s[i[0] - 1] == '%' && s[i[0] - 2] != '%')
					return (1);
				if (s[i[0]] == '%')
				{
					while (s[i[0]++] == '%' && s[i[0]++])
						i[2]++;
					if ((i[2] % 2) != 0)
						return (1);
				}
			}
		}
	}
	return (0);
}

int		ft_verif_firstarg(const char *s)
{
	if (ft_verif_arg1(s) == 1)
		return (1);
	if (ft_verif_arg2(s) == 1)
		return (1);
	return (0);
}
