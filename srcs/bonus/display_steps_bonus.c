/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   display_steps_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/15 16:58:17 by lwray         #+#    #+#                 */
/*   Updated: 2021/08/15 16:58:18 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	display_steps(t_mapstruct map)
{
	char	*int_as_str;
	char	*full_str;

	int_as_str = ft_itoa(map.step_count);
	full_str = ft_strjoin(int_as_str, " steps");
	mlx_string_put(map.mlx, map.mlx_win, 25, 20, 0X00FFFF99, full_str);
	free(int_as_str);
	free(full_str);
}
