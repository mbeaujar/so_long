/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 21:44:14 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/06/10 23:07:25 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../minilibx_opengl/mlx.h"
# include "../libft/inc/libft.h"
# include <sys/errno.h>

typedef struct s_game
{
	int		posx;
	int		posy;
	void	*mlx;
	void	*img;
	void	*win;
	int		resolutionx;
	int		resolutiony;
	char	**map;
	int		fd_map;
}		t_game;

char	*ft_strjoin_endl(char *s1, char *s2);
void	secure_free(char *str);
int		ft_strcmp(char *s1, char *s2);
int		big_strlen(char **str);
int		parsing(t_game *game, char **argv);
int		parse_character(char *line);
int		parse_dimension(char **map);
int		parse_map(t_game *game);

#endif 
