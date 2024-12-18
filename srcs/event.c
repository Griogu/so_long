/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:26:32 by mpendilh          #+#    #+#             */
/*   Updated: 2024/12/17 11:20:50 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static int	key_item(t_data *data)
{
	if (data->obj_utils.signal == 1)
		data->map[data->obj_utils.new_y[0]][data->obj_utils.new_x[0]] = '0';
	if (data->obj_utils.signal == 2)
		data->map[data->obj_utils.new_y[1]][data->obj_utils.new_x[0]] = '0';
	if (data->obj_utils.signal == 3)
		data->map[data->obj_utils.new_y[0]][data->obj_utils.new_x[1]] = '0';
	if (data->obj_utils.signal == 4)
		data->map[data->obj_utils.new_y[1]][data->obj_utils.new_x[1]] = '0';
	if (data->obj_utils.signal == 5)
		mlx_loop_end(data->window.mlx);
	return (0);
}

static int	key_down(int key, t_data *data)
{
	if (key == SDL_SCANCODE_ESCAPE)
		mlx_loop_end(data->window.mlx);
	if (key == SDL_SCANCODE_D && !data->water[0].is_attack
		&& !data->fire[0].is_attack)
		data->player.speed_x = data->player.speed_player;
	if (key == SDL_SCANCODE_A && !data->water[0].is_attack
		&& !data->fire[0].is_attack)
		data->player.speed_x = -data->player.speed_player;
	if (key == SDL_SCANCODE_W && !data->water[0].is_attack
		&& !data->fire[0].is_attack)
		data->player.speed_y = -data->player.speed_player;
	if (key == SDL_SCANCODE_S && !data->water[0].is_attack
		&& !data->fire[0].is_attack)
		data->player.speed_y = data->player.speed_player;
	if (key == SDL_SCANCODE_E)
		key_item(data);
	return (0);
}

static int	key_up(int key, t_data *data)
{
	if (key == SDL_SCANCODE_D || key == SDL_SCANCODE_A)
		data->player.speed_x = 0;
	if (key == SDL_SCANCODE_W || key == SDL_SCANCODE_S)
		data->player.speed_y = 0;
	return (0);
}

static int	window_hook(int event, t_data *data)
{
	if (event == 0)
		mlx_loop_end(data->window.mlx);
	return (0);
}

void	event(t_data *data)
{
	mlx_on_event(data->window.mlx, data->window.win,
		MLX_KEYDOWN, (void *)key_down, data);
	mlx_on_event(data->window.mlx, data->window.win,
		MLX_KEYUP, (void *)key_up, data);
	mlx_on_event(data->window.mlx, data->window.win,
		MLX_WINDOW_EVENT, (void *)window_hook, data);
	mlx_on_event(data->window.mlx, data->window.win,
		MLX_MOUSEDOWN, (void *)mouse_hook, data);
}
