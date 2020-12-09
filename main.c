/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 11:02:29 by zsidki            #+#    #+#             */
/*   Updated: 2020/12/04 19:09:03 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



void    ft_putchar(char c)
{
	write(1, &c, 1);
}

int Map[MAPHEIGHT][MAPWIDTH]=
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1},
	{1,0,1,1,1,0,0,0,0,1,1,0,0,0,0,1,1,1,1,0,1},
	{1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
	{1,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,0,1},
	{1,0,1,1,0,0,0,0,1,1,0,0,0,0,0,1,1,1,1,0,1},
	{1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,1,0,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1},
	{1,0,0,0,1,0,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,1,1,1,1,0,1,1,1,0,1,1,1,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},

};


// void    ft_update()
// {
//     player.rotationAngle += player.turnDirection *  player.rotationSpeed;
//     player.moveStep = player.turnDirection *  player.rotationSpeed;
//     player.x += cos(player.rotationAngle) *  player.moveStep;
//     player.y += sin(player.rotationAngle) *  player.moveStep;
// }


// void    my_pixel_put(void *img, int x, int y, int color)
// {
//     int bits_per_pixel;
//     int size_line;
//     int endian;
//     int *var;

//     var = (int*)mlx_get_data_addr(img, &bits_per_pixel, &size_line, &endian);
//     if (x < MAPWIDTH && x >= 0 && y < MAPHEIGHT && y >= 0)
//     var[x + MAPWIDTH * y] = color;
// }
/*int ft_checkwall(float x, float y, int i)
  {
  if (Map[(int)(x / TILE_SIZE)][(int)(y / TILE_SIZE)] == 1)
  return (1);
  return 0;
  }*/


int     main()
{
	int i;
	//int j;
	//int color;

	//int key;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	
	g_num_rays = SCREENWIDTH;
	rays = (t_rays *)malloc(sizeof(t_rays) * g_num_rays);
	player.x = SCREENWIDTH / 2;
	player.y = SCREENHEIGHT / 2;
	player.turnDirection = 0;
	player.walkDirection = 0;
	player.rotationAngle = (M_PI / 2);
	player.moveSpeed = 5.0;
	player.rotationSpeed = 2 * (M_PI / 180);
	


	g_mlx_ptr = mlx_init();
	g_win_ptr = mlx_new_window(g_mlx_ptr, SCREENWIDTH, SCREENHEIGHT, "Cub3d");
	g_img = mlx_new_image(g_mlx_ptr,SCREENWIDTH,SCREENHEIGHT);
	//int *data = (int*)mlx_get_data_addr(g_img,&i,&i,&i);
	//mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
	ft_render_box(x,y);
	ft_render_player();
	ft_castAllRays();

	mlx_loop_hook(g_mlx_ptr, ft_render_map, NULL);
	//ft_render_box(x,y);
	//ft_render_map();

	//printf("x = %f\n", player.x);

	mlx_key_hook(g_win_ptr, deal_key, (void *)0);
	mlx_put_image_to_window(g_mlx_ptr,g_win_ptr,g_img,0,0);
	mlx_loop(g_mlx_ptr);
	return 0;
}
