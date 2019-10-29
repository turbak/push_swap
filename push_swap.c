/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:41:01 by cauranus          #+#    #+#             */
/*   Updated: 2019/10/29 21:52:26 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void die(void)
{
	write(1, "Error", 6);
	exit(-1);
}

int	main(int ac, char **av)
{
	int *arg;
	int i;
	int size;

	if (ac < 2)
		die();
	size = 1;
	while (av[size])
	{
		i = 0;
		while(av[size][i])
		{
			if (!(av[size][i] > '0' || av[size][i] < '9' || av[size][i] == '-'))
				die();
			i++;
		}
		size++;
	}
	arg = (int *)malloc(sizeof(int) * size - 1);
	i = 0;
	while (av[i + 1])
	{
		arg[i] = ft_atoi(av[i + 1]);
		i++;
	}
	write_stacks(atostack(arg, size - 1), NULL);
	return (0);
}
