/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:46:54 by mpendilh          #+#    #+#             */
/*   Updated: 2024/12/14 10:41:01 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	free_error(t_data *data)
{
	free(data->map_to_split);
	free(data->map_line);
	error_management(MAP_NOT_VALID, data);
}

void	error_management(char *message, t_data *data)
{
	close_files(data);
	ft_putstr_fd(ERROR_MESS, 2);
	ft_putstr_fd(message, 2);
	exit(0);
}

void	error_textures(t_data *data)
{
	destroy_all(data);
	free_tab(data->map);
	error_management(TEXTURES_ERROR, data);
}

void	free_error2(t_data *data)
{
	free(data->map_to_split);
	free_tab(data->map);
	error_management(MONSTER_ERROR, data);
}
