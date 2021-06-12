/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 21:48:01 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/06/12 20:27:10 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct(t_game *game)
{
	game->map = NULL;
	game->posx = -1;
	game->posy = -1;
	game->resolutionx = 800;
	game->resolutiony = 600;
	game->lenx = 0;
	game->leny = 0;
	game->collectible = 0;
	game->move = 0;
}

int	game_loop(t_game *game)
{
	//mlx_clear_window(game->mlx, game->win);
	draw_map(game);
	//my_mlx_pixel_put(5, 50, game, 0xFFFFFF);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return (1);
}

void	launch_the_game(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->resolutionx, game->resolutiony, "./so_long");
	game->img = mlx_new_image(game->mlx, game->resolutionx, game->resolutiony);
	game->addr = mlx_get_data_addr(game->img, &game->bpp, &game->sl, &game->ed);
	open_texture_exit(game);
	open_texture_collec(game);
	mlx_hook(game->win, 2, 1L << 0, key, game);
	mlx_hook(game->win, 17, 1L << 17, quit_the_game, game);
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;

	(void)argv;
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
	//printmap(game.map);
	calcule_len_squarre(&game);
	//printf("pos x : %d\tpos y : %d\n", game.posx, game.posy);
	launch_the_game(&game);
	return (0);
}