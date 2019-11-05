/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardcoded_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 20:08:27 by cauranus          #+#    #+#             */
/*   Updated: 2019/11/05 20:36:58 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	size3_2(t_stack **a)
{
	if ((*a)->num > (*a)->next->num && (*a)->next->next->num
	> (*a)->next->num && (*a)->num > (*a)->next->next->num)
	{
		rab(a);
		ft_putendl("ra");
	}
	else if ((*a)->num < (*a)->next->num && (*a)->next->next->num
	< (*a)->next->num && (*a)->num > (*a)->next->next->num)
	{
		rrab(a);
		ft_putendl("rra");
	}
	else if ((*a)->num < (*a)->next->num && (*a)->next->next->num
	< (*a)->next->num && (*a)->num < (*a)->next->next->num)
	{
		sab(a);
		ft_putendl("sa");
		rab(a);
		ft_putendl("ra");
	}
}

static void	size3(t_stack **a)
{
	if ((*a)->num > (*a)->next->num && (*a)->next->num
	> (*a)->next->next->num)
	{
		sab(a);
		ft_putendl("sa");
		rrab(a);
		ft_putendl("rra");
	}
	else if ((*a)->num > (*a)->next->num && (*a)->next->next->num
	> (*a)->next->num && (*a)->num < (*a)->next->next->num)
	{
		sab(a);
		ft_putendl("sa");
	}
	size3_2(a);
}

static void	size5(t_stack **a, t_stack **b)
{
	move_num_up(a, find_smallest(*a), get_size(*a), 'a');
	pab(a, b);
	ft_putendl("pb");
	move_num_up(a, find_smallest(*a), get_size(*a), 'a');
	pab(a, b);
	ft_putendl("pb");
	size3(a);
	pab(b, a);
	pab(b, a);
	ft_putendl("pa\npa");
}

void		less_5(t_stack **a, t_stack **b, int size)
{
	if (size <= 1 || check(*a))
		return ;
	else if (size == 2)
	{
		if ((*a)->next->num < (*a)->num)
		{
			sab(a);
			ft_putendl("sa");
		}
	}
	else if (size == 3)
		size3(a);
	else if (size == 4)
	{
		move_num_up(a, find_smallest(*a), get_size(*a), 'a');
		pab(a, b);
		ft_putendl("pb");
		size3(a);
		pab(b, a);
	}
	else if (size == 5)
		size5(a, b);
}
