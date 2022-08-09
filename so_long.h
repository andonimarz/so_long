/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 11:28:25 by amarzana          #+#    #+#             */
/*   Updated: 2022/08/09 18:51:54 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "gnl/get_next_line.h"

typedef struct s_control
{
	char	**map;
	char	*str;
	int		aux;
	int		error;
	int		fd;
	int		height;
	int		width;
	int		i;

}					t_control;

/*	ft_checks.c	*/
void	ft_checks(t_control *control);

void	ft_free(char **ptr);

#endif