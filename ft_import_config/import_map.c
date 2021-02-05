/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 11:29:04 by zsidki            #+#    #+#             */
/*   Updated: 2021/01/22 12:40:31 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		is_valid_in_map(char c)
{
	if (c != '2' && c != '1' && c != '0' && c != '\t' &&
			c != ' ' && !is_player(c))
		return (ft_perror("Invalid Map , You add non valid element in map\n"));
	return (1);
}

void			import_map(char *line)
{
	char *tmp;

	tmp = g_map.ptr;
	g_map.ptr = ft_strjoin(g_map.ptr, line);
	free(tmp);
	tmp = g_map.ptr;
	g_map.ptr = ft_strjoin(g_map.ptr, "\n");
	free(tmp);
}

static	void	get_tile(void)
{
	if (ft_strlen(g_map.ptr) < 4)
		ft_perror("No Map!!\n");
	g_tile = 32;
	g_tile_p = g_tile / 2;
}

static	void	fill_column(int i, char *line)
{
	int j;
	int len;

	len = (int)ft_strlen(line);
	j = -1;
	while (++j < g_map.w)
	{
		if (j >= len)
			g_map.map[i][j] = ' ';
		else if (is_valid_in_map(line[j]))
			g_map.map[i][j] = line[j];
		if (g_map.map[i][j] == '2')
			g_n_sp++;
		else if (is_player(g_map.map[i][j]))
			get_position_player(g_map.map[i][j], i, j);
	}
	g_map.map[i][j] = '\0';
}

void			fill_map(void)
{
	char	**line;
	int		i;

	get_tile();
	line = ft_split(g_map.ptr, '\n');
	g_map.map = malloc(sizeof(char *) * g_map.h);
	i = -1;
	while (++i < g_map.h)
	{
		g_map.map[i] = malloc(sizeof(char) * g_map.w + 1);
		fill_column(i, line[i]);
	}
	i = 0;
	while (line[i])
		free(line[i++]);
	free(line);
	check_map();
}
