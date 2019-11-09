/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardcoded_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 20:08:27 by cauranus          #+#    #+#             */
/*   Updated: 2019/11/09 17:06:24 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	size3_2(t_stack **a, t_flags *flags)
{
	if ((*a)->num > (*a)->next->num && (*a)->next->next->num
	> (*a)->next->num && (*a)->num > (*a)->next->next->num)
	{
		rab(a);
		write_stacks(*a, *flags->b, flags, 6);
	}
	else if ((*a)->num < (*a)->next->num && (*a)->next->next->num
	< (*a)->next->num && (*a)->num > (*a)->next->next->num)
	{
		rrab(a);
		write_stacks(*a, *flags->b, flags, 9);
	}
	else if ((*a)->num < (*a)->next->num && (*a)->next->next->num
	< (*a)->next->num && (*a)->num < (*a)->next->next->num)
	{
		sab(a);
		write_stacks(*a, *flags->b, flags, 1);
		rab(a);
		write_stacks(*a, *flags->b, flags, 6);
	}
}

static void	size3(t_stack **a, t_flags *flags)
{
	if ((*a)->num > (*a)->next->num && (*a)->next->num
	> (*a)->next->next->num)
	{
		sab(a);
		write_stacks(*a, *flags->b, flags, 1);
		rrab(a);
		write_stacks(*a, *flags->b, flags, 9);
	}
	else if ((*a)->num > (*a)->next->num && (*a)->next->next->num
	> (*a)->next->num && (*a)->num < (*a)->next->next->num)
	{
		sab(a);
		write_stacks(*a, *flags->b, flags, 1);
	}
	size3_2(a, flags);
}

static void	size5(t_stack **a, t_stack **b, t_flags *flags)
{
	move_num_up(a, find_smallest(*a), get_size(*a), flags);
	pab(a, b);
	write_stacks(*a, *b, flags, 5);
	move_num_up(a, find_smallest(*a), get_size(*a), flags);
	pab(a, b);
	write_stacks(*a, *b, flags, 5);
	size3(a, flags);
	pab(b, a);
	write_stacks(*a, *b, flags, 4);
	pab(b, a);
	write_stacks(*a, *b, flags, 4);
}

void		less_5(t_stack **a, t_stack **b, int size, t_flags *flags)
{
	flags->stack = 'a';
	if (size <= 1 || check(*a))
		return ;
	else if (size == 2)
	{
		if ((*a)->next->num < (*a)->num)
		{
			sab(a);
			write_stacks(*a, *b, flags, 1);
		}
	}
	else if (size == 3)
		size3(a, flags);
	else if (size == 4)
	{
		move_num_up(a, find_smallest(*a), get_size(*a), flags);
		pab(a, b);
		write_stacks(*a, *b, flags, 5);
		size3(a, flags);
		pab(b, a);
		write_stacks(*a, *b, flags, 4);
	}
	else if (size == 5)
		size5(a, b, flags);
}
