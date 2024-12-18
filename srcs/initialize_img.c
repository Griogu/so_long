/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 09:54:33 by mpendilh          #+#    #+#             */
/*   Updated: 2024/12/14 13:15:20 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	initialize_button(t_data *data)
{
	int			i;
	static char	*button[BUTTON_TEXTURES] = {
		"textures/button/button1.png", "textures/button/button2.png"
	};

	i = 0;
	while (i < BUTTON_TEXTURES)
	{
		data->button[i].fd = open(button[i], O_RDONLY);
		if (data->button[i].fd == -1)
			error_textures(data);
		data->button[i].img = mlx_png_file_to_image(data->window.mlx,
				button[i], &data->button[i].width, &data->button[i].height);
		close(data->button[i].fd);
		i++;
	}
}

void	initialize_exit(t_data *data)
{
	int			i;
	static char	*exit[EXIT_TEXTURES] = {
		"textures/exit/exit1.png", "textures/exit/exit2.png",
		"textures/exit/exit3.png", "textures/exit/exit4.png"
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

void	initialize_wall(t_data *data)
{
	int			i;
	static char	*wall[WALL_TEXTURES] = {
		"textures/wall/wall_nw.png", "textures/wall/wall_nw_02.png",
		"textures/wall/wall_n.png", "textures/wall/wall_ne.png",
		"textures/wall/wall_ne_02.png", "textures/wall/wall_w.png",
		"textures/wall/wall_sw.png", "textures/wall/wall_sw_02.png",
		"textures/wall/wall_s.png", "textures/wall/wall_e.png",
		"textures/wall/wall_se.png", "textures/wall/wall_se_02.png",
		"textures/wall/wall_center.png", "textures/wall/stalagmite.png",
		"textures/wall/wall_w_02.png", "textures/wall/wall_w_03.png",
		"textures/wall/wall_e_02.png", "textures/wall/wall_e_03.png"
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

static char	**item_utils(void)
{
	static char	*item[ITEM_NBR * ITEM_FRAME] = {
		"textures/item/Purple/purple1.png", "textures/item/Purple/purple2.png",
		"textures/item/Purple/purple3.png", "textures/item/Purple/purple4.png",
		"textures/item/Blue/blue1.png", "textures/item/Blue/blue2.png",
		"textures/item/Blue/blue3.png", "textures/item/Blue/blue4.png",
		"textures/item/Green/green1.png", "textures/item/Green/green2.png",
		"textures/item/Green/green3.png", "textures/item/Green/green4.png",
		"textures/item/Pink/pink1.png", "textures/item/Pink/pink2.png",
		"textures/item/Pink/pink3.png", "textures/item/Pink/pink4.png",
		"textures/item/Red/red1.png", "textures/item/Red/red2.png",
		"textures/item/Red/red3.png", "textures/item/Red/red4.png"
	};

	return (item);
}

void	initialize_collectible(t_data *data)
{
	int		i;
	int		j;
	int		ctr_item;
	char	**item;

	item = item_utils();
	i = -1;
	ctr_item = 0;
	while (++i < ITEM_NBR)
	{
		j = -1;
		while (++j < ITEM_FRAME)
		{
			data->item[i][j].fd = open(item[ctr_item], O_RDONLY);
			if (data->item[i][j].fd == -1)
				error_textures(data);
			data->item[i][j].img = mlx_png_file_to_image(data->window.mlx,
					item[ctr_item], &data->item[i][j].width,
					&data->item[i][j].height);
			close(data->item[i][j].fd);
			ctr_item++;
		}
	}
}
