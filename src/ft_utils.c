/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 19:35:57 by amarzana          #+#    #+#             */
/*   Updated: 2022/08/17 10:33:38 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_init_control(t_control *control)
{
	control->map = NULL;
	control->str = NULL;
	control->error = 0;
	control->fd = 0;
	control->height = 0;
	control->width = 0;
}

void	ft_init_data(t_data *data)
{
	data->mlx_ptr = NULL;
	data->mlx_win = NULL;
	data->player = NULL;
	data->collect = NULL;
	data->floor = NULL;
	data->door = NULL;
	data->wall = NULL;
	data->player_x = 0;
	data->player_y = 0;
	data->collect_count = 0;
	data->moves_count = 0;
	data->size_x = 0;
	data->size_y = 0;
}

void	ft_free_data(t_data *data)
{
	free(data->mlx_ptr);
	free(data->player);
	free(data->collect);
	free(data->floor);
	free(data->door);
	free(data->wall);
}

void	ft_free(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

void	ft_exit(t_control *control)
{
	int	i;

	i = 0;
	if (control->data->mlx_win)
		mlx_destroy_window(control->data->mlx_ptr, control->data->mlx_win);
	if (control->data)
		ft_free_data(control->data);
	ft_free(control->map);
	exit(0);
}
