/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:29:42 by mpendilh          #+#    #+#             */
/*   Updated: 2024/12/16 10:17:36 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static void	get_movement3(t_data *data)
{
	if (data->player.speed_x < 0 && data->player.speed_y > 0)
	{
		player_frame(data, 6);
		mlx_put_image_to_window(data->window.mlx, data->window.win,
			data->sprite_p[6][data->sprite_p[6][0].counter].img,
			data->player.x - data->camera_x, data->player.y - data->camera_y);
	}
	if (data->player.speed_x < 0 && data->player.speed_y < 0)
	{
		player_frame(data, 7);
		mlx_put_image_to_window(data->window.mlx, data->window.win,
			data->sprite_p[7][data->sprite_p[7][0].counter].img,
			data->player.x - data->camera_x, data->player.y - data->camera_y);
	}
	if (data->player.speed_x > 0 && data->player.speed_y < 0)
	{
		player_frame(data, 8);
		mlx_put_image_to_window(data->window.mlx, data->window.win,
			data->sprite_p[8][data->sprite_p[8][0].counter].img,
			data->player.x - data->camera_x, data->player.y - data->camera_y);
	}
}

static void	get_movement2(t_data *data)
{
	if (data->player.speed_y < 0 && !data->player.speed_x)
	{
		player_frame(data, 3);
		mlx_put_image_to_window(data->window.mlx, data->window.win,
			data->sprite_p[3][data->sprite_p[3][0].counter].img,
			data->player.x - data->camera_x, data->player.y - data->camera_y);
	}
	if (data->player.speed_y > 0 && !data->player.speed_x)
	{
		player_frame(data, 4);
		mlx_put_image_to_window(data->window.mlx, data->window.win,
			data->sprite_p[4][data->sprite_p[4][0].counter].img,
			data->player.x - data->camera_x, data->player.y - data->camera_y);
	}
	if (data->player.speed_x > 0 && data->player.speed_y > 0)
	{
		player_frame(data, 5);
		mlx_put_image_to_window(data->window.mlx, data->window.win,
			data->sprite_p[5][data->sprite_p[5][0].counter].img,
			data->player.x - data->camera_x, data->player.y - data->camera_y);
	}
	get_movement3(data);
}

static void	get_movement(t_data *data)
{
	if (!data->player.speed_x && !data->player.speed_y)
	{
		player_frame(data, 0);
		mlx_put_image_to_window(data->window.mlx, data->window.win,
			data->sprite_p[0][data->sprite_p[0][0].counter].img,
			data->player.x - data->camera_x, data->player.y - data->camera_y);
	}
	if (data->player.speed_x > 0 && !data->player.speed_y)
	{
		player_frame(data, 1);
		mlx_put_image_to_window(data->window.mlx, data->window.win,
			data->sprite_p[1][data->sprite_p[1][0].counter].img,
			data->player.x - data->camera_x, data->player.y - data->camera_y);
	}
	if (data->player.speed_x < 0 && !data->player.speed_y)
	{
		player_frame(data, 2);
		mlx_put_image_to_window(data->window.mlx, data->window.win,
			data->sprite_p[2][data->sprite_p[2][0].counter].img,
			data->player.x - data->camera_x, data->player.y - data->camera_y);
	}
	get_movement2(data);
}

static void	move_counter(t_data *data)
{
	data->player.move_counter += ABS(data->player.speed_x);
	data->player.move_counter += ABS(data->player.speed_y);
	if (data->player.move_counter > 64.0f)
	{
		data->player.move_counter = 0;
		data->player.move_print++;
	}
}

void	put_player_position(t_data *data)
{
	data->camera_x = data->player.x - 32 - 1920.0f / 2;
	data->camera_y = data->player.y - 32 - 1080.0f / 2;
	get_item(data);
	exit_map(data);
	data->player.move = ft_strjoin("MOVE : ", ft_itoa(data->player.move_print));
	mlx_set_font_scale(data->window.mlx, data->window.win,
		"textures/font/font.ttf", 20);
	mlx_string_put(data->window.mlx, data->window.win,
		data->player.x - 45 - data->camera_x, 0 - data->camera_y,
		0xFFFFFFFF, data->player.move);
	free(data->player.move);
	put_veldra(data);
	if (collision(data))
	{
		get_movement(data);
		return ;
	}
	move_counter(data);
	data->player.x += data->player.speed_x;
	data->player.y += data->player.speed_y;
	get_movement(data);
}
