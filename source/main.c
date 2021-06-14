/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 21:48:01 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/06/14 15:46:25 by mbeaujar         ###   ########.fr       */
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
	game->anim = 0;
}

void	display_movement(t_game *game)
{
	char	*str;

	str = ft_itoa(game->move);
	mlx_string_put(game->mlx, game->win, 0, 20, 0xFFFFFF, str);
	free(str);
}

int	game_loop(t_game *game)
{
	static int	count = 0;

	if (count > 100)
	{
		count = 0;
		game->anim = 0;
	}
	draw_map(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	display_movement(game);
	count++;
	return (1);
}

void	launch_the_game(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx,
			game->resolutionx, game->resolutiony, "./so_long");
	game->img = mlx_new_image(game->mlx, game->resolutionx, game->resolutiony);
	game->addr = mlx_get_data_addr(game->img, &game->bpp, &game->sl, &game->ed);
	open_texture_exit(game);
	open_texture_collec(game);
	open_texture_minion(game, 0, "./textures/minion.xpm");
	open_texture_minion(game, 1, "./textures/minion_running.xpm");
	open_texture_enemy(game);
	mlx_hook(game->win, 2, 1L << 0, key, game);
	mlx_hook(game->win, 3, (1L << 1), clear_key, &game);
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
	calcule_len_squarre(&game);
	launch_the_game(&game);
	return (0);
}
