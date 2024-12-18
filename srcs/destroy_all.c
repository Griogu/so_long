/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:09:21 by mpendilh          #+#    #+#             */
/*   Updated: 2024/12/17 14:11:16 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static void	destroy_all3(t_data *data, int i)
{
	i = -1;
	while (++i < EASTER_EGG && data->easter_egg[i].img)
		mlx_destroy_image(data->window.mlx, data->easter_egg[i].img);
	i = -1;
	while (++i < DEATH && data->death[i].img)
		mlx_destroy_image(data->window.mlx, data->death[i].img);
	mlx_destroy_image(data->window.mlx, data->ground.img);
	mlx_destroy_window(data->window.mlx, data->window.win);
	mlx_destroy_display(data->window.mlx);
}

static void	destroy_all2(t_data *data, int i, int j)
{
	i = -1;
	while (++i < PLAYER_TEXTURES)
	{
		j = -1;
		while (++j < PLAYER_FRAME && data->sprite_p[i][j].img)
			mlx_destroy_image(data->window.mlx, data->sprite_p[i][j].img);
	}
	i = -1;
	while (++i < VELDRA_FRAME && data->veldra[i].img)
		mlx_destroy_image(data->window.mlx, data->veldra[i].img);
	i = -1;
	while (++i < MONSTER_TEXTURES && data->monster[i].img)
		mlx_destroy_image(data->window.mlx, data->monster[i].img);
	i = -1;
	while (++i < WATER_SPELL && data->water[i].img)
		mlx_destroy_image(data->window.mlx, data->water[i].img);
	i = -1;
	while (++i < WATER_ICON_NBR && data->icon[i].img)
		mlx_destroy_image(data->window.mlx, data->icon[i].img);
	i = -1;
	while (++i < FIRE_ICON_NBR && data->icon2[i].img)
		mlx_destroy_image(data->window.mlx, data->icon2[i].img);
	destroy_all3(data, i);
}

void	destroy_all(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < WALL_TEXTURES && data->wall[i].img)
		mlx_destroy_image(data->window.mlx, data->wall[i].img);
	i = -1;
	while (++i < EXIT_TEXTURES && data->exit[i].img)
		mlx_destroy_image(data->window.mlx, data->exit[i].img);
	i = -1;
	while (++i < ITEM_NBR)
	{
		j = -1;
		while (++j < ITEM_FRAME && data->item[i][j].img)
			mlx_destroy_image(data->window.mlx, data->item[i][j].img);
	}
	i = -1;
	while (++i < BUTTON_TEXTURES && data->button[i].img)
		mlx_destroy_image(data->window.mlx, data->button[i].img);
	i = -1;
	while (++i < FIRE_SPELL && data->fire[i].img)
		mlx_destroy_image(data->window.mlx, data->fire[i].img);
	destroy_all2(data, i, j);
}
