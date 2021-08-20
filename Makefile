# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hwon <ohj8447@gmail.com>                   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/10 22:17:13 by hwon              #+#    #+#              #
#    Updated: 2021/08/20 22:57:00 by hwon             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFTDIR	= ./libft
LIBFTFILE	= libft.a

SRCS	= ft_printf.c \
		  ft_format.c \
		  ft_format_decode.c \
		  ft_putnbr_info.c \
		  ft_putstr_info.c \
		  ft_putchar_info.c \
		  ft_utils.c
HEADS	= ft_printf.h \
		  ft_format.h

OBJS	= ${SRCS:.c=.o}
NAME	= libftprintf.a

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar
ARFLAGS	= rc
RM		= rm -f

.c.o :
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME) : $(OBJS)
	make -C $(LIBFTDIR)/
	cp $(LIBFTDIR)/$(LIBFTFILE) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

all : $(NAME)

clean :
	make clean -C $(LIBFTDIR)/
	$(RM) $(OBJS) $(OBJS_B)

fclean : clean
	make fclean -C $(LIBFTDIR)/
	$(RM) $(NAME)

re : fclean all

test : $(OBJS) $(OBJS_B)
	$(CC) -o a.out test.c $(NAME)

norm :
	make norm -C $(LIBFTDIR)/
	norminette -R CheckForbiddenSourceHeader $(SRCS) $(SRCS_B)
	norminette -R CheckDefine $(HEADS)

.PHONY: all clean fclean re .c.o norm
