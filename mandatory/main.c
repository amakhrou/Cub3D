/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakhrou <amakhrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:44:39 by amakhrou          #+#    #+#             */
/*   Updated: 2024/01/08 14:57:12 by amakhrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting/cub3D.h"

void	error_msg(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}

void	get_path(t_game *game)
{
	game->no_text = mlx_xpm_file_to_image(game->mlx, game->parse->no_tex,
			&game->n_w, &game->n_h);
	if (!game->no_text)
		error_msg(RED"invalid north texture\n");
	game->we_text = mlx_xpm_file_to_image(game->mlx, game->parse->we_tex,
			&game->w_w, &game->w_h);
	if (!game->we_text)
		error_msg(RED"invalid west texture\n");
	game->so_text = mlx_xpm_file_to_image(game->mlx, game->parse->so_tex,
			&game->s_w, &game->s_h);
	if (!game->so_text)
		error_msg(RED"invalid south texture\n");
	game->ea_text = mlx_xpm_file_to_image(game->mlx, game->parse->ea_tex,
			&game->e_w, &game->e_h);
	if (!game->ea_text)
		error_msg(RED"invalid east texture\n");
	game->no_addr = mlx_get_data_addr(game->no_text, &game->bits_per_pixel[1],
			&game->line_length[1], &game->endian[1]);
	game->so_addr = mlx_get_data_addr(game->so_text, &game->bits_per_pixel[2],
			&game->line_length[2], &game->endian[2]);
	game->we_addr = mlx_get_data_addr(game->we_text, &game->bits_per_pixel[3],
			&game->line_length[3], &game->endian[3]);
	game->ea_addr = mlx_get_data_addr(game->ea_text, &game->bits_per_pixel[4],
			&game->line_length[4], &game->endian[4]);
}

int	game_loop(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img);
	game->img = mlx_new_image(game->mlx, WIN_W, WIN_H);
	game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel[0],
			&game->line_length[0], &game->endian[0]);
	castoneray(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return (0);
}

int	key_hook(t_game *game)
{
	int	check;

	check = 0;
	if (game->turn_left == 1)
		turn_left(game);
	if (game->turn_right == 1)
		turn_right(game);
	if (game->walk_left == 1)
		move_left(game);
	if (game->walk_right == 1)
		move_right(game);
	if (game->walk_up == 1)
		check = move_up(game, check);
	if (game->walk_down == 1)
		check = move_down(game, check);
	game_loop(game);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (ac != 2)
	{
		ft_putstr_fd(RED"Error\n Bad arguments", 2);
		return (0);
	}
	init_game(game, av[1]);
	get_path(game);
	get_angle(game);
	mlx_hook(game->win, 2, 1L << 0, key_press, game);
	mlx_hook(game->win, 3, 1L << 1, key_release, game);
	mlx_hook(game->win, 17, 0, free_exit, game);
	mlx_loop_hook(game->mlx, key_hook, game);
	mlx_loop(game->mlx);
}
