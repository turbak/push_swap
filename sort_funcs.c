/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 18:59:07 by cauranus          #+#    #+#             */
/*   Updated: 2019/11/01 21:38:49 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*find_smallest(t_stack *a)
{
	t_stack *smallest;

	smallest = a;
	while (a)
	{
		if (a->num < smallest->num)
			smallest = a;
		a = a->next;
	}
	return (smallest);
}

int			get_ptr_pos(t_stack *a, t_stack *num)
{
	int counter;

	counter = 0;
	while (a != num)
	{
		a = a->next;
		counter++;
	}
	return (counter);
}

void		move_num_up(t_stack **a, t_stack *num, int size)
{
	if (get_ptr_pos(*a, num) > size / 2)
	{
		while (*a != num)
		{
			rrab(a);
			ft_putendl("rra");
		}
	}
	else
	{
		while (*a != num)
		{
			rab(a);
			ft_putendl("ra");
		}
	}
}
