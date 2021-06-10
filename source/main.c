/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 21:48:01 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/06/10 23:15:52 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct(t_game *game)
{
	game->map = NULL;
	game->posx = -1;
	game->posx = -1;
}

void	launch_the_game(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 800, 600, "./so_long");
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		if (argc < 2)
			write(1, "Error\nNot enough arguments.\n", 28);
		if (argc > 2)
			write(1, "Error\nToo many arguments.\n", 26);
		return (-1);
	}
	init_struct(&game);
	if (parsing(&game, argv) == -1)
		return (-1);
	launch_the_game(&game);
	return (0);
}