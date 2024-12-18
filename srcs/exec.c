/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 09:11:36 by mpendilh          #+#    #+#             */
/*   Updated: 2024/12/16 11:52:25 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 1)
		error_management(NO_MAP, &data);
	ft_bzero((char *)&data, sizeof(t_data));
	data.map_name = av[1];
	parsing(&data);
	choose_map(&data);
	start_game(&data);
	close_files(&data);
	free_tab(data.map);
	return (0);
}
