# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/18 11:21:16 by irychkov          #+#    #+#              #
#    Updated: 2024/08/05 14:21:08 by irychkov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECKER = checker

SRCS = main.c push.c swap.c rotate.c reverse_rotate.c fill_a.c free.c \
		init_info.c sort.c validation.c ft_atoi2.c argv_handler.c

BONUS_SRCS = checker_bonus.c push_swap_bonus.c push.c swap.c rotate.c \
		reverse_rotate.c fill_a.c free.c init_info.c sort.c validation.c \
		ft_atoi2.c argv_handler.c


OBJS = $(SRCS:.c=.o)

BONUS_OBJS = ${BONUS_SRCS:.c=.o}

HEADERS = -I. -I$(LIBFT_DIR)

LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)/libft.a

CFLAGS = -Wall -Wextra -Werror

CC = cc

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)
	@echo "Compiling: $<"

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(OBJS) $(LIBFT) -o $(NAME)

$(CHECKER): $(LIBFT) $(BONUS_OBJS)
	@$(CC) $(BONUS_OBJS) $(LIBFT) -o $(CHECKER)

bonus: checker

clean:
	@rm -rf $(OBJS) $(BONUS_OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME) $(CHECKER)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re libft bonus