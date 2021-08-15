/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   png_to_mlx.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/15 16:59:39 by lwray         #+#    #+#                 */
/*   Updated: 2021/08/15 16:59:41 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image_error(t_mapstruct map, t_images images)
{
	perror("Error: mlx images error");
	free_images(images, map.mlx);
	free_fields(map.fields, map.height);
	exit(EXIT_FAILURE);
}

t_images	png_to_mlx(t_mapstruct map)
{
	t_images	images;
	int			img_width;
	int			img_height;

	images.cat = mlx_png_file_to_image(map.mlx, "images/cat.png",
			&img_width, &img_height);
	images.wall = mlx_png_file_to_image(map.mlx, "images/wall.png",
			&img_width, &img_height);
	images.catnip = mlx_png_file_to_image(map.mlx, "images/catnip.png",
			&img_width, &img_height);
	images.exit = mlx_png_file_to_image(map.mlx, "images/exit.png",
			&img_width, &img_height);
	images.vacuum = mlx_png_file_to_image(map.mlx, "images/vacuum.png",
			&img_width, &img_height);
	images.lose = mlx_png_file_to_image(map.mlx, "images/lose.png",
			&img_width, &img_height);
	images.win = mlx_png_file_to_image(map.mlx, "images/win.png",
			&img_width, &img_height);
	if (!images.cat || !images.wall || !images.catnip || !images.exit
		|| !images.vacuum || !images.lose || !images.win)
		image_error (map, images);
	return (images);
}
