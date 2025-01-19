/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sferrad <sferrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:51:29 by sferrad           #+#    #+#             */
/*   Updated: 2025/01/18 17:45:57 by sferrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	up(t_map *map, t_player *player)
{
	if (map->map[player->player_pos.y - 1][player->player_pos.x] == '1')
		return ;
	if (map->map[player->player_pos.y - 1][player->player_pos.x] == 'C')
		player->coin = player->coin + 1;
	if (map->map[player->player_pos.y - 1][player->player_pos.x] == 'E')
		if (player->coin == map->coin)
			player->exit = 1;
	player->player_pos.y -= 1;
	map->map[player->player_pos.y][player->player_pos.x] = 'P';
	if (player->player_pos.y + 1 == map->exit_pos.y
		&& player->player_pos.x == map->exit_pos.x)
		map->map[player->player_pos.y + 1][player->player_pos.x] = 'E';
	else
		map->map[player->player_pos.y + 1][player->player_pos.x] = '0';
	player->move = player->move + 1;
	ft_printf("move: %d\n", player->move);
}

void	down(t_map *map, t_player *player)
{
	if (map->map[player->player_pos.y + 1][player->player_pos.x] == '1')
		return ;
	if (map->map[player->player_pos.y + 1][player->player_pos.x] == 'C')
		player->coin = player->coin + 1;
	if (map->map[player->player_pos.y + 1][player->player_pos.x] == 'E')
		if (player->coin == map->coin)
			player->exit = 1;
	player->player_pos.y += 1;
	map->map[player->player_pos.y][player->player_pos.x] = 'P';
	if (player->player_pos.y - 1 == map->exit_pos.y
		&& player->player_pos.x == map->exit_pos.x)
		map->map[player->player_pos.y - 1][player->player_pos.x] = 'E';
	else
		map->map[player->player_pos.y - 1][player->player_pos.x] = '0';
	player->move = player->move + 1;
	ft_printf("move: %d\n", player->move);
}

void	left(t_map *map, t_player *player)
{
	if (map->map[player->player_pos.y][player->player_pos.x - 1] == '1')
		return ;
	if (map->map[player->player_pos.y][player->player_pos.x - 1] == 'C')
		player->coin = player->coin + 1;
	if (map->map[player->player_pos.y][player->player_pos.x - 1] == 'E')
		if (player->coin == map->coin)
			player->exit = 1;
	player->player_pos.x -= 1;
	map->map[player->player_pos.y][player->player_pos.x] = 'P';
	if (player->player_pos.y == map->exit_pos.y && player->player_pos.x
		+ 1 == map->exit_pos.x)
		map->map[player->player_pos.y][player->player_pos.x + 1] = 'E';
	else
		map->map[player->player_pos.y][player->player_pos.x + 1] = '0';
	player->move = player->move + 1;
	ft_printf("move: %d\n", player->move);
}

void	right(t_map *map, t_player *player)
{
	if (map->map[player->player_pos.y][player->player_pos.x + 1] == '1')
		return ;
	if (map->map[player->player_pos.y][player->player_pos.x + 1] == 'C')
		player->coin = player->coin + 1;
	if (map->map[player->player_pos.y][player->player_pos.x + 1] == 'E')
		if (player->coin == map->coin)
			player->exit = 1;
	player->player_pos.x += 1;
	map->map[player->player_pos.y][player->player_pos.x] = 'P';
	if (player->player_pos.y == map->exit_pos.y && player->player_pos.x
		- 1 == map->exit_pos.x)
		map->map[player->player_pos.y][player->player_pos.x - 1] = 'E';
	else
		map->map[player->player_pos.y][player->player_pos.x - 1] = '0';
	player->move = player->move + 1;
	ft_printf("move: %d\n", player->move);
}
