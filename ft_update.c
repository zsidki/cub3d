/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 20:11:44 by zsidki            #+#    #+#             */
/*   Updated: 2020/12/09 20:43:48 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int     ft_update(void)
{
    mlx_clear_window(g_mlx_ptr, g_win_ptr);
	ft_render_map();
	ft_render_player();
	ft_castAllRays();

    return (0);
}