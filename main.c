/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 15:30:46 by zsidki            #+#    #+#             */
/*   Updated: 2021/02/08 16:55:14 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

int			tets(void *p)
{
	p = NULL;
	exit(0);
}

int			main(int argc, char *argv[])
{
	int i;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	get_args(argc, argv);
	g_cub.ptr = mlx_init();
	g_newline = 0;
	reset_elem_conf();
	import_data();
	mainmain();
	ft_update();
	mlx_hook(g_win_ptr, 2, 1L << 0, key_press, NULL);
	mlx_hook(g_win_ptr, 3, 1L << 1, key_release, NULL);
	mlx_hook(g_win_ptr, 17, 0L, finalize, NULL);
	mlx_loop_hook(g_cub.ptr, ft_update, NULL);
	mlx_loop(g_cub.ptr);
	return (0);
}

int			mainmain(void)
{
	g_num_rays = g_cub.w;
	g_index_sp = 0;
	g_rays = (t_rays *)malloc(sizeof(t_rays) * g_num_rays);
	g_sprites = (t_sprite *)(malloc((1 * g_n_sp) * sizeof(t_sprite)));
	g_player.turndirection = 0;
	g_player.walkdirection = 0;
	g_player.rotationangle = (-M_PI / 2);
	g_player.movespeed = 2.1;
	g_player.rotationspeed = 1.5 * (M_PI / 180);
	g_win_ptr = mlx_new_window(g_cub.ptr, g_cub.w, g_cub.h, "cub3D");
	g_img_3d = mlx_new_image(g_cub.ptr, g_cub.w, g_cub.h);
	return (0);
}
