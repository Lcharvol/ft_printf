/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 00:55:08 by lcharvol          #+#    #+#             */
/*   Updated: 2017/01/21 10:42:51 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <wchar.h>
# include "../libft/libft.h"

typedef struct				s_env
{
	int						ret;
	unsigned long long int	nb2;
	int						count;
	int						useflag;
	int						less;
	char					c;
	int						i;
	int						pres2;
	int						pres;
	int						large;
	long long				nb;
	int						lenstr;
	int						lennb;
	char					*str;
	char					*str2;
	char					*str3;
	char					*type;
	int						flag2;
	int						maj;
	int						flagminus;
}							t_env;

int							ft_flag2(char *type);
int							ft_cherch_flag(char *str, char c);
int							ft_useflag(char *str, int nb);
int							ft_is_a_type(char c);
int							ft_isflag(char c, char b);
int							ft_is_a_flag2(char c);
int							ft_in_or_not(const char *str, int i);
int							ft_isnumber(char c);
void						ft_exit();
int							ft_not_in_type(const char *str, int i);

int							ft_printbigc(va_list ap, t_env *e);
int							ft_stock_lennb(long long nb);
int							ft_stock_large(char *str);
int							ft_stock_pres(char *str);

int							ft_printbigs(va_list ap, t_env *e);
int							ft_printp(va_list ap, char *type);
int							ft_printflagsu(char *str, int nb);
int							ft_printu(va_list ap, t_env *e, int flag2);
int							ft_printflagso(char *str, int nb);
int							ft_printflagsd(char *str, int less);
void						ft_printflags(char *str);
int							ft_printflagsd2(int nb);
int							ft_printflagsx(char *str, unsigned long long
	nb, int maj);
int							ft_printo(va_list ap, t_env *e, int flag2);
int							ft_printol(t_env *e);
int							ft_printx(va_list ap, t_env *e, int flag2, int maj);
int							ft_printc(va_list ap, t_env *e, int flag2);
void						ft_print_flagminus(int nb);
int							ft_printpercent(t_env *e);
void						ft_print_large(int large);
void						ft_print_pres(int pres);
int							ft_prints(va_list ap, t_env *e, int flag2);
int							ft_printd(va_list ap, t_env *e, int flag2);
int							ft_print_arg(va_list ap, t_env *e);

t_env						*ft_final(t_env *e);
t_env						*ft_initia(void);
int							ft_printbigs2(t_env *e, wchar_t str);
char						*ft_complete(char *str2, char *bits);
int							ft_convert_int(char *str, int nb, t_env *e);
char						*ft_get_oct(char *str, int i);
int							ft_conv_dec(char *bin);
char						*ft_itoa_basebigs(unsigned long long nbr, int base);

int							ft_is_flag2(char c);
int							ft_wstrlen(wchar_t *str);
int							ft_fuck_the_norm2(int nb2, t_env *e);
unsigned long long int		ft_verifx(va_list ap, int flag2);
char						ft_verifc(va_list ap, int flag2);
char						*ft_verifs(va_list ap, int flag2);
long long int				ft_verifd(va_list ap, int flag2);
int							ft_verif_firstarg(const char *s);

int							ft_printbigs4(t_env *e, wchar_t *str);
int							ft_type_len(const char *str);
int							ft_count_point(char *str);
void						ft_putstr_new(char *str);
int							ft_is_a_type(char c);
void						ft_putnbr2(long long nb);

int							ft_printf(const char *format, ...);

#endif
