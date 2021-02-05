/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 20:11:44 by zsidki            #+#    #+#             */
/*   Updated: 2021/02/02 11:10:04 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_update(void)
{
	int i;

	i = 0;
	while (i < 7)
	{
		if (g_keys[i])
			deal_key(g_keys[i]);
		i++;
	}
	clear_sprites();
	ft_castallrays();
	render3d();
	return (0);
}
