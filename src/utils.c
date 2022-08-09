/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 19:35:57 by amarzana          #+#    #+#             */
/*   Updated: 2022/08/09 19:37:05 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
		free(ptr[i++]);
	free(ptr);
}

int	ft_count_lines(t_control *control)
{
	int	i;

	i = 0;
	while (control->map[i])
		i++;
	return (i);
}

void	ft_init_control(t_control *control)
{
	control->map = NULL;
	control->str = NULL;
	control->aux = 0;
	control->error = 0;
	control->fd = 0;
	control->height = 0;
	control->width = 0;
	control->i = 0;
}
