/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:53:50 by mpendilh          #+#    #+#             */
/*   Updated: 2024/12/14 12:32:58 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static void	get_player_position(t_data *data)
{
	bool	loop;

	loop = false;
	while (!loop)
	{
		data->player.x = 0;
		while (data->map[(int)data->player.y][(int)data->player.x] != 'P'
			&& data->map[(int)data->player.y][(int)data->player.x])
			data->player.x++;
		if (data->map[(int)data->player.y][(int)data->player.x] == 'P')
			loop = true;
		else
			data->player.y++;
	}
}

static void	flood_fill(char **map, int x, int y, t_data *data)
{
	if (map[y][x] == 'X' || map[y][x] == '1')
		return ;
	if (map[y][x] == 'C')
		data->item_nbr--;
	else if (map[y][x] == 'E')
		data->exit_nbr--;
	map[y][x] = 'X';
	flood_fill(map, x + 1, y, data);
	flood_fill(map, x, y + 1, data);
	flood_fill(map, x - 1, y, data);
	flood_fill(map, x, y - 1, data);
}

void	check_all_map(t_data *data)
{
	get_player_position(data);
	flood_fill(data->cpy_map, data->player.x, data->player.y, data);
	free_tab(data->cpy_map);
	if (data->exit_nbr || data->item_nbr)
	{
		free_tab(data->map);
		error_management(MAP_NOT_VALID, data);
	}
}
