/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:59:13 by mpendilh          #+#    #+#             */
/*   Updated: 2024/12/17 14:15:54 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	count_frame_icon(t_data *data)
{
	data->icon[0].frame++;
	if (data->icon[0].frame > 600)
	{
		data->icon[0].frame = 0;
		data->icon[0].counter++;
	}
	if (data->icon[0].counter > 4)
		data->icon[0].counter = 0;
}

void	count_frame_icon2(t_data *data)
{
	data->icon2[0].frame++;
	if (data->icon2[0].frame > 600)
	{
		data->icon2[0].frame = 0;
		data->icon2[0].counter++;
	}
	if (data->icon2[0].counter > 3)
		data->icon2[0].counter = 0;
}

static void	count_frame_easter_egg(t_data *data)
{
	data->easter_egg[0].frame++;
	if (data->easter_egg[0].frame > 400)
	{
		data->easter_egg[0].frame = 0;
		data->easter_egg[0].counter++;
	}
	if (data->easter_egg[0].counter > EASTER_EGG - 1)
		data->easter_egg[0].counter = 0;
}

void	count_frame_death(t_data *data)
{
	data->death[0].frame++;
	if (data->death[0].frame > 400)
	{
		data->death[0].frame = 0;
		data->death[0].counter++;
	}
	if (data->death[0].counter > DEATH - 1)
	{
		data->death[0].counter = 0;
		mlx_loop_end(data->window.mlx);
	}
}

void	count_all_frame(t_data *data)
{
	count_frame_easter_egg(data);
	count_frame_item(data);
	count_frame_button(data);
	count_frame_exit_close(data);
	count_frame_exit_open(data);
	count_frame_monster(data);
}
