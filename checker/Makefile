# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsabir <marvin@42lausanne.ch>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 14:36:31 by hsabir            #+#    #+#              #
#    Updated: 2021/11/22 14:44:42 by hsabir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

CC = gcc
CFLAGS = -Wall -Wextra -Werror
# CFLAGS = -g3 -fsanitize=address

# ifeq ($(DEBUG),true)
# 	CFLAGS += -g
# endif

INCS = ./checker.h \
	   ./push_swap.h \
	   ./gnl/get_next_line_bonus.h

AR = ar
ARFLAGS = rc

SRCS_DIR =	./gnl	\
			./operations	\
			./utils

OBJS_DIR = ./objs

LIBFT = libft.a
LIBFT_DIR = ./libft

SRCS =	./gnl/get_next_line_bonus.c	\
		./gnl/get_next_line_utils_bonus.c	\
		./operations/push_pop.c	\
		./operations/reverse_rotate_stack.c	\
		./operations/swap.c	\
		./utils/check_utils.c	\
		./utils/my_atoi.c	\
		./utils/stack_utils.c	\
		./utils/min_mid_max.c \
		./main.c	\
		./checker.c	\
		./do_operations.c	\
		./free.c

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
