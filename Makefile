# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hwon <ohj8447@gmail.com>                   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/10 22:17:13 by hwon              #+#    #+#              #
#    Updated: 2021/05/10 22:25:06 by hwon             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= 
OBJS	= ${SRCS:.c=.o}
NAME	= libftprintf.a

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar
ARFLAGS	= rs
RM		= rm -f

.c.o :
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

bonus : $(OBJS) $(OBJS_B)
	$(AR) $(ARFLAGS) $(NAME) $^

all : $(NAME)

clean :
	$(RM) $(OBJS) $(OBJS_B)

fclean : clean
	$(RM) $(NAME)

re : fclean all

norm :
	norminette -R CheckForbiddenSourceHeader $(SRCS) $(SRCS_B)
	norminette -R CheckDefine libft.h

.PHONY: all clean fclean re .c.o norm
