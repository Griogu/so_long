/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_settings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 20:00:40 by mpendilh          #+#    #+#             */
/*   Updated: 2024/12/12 10:33:04 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	choose_map(t_data *data)
{
	data->fd_map = open("/dev/random", O_RDONLY);
	read(data->fd_map, &data->random, sizeof(unsigned int));
	data->random %= 10;
}
