/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 11:31:53 by amarzana          #+#    #+#             */
/*   Updated: 2022/08/09 18:40:48 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <unistd.h>
#include <fcntl.h>

int	ft_count_lines(t_control *control)
{
	int	i;

	i = 0;
	while (control->map[i])
		i++;
	return (i);
}

static void	ft_init_control(t_control *control)
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

void	ft_free(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
		free(ptr[i++]);
	free(ptr);
}

static char	*ft_get_map(t_control *control)
{
	int		len;
	int		first;
	char	*buf;
	char	*str;

	first = 0;
	len = 1;
	buf = ft_calloc(1, sizeof(char *));
	if (!buf)
		return (0);
	while (len > 0)
	{
		len = read(control->fd, buf, 1);
		if (first && len)
			str = ft_strjoin(str, buf);
		else if (first++ == 0)
			ft_strlcpy(str, buf, 2);
	}
	free (buf);
	close (control->fd);
	return (str);
}

int	main(int argc, char **argv)
{
	t_control	control;

	ft_init_control(&control);
	if (argc > 1)
	{
		control.fd = open(argv[1], O_RDONLY);
		if (control.fd < 0)
		{
			close(control.fd);
			ft_putstr_fd("Error\n Invalid or missing input file\n", 2);
			exit(0);
		}
		control.str = ft_get_map(&control);
		control.map = ft_split(control.str, '\n');
		free (control.str);
		control.height = ft_count_lines(&control);
		ft_checks(&control);
		control.i = -1;
		while (control.map[++control.i])
			printf("%s\n", control.map[control.i]);
		printf("Error -> %d\n", control.error);
		printf("Height -> %d\n", control.height);
		printf("Width -> %d\n", control.width);
		ft_free(control.map);
	}
}
