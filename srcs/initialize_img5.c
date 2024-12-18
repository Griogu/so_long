/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_img5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:22:48 by mpendilh          #+#    #+#             */
/*   Updated: 2024/12/17 14:13:05 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	initialize_death(t_data *data)
{
	int			i;
	static char	*death[DEATH] = {
		"textures/death/death1.png", "textures/death/death_player1.png",
		"textures/death/death_player2.png", "textures/death/death_player3.png",
		"textures/death/death_player4.png", "textures/death/death_player5.png"
	};

	i = 0;
	while (i < DEATH)
	{
		data->death[i].fd = open(death[i], O_RDONLY);
		if (data->death[i].fd == -1)
			error_textures(data);
		data->death[i].img = mlx_png_file_to_image(data->window.mlx,
				death[i], &data->death[i].width, &data->death[i].height);
		close(data->death[i].fd);
		i++;
	}
}
