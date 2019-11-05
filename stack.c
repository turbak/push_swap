/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 16:42:24 by cauranus          #+#    #+#             */
/*   Updated: 2019/11/05 19:59:33 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pab(t_stack **a, t_stack **b)
{
	t_stack *buf;

	if (!(*a))
		return ;
	buf = (*a)->next;
	(*a)->next = (*b);
	(*b) = (*a);
	(*a) = buf;
}

void	rab(t_stack **a)
{
	t_stack *head;

	if ((*a) && (*a)->next)
	{
		head = (*a);
		while ((*a)->next)
			(*a) = (*a)->next;
		(*a)->next = head;
		(*a) = head->next;
		head->next = NULL;
	}
}

void	rr(t_stack **a, t_stack **b)
{
	rab(a);
	rab(b);
}

void	rrab(t_stack **a)
{
	t_stack *end;

	if ((*a) && (*a)->next)
	{
		end = (*a);
		while (end->next->next)
			end = end->next;
		end->next->next = (*a);
		(*a) = end->next;
		end->next = NULL;
	}
}

void	rrr(t_stack **a, t_stack **b)
{
	rrab(a);
	rrab(b);
}
