# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsabir <marvin@42lausanne.ch>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 14:36:31 by hsabir            #+#    #+#              #
#    Updated: 2021/12/02 12:10:44 by hsabir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
# CFLAGS = -g3 -fsanitize=address

# ifeq ($(DEBUG),true)
# 	CFLAGS += -g
# endif

INCS = ./checker.h \
	   ./push_swap.h \
	   ./get_next_line/get_next_line_bonus.h

AR = ar
ARFLAGS = rc

SRCS_DIR =	./get_next_line	\
		./operations	\
		./utils

OBJS_DIR = ./objs

LIBFT = libft.a
LIBFT_DIR = ./libft

SRCS =	./operations/push_pop.c	\
		./operations/reverse_rotate_stack.c	\
		./operations/swap.c	\
		./utils/check_utils.c	\
		./utils/free.c \
		./utils/my_atoi.c	\
		./utils/stack_utils.c	\
		./utils/min_mid_max.c \
		./main.c	\
		./checker.c	\
		./do_operations.c

OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

vpath %.c $(SRCS_DIR)

RM = rm -f

all : $(NAME)

$(NAME) : $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft

$(OBJS_DIR) :
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o : %.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -o $@ -I$(INC_DIR) -I$(LIBFT_DIR) -c $^

clean :
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(RM) -r $(OBJS_DIR)

fclean : clean
	@$(RM) $(NAME)

re : fclean all
