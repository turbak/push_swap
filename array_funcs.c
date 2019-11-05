/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 21:19:41 by cauranus          #+#    #+#             */
/*   Updated: 2019/11/05 15:05:00 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void die(void)
{
	write(2, "Error\n", 7);
	exit(-1);
}

int		*sorted_arr(int *sort, int size)
{
	int i;
	int j;
	int buf;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (sort[i] > sort[j])
			{	
				buf = sort[i];
				sort[i] = sort[j];
				sort[j] = buf;
			}
			j++;
		}
		i++;
	}
	return (sort);
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

int		*readtoarr(char **argv, int size)
{
	int i;
	int *arg;
	
	arg = (int *)malloc(sizeof(int) * size);
	i = 0;
	while (argv[i])
	{
		arg[i] = ft_atoi(argv[i]);
		i++;
	}
	free_array(argv);
	return (arg);
}

t_stack	*readtostack(char **av)
{
	char 	**argv;
	int 	*arg;
	int		i;

	argv = read_to_arr(av);
	i = 0;
	while (argv[i])
		i++;
	arg = (int *)malloc(sizeof(int) * i);
	i = 0;
	while (argv[i])
	{
		if (!validate_str(argv[i]))
		{
			free_array(argv);
			die();
		}
		arg[i] = ft_atoi(argv[i]);
		printf("[%d]\n", arg[i]);
		i++;
	}
	free_array(argv);
	return (atostack(arg, i));
}
