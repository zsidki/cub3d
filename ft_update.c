/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 15:33:41 by zsidki            #+#    #+#             */
/*   Updated: 2021/02/08 15:33:45 by zsidki           ###   ########.fr       */
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
