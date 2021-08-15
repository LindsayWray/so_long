/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_handler.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/15 16:59:26 by lwray         #+#    #+#                 */
/*   Updated: 2021/08/15 16:59:28 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	malloc_error(t_list **list)
{
	perror("Error: malloc error");
	ft_lstclear(list);
	exit(EXIT_FAILURE);
}

void	malloc_error_map(t_list **list, t_field **fields, int len)
{
	perror("Error: malloc error");
	ft_lstclear(list);
	free_fields(fields, len);
	exit(EXIT_FAILURE);
}

void	parsing_error(t_list **list)
{
	ft_putstr_fd("Error: incorrect map input\n", STDERR_FILENO);
	ft_lstclear(list);
	exit(EXIT_FAILURE);
}

void	file_error(char *error_message)
{
	ft_putstr_fd("Error: ", STDERR_FILENO);
	ft_putstr_fd(error_message, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	mlx_error(t_field **fields, int len)
{
	perror("Error: mlx error");
	free_fields(fields, len);
	exit(EXIT_FAILURE);
}
