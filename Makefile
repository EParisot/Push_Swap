# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/30 19:40:33 by eparisot          #+#    #+#              #
#    Updated: 2018/03/23 12:04:08 by eparisot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1	=	checker

SRCS1	=	srcs_checker/main.c \
			srcs_checker/checker.c \
			srcs_common/instructions1.c \
			srcs_common/instructions2.c \
			srcs_common/instructions3.c \
			srcs_common/tools.c \
			GNL/get_next_line.c \
			SDL/sdl_pushswap.c

OBJS1	=	$(SRCS1:.c=.o)

NAME2	=	push_swap

SRCS2	=	srcs_pushswap/main.c \
			srcs_pushswap/pushswap.c \
			srcs_common/instructions1.c \
			srcs_common/instructions2.c \
			srcs_common/instructions3.c \
			srcs_common/tools.c \

OBJS2	=	$(SRCS2:.c=.o)

LIBS	=	libft/libft.a \
			printf/libftprintf.a \
			~/Library/Frameworks/SDL2.framework/SDL2

RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror

all		:	$(NAME1) $(NAME2) $(LIBS)

$(NAME1)	:	$(OBJS1) $(LIBS)
	gcc $(CFLAGS) $(OBJS1) $(LIBS) -o $(NAME1)

$(NAME2)	:	$(OBJS2) $(LIBS)
	gcc $(CFLAGS) $(OBJS2) $(LIBS) -o $(NAME2)

$(LIBS)	:
	cd libft && make && cd ../printf && make && cd ..

clean	:
	$(RM) $(OBJS1) $(OBJS2) && cd libft/ && make clean && \
cd ../printf && make clean && cd ..

fclean	:	clean
	$(RM) $(NAME1) $(NAME2) libft/libft.a printf/libftprintf.a

re		:	fclean all
