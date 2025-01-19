/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sferrad <sferrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:15:20 by sferrad           #+#    #+#             */
/*   Updated: 2025/01/18 18:11:23 by sferrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	on_destroy(t_data *data)
{
	ft_free_maps(data->map->map);
	free_resources(data);
	exit(0);
	return (0);
}

void	free_resources(t_data *data)
{
	int	i;

	i = 0;
	if (data->textures)
	{
		while (i < 5)
		{
			if (data->textures[i])
				mlx_destroy_image(data->mlx, data->textures[i]);
			i++;
		}
	}
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->mlx_win)
		mlx_destroy_window(data->mlx, data->mlx_win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	free(data);
}

int	textures_init(t_data *data)
{
	int	width;
	int	height;

	width = 40;
	height = 40;
	data->textures[0] = mlx_xpm_file_to_image(data->mlx, "./img/Char.xpm",
			&width, &height);
	data->textures[1] = mlx_xpm_file_to_image(data->mlx, "./img/Wall.xpm",
			&width, &height);
	data->textures[2] = mlx_xpm_file_to_image(data->mlx, "./img/Background.xpm",
			&width, &height);
	data->textures[3] = mlx_xpm_file_to_image(data->mlx, "./img/Coin.xpm",
			&width, &height);
	data->textures[4] = mlx_xpm_file_to_image(data->mlx, "./img/Exit.xpm",
			&width, &height);
	if ((!data->textures[0]) || (!data->textures[1]) || (!data->textures[2])
		|| (!data->textures[3]) || (!data->textures[4]))
		return (ft_printf("Error: Failed to load textures\n"), -1);
	return (0);
}

t_data	*init_data(t_map *map, t_player player)
{
	t_data	*data;
	int		height;
	int		width;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->mlx = mlx_init();
	if (!data->mlx)
		return (free(data), NULL);
	data->map = map;
	height = map->height * 40;
	width = map->width * 40;
	data->mlx_win = mlx_new_window(data->mlx, width, height, "so_long");
	if (!data->mlx_win)
		return (free(data), NULL);
	data->img = mlx_new_image(data->mlx, 1920, 1080);
	if (!data->img)
		return (free(data), NULL);
	data->player = player;
	return (data);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_w)
	{
		up(data->map, &data->player);
	}
	else if (keysym == XK_s)
		down(data->map, &data->player);
	else if (keysym == XK_a)
		left(data->map, &data->player);
	else if (keysym == XK_d)
		right(data->map, &data->player);
	else if (keysym == XK_Escape)
		on_destroy(data);
	if (data->player.exit)
	{
		fill_map(data);
		ft_printf("Felicitation ! Vous etes sortie !\n");
		on_destroy(data);
	}
	fill_map(data);
	return (0);
}
