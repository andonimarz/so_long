/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 16:17:08 by amarzana          #+#    #+#             */
/*   Updated: 2022/08/08 17:49:21 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_check_perim(t_control *control)
{
	char	**aux;
	int		i;

	i = -1;
	aux = control->map;
	while (aux[0][++i])
	{
		if (aux[0][i] == '\n')
			control->width = i;
		if (aux[0][i] != '1' && aux[0][i] != '\n')
			control->error = 1;
	}
	i = -1;
	while (aux[++i])
		if (aux[i][0] != '1' || aux[i][control->width - 1] != '1')
			control->error = 1;
	i = -1;
	while (aux[control->height - 1][++i])
		if (aux[control->height - 1][i] != '1')
			control->error = 1;
}

static void	ft_check_elem(t_control *control)
{
	char	**aux;
	int		i;
	int		j;

	i = -1;
	while (aux[++i])
	{
		j = -1;
		while (aux[i][++j])
		{
			
		}
	}
}

void	ft_checks(t_control *control)
{
	ft_check_perim(control);
	ft_check_elem(control);
}
