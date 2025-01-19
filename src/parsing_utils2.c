/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sferrad <sferrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 21:11:03 by sferrad           #+#    #+#             */
/*   Updated: 2025/01/08 17:54:10 by sferrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_count_item(char **maps, char item)
{
	int	i;
	int	count;
	int	j;

	i = 0;
	count = 0;
	while (maps[i])
	{
		j = 0;
		while (maps[i][j])
		{
			if (maps[i][j] == item)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

t_point	ft_content_yx(t_map *maps, char item)
{
	t_point	player;
	int		i;
	int		j;

	player.y = -1;
	player.x = -1;
	i = 0;
	while (maps->map[i])
	{
		j = 0;
		while (maps->map[i][j])
		{
			if (maps->map[i][j] == item)
			{
				player.y = i;
				player.x = j;
				return (player);
			}
			j++;
		}
		i++;
	}
	return (player);
}

char	**ft_copy_tab(char **tab, int height)
{
	char	**copy;
	int		i;

	copy = (char **)malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = strdup(tab[i]);
		if (!copy[i])
		{
			while (i > 0)
				free(copy[--i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[height] = NULL;
	return (copy);
}
