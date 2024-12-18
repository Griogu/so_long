/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:35:08 by mpendilh          #+#    #+#             */
/*   Updated: 2024/12/17 09:54:08 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static int	monster_position(t_data *data, int new_x[2], int new_y[2])
{
	if (data->fire[0].counter > 10 && data->fire[0].counter < 20
		&& (data->obj_utils.new_x[0] == new_x[0]
			|| data->obj_utils.new_x[0] == new_x[1]
			|| data->obj_utils.new_x[1] == new_x[0]
			|| data->obj_utils.new_x[1] == new_x[1])
		&& (data->obj_utils.new_y[0] == new_y[0]
			|| data->obj_utils.new_y[0] == new_y[1]
			|| data->obj_utils.new_y[1] == new_y[0]
			|| data->obj_utils.new_y[1] == new_y[1]))
		return (1);
	return (0);
}

void	monster_spell_collision2(t_data *data)
{
	int	i;
	int	new_x[2];
	int	new_y[2];

	i = 0;
	while (i < data->monster_nbr)
	{
		new_x[0] = (int)(data->monster2[i].x / 64);
		new_x[1] = (int)ceilf(data->monster2[i].x / 64);
		new_y[0] = (int)(data->monster2[i].y / 64);
		new_y[1] = (int)ceilf(data->monster2[i].y / 64);
		if (monster_position(data, new_x, new_y))
			data->map[data->monster2[i].y_save][data->monster2[i].x_save] = '0';
		i++;
	}
}
