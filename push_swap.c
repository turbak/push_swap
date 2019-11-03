/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:41:01 by cauranus          #+#    #+#             */
/*   Updated: 2019/11/03 18:34:45 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_size(t_stack *a)
{
	int counter;

	counter = 0;
	while (a)
	{
		a = a->next;
		counter++;
	}
	return (counter);
}

void	size3(t_stack *a)
{
	if (a->num > a->next->num && a->next->num > a->next->next->num)
	{
		sab(&a);
		ft_putendl("sa");
		rrab(&a);
		ft_putendl("rra");
	}
	else if (a->num > a->next->num && a->next->next->num > a->next->num && a->num < a->next->next->num)
	{
		sab(&a);
		ft_putendl("sa");
	}
	else if (a->num > a->next->num && a->next->next->num > a->next->num && a->num > a->next->next->num)
	{
		rab(&a);
		ft_putendl("ra");
	}
	else if (a->num < a->next->num && a->next->next->num < a->next->num && a->num > a->next->next->num)
	{
		rrab(&a);
		ft_putendl("rra");
	}
	else if (a->num < a->next->num && a->next->next->num < a->next->num && a->num < a->next->next->num)
	{
		sab(&a);
		ft_putendl("sa");
		rab(&a);
		ft_putendl("ra");
	}
}

void	size5(t_stack *a, t_stack *b)
{
	move_num_up(&a, find_smallest(a), get_size(a));
	pab(&a, &b);
	ft_putendl("pb");
	move_num_up(&a, find_smallest(a), get_size(a));
	pab(&a, &b);
	ft_putendl("pb");
	size3(a);
	pab(&b, &a);
	pab(&b, &a);
	ft_putendl("pa\npa");
}

void	push_swap(t_stack *a, t_stack *b, int size, int *sort)
{
	int start;
	int max;
	int counter;
	t_stack	*number;

	if (size == 3)
		size3(a);
	else if (size == 5)
		size5(a, b);
	else
	{
		start = 0;
		max = size <= 19 ? size : 19;
		counter = 0;
		while (a->next)
		{
			number = find_min_ops(a, sort, max, start);
			move_num_up(&a, number, get_size(a));
			counter++;
			if (counter % 19 == 0)
			{
				start = start + 19 > size ? size : start + 19;
				max = max + 19 > size ? size : max + 19;
			}
			pab(&a, &b);
			ft_putendl("pb");
		}
		while (b)
		{
			pab(&b, &a);
			ft_putendl("pa");
		}
	}
}

int	main(int ac, char **av)
{
	t_stack *a;
	int size;
	int *sort;

	if (ac < 2)
		die();
	a = readtostack(av);
	size = get_size(a);
	sort = sorted_arr(readtoarr(av, size), size);
	push_swap(a, NULL, size, sort);
	return (0);
}
