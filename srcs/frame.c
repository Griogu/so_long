/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:13:46 by mpendilh          #+#    #+#             */
/*   Updated: 2024/12/15 13:28:29 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	count_frame_exit_close(t_data *data)
{
	data->exit[0].frame++;
	if (!data->exit[0].counter && data->exit[0].frame > 1700)
	{
		data->exit[0].frame = 0;
		data->exit[0].counter++;
	}
	else if (data->exit[0].counter && data->exit[0].frame > 150)
	{
		data->exit[0].frame = 0;
		data->exit[0].counter++;
	}
	if (data->exit[0].counter > EXIT_TEXTURES - 3)
		data->exit[0].counter = 0;
}

void	count_frame_exit_open(t_data *data)
{
	data->exit[1].frame++;
	if (data->exit[1].counter >= 2 && data->exit[1].frame > 1700)
	{
		data->exit[1].frame = 0;
		data->exit[1].counter++;
	}
	else if (data->exit[1].counter == 3 && data->exit[1].frame > 150)
	{
		data->exit[1].frame = 0;
		data->exit[1].counter++;
	}
	if (data->exit[1].counter > EXIT_TEXTURES - 1)
		data->exit[1].counter = 2;
}

void	count_frame_item(t_data *data)
{
	data->item[0][0].frame++;
	if (data->item[0][0].frame > 400)
	{
		data->item[0][0].frame = 0;
		data->item[0][0].counter++;
	}
	if (data->item[0][0].counter > ITEM_FRAME - 1)
		data->item[0][0].counter = 0;
}

void	count_frame_button(t_data *data)
{
	data->button[0].frame++;
	if (data->button[0].frame > 300)
	{
		data->button[0].frame = 0;
		data->button[0].counter++;
	}
	if (data->button[0].counter > BUTTON_TEXTURES - 1)
		data->button[0].counter = 0;
}

void	count_frame_monster(t_data *data)
{
	data->monster[0].frame++;
	if (data->monster[0].frame > 300)
	{
		data->monster[0].frame = 0;
		data->monster[0].counter++;
	}
	if (data->monster[0].counter > MONSTER_TEXTURES - 1)
		data->monster[0].counter = 0;
}
