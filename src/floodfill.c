/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sferrad <sferrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:36:08 by sferrad           #+#    #+#             */
/*   Updated: 2025/01/08 17:47:28 by sferrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	to_fill(char c)
{
	char	*to_fill;

	to_fill = "PEC0";
	while (*to_fill)
	{
		if (*to_fill == c)
			return (1);
		to_fill++;
	}
	return (0);
}

void	fill(char **tab, t_point size, t_point cur)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| !to_fill(tab[cur.y][cur.x]))
		return ;
	tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_point){cur.x - 1, cur.y});
	fill(tab, size, (t_point){cur.x + 1, cur.y});
	fill(tab, size, (t_point){cur.x, cur.y - 1});
	fill(tab, size, (t_point){cur.x, cur.y + 1});
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin);
}

int	flood_fill_check(t_map *map)
{
	char	**copy;
	t_point	size;
	t_point	player_pos;

	size = map->size;
	player_pos = map->player_pos;
	copy = ft_copy_tab(map->map, size.y);
	if (!copy)
		return (0);
	flood_fill(copy, size, player_pos);
	if (ft_count_item(copy, 'C') == 0 && ft_count_item(copy, 'E') == 0)
	{
		ft_free_maps(copy);
		return (1);
	}
	ft_free_maps(copy);
	return (0);
}
