/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:31:48 by mpendilh          #+#    #+#             */
/*   Updated: 2024/12/17 08:33:09 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	water_spell_frame(t_data *data)
{
	data->water[0].frame++;
	if (data->water[0].frame > 200)
	{
		data->water[0].frame = 0;
		data->water[0].counter++;
	}
	if (data->water[0].counter > WATER_SPELL - 1)
	{
		data->water[0].counter = 0;
		data->water[0].is_attack = false;
	}
}

void	fire_spell_frame(t_data *data)
{
	data->fire[0].frame++;
	if (data->fire[0].frame > 50)
	{
		data->fire[0].frame = 0;
		data->fire[0].counter++;
	}
	if (data->fire[0].counter > FIRE_SPELL - 1)
	{
		data->fire[0].counter = 0;
		data->fire[0].is_attack = false;
	}
}

void	player_frame(t_data *data, int i)
{
	data->sprite_p[i][0].frame++;
	if (data->sprite_p[i][0].frame > 300)
	{
		data->sprite_p[i][0].frame = 0;
		data->sprite_p[i][0].counter++;
	}
	if (data->sprite_p[i][0].counter > PLAYER_FRAME - 1)
		data->sprite_p[i][0].counter = 0;
}
