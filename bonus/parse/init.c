/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakhrou <amakhrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:40:38 by amakhrou          #+#    #+#             */
/*   Updated: 2023/12/18 20:40:38 by amakhrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/cub3D.h"

int	open_path(char *path, int permition)
{
	int	fd;

	fd = open(path, permition);
	if (fd <= 0)
	{
		ft_putstr_fd("ERROR:\n cant find file\n", 2);
		exit(0);
	}
	return (fd);
}

t_map	*init_map(char *path, t_parse *parse)
{
	t_map	*map;
	int		fd;
	int		c;

	c = 0;
	map = malloc(sizeof(t_map));
	fd = open_path(path, O_RDONLY);
	reads(parse, fd, c);
	map->map = parse->map_holder;
	if (!map->map[0])
	{
		ft_putstr_fd(RED"ERROR:\n map not found\n", 2);
		exit(0);
	}
	close(fd);
	return (map);
}

void	init_parse(t_parse *parse)
{
	parse->c_value = NULL;
	parse->f_value = NULL;
	parse->no_tex = NULL;
	parse->so_tex = NULL;
	parse->ea_tex = NULL;
	parse->we_tex = NULL;
	parse->line_size = 0;
	parse->f_rgb = 0;
	parse->c_rgb = 0;
	parse->map_holder = NULL;
}
