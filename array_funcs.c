/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 21:19:41 by cauranus          #+#    #+#             */
/*   Updated: 2019/11/10 22:49:32 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sort_arr(int **sor, int size)
{
	int i;
	int j;
	int buf;
	int *sort;

	sort = *sor;
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
}

t_stack		*atostack(int *arg, int size)
{
	t_stack	*a;
	t_stack	*head;
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
	a->next = NULL;
	ft_memdel((void **)&arg);
	return (head);
}

void		validate_arr(int *arg, int size)
{
	int i;
	int j;

	if (!size)
		die();
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (arg[i] == arg[j] && j != i)
			{
				ft_memdel((void **)&arg);
				die();
			}
			j++;
		}
		i++;
	}
}

int			*readtoarr(char **argv, int size)
{
	int i;
	int *arg;

	arg = (int *)malloc(sizeof(int) * size);
	i = 0;
	while (argv[i])
	{
		arg[i] = ft_atoi(argv[i]);
		ft_strdel(&argv[i]);
		i++;
	}
	free(argv);
	return (arg);
}

t_stack		*readtostack(char **av, t_flags *flags)
{
	char	**argv;
	int		*arg;
	int		i;

	get_flags(av, flags);
	argv = read_to_arr(av, flags);
	i = 0;
	while (argv[i])
		i++;
	arg = (int *)malloc(sizeof(int) * i);
	i = -1;
	while (argv[++i])
	{
		if (!validate_str(argv[i]))
		{
			while (argv[i])
				ft_strdel(&argv[i++]);
			free(argv);
			die();
		}
		arg[i] = ft_atoi(argv[i]);
		ft_memdel((void**)&argv[i]);
	}
	free(argv);
	return (atostack(arg, i));
}
