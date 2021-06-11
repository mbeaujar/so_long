/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 22:09:16 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/06/11 21:25:29 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	msg_error(char *str)
{
	write(1, "Error\n", 6);
	perror(str);
	errno = 0;
	return (1);
}

int	open_file(char *path)
{
	int	fd;

	if (ft_strcmp(path + ft_strlen(path) - 4, ".ber") != 0)
	{
		write(1, "Error\nFile in argument not a \".ber\".\n", 37);
		return (-1);
	}
	fd = open(path, O_RDONLY);
	if (fd == -1)
		msg_error("open");
	return (fd);
}

int	read_map(t_game *game, int fd)
{
	int		ret;
	char	*line;
	char	*map;

	ret = 1;
	line = NULL;
	map = NULL;
	while (ret)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1 || parse_character(line))
		{
			secure_free(line);
			secure_free(map);
			if (ret == -1)
				return (msg_error("read"));
			return (1);
		}
		map = ft_strjoin_endl(map, line);
		free(line);
		if (ret == 0)
			break ;
	}
	game->map = ft_split(map, '\n');
	return (game->map == NULL);
}

void printmap(char **str)
{
	int i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
		printf("%s\n", str[i++]);
}

int	parsing(t_game *game, char **argv)
{
	int	fd;

	fd = open_file(argv[1]);
	if (fd == -1)
		return (-1);
	game->fd_map = fd;
	if (read_map(game, fd) == 1)
	{
		close(fd);
		return (-1);
	}
	if (game->map == NULL || parse_dimension(game, game->map) || parse_map(game)
		|| game->posx == -1 || game->posy == -1)
	{
		write(1, "Error\nInvalid map.\n", 19);
		free_tab(game->map);
		close(fd);
		return (-1);
	}
	close(fd);
	return (0);
}
