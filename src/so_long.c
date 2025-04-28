/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sferrad <sferrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:57:56 by sferrad           #+#    #+#             */
/*   Updated: 2025/04/28 17:39:06 by sferrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_player	ft_init_player(t_map *map)
{
	t_player	player;

	player.player_pos = map->player_pos;
	player.move = 0;
	player.coin = 0;
	player.exit = 0;
	return (player);
}

int	main(int ac, char **av)
{
	t_player	player;
	t_map		map;
	t_data		*data;

	if (!ft_parsing(ac, av[1], &map))
		return (0);
	player = ft_init_player(&map);
	data = init_data(&map, player);
	if (!data)
	{
		ft_free_maps(map.map);
		return (0);
	}
	if (textures_init(data) == -1)
	{
		on_destroy(data);
		ft_free_maps(map.map);
		return (0);
	}
	fill_map(data);
	mlx_hook(data->mlx_win, KeyPress, KeyPressMask, handle_keypress, data);
	mlx_hook(data->mlx_win, 17, 0, &on_destroy, data);
	mlx_loop(data->mlx);
	ft_free_maps(map.map);
	return (0);
}
