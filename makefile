# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/15 16:32:19 by aasselma          #+#    #+#              #
#    Updated: 2023/02/17 18:26:57 by aasselma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
B_NAME = So_long

SRC = check_map.c check_path.c \
		creat_window.c draw_map.c \
		ft_free.c moves_in_map.c \
		so_long.c so_long_utils.c \
		get_map.c \

BONUS = check_map_bonus.c check_path_bonus.c \
		creat_window_bonus.c draw_map_bonus.c \
		ft_free_bonus.c moves_in_map_bonus.c \
		so_long_bonus.c so_long_utils_bonus.c \
		animated_bonus.c animated_enemy_bonus.c \
		moving_enemy_bonus.c ft_itoa_bonus.c \
		animated_lose_bonus.c calculate_moves_bonus.c \
		get_map_bonus.c \

BONUS_OBJ = $(BONUS:.c=.o)

OBJ = $(SRC:.c=.o)

Dependecies = -lmlx -framework OpenGL -framework AppKit

utils = ./GNL/get_next_line.c ./GNL/get_next_line_utils.c

PRINTF_LIB = ./ft_printf/ft_printf.c ./ft_printf/ft_putnbr2.c\
	  ./ft_printf/ft_putchar.c ./ft_printf/ft_putnbr.c \
	  ./ft_printf/ft_putnbr_base.c ./ft_printf/ft_putstr.c ./ft_printf/ft_putadrs_base.c

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(Dependecies) $(PRINTF_LIB) $(utils) -o $(NAME)

all: $(NAME)

clean:
	@$(RM) $(OBJ) $(BONUS_OBJ)
	@echo "<<<<all files are deleted>>>>"

fclean: clean
	@$(RM) $(NAME)

re:	fclean all

$(B_NAME) : $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(Dependecies) $(PRINTF_LIB) $(utils) -o $(B_NAME)

bonus: $(B_NAME)
