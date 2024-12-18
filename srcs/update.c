/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:52:03 by mpendilh          #+#    #+#             */
/*   Updated: 2024/12/17 13:37:33 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	update(t_data *data)
{
	count_all_frame(data);
	event(data);
	mlx_clear_window(data->window.mlx, data->window.win);
	put_image(data);
	put_monster(data);
	put_icon(data);
	put_icons2(data);
	if (!data->player.is_dead)
		put_player_position(data);
	else
		death_animation(data);
	if (data->water[0].is_attack)
	{
		monster_spell_collision(data);
		water_attack(data);
		data->icon[0].is_attack = true;
	}
	if (data->fire[0].is_attack)
	{
		monster_spell_collision2(data);
		fire_attack(data);
		data->icon[0].is_attack = true;
	}
}
