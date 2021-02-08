# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/04 11:25:05 by zsidki            #+#    #+#              #
#    Updated: 2021/01/22 17:26:56 by zsidki           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all fclean clean re
NAME = cub3D
CC = gcc -g #-fsanitize=address
FLAGS = -Wall -Werror -Wextra -I /usr/local/include -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

SRC = 		main.c \
			ft_import_config/import_data_utils.c ft_import_config/import_data.c \
			ft_import_config/ft_atoi.c ft_import_config/ft_check_map.c ft_import_config/import_map.c \
			ft_import_config/import_res_color.c ft_import_config/import_texture.c \
			ft_rander/ft_rander_box.c ft_rander/ft_rander_map.c ft_rander/ft_rander_player.c \
			ft_keys/deal_key.c ft_update.c \
			ft_utils/utils.c ft_utils/ft_get.c\
			ft_ray_casting/ft_vertical.c ft_ray_casting/ft_horizontal.c \
			ft_ray_casting/ft_rays.c \
			my_pixel_put.c ft_keys/deal_keytwo.c \
			ft_renders/render_3d_utils.c \
			ft_renders/render_3d.c sprites.c screenbmb.c\

all: $(NAME)
$(NAME): 
	@$(CC) -I. $(FLAGS) get_next_line.a libft.a $(SRC) -o $(NAME)

clean: 
	@rm -rf $(NAME)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

push:
	@git add .
	@git commit -m "$(m)"
	@git push origin main
