/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cleanup.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/15 16:58:25 by lwray         #+#    #+#                 */
/*   Updated: 2021/08/15 16:58:26 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_fields(t_field	**fields, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free (fields[i]);
		i++;
	}
	free (fields);
}

void	free_images(t_images images, void *mlx)
{
	if (images.cat)
		mlx_destroy_image(mlx, images.cat);
	if (images.wall)
		mlx_destroy_image(mlx, images.wall);
	if (images.catnip)
		mlx_destroy_image(mlx, images.catnip);
	if (images.exit)
		mlx_destroy_image(mlx, images.exit);
	if (images.vacuum)
		mlx_destroy_image(mlx, images.vacuum);
	if (images.lose)
		mlx_destroy_image(mlx, images.lose);
	if (images.win)
		mlx_destroy_image(mlx, images.win);
}
