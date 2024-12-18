/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_img2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:59:04 by mpendilh          #+#    #+#             */
/*   Updated: 2024/12/17 11:30:01 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static void	initialize_ground(t_data *data)
{
	static char	*ground[1] = {
		"textures/ground/ground1.png"
	};

	data->ground.fd = open(ground[0], O_RDONLY);
	if (data->ground.fd == -1)
		error_textures(data);
	data->ground.img = mlx_png_file_to_image(data->window.mlx,
			ground[0], &data->ground.width, &data->ground.height);
	close(data->ground.fd);
}

static void	initialize_ground_2(t_data *data)
{
	static char	*ground[1] = {
		"textures/ground/ground2.png"
	};

	data->ground.fd = open(ground[0], O_RDONLY);
	if (data->ground.fd == -1)
		error_textures(data);
	data->ground.img = mlx_png_file_to_image(data->window.mlx,
			ground[0], &data->ground.width, &data->ground.height);
	close(data->ground.fd);
}

static void	initialize_wall_2(t_data *data)
{
	int			i;
	static char	*wall[WALL_TEXTURES] = {
		"textures/wall_2/wall_nw_2.png", "textures/wall_2/wall_nw_02_2.png",
		"textures/wall_2/wall_n_2.png", "textures/wall_2/wall_ne_2.png",
		"textures/wall_2/wall_ne_02_2.png", "textures/wall_2/wall_w_2.png",
		"textures/wall_2/wall_sw_2.png", "textures/wall_2/wall_sw_02_2.png",
		"textures/wall_2/wall_s_2.png", "textures/wall_2/wall_e_2.png",
		"textures/wall_2/wall_se_2.png", "textures/wall_2/wall_se_02_2.png",
		"textures/wall_2/wall_center_2.png", "textures/wall_2/stalagmite_2.png",
		"textures/wall_2/wall_w_02_2.png", "textures/wall_2/wall_w_03_2.png",
		"textures/wall_2/wall_e_02_2.png", "textures/wall_2/wall_e_03_2.png"
	};

	i = 0;
	while (i < WALL_TEXTURES)
	{
		data->wall[i].fd = open(wall[i], O_RDONLY);
		if (data->wall[i].fd == -1)
			error_textures(data);
		data->wall[i].img = mlx_png_file_to_image(data->window.mlx,
				wall[i], &data->wall[i].width, &data->wall[i].height);
		close(data->wall[i].fd);
		i++;
	}
}

static void	initialize_exit_2(t_data *data)
{
	int			i;
	static char	*exit[EXIT_TEXTURES] = {
		"textures/exit_2/exit1.png", "textures/exit_2/exit2.png",
		"textures/exit_2/exit3.png", "textures/exit_2/exit4.png"
	};

	i = 0;
	while (i < EXIT_TEXTURES)
	{
		data->exit[i].fd = open(exit[i], O_RDONLY);
		if (data->exit[i].fd == -1)
			error_textures(data);
		data->exit[i].img = mlx_png_file_to_image(data->window.mlx,
				exit[i], &data->exit[i].width,
				&data->exit[i].height);
		close(data->exit[i].fd);
		i++;
	}
}

void	initialize_textures(t_data *data)
{
	if (data->random)
	{
		initialize_collectible(data);
		initialize_wall(data);
		initialize_exit(data);
		initialize_ground(data);
	}
	else
	{
		initialize_easter_egg(data);
		initialize_wall_2(data);
		initialize_exit_2(data);
		initialize_ground_2(data);
	}
	initialize_death(data);
	initialize_spell(data);
	initialize_spell2(data);
	initialize_spell_icon(data);
	initialize_spell_icon2(data);
	initialize_monster(data);
	initialize_veldra(data);
	initialize_player(data);
	initialize_button(data);
}
