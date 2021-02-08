/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 15:43:32 by zsidki            #+#    #+#             */
/*   Updated: 2021/02/08 17:05:30 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	g_dst_proj_pl;

static	int		get_offset_x(int ray_n)
{
	if (g_rays[ray_n].was_hit_vertical)
		return ((int)g_rays[ray_n].wall_hit.y % (int)g_tile);
	return ((int)g_rays[ray_n].wall_hit.x % (int)g_tile);
}

static	void	render_sprites(void)
{
	float	sp_width;
	float	corr_sp_dst;
	float	dst_prj_plane;
	int		i;

	i = 0;
	sort_sprites();
	while (i < g_index_sp)
	{
		dst_prj_plane = (g_cub.w / 2) / tan((FOV_ANGLE) / 2);
		corr_sp_dst = g_sprites[i].dist *
			cos(g_sprites[i].angle - g_player.rotationangle);
		
		sp_width = (g_tile / corr_sp_dst) * dst_prj_plane;
		// printf("%d %f\n", g_text_sp.w, dst_prj_plane);
		if (sp_width <= (g_cub.w * 1.5)) {
			create_strip_sprite((float[]){g_sprites[i].num_ray - (sp_width / 2),
					(g_cub.h / 2) - (sp_width / 2), sp_width, sp_width}, i);

		}
		i++;
	}
}

void			render3d(void)
{
	int		i;
	float	strip_h;
	float	corr_wal_dst;

	g_img_3d = mlx_new_image(g_cub.ptr, g_cub.w, g_cub.h);
	g_dst_proj_pl = (g_cub.w / 2) / tan((FOV_ANGLE) / 2);
	i = -1;
	while (++i < g_num_rays)
	{
		corr_wal_dst = g_rays[i].dist * cos(g_rays[i].angle - g_player.rotationangle);
		strip_h = (g_tile / corr_wal_dst) * g_dst_proj_pl;
		create_strip_wall((float[]){i , (g_cub.h / 2) -
				(strip_h / 2), strip_h}, get_offset_x(i), i);
		create_strip_height((float[]){i , 1, (g_cub.h - strip_h) / 2 }, g_ceil_color);
		create_strip_height((float[]){i , strip_h +
			((g_cub.h - strip_h) / 2), (g_cub.h - strip_h) / 2},
				g_floor_color);
	}
	render_sprites();
	if (g_screenshot)
		ft_screenshot();
	mlx_put_image_to_window(g_cub.ptr, g_win_ptr, g_img_3d, 0, 0);
	mlx_destroy_image(g_cub.ptr, g_img_3d);
}
