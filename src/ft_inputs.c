/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 16:23:38 by amarzana          #+#    #+#             */
/*   Updated: 2022/08/16 12:35:32 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	ft_checkmove(t_control *ctr, int x, int y)
{
	if (ctr->map[y][x] == 'C')
		ctr->data->collect_count--;
	if (ctr->map[y][x] == '0' || ctr->map[y][x] == 'C')
	{
		ctr->map[y][x] = 'P';
		ctr->data->player_x = x;
		ctr->data->player_y = y;
		ctr->data->moves_count++;
	}
	if (ctr->map[y][x] == 'E')
	{
		if (ctr->data->collect_count != 0)
			return (0);
		ft_exit(ctr);
	}
	return (1);
}

static int	ft_updown(t_control *ctr, int key)
{
	int	x;
	int	y;

	x = ctr->data->player_x;
	y = ctr->data->player_y;
	if (key == 0)
	{
		if (ctr->map[y][--x] == '1')
			return (0);
		if (ft_checkmove(ctr, x, y) == 0)
			return (0);
		ctr->map[y][x + 1] = '0';
	}
	else if (key == 2)
	{
		if (ctr->map[y][++x] == '1')
			return (0);
		if (ft_checkmove(ctr, x, y) == 0)
			return (0);
		ctr->map[y][x - 1] = '0';
	}
	return (1);
}

static int	ft_leftright(t_control *ctr, int key)
{
	int	x;
	int	y;

	x = ctr->data->player_x;
	y = ctr->data->player_y;
	if (key == 13)
	{
		if (ctr->map[--y][x] == '1')
			return (0);
		if (ft_checkmove(ctr, x, y) == 0)
			return (0);
		ctr->map[y + 1][x] = '0';
	}
	else if (key == 1)
	{
		if (ctr->map[++y][x] == '1')
			return (0);
		if (ft_checkmove(ctr, x, y) == 0)
			return (0);
		ctr->map[y - 1][x] = '0';
	}
	return (1);
}

int	ft_inputs(int key, t_control *ctr)
{
	int		move;

	move = 0;
	if (key == 53)
		ft_exit(ctr);
	if (key == 0)
		move = ft_updown(ctr, key);
	if (key == 2)
		move = ft_updown(ctr, key);
	if (key == 13)
		move = ft_leftright(ctr, key);
	if (key == 1)
		move = ft_leftright(ctr, key);
	if (move)
	{
		ft_fill_map(ctr);
		ft_putstr_fd("Steps: ", 1);
		ft_putstr_fd(ft_itoa(ctr->data->moves_count), 1);
		ft_putchar_fd('\n', 1);
	}
	return (1);
}
