/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   veldra_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 12:44:45 by mpendilh          #+#    #+#             */
/*   Updated: 2024/12/16 14:15:07 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	veldra_frame(t_data *data)
{
	data->veldra[0].frame++;
	if (data->veldra[0].frame > 150)
	{
		data->veldra[0].frame = 0;
		data->veldra[0].counter++;
	}
	if (data->veldra[0].counter > VELDRA_FRAME - 5)
		data->veldra[0].counter = 0;
}

void	veldra_frame2(t_data *data)
{
	data->veldra[1].frame++;
	if (data->veldra[1].frame > 150)
	{
		data->veldra[1].frame = 0;
		data->veldra[1].counter++;
	}
	if (data->veldra[1].counter > VELDRA_FRAME - 1)
		data->veldra[1].counter = 4;
}
