/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 12:10:53 by cauranus          #+#    #+#             */
/*   Updated: 2019/11/05 17:14:46 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char **read_to_arr(char **av)
{
	char *str;
	int size;
	int i;
	char **argv;

	size = 1;
	str = ft_strnew(0);
	while (av[size])
	{
		i = 0;
		argv = ft_strsplit(av[size], ' ');
		while (argv[i])
		{
			ft_swapfree((void**)&str, ft_strjoin(str, argv[i]));
			ft_swapfree((void**)&str, ft_strjoin(str, " "));
			i++;
		}
		free_array(argv);
		free(argv);
		size++;
	}
	argv = ft_strsplit(str, ' ');
	ft_strdel(&str);
	return (argv);
}

int	validate_str(char *str)
{
	int i;

	i = 0;
	if (*str == '-')
		str++;
	if (ft_strlen(str) > 10)
		return (0);
	else if (ft_strlen(str) == 10)
		if (ft_atoi(str) == 0 || ft_atoi(str) == -1)
			return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}