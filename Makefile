# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/18 11:21:16 by irychkov          #+#    #+#              #
#    Updated: 2024/08/01 17:51:52 by irychkov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = main.c push.c swap.c rotate.c reverse_rotate.c fill_a.c free.c \
		init_info.c sort.c validation.c

OBJS = $(SRCS:.c=.o)

HEADERS = -I. -I$(LIBFT_DIR)

LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)/libft.a

CFLAGS = -Wall -Wextra -Werror

CC = cc

all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)
	@echo "Compiling: $<"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBFT) -o $(NAME)


clean:
	@rm -rf $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re libft