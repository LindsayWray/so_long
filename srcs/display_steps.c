/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   display_steps.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/15 16:58:31 by lwray         #+#    #+#                 */
/*   Updated: 2021/08/15 16:58:33 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_steps(t_mapstruct map)
{
	ft_printf("%d steps\n", map.step_count);
}
