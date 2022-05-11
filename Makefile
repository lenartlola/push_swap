# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsabir <marvin@42lausanne.ch>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/19 14:09:06 by hsabir            #+#    #+#              #
#    Updated: 2022/05/11 09:23:29 by hsabir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

AR = ar -rc

SRCS_DIR = ./operations \
		   ./utils \
		   ./algorithms \

OBJS_DIR = ./objs
INC_DIR = .
LIBFT_DIR = ./libft
LIBFT = libft.a
BONUS_DIR = ./checker_bonus

SRCS = main.c \
		push_swap.c \
	   ./operations/push_pop.c \
	   ./operations/reverse_rotate_stack.c \
	   ./operations/swap.c \
	   ./utils/check_utils.c \
	   ./utils/free.c \
	   ./utils/min_mid_max.c \
	   ./utils/my_atoi.c \
	   ./utils/stack_utils.c \
	   ./algorithms/a_to_b.c \
	   ./algorithms/b_to_a.c \
	   ./algorithms/fives.c \
	   ./algorithms/three_a.c \
	   ./algorithms/three_b.c \
	   ./algorithms/under_three.c

OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

vpath %.c $(SRCS_DIR)

RM = rm -f

all : $(NAME)

bonus : re
	echo "Compiling bonus checker..."
	@$(MAKE) fclean -C $(BONUS_DIR)
	@$(MAKE) -C $(BONUS_DIR)
	@cp checker_bonus/checker ./checker
	echo "bonus checker has been compiled..."

$(NAME) : $(OBJS)
	echo "Compling libft..."
	@$(MAKE) -C $(LIBFT_DIR)
	echo "Libft has been compiled..."
	echo "Compiling push_swap"
	@$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft
	echo "push_swap has been compiled..."

$(OBJS_DIR) :
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o : %.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -o $@ -I $(INC_DIR) -I$(LIBFT_DIR) -c $^

clean :
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C checker_bonus fclean
	@$(RM) -r $(OBJS_DIR)

fclean : clean
	@$(RM) $(NAME)
	@if [ -f ./checker ]; then $(RM) ./checker; fi;

re : fclean all
