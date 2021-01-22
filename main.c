/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 11:02:29 by zsidki            #+#    #+#             */
/*   Updated: 2021/01/22 17:46:26 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



void    ft_putchar(char c)
{
	write(1, &c, 1);
}

// int Map[g_map.h][g_map.w]=
// {
// 	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
// 	{1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,1,1,1,0,0,0,0,1,1,0,0,0,0,1,1,1,1,0,1},
// 	{1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
// 	{1,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,0,1},
// 	{1,0,1,1,0,0,0,0,1,1,0,0,0,0,0,1,1,1,1,0,1},
// 	{1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,1,0,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1},
// 	{1,0,0,0,1,0,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1},
// 	{1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,1,1,1,1,0,1,1,1,0,1,1,1,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},

// };


/*int ft_checkwall(float x, float y, int i)
  {
  if (Map[(int)(x / g_tile)][(int)(y / g_tile)] == 1)
  return (1);
  return 0;
  }*/


int     main(int argc, char *argv[])
{
	get_args(argc, argv);
	g_cub.ptr = mlx_init();
	g_newline = 0;
	reset_elem_conf();
	import_data();
	int i;

	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	
	g_num_rays = g_cub.w;
	rays = (t_rays *)malloc(sizeof(t_rays) * g_num_rays);
	player.turnDirection = 0;
	player.walkDirection = 0;
	player.rotationAngle = ( -M_PI / 2);
	player.moveSpeed = 2.1;
	player.rotationSpeed = 1.5 * (M_PI / 180);


	
	g_win_ptr = mlx_new_window(g_cub.ptr, g_cub.w, g_cub.h, "cub3D");
	g_img_3d = mlx_new_image(g_cub.ptr, g_cub.w, g_cub.h);
	ft_update();
	mlx_hook(g_win_ptr, 2, 1L << 0, key_press, NULL); // listen to keybord 1L << 0
	mlx_hook(g_win_ptr, 3, 1L << 1, key_release, NULL);
	mlx_loop_hook(g_cub.ptr , ft_update, NULL);
	// mlx_hook(g_cub.win, 17, 0L, finalize, NULL); //button fquite (red x)
	// mlx_loop_hook(g_cub.ptr, update, NULL);
	mlx_loop(g_cub.ptr);
	return 0;
}
