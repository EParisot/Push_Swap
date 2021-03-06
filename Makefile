# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/30 19:40:33 by eparisot          #+#    #+#              #
#    Updated: 2018/04/11 19:46:51 by eparisot         ###   ########.fr        #
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
			srcs_pushswap/tools.c \
			srcs_pushswap/tools2.c \
			srcs_pushswap/very_small_sort.c \
			srcs_pushswap/small_sort.c \
			srcs_pushswap/sort_bis.c \
			srcs_pushswap/sort_bis1.c \
			srcs_pushswap/sort_bis2.c \
			srcs_common/instructions1.c \
			srcs_common/instructions2.c \
			srcs_common/instructions3.c \
			srcs_common/tools.c \

OBJS2	=	$(SRCS2:.c=.o)

LIBS	=	libft/libft.a \
			printf/libftprintf.a \
			`sdl2-config --libs`

RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror `sdl2-config --cflags`

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
