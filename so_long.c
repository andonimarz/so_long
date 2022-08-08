/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 11:31:53 by amarzana          #+#    #+#             */
/*   Updated: 2022/08/08 16:45:39 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>
#include <fcntl.h>
#include "libft/libft.h"
#include "gnl/get_next_line.h"

int	ft_count_lines(int fd)
{
	int		len;
	int		count;
	char	*buffer;

	len = 1;
	count = 1;
	buffer = (char *)malloc(sizeof(char) * 1);
	if (!buffer)
		return (0);
	while (len > 0)
	{
		len = read(fd, buffer, 1);
		if (buffer[0] == '\n')
				count++;
	}
	free (buffer);
	return (count);
	close (fd);
}

static void	ft_init_control(t_control *control)
{
	control->map = NULL;
	control->aux = 0;
	control->error = 0;
	control->fd = 0;
	control->height = 0;
	control->width = 0;

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
		control.height = ft_count_lines(control.fd);
		control.fd = open(argv[1], O_RDONLY);
		control.map = (char **)malloc(sizeof(char *) * control.height);
		control.aux = control.height;
		control.i = 0;
		while (control.aux--)
			control.map[control.i++] = get_next_line(control.fd);
		control.error = 0;
		ft_checks(&control);
		printf("Error -> %d\n", control.error);
		printf("Height -> %d\n", control.height);
		printf("Width -> %d\n", control.width);
		control.i = -1;
		while (control.map[++control.i])
			printf("%s", control.map[control.i]);
		close(control.fd);
	}
}
