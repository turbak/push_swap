/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:41:01 by cauranus          #+#    #+#             */
/*   Updated: 2019/11/01 21:39:10 by cauranus         ###   ########.fr       */
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
	pab(&a, &b);
	pab(&a, &b);
	ft_putendl("pb\npb");
	size3(a);
	if (b->num > b->next->num)
	{
		sab(&b);
		ft_putendl("sb");
	}
	pab(&b, &a);
	pab(&b, &a);
	ft_putendl("pa\npa");	
}

void	push_swap(t_stack *a, t_stack *b, int size)
{
	if (size == 3)
		size3(a);
	else if (size == 5)
		size5(a, b);
	else if (size < 101)
	{
		while (a->next)
		{
			move_num_up(&a, find_smallest(a), get_size(a));
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

	if (ac < 2)
		die();
	a = readtostack(av);
	size = get_size(a);
	push_swap(a, NULL, size);
	return (0);
}
