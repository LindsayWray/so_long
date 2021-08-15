/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_map.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/15 16:58:53 by lwray         #+#    #+#                 */
/*   Updated: 2021/08/15 16:58:55 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	color_in_background(t_mapstruct map)
{
	int	x;
	int	y;

	y = 0;
	while (y < (map.height * 48))
	{
		x = 0;
		while (x < (map.width * 48))
		{
			mlx_pixel_put(map.mlx, map.mlx_win, x, y, BACKGROUND);
			x++;
		}
		y++;
	}
}

void	put_image_to_window(int i, int j, t_mapstruct map)
{
	if (map.fields[i][j] == WALL)
		mlx_put_image_to_window(map.mlx, map.mlx_win, map.images.wall,
			(j * 48), (i * 48));
	else if (map.fields[i][j] == PLAYER)
		mlx_put_image_to_window(map.mlx, map.mlx_win, map.images.cat,
			(j * 48), (i * 48));
	else if (map.fields[i][j] == COLLECTIBLE)
		mlx_put_image_to_window(map.mlx, map.mlx_win, map.images.catnip,
			(j * 48), (i * 48));
	else if (map.fields[i][j] == EXIT)
		mlx_put_image_to_window(map.mlx, map.mlx_win, map.images.exit,
			(j * 48), (i * 48));
	else if (map.fields[i][j] == ENEMY)
		mlx_put_image_to_window(map.mlx, map.mlx_win, map.images.vacuum,
			(j * 48), (i * 48));
}

void	render_map(t_mapstruct map)
{
	int	i;
	int	j;

	color_in_background(map);
	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			put_image_to_window(i, j, map);
			j++;
		}
		i++;
	}
	display_steps(map);
}
