/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 11:31:53 by amarzana          #+#    #+#             */
/*   Updated: 2022/08/17 11:00:43 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <unistd.h>
#include <fcntl.h>

static int	ft_count_lines(t_control *control)
{
	int	i;

	i = 0;
	while (control->map[i])
		i++;
	return (i);
}

static char	*ft_get_map(t_control *control)
{
	int		len;
	int		first;
	char	*buf;
	char	*str;
	char	*aux;

	first = 0;
	len = 1;
	buf = ft_calloc(1, sizeof(char *));
	while (len > 0)
	{
		len = read(control->fd, buf, 1);
		if (first && len)
		{
			aux = ft_strjoin(str, buf);
			free(str);
			str = ft_strdup(aux);
			free (aux);
		}
		else if (first++ == 0)
			str = ft_strdup(buf);
	}
	free (buf);
	close (control->fd);
	return (str);
}

int	main(int argc, char **argv)
{
	t_control	control;

	if (argc == 2)
	{
		ft_init_control(&control);
		ft_check_ber(argv[1]);
		control.fd = open(argv[1], O_RDONLY);
		ft_check_file(control.fd);
		control.fd = open(argv[1], O_RDONLY);
		ft_check_fd(control.fd);
		control.str = ft_get_map(&control);
		control.map = ft_split(control.str, '\n');
		free (control.str);
		control.height = ft_count_lines(&control);
		ft_checks(&control);
		ft_mlx(&control);
		ft_exit(&control);
	}
	else
		ft_putstr_fd("Error\nInvalid arg number.\n", 2);
}
