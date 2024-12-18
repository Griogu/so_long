/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 01:16:26 by mpendilh          #+#    #+#             */
/*   Updated: 2024/12/14 09:32:50 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	check_character(int c)
{
	return (c != 'P' && c != 'C' && c != 'E' && c != '0' && c != '1'
		&& c != '\n' && c != 'M');
}

int	check_map_limit(t_data *data)
{
	int	i;

	i = 0;
	while (data->map_line[i])
	{
		if (data->map_line[i] != '1' && data->map_line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

void	check_character_nbr(t_data *data)
{
	if (data->limit_map_counter != 2)
	{
		free(data->map_to_split);
		error_management(MAP_NOT_VALID, data);
	}
	if (data->player_nbr != 1)
	{
		free(data->map_to_split);
		error_management(PLAYER_ERROR, data);
	}
	if (data->exit_nbr != 1)
	{
		free(data->map_to_split);
		error_management(EXIT_ERROR, data);
	}
	if (data->item_nbr < 1)
	{
		free(data->map_to_split);
		error_management(ITEM_ERROR, data);
	}
}

void	check_size_map(t_data *data)
{
	if (data->height == data->width)
	{
		free(data->map_to_split);
		error_management(MAP_NOT_VALID, data);
	}
}

int	check_file(char *map_name, t_data *data)
{
	if (ft_strlen(map_name) <= 4)
		return (0);
	data->fd = open(map_name, O_RDONLY);
	if (data->fd == -1)
		return (0);
	while (ft_strlen(map_name) > 4)
		map_name++;
	if (ft_strcmp(map_name, ".ber"))
		return (0);
	return (1);
}
