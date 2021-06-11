/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 22:24:09 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/06/11 14:04:19 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	parse_character(char *line)
{
	if (!line || !*line)
	{
		write(1, "Error\nEmpty line in the map.\n", 29);
		return (1);
	}
	while (*line)
	{
		if (*line != '1' && *line != '0'
			&& *line != 'C' && *line != 'E' && *line != 'P')
		{
			write(1, "Error\nInvalid character in the map.\n", 36);
			return (1);
		}
		line++;
	}
	return (0);
}

int	is_player(t_game *game, int i, int j)
{
	if (game->posx != -1 || game->posx != -1)
		return (-1);
	game->posx = i;
	game->posx = j;
	return (0);
}

int	parse_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->leny = (int)ft_strlen(game->map[0]);
	game->lenx = big_strlen(game->map);
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] != '1' && (i == 0 || i == game->lenx - 1))
				return (1);
			if (game->map[i][j] != '1' && (j == 0 || j == game->leny - 1))
				return (1);
			if (game->map[i][j] == 'P' && is_player(game, i, j) == -1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	init_var_parse_dimension(int *i, int *exit, int *collectible, char **map)
{
	*i = 0;
	*exit = 0;
	*collectible = 0;
	return ((int)ft_strlen(map[0]));
}

int	parse_dimension(char **map)
{
	int	i;
	int	len;
	int	j;
	int	exit;
	int	collectible;

	len = init_var_parse_dimension(&i, &exit, &collectible, map);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				exit++;
			if (map[i][j] == 'C')
				collectible++;
			j++;
		}
		if (j != len)
			return (-1);
		i++;
	}
	if (exit == 0 || collectible == 0)
		return (-1);
	return (0);
}
