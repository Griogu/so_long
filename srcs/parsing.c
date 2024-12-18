/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:56:06 by mpendilh          #+#    #+#             */
/*   Updated: 2024/12/15 13:18:35 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static void	check_limit_height(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		if (data->map[i][(int)data->width - 1]
				== data->map[i][(int)data->width - 2])
			data->limit_map_counter_2++;
		i++;
	}
	if (data->limit_map_counter_2 == data->height)
	{
		free(data->map_to_split);
		free_tab(data->map);
		error_management(MAP_NOT_VALID, data);
	}
}

static int	get_monster_nbr(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'M')
				data->monster_nbr++;
			j++;
		}
		i++;
	}
	if (data->width * data->height / data->monster_nbr <= 10)
		return (0);
	return (1);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static int	check_line(t_data *data)
{
	int	i;

	i = 0;
	if (data->map_line[0] == '\n' || data->width > 100 || data->height > 100)
		return (0);
	if (data->map_line[0] != '1' || data->map_line[(int)data->width - 1] != '1')
		return (0);
	while (data->map_line[i])
	{
		if (data->map_line[i] == 'P')
			data->player_nbr++;
		if (data->map_line[i] == 'C')
			data->item_nbr++;
		if (data->map_line[i] == 'E')
			data->exit_nbr++;
		if (check_character(data->map_line[i]))
			return (0);
		i++;
	}
	if (data->width != ft_strlen(data->map_line) - 1)
		return (0);
	if (check_map_limit(data))
		data->limit_map_counter++;
	return (1);
}

void	parsing(t_data *data)
{
	if (!check_file(data->map_name, data))
		error_management(FILE_ERROR, data);
	data->map_line = get_next_line(data->fd);
	data->width = ft_strlen(data->map_line) - 1;
	while (data->map_line)
	{
		if (!check_line(data))
			free_error(data);
		data->tmp = data->map_to_split;
		data->map_to_split = ft_strjoin(data->map_to_split, data->map_line);
		free(data->tmp);
		free(data->map_line);
		data->map_line = get_next_line(data->fd);
		data->height++;
	}
	check_size_map(data);
	check_character_nbr(data);
	data->map = ft_split(data->map_to_split, '\n');
	check_limit_height(data);
	if (!get_monster_nbr(data))
		free_error2(data);
	data->cpy_map = ft_split(data->map_to_split, '\n');
	free(data->map_to_split);
	check_all_map(data);
}
