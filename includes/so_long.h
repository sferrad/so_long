/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sferrad <sferrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:10:58 by sferrad           #+#    #+#             */
/*   Updated: 2025/01/18 18:13:54 by sferrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/ft_printf/ft_printf.h"
# include "../libft/get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct s_map
{
	char		**map;
	t_point		size;
	t_point		player_pos;
	t_point		exit_pos;
	int			coin;
	int			exit;
	int			player;
	int			height;
	int			width;
}				t_map;
typedef struct s_player
{
	t_point		player_pos;
	int			move;
	int			coin;
	int			exit;
}				t_player;
typedef struct s_data
{
	void		*img;
	void		*mlx;
	void		*mlx_win;
	void		*textures[5];
	t_map		*map;
	t_player	player;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;
int				ft_is_ber(char *av);
int				ft_parsing(int ac, char *av, t_map *carte);
int				ft_count_line(char *av);
char			**ft_tab_maps(char *av);
int				ft_wall(char **maps);
void			ft_free_maps(char **maps);
int				ft_check(char **maps);
int				ft_count_content(char **maps);
int				flood_fill_check(t_map *map);
int				ft_find_exit(t_map *maps);
int				ft_count_item(char **maps, char item);
t_point			ft_content_yx(t_map *maps, char item);
char			**ft_copy_tab(char **tab, int height);
void			up(t_map *map, t_player *player);
void			right(t_map *map, t_player *player);
void			down(t_map *map, t_player *player);
void			left(t_map *map, t_player *player);
t_data			*init_data(t_map *map, t_player player);
int				close_win(t_data *data);
void			free_resources(t_data *data);
int				on_destroy(t_data *data);
int				handle_keypress(int keysym, t_data *data);
int				textures_init(t_data *data);
void			fill_map(t_data *data);
#endif