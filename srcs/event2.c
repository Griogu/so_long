/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:22:34 by mpendilh          #+#    #+#             */
/*   Updated: 2024/12/17 09:57:51 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	mouse_hook(int button, t_data *data)
{
	if (button == 1 && !data->icon[0].counter && !data->fire[0].is_attack)
		data->water[0].is_attack = true;
	if (button == 3 && !data->icon2[0].counter && !data->water[0].is_attack)
		data->fire[0].is_attack = true;
	return (0);
}
