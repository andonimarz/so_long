/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:45:26 by amarzana          #+#    #+#             */
/*   Updated: 2022/08/06 12:11:50 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 1
# include "../libft/libft.h"

char	*get_next_line(int fd);
char	*ft_gnl_strjoin(char *s1, char *s2);
char	*ft_gnl_strchr(char *str, int c);

#endif
