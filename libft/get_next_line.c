/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 14:39:55 by cauranus          #+#    #+#             */
/*   Updated: 2019/11/11 19:37:35 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_vl(char *arr)
{
	int		i;

	i = 0;
	while (arr[i] && arr[i] != '\n')
		i++;
	return (i);
}

int				get_next_line(const int fd, char **line)
{
	static	char	*a[256];
	char			buf[BUFF_SIZE + 1];
	int				n;

	if (fd < 0 || !line || (read(fd, buf, 0) < 0))
		return (-1);
	if (!a[fd])
		a[fd] = ft_strnew(0);
	while ((n = read(fd, buf, BUFF_SIZE)))
	{
		buf[n] = '\0';
		ft_swapfree((void**)&a[fd], ft_strjoin(a[fd], buf));
		if (ft_strchr(a[fd], '\n'))
			break ;
	}
	if (!n && *a[fd] == '\0')
		return (0);
	*line = ft_strsub(a[fd], 0, ft_vl(a[fd]));
	n = ft_strlen(a[fd] + ft_vl(a[fd]) + 1);
	(ft_strlen(*line) < ft_strlen(a[fd])) ?
	ft_memmove(a[fd], a[fd] + ft_vl(a[fd]) + 1, n + 1) : ft_strdel(&a[fd]);
	return (1);
}
