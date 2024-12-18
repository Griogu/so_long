/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:01:37 by mpendilh          #+#    #+#             */
/*   Updated: 2024/12/11 18:07:49 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	exit_map(t_data *data)
{
	if (!data->item_nbr)
	{
		data->obj_utils.signal = 0;
		if (data->map[data->obj_utils.new_y[0]][data->obj_utils.new_x[0]] == 'E'
			|| data->map[data->obj_utils.new_y[1]]
			[data->obj_utils.new_x[0]] == 'E'
			|| data->map[data->obj_utils.new_y[0]]
			[data->obj_utils.new_x[1]] == 'E'
			|| data->map[data->obj_utils.new_y[1]]
			[data->obj_utils.new_x[1]] == 'E')
		{
			put_button(data);
			data->obj_utils.signal = 5;
			event(data);
		}
	}
}
