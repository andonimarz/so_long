/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:10:40 by amarzana          #+#    #+#             */
/*   Updated: 2022/08/17 11:01:10 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_check_ber(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (file[len - 4] != '.' || file[len - 3] != 'b' || \
			file[len - 2] != 'e' || file[len - 1] != 'r')
	{
		ft_putstr_fd("Error\nYou must use a .ber map\n", 2);
		exit(0);
	}
}

void	ft_check_file(int fd)
{
	char	*buf;
	int		len;

	buf = ft_calloc(1, sizeof(char *));
	len = read(fd, buf, 1);
	free(buf);
	close(fd);
	if (len < 1)
	{
		ft_putstr_fd("Error\nInvalid or missing input file\n", 2);
		exit(0);
	}
}

void	ft_check_fd(int fd)
{
	if (fd < 0)
	{
		close(fd);
		ft_putstr_fd("Error\nInvalid or missing input file\n", 2);
		exit(0);
	}
}
