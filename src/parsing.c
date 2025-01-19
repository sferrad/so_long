/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sferrad <sferrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 20:52:50 by sferrad           #+#    #+#             */
/*   Updated: 2025/01/18 12:55:22 by sferrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_is_ber(char *av)
{
	int	i;

	if (!av)
		return (0);
	i = ft_strlen(av) - 4;
	if (ft_strncmp(&av[i], ".ber", 10) != 0)
		return (0);
	return (1);
}

static int	check_line_length(char *line, size_t length)
{
	if (ft_strlen(line) != length)
		return (0);
	return (1);
}

int	ft_is_rectangle(char *av)
{
	size_t	i;
	int		fd;
	char	*line;
	char	*stash;

	stash = NULL;
	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd, &stash);
	if (!line)
	{
		close(fd);
		return (0);
	}
	i = ft_strlen(line);
	while (line)
	{
		if (!check_line_length(line, i))
			return (free(line), free(stash), close(fd), 0);
		free(line);
		line = get_next_line(fd, &stash);
	}
	return (free(line), free(stash), close(fd), 1);
}

t_map	ft_fill_list(char **maps)
{
	t_map	carte;

	carte.map = maps;
	carte.exit = 1;
	carte.player = 1;
	carte.coin = ft_count_item(maps, 'C');
	carte.size.y = 0;
	while (maps[carte.size.y])
		carte.size.y++;
	carte.player_pos = ft_content_yx(&carte, 'P');
	carte.exit_pos = ft_content_yx(&carte, 'E');
	if (carte.size.y > 0)
		carte.size.x = ft_strlen(maps[0]);
	else
		carte.size.x = 0;
	carte.height = carte.size.y;
	carte.width = carte.size.x;
	return (carte);
}

int	ft_parsing(int ac, char *av, t_map *carte)
{
	char	**maps;

	if (ac != 2)
		return (ft_putendl_fd("Error: Incorrect number of arguments\n", 2), 0);
	if (!ft_is_ber(av))
		return (ft_putendl_fd("Error: File is not a .ber file\n", 2), 0);
	if (!ft_is_rectangle(av))
		return (ft_putendl_fd("Error: Map is not a rectangle\n", 2), 0);
	maps = ft_tab_maps(av);
	if (!maps)
		return (ft_putendl_fd("Error: Failed to read map\n", 2), 0);
	if (!ft_check(maps))
		return (ft_putendl_fd("Error: Invalid map structure\n", 2),
			ft_free_maps(maps), 0);
	if (!ft_count_content(maps))
		return (ft_putendl_fd("Error: Invalid map content\n", 2),
			ft_free_maps(maps), 0);
	*carte = ft_fill_list(maps);
	if (!flood_fill_check(carte))
		return (ft_putendl_fd("Error: Invalid wall configuration\n", 2),
			ft_free_maps(maps), 0);
	return (1);
}
