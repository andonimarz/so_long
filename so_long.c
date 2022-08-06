/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 11:31:53 by amarzana          #+#    #+#             */
/*   Updated: 2022/08/06 13:12:17 by amarzana         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	int		fd;
	int		line_nb;
	char	**map;
	int		i;

	i = 0;
	if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
		{
			close(fd);
			ft_putstr_fd("Error\n Invalid or missing input file\n", 2);
			exit(0);
		}
		line_nb = ft_count_lines(fd);
		fd = open(argv[1], O_RDONLY);
		map = (char **)malloc(sizeof(char *) * line_nb);
		while (line_nb--)
			map[i++] = get_next_line(fd);
		i = -1;
		while (map[++i])
			printf("%s", map[i]);
		close(fd);
	}
}
