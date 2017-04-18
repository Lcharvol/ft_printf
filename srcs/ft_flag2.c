/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 23:12:05 by lcharvol          #+#    #+#             */
/*   Updated: 2017/01/08 23:12:06 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_cherch_flag2(char *str)
{
	int i;

	i = 0;
	if (ft_strstr(str, "z") != 0)
		return (6);
	else if (ft_strstr(str, "j") != 0)
		return (5);
	else if (ft_strstr(str, "ll") != 0)
		return (1);
	else if (ft_strstr(str, "l") != 0)
		return (2);
	else if (ft_strstr(str, "hh") != 0)
		return (3);
	else if (ft_strstr(str, "h") != 0)
		return (4);
	return (0);
}

int		ft_flag2(char *type)
{
	int ret;

	ret = ft_cherch_flag2(type);
	return (ret);
}
