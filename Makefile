# ***************s************************************************************* #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/05 08:56:48 by lcharvol          #+#    #+#              #
#    Updated: 2016/12/05 08:56:50 by lcharvol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =				libftprintf.a

CC =				gcc
FLAGS =				-Wall -Werror -Wextra

FT_SRC_DIR =		./libft
PRINTF_SRC_DIR =	./srcs

HEADER =			$(FT_SRC_DIR)libft.h
PRINTF_SRC_HEADER =	$(PRINTF_SRC_DIR) includes/ft_printf.h

FT_COMPILED :=		ft_isalpha.o
FT_COMPILED +=		ft_putchar.o 
FT_COMPILED +=		ft_putendl.o 
FT_COMPILED +=		ft_putnbr.o 
FT_COMPILED +=		ft_putstr.o 
FT_COMPILED +=		ft_strlen.o 
FT_COMPILED +=		ft_toupper.o 
FT_COMPILED +=		ft_tolower.o 
FT_COMPILED +=		ft_strcat.o 
FT_COMPILED +=		ft_strncat.o 
FT_COMPILED +=		ft_strcpy.o 
FT_COMPILED +=		ft_strcmp.o 
FT_COMPILED +=		ft_isdigit.o 
FT_COMPILED +=		ft_isascii.o 
FT_COMPILED +=		ft_isprint.o 
FT_COMPILED +=		ft_isalnum.o 
FT_COMPILED +=		ft_atoi.o 
FT_COMPILED +=		ft_strstr.o 
FT_COMPILED +=		ft_strncmp.o 
FT_COMPILED +=		ft_strclr.o 
FT_COMPILED +=		ft_striter.o 
FT_COMPILED +=		ft_strnstr.o 
FT_COMPILED +=		ft_striteri.o 
FT_COMPILED +=		ft_strmap.o 
FT_COMPILED +=		ft_strmapi.o 
FT_COMPILED +=		ft_strdel.o 
FT_COMPILED +=		ft_strnew.o 
FT_COMPILED +=		ft_memdel.o 
FT_COMPILED +=		ft_memalloc.o 
FT_COMPILED +=		ft_memset.o 
FT_COMPILED +=		ft_strequ.o 
FT_COMPILED +=		ft_strnequ.o 
FT_COMPILED +=		ft_strsub.o 
FT_COMPILED +=		ft_strjoin.o 
FT_COMPILED +=		ft_strtrim.o 
FT_COMPILED +=		ft_strchr.o 
FT_COMPILED +=		ft_strrchr.o 
FT_COMPILED +=		ft_strsplit.o 
FT_COMPILED +=		ft_strncpy.o 
FT_COMPILED +=		ft_strdup.o 
FT_COMPILED +=		ft_bzero.o 
FT_COMPILED +=		ft_memcpy.o 
FT_COMPILED +=		ft_memccpy.o 
FT_COMPILED +=		ft_putchar_fd.o 
FT_COMPILED +=		ft_putstr_fd.o 
FT_COMPILED +=		ft_putendl_fd.o 
FT_COMPILED +=		ft_putnbr_fd.o 
FT_COMPILED +=		ft_memcmp.o 
FT_COMPILED +=		ft_memchr.o 
FT_COMPILED +=		ft_memmove.o 
FT_COMPILED +=		ft_itoa.o 
FT_COMPILED +=		ft_strlcat.o 
FT_COMPILED +=		ft_lstnew.o 
FT_COMPILED +=		ft_lstdelone.o 
FT_COMPILED +=		ft_lstdel.o 
FT_COMPILED +=		ft_lstadd.o 
FT_COMPILED +=		ft_lstiter.o 
FT_COMPILED +=		ft_lstmap.o 
FT_COMPILED +=		ft_get_next_line.o 
				
PRINTF_COMPILED :=	ft_printf.o
PRINTF_COMPILED +=	ft_printarg.o
PRINTF_COMPILED +=  ft_verif_firstarg.o
PRINTF_COMPILED +=	ft_printd.o
PRINTF_COMPILED +=	ft_verif_str.o
PRINTF_COMPILED +=	ft_pres_and_large.o
PRINTF_COMPILED +=	ft_prints.o
PRINTF_COMPILED +=	ft_flag.o
PRINTF_COMPILED +=	ft_printpercent.o
PRINTF_COMPILED +=	ft_printc.o
PRINTF_COMPILED +=	ft_printu.o
PRINTF_COMPILED +=	ft_tools.o
PRINTF_COMPILED +=	ft_printx.o
PRINTF_COMPILED +=	ft_printo.o
PRINTF_COMPILED +=	ft_printol.o
PRINTF_COMPILED +=	ft_printflags.o
PRINTF_COMPILED +=	ft_printflags2.o
PRINTF_COMPILED +=	ft_flag2.o
PRINTF_COMPILED +=	ft_tools2.o
PRINTF_COMPILED +=	ft_printbigs.o
PRINTF_COMPILED +=	ft_printbigs2.o

COMPILED =			$(FT_COMPILED) $(PRINTF_COMPILED)

all: $(NAME)

$(NAME): $(COMPILED)
	@ar rc $(NAME) $(COMPILED)
	@ranlib $(NAME)

$(FT_COMPILED): %.o: $(FT_SRC_DIR)/%.c
	@$(CC) -c $(FLAGS) -I $(FT_SRC_DIR) $< -o $@

$(PRINTF_COMPILED): %.o: $(PRINTF_SRC_DIR)/%.c
	@$(CC) -c $(FLAGS) -I $(FT_SRC_DIR) -I $(PRINTF_SRC_DIR) $< -o $@

clean:
	@-/bin/rm -f $(COMPILED)

fclean: clean
	@-/bin/rm -f $(NAME) $(COMPILED) $(FT_SRC_DIR)/libft.a

re: fclean all
