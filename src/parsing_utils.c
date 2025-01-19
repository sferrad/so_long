/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sferrad <sferrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:55:44 by sferrad           #+#    #+#             */
/*   Updated: 2025/01/15 14:48:14 by sferrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_count_line(char *av)
{
	int		fd;
	int		i;
	char	*stash;
	char	*line;

	stash = NULL;
	i = 0;
	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd, &stash);
	while (line)
	{
		free(line);
		line = get_next_line(fd, &stash);
		i++;
	}
	close(fd);
	return (i);
}

void	ft_free_maps(char **maps)
{
	int	i;

	i = 0;
	while (maps[i])
	{
		free(maps[i]);
		i++;
	}
	free(maps);
}

char	**ft_tab_maps(char *av)
{
	char	**maps;
	int		i;
	int		fd;
	char	*line;
	char	*stash;

	i = 0;
	stash = NULL;
	fd = open(av, O_RDONLY);
	if (fd < 0)
		return (NULL);
	maps = malloc(sizeof(char *) * (ft_count_line(av) + 1));
	if (!maps)
		return (close(fd), NULL);
	line = get_next_line(fd, &stash);
	while (line != NULL)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		maps[i++] = line;
		line = get_next_line(fd, &stash);
	}
	maps[i] = NULL;
	close(fd);
	return (free(stash), maps);
}

int	ft_check(char **maps)
{
	int	i;
	int	j;
	int	len;

	if (!maps || !maps[0])
		return (0);
	i = -1;
	while (maps[++i])
	{
		len = ft_strlen(maps[i]);
		if (len == 0)
			return (0);
		j = -1;
		while (maps[i][++j])
			if (maps[i][j] != '1' && maps[i][j] != 'P' && maps[i][j] != 'E'
				&& maps[i][j] != 'C' && maps[i][j] != '0')
				return (0);
		if ((i == 0 || !maps[i + 1]) && ft_strchr(maps[i], '0'))
			return (0);
		if (maps[i][0] != '1' || maps[i][len - 1] != '1')
			return (0);
	}
	return (1);
}

int	ft_count_content(char **maps)
{
	int	i;
	int	j;
	int	p_count;
	int	e_count;
	int	c_count;

	p_count = 0;
	e_count = 0;
	c_count = 0;
	i = -1;
	while (maps[++i])
	{
		j = -1;
		while (maps[i][++j])
		{
			if (maps[i][j] == 'P')
				p_count++;
			else if (maps[i][j] == 'E')
				e_count++;
			else if (maps[i][j] == 'C')
				c_count++;
		}
	}
	return (p_count == 1 && e_count == 1 && c_count > 0);
}
