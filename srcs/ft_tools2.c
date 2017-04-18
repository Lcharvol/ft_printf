/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 06:52:37 by lcharvol          #+#    #+#             */
/*   Updated: 2017/01/14 06:52:38 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_type_len(const char *str)
{
	int i;

	i = 1;
	while (str[i] != '\n')
	{
		if (ft_isalpha(str[i]) == 1 && ft_is_a_flag2(str[i]) != 1)
		{
			if (ft_is_a_type(str[i]) == 0)
				i--;
			break ;
		}
		if (str[i] == '%')
			break ;
		if (ft_isalpha(str[i]) == 0 && ft_isnumber(str[i]) == 0 && str[i] != '.'
			&& str[i] != ' ' && ft_isflag(str[i], str[i - 1]) == 0)
		{
			i--;
			break ;
		}
		i++;
	}
	return (i + 1);
}

int			ft_count_point(char *str)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while (str[i])
	{
		if (str[i] == '.')
			ret++;
		i++;
	}
	return (ret);
}

t_env		*ft_initia(void)
{
	t_env *e;

	e = (t_env *)malloc(sizeof(*e));
	e->nb2 = 0;
	e->count = 0;
	e->useflag = 0;
	e->less = 0;
	e->c = 0;
	e->i = 0;
	e->pres2 = 0;
	e->pres = 0;
	e->large = 0;
	e->nb = 0;
	e->lenstr = 0;
	e->lennb = 0;
	e->str = NULL;
	e->str2 = NULL;
	e->str3 = NULL;
	e->type = NULL;
	e->flag2 = 0;
	e->maj = 0;
	e->flagminus = 0;
	return (e);
}

int			ft_is_a_flag2(char c)
{
	int		i;
	char	*type;

	i = 0;
	type = "lhjz";
	while (type[i])
	{
		if (type[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int			ft_is_a_type(char c)
{
	int		i;
	char	*type;

	i = 0;
	type = "sSpdDioOuUxXcC%";
	while (type[i])
	{
		if (type[i] == c)
			return (1);
		i++;
	}
	return (0);
}
