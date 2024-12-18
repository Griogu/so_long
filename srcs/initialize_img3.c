/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_img3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:03:30 by mpendilh          #+#    #+#             */
/*   Updated: 2024/12/17 10:28:55 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static char	**player_utils(void)
{
	static char	*player[PLAYER_TEXTURES * PLAYER_FRAME] = {
		"textures/player/player1.png", "textures/player/player2.png",
		"textures/player/player3.png", "textures/player/player2.png",
		"textures/player/player4.png", "textures/player/player5.png",
		"textures/player/player6.png", "textures/player/player5.png",
		"textures/player/player7.png", "textures/player/player8.png",
		"textures/player/player9.png", "textures/player/player8.png",
		"textures/player/player10.png", "textures/player/player11.png",
		"textures/player/player12.png", "textures/player/player11.png",
		"textures/player/player13.png", "textures/player/player14.png",
		"textures/player/player15.png", "textures/player/player14.png",
		"textures/player/player16.png", "textures/player/player17.png",
		"textures/player/player18.png", "textures/player/player17.png",
		"textures/player/player19.png", "textures/player/player20.png",
		"textures/player/player21.png", "textures/player/player20.png",
		"textures/player/player22.png", "textures/player/player23.png",
		"textures/player/player24.png", "textures/player/player23.png",
		"textures/player/player25.png", "textures/player/player26.png",
		"textures/player/player27.png", "textures/player/player26.png",
	};

	return (player);
}

void	initialize_player(t_data *data)
{
	int		i;
	int		j;
	int		ctr_p;
	char	**player;

	i = -1;
	ctr_p = 0;
	player = player_utils();
	while (++i < PLAYER_TEXTURES)
	{
		j = -1;
		while (++j < PLAYER_FRAME)
		{
			data->sprite_p[i][j].fd = open(player[i], O_RDONLY);
			if (data->sprite_p[i][j].fd == -1)
				error_textures(data);
			data->sprite_p[i][j].img = mlx_png_file_to_image(data->window.mlx,
					player[ctr_p], &data->sprite_p[i][j].width,
					&data->sprite_p[i][j].height);
			close(data->sprite_p[i][j].fd);
			ctr_p++;
		}
	}
}

void	initialize_veldra(t_data *data)
{
	int			i;
	static char	*veldra[VELDRA_FRAME] = {
		"textures/veldra/veldra1.png", "textures/veldra/veldra2.png",
		"textures/veldra/veldra3.png", "textures/veldra/veldra4.png",
		"textures/veldra/veldra5.png", "textures/veldra/veldra6.png",
		"textures/veldra/veldra7.png", "textures/veldra/veldra8.png",
	};

	i = 0;
	while (i < VELDRA_FRAME)
	{
		data->veldra[i].fd = open(veldra[i], O_RDONLY);
		if (data->veldra[i].fd == -1)
			error_textures(data);
		data->veldra[i].img = mlx_png_file_to_image(data->window.mlx,
				veldra[i], &data->veldra[i].width, &data->veldra[i].height);
		close(data->veldra[i].fd);
		i++;
	}
}

void	initialize_monster(t_data *data)
{
	int			i;
	static char	*monster[MONSTER_TEXTURES] = {
		"textures/monster/monster1.png", "textures/monster/monster2.png"
	};

	i = 0;
	while (i < MONSTER_TEXTURES)
	{
		data->monster[i].fd = open(monster[i], O_RDONLY);
		if (data->monster[i].fd == -1)
			error_textures(data);
		data->monster[i].img = mlx_png_file_to_image(data->window.mlx,
				monster[i], &data->monster[i].width, &data->monster[i].height);
		close(data->monster[i].fd);
		i++;
	}
}

void	initialize_spell(t_data *data)
{
	int			i;
	static char	*spell[WATER_SPELL] = {
		"textures/spell/water_spell1.png", "textures/spell/water_spell2.png",
		"textures/spell/water_spell3.png", "textures/spell/water_spell4.png",
		"textures/spell/water_spell5.png", "textures/spell/water_spell6.png"
	};

	i = 0;
	while (i < WATER_SPELL)
	{
		data->water[i].fd = open(spell[i], O_RDONLY);
		if (data->water[i].fd == -1)
			error_textures(data);
		data->water[i].img = mlx_png_file_to_image(data->window.mlx,
				spell[i], &data->water[i].width, &data->water[i].height);
		close(data->water[i].fd);
		i++;
	}
}
