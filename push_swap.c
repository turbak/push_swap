/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:41:01 by cauranus          #+#    #+#             */
/*   Updated: 2019/11/07 15:46:37 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	clear_b(t_stack **a, t_stack **b)
{
	while (*b)
	{
		move_num_up(b, find_biggest(*b), get_size(*b), 'b');
		pab(b, a);
		ft_putendl("pa");
	}
}

static void	less_100(t_stack **a, t_stack **b, int size, int *sort)
{
	int		start;
	int		max;
	int		counter;
	t_stack	*number;

	start = 0;
	max = size / 5;
	counter = 0;
	while (*a)
	{
		number = find_min_ops(*a, sort, max, start);
		move_num_up(a, number, get_size(*a), 'a');
		counter++;
		if (counter == max)
		{
			start = start + size / 5 > size ? size : start + size / 5;
			max = max + size / 5 > size ? size : max + size / 5;
		}
		pab(a, b);
		ft_putendl("pb");
	}
	clear_b(a, b);
}

static void	more(t_stack **a, t_stack **b, int size, int *sort)
{
	int		start;
	int		max;
	int		counter;
	t_stack	*number;

	start = 0;
	max = size / 11;
	counter = 0;
	while (*a)
	{
		number = find_min_ops(*a, sort, max, start);
		move_num_up(a, number, get_size(*a), 'a');
		counter++;
		if (counter == max)
		{
			start = start + size / 11 > size ? size : start + size / 11;
			max = max + size / 11 > size ? size : max + size / 11;
		}
		pab(a, b);
		ft_putendl("pb");
	}
	clear_b(a, b);
}

void		push_swap(t_stack *a, t_stack *b, int size, int *sort)
{
	if (size <= 5 || check(a))
		less_5(&a, &b, size);
	else if (size <= 101)
		less_100(&a, &b, size, sort);
	else
		more(&a, &b, size, sort);
	free_stack(&a);
	a = NULL;
}

int			main(int ac, char **av)
{
	t_stack	*a;
	int		size;
	int		*sort;

	if (ac < 2)
		die();
	a = readtostack(av);
	size = get_size(a);
	sort = readtoarr(read_to_arr(av), size);
	sort_arr(&sort, size);
	push_swap(a, NULL, size, sort);
	ft_memdel((void **)&sort);
	return (0);
}
