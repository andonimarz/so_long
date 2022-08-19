/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 11:28:25 by amarzana          #+#    #+#             */
/*   Updated: 2022/08/17 10:57:27 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx/mlx.h"

typedef struct s_data
{
	void		*mlx_ptr;
	void		*mlx_win;
	void		*player;
	void		*collect;
	void		*floor;
	void		*door;
	void		*wall;
	int			player_x;
	int			player_y;
	int			collect_count;
	int			moves_count;
	int			size_x;
	int			size_y;
}				t_data;

typedef struct s_control
{
	char	**map;
	char	*str;
	int		error;
	int		fd;
	int		height;
	int		width;
	t_data	*data;

}					t_control;

/*	ft_checks.c	*/
void	ft_checks(t_control *control);

/* ft_checks2.c */
void	ft_check_ber(char *file);
void	ft_check_file(int fd);
void	ft_check_fd(int fd);

/*	utils.c	*/
void	ft_init_control(t_control *control);
void	ft_init_data(t_data *data);
void	ft_free(char **ptr);
void	ft_exit(t_control *control);

/*	ft_mlx.c */
void	ft_mlx(t_control *control);
void	ft_fill_map(t_control *ctr);

/* ft_inputs.c */
int		ft_inputs(int key, t_control *ctr);

#endif