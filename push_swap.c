/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:41:01 by cauranus          #+#    #+#             */
/*   Updated: 2019/11/04 20:16:01 by cauranus         ###   ########.fr       */
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

void	size3(t_stack **a)
{
	if ((*a)->num > (*a)->next->num && (*a)->next->num > (*a)->next->next->num)
	{
		sab(a);
		ft_putendl("sa");
		rrab(a);
		ft_putendl("rra");
	}
	else if ((*a)->num > (*a)->next->num && (*a)->next->next->num > (*a)->next->num && (*a)->num < (*a)->next->next->num)
	{
		sab(a);
		ft_putendl("sa");
	}
	else if ((*a)->num > (*a)->next->num && (*a)->next->next->num > (*a)->next->num && (*a)->num > (*a)->next->next->num)
	{
		rab(a);
		ft_putendl("ra");
	}
	else if ((*a)->num < (*a)->next->num && (*a)->next->next->num < (*a)->next->num && (*a)->num > (*a)->next->next->num)
	{
		rrab(a);
		ft_putendl("rra");
	}
	else if ((*a)->num < (*a)->next->num && (*a)->next->next->num < (*a)->next->num && (*a)->num < (*a)->next->next->num)
	{
		sab(a);
		ft_putendl("sa");
		rab(a);
		ft_putendl("ra");
	}
}

void	size5(t_stack *a, t_stack *b)
{
	move_num_up(&a, find_smallest(a), get_size(a), 'a');
	pab(&a, &b);
	ft_putendl("pb");
	move_num_up(&a, find_smallest(a), get_size(a), 'a');
	pab(&a, &b);
	ft_putendl("pb");
	size3(&a);
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

	if (size <= 1 || check(a))
		return ;
	else if (size == 2)
	{
		if (a->next->num < a->num)
		{
			sab(&a);
			ft_putendl("sa");
		}
	}
	else if (size == 3)
		size3(&a);
	else if (size == 5)
		size5(a, b);
	else if (size <= 100)
	{
		start = 0;
		max = size / 5;
		counter = 0;
		while (a)
		{
			number = find_min_ops(a, sort, max, start);
			move_num_up(&a, number, get_size(a), 'a');
			counter++;
			if (counter == max)
			{
				start = start + size / 5 > size ? size : start + size / 5;
				max = max + size / 5 > size ? size : max + size / 5;
			}
			pab(&a, &b);
			ft_putendl("pb");
		}
		while (b)
		{
			move_num_up(&b, find_biggest(b), get_size(b), 'b');
			pab(&b, &a);
			ft_putendl("pa");
		}
	}
	else
	{
		start = 0;
		max = size / 15;
		counter = 0;
		while (a)
		{
			number = find_min_ops(a, sort, max, start);
			move_num_up(&a, number, get_size(a), 'a');
			counter++;
			if (counter == max)
			{
				start = start + size / 15 > size ? size : start + size / 15;
				max = max + size / 15 > size ? size : max + size / 15;
			}
			pab(&a, &b);
			ft_putendl("pb");
		}
		while (b)
		{
			move_num_up(&b, find_biggest(b), get_size(b), 'b');
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
