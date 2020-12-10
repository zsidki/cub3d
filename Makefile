# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/04 11:25:05 by zsidki            #+#    #+#              #
#    Updated: 2020/12/10 12:28:37 by zsidki           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all fclean clean re
NAME = cub3D
CC = gcc -g -fsanitize=address
FLAGS = -Wall -Werror -Wextra -I /usr/local/include -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

SRC = 		main.c ft_rander_box.c ft_rander_map.c my_pixel_put.c\
			ft_rander_player.c deal_key.c  ft_rays.c ft_update.c\


all: $(NAME)
$(NAME): 
	@$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean: 
	@rm -rf $(NAME)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

push:
	@git add .
	@git commit -m "$(m)"
	@git push origin main