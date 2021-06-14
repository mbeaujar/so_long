/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 21:44:14 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/06/14 15:16:10 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/inc/libft.h"
# include <sys/errno.h>

# ifndef LINUX
#  include "../minilibx_opengl/mlx.h"
#  define FORWARD 13
#  define BACKWARD 1
#  define LEFT 0
#  define RIGHT 2
#  define ESC 53
# endif

# ifndef MACOS
#  include "../minilibx_linux/mlx.h"
#  define FORWARD 119
#  define BACKWARD 115
#  define LEFT 97
#  define RIGHT 100
#  define ESC 65307
# endif

# define NONE 0xFF000000
# define BLACK 0x00000000

typedef struct s_image
{
	void	*text;
	char	*addr;
	int		height;
	int		width;
	int		bpp;
	int		sl;
	int		ed;
}		t_image;

typedef struct s_game
{
	int		posx;
	int		posy;
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		move;
	int		bpp;
	int		sl;
	int		ed;
	int		collectible;
	int		resolutionx;
	int		resolutiony;
	int		sq_lenx;
	int		sq_leny;
	int		lenx;
	int		leny;
	char	**map;
	int		fd_map;
	t_image	exit;
	t_image	collec;
	t_image	minion[2];
	t_image	enemy;
	int		anim;
}			t_game;

char	*ft_strjoin_endl(char *s1, char *s2);
void	secure_free(char *str);
int		ft_strcmp(char *s1, char *s2);
int		big_strlen(char **str);
int		parsing(t_game *game, char **argv);
int		parse_character(char *line);
int		parse_dimension(t_game *game, char **map);
int		parse_map(t_game *game);
void	keyforward(int keycode, t_game *game);
void	keybackward(int keycode, t_game *game);
void	keyleft(int keycode, t_game *game);
void	keyright(int keycode, t_game *game);
void	free_tab(char **str);
int		key(int keycode, t_game *game);
int		quit_the_game(t_game *game);
void	calcule_len_squarre(t_game *game);
void	printmap(char **str);
void	my_mlx_pixel_put(int x, int y, t_game *game, unsigned int color);
void	draw_map(t_game *game);
void	draw_texture(t_game *game, int i, int j, t_image image);
void	open_texture_exit(t_game *game);
void	open_texture_collec(t_game *game);
void	open_texture_minion(t_game *game, int i, char *path);
void	open_texture_enemy(t_game *game);
int		clear_key(int key, t_game *game);

#endif
