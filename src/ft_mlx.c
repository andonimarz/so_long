/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 14:19:41 by amarzana          #+#    #+#             */
/*   Updated: 2022/08/16 11:19:43 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_put_items(t_control *ctr, int y, int x)
{
	if (ctr->map[y][x] == 'P')
	{
		mlx_put_image_to_window(ctr->data->mlx_ptr, ctr->data->mlx_win,
			ctr->data->player, x * 32, y * 32);
		ctr->data->player_x = x;
		ctr->data->player_y = y;
	}
	if (ctr->map[y][x] == 'C')
	{
		mlx_put_image_to_window(ctr->data->mlx_ptr, ctr->data->mlx_win,
			ctr->data->collect, x * 32, y * 32);
		ctr->data->collect_count++;
	}
	if (ctr->map[y][x] == '1')
		mlx_put_image_to_window(ctr->data->mlx_ptr, ctr->data->mlx_win,
			ctr->data->wall, x * 32, y * 32);
	if (ctr->map[y][x] == 'E')
		mlx_put_image_to_window(ctr->data->mlx_ptr, ctr->data->mlx_win,
			ctr->data->door, x * 32, y * 32);
}

void	ft_fill_map(t_control *ctr)
{
	int	y;
	int	x;

	ctr->data->collect_count = 0;
	y = 0;
	while (y < ctr->height)
	{
		x = 0;
		while (x < ctr->width)
		{
			mlx_put_image_to_window(ctr->data->mlx_ptr, ctr->data->mlx_win, \
			ctr->data->floor, x * 32, y * 32);
			ft_put_items(ctr, y, x);
			x++;
		}
		y++;
	}
}

static void	ft_create_images(t_data *data)
{
	data->floor = mlx_xpm_file_to_image(data->mlx_ptr, "img/floor.xpm", \
				&data->size_x, &data->size_y);
	data->player = mlx_xpm_file_to_image(data->mlx_ptr, "img/player.xpm", \
				&data->size_x, &data->size_y);
	data->collect = mlx_xpm_file_to_image(data->mlx_ptr, "img/chest.xpm", \
				&data->size_x, &data->size_y);
	data->wall = mlx_xpm_file_to_image(data->mlx_ptr, "img/wall.xpm", \
				&data->size_x, &data->size_y);
	data->door = mlx_xpm_file_to_image(data->mlx_ptr, "img/door.xpm", \
				&data->size_x, &data->size_y);
}

void	ft_mlx(t_control *control)
{
	t_data	data;

	control->data = &data;
	ft_init_data(control->data);
	control->data->mlx_ptr = mlx_init();
	control->data->mlx_win = mlx_new_window(control->data->mlx_ptr, \
				control->width * 32, control->height * 32, "so_long");
	ft_create_images(control->data);
	ft_fill_map(control);
	mlx_key_hook(control->data->mlx_win, &ft_inputs, control);
	mlx_hook(control->data->mlx_win, 17, 0, (void *)exit, 0);
	mlx_loop(control->data->mlx_ptr);
}
