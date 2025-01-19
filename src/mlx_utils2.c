/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sferrad <sferrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:39:43 by sferrad           #+#    #+#             */
/*   Updated: 2025/01/18 18:13:25 by sferrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_image(t_data *data, int x, int y)
{
	if (data->map->map[y][x] == '1')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->textures[1], x * 40, y * 40);
	else if (data->map->map[y][x] == 'P')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->textures[0], x * 40, y * 40);
	else if (data->map->map[y][x] == 'E')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->textures[4], x * 40, y * 40);
	else if (data->map->map[y][x] == 'C')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->textures[3], x * 40, y * 40);
	else if (data->map->map[y][x] == '0')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->textures[2], x * 40, y * 40);
}

void	fill_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map->height)
	{
		x = 0;
		while (x < data->map->width)
		{
			put_image(data, x, y);
			x++;
		}
		y++;
	}
}
