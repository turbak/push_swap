/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 21:19:41 by cauranus          #+#    #+#             */
/*   Updated: 2019/10/31 18:11:35 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void die(void)
{
	write(2, "Error\n", 7);
	exit(-1);
}

t_stack	*atostack(int *arg, int size)
{
	t_stack *a;
	t_stack *head;
	int		i;

	validate_arr(arg, size);
	a = malloc(sizeof(t_stack));
	a->num = arg[0];
	head = a;
	i = 1;
	while (size > i)
	{
		a->next = malloc(sizeof(t_stack));
		a = a->next;
		a->num = arg[i];
		i++;
		a->next = NULL;
	}
	ft_memdel((void **)&arg);
	return (head);
}

void	validate_arr(int *arg, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while(j < size)
		{
			if (arg[i] == arg[j] && j != i)
			{
				ft_memdel((void**)&arg);
				die();
			}
			j++;
		}
		i++;
	}
}

t_stack	*readtostack(char **av)
{
	int size;
	int *arg;
	int i;

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
	return (atostack(arg, size - 1));
}
