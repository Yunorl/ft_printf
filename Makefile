# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dnahon <dnahon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/06 17:04:07 by dnahon            #+#    #+#              #
#    Updated: 2025/05/13 14:58:54 by dnahon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
SRC = 	ft_printf.c ft_printf_utils.c ft_printnbr.c \
		ft_printnbrui.c ft_putnbr_base.c ft_printptr.c

OBJ = $(SRC:.c=.o)

# Color codes
GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
BLUE = \033[0;34m
PURPLE = \033[0;35m
CYAN = \033[0;36m
NC = \033[0m # No Color

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(GREEN)Building $(NC)$(NAME)"
	@$(AR) $(NAME) $(OBJ)

%.o: %.c ft_printf.h
	@echo "$(CYAN)Compiling $(NC)$<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(CYAN)Cleaning object files"
	@$(RM) $(OBJ)

fclean: clean
	@echo "$(CYAN)Cleaning $(NC)$(NAME)"
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re