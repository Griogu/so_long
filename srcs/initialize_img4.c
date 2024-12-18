/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_img4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:45:15 by mpendilh          #+#    #+#             */
/*   Updated: 2024/12/17 14:33:00 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static char	**spell_2_utils(void)
{
	static char	*fire[FIRE_SPELL] = {
		"textures/spell/fire_spell1.png", "textures/spell/fire_spell2.png",
		"textures/spell/fire_spell3.png", "textures/spell/fire_spell4.png",
		"textures/spell/fire_spell5.png", "textures/spell/fire_spell6.png",
		"textures/spell/fire_spell7.png", "textures/spell/fire_spell8.png",
		"textures/spell/fire_spell9.png", "textures/spell/fire_spell10.png",
		"textures/spell/fire_spell11.png", "textures/spell/fire_spell12.png",
		"textures/spell/fire_spell13.png", "textures/spell/fire_spell14.png",
		"textures/spell/fire_spell15.png", "textures/spell/fire_spell16.png",
		"textures/spell/fire_spell17.png", "textures/spell/fire_spell18.png",
		"textures/spell/fire_spell19.png", "textures/spell/fire_spell20.png",
		"textures/spell/fire_spell21.png", "textures/spell/fire_spell22.png",
		"textures/spell/fire_spell23.png", "textures/spell/fire_spell24.png",
		"textures/spell/fire_spell25.png", "textures/spell/fire_spell26.png",
		"textures/spell/fire_spell27.png", "textures/spell/fire_spell28.png",
	};

	return (fire);
}

void	initialize_spell2(t_data *data)
{
	int		i;
	char	**fire;

	i = 0;
	fire = spell_2_utils();
	while (i < FIRE_SPELL)
	{
		data->fire[i].fd = open(fire[i], O_RDONLY);
		if (data->fire[i].fd == -1)
			error_textures(data);
		data->fire[i].img = mlx_png_file_to_image(data->window.mlx,
				fire[i], &data->fire[i].width, &data->fire[i].height);
		close(data->fire[i].fd);
		i++;
	}
}

void	initialize_spell_icon(t_data *data)
{
	int			i;
	static char	*icon[WATER_ICON_NBR] = {
		"textures/icons/icon1.png", "textures/icons/icon2.png",
		"textures/icons/icon3.png", "textures/icons/icon4.png",
		"textures/icons/icon5.png"
	};

	i = 0;
	while (i < WATER_ICON_NBR)
	{
		data->icon[i].fd = open(icon[i], O_RDONLY);
		if (data->icon[i].fd == -1)
			error_textures(data);
		data->icon[i].img = mlx_png_file_to_image(data->window.mlx,
				icon[i], &data->icon[i].width, &data->icon[i].height);
		close(data->icon[i].fd);
		i++;
	}
}

void	initialize_spell_icon2(t_data *data)
{
	int			i;
	static char	*icon2[FIRE_ICON_NBR] = {
		"textures/icons/icon_2_1.png", "textures/icons/icon_2_2.png",
		"textures/icons/icon_2_3.png", "textures/icons/icon_2_4.png"
	};

	i = 0;
	while (i < FIRE_ICON_NBR)
	{
		data->icon2[i].fd = open(icon2[i], O_RDONLY);
		if (data->icon2[i].fd == -1)
			error_textures(data);
		data->icon2[i].img = mlx_png_file_to_image(data->window.mlx,
				icon2[i], &data->icon2[i].width, &data->icon2[i].height);
		close(data->icon2[i].fd);
		i++;
	}
}

void	initialize_easter_egg(t_data *data)
{
	int			i;
	static char	*easter_egg[EASTER_EGG] = {
		"textures/item/easter_egg/easter_egg1.png",
		"textures/item/easter_egg/easter_egg2.png",
		"textures/item/easter_egg/easter_egg3.png",
		"textures/item/easter_egg/easter_egg2.png"
	};

	i = 0;
	while (i < EASTER_EGG)
	{
		data->easter_egg[i].fd = open(easter_egg[i], O_RDONLY);
		if (data->easter_egg[i].fd == -1)
			error_textures(data);
		data->easter_egg[i].img = mlx_png_file_to_image(data->window.mlx,
				easter_egg[i], &data->easter_egg[i].width,
				&data->easter_egg[i].height);
		close(data->easter_egg[i].fd);
		i++;
	}
}
