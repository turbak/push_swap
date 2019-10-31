/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 16:42:24 by cauranus          #+#    #+#             */
/*   Updated: 2019/10/30 21:24:02 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
* swap first 2 elems of stack
*/

void	sab(t_stack **a)
{
	t_stack *buf;
	
	if (!(*a) || !(*a)->next)
		return ;
	buf = (*a)->next;
	(*a)->next = (*a)->next->next;
	buf->next = (*a);
	(*a) = buf;
}

/*
* swap first 2 elems of stack in both stacks
*/
void	ss(t_stack **a, t_stack **b)
{
	sab(a);
	sab(b);
}
/*
* push first elem of one stack to another
*/
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
/*
** rotate elems up in stack by 1
*/
void	rab(t_stack **a)
{
	t_stack *head;

	if ((*a)->next)
	{
		head = (*a);
		while ((*a)->next)
			(*a) = (*a)->next;
		(*a)->next = head;
		(*a) = head->next;
		head->next = NULL;
	}
}
/*
* rotate elems up in both stacks by 1
*/
void	rr(t_stack **a, t_stack **b)
{
	rab(a);
	rab(b);	
}
/*
* rotate elems down in stack by 1
*/
void	rrab(t_stack **a)
{
	t_stack *end;

	if ((*a)->next)
	{
		end = (*a);
		while (end->next->next)
			end = end->next;
		end->next->next = (*a);
		(*a) = end->next;
		end->next = NULL;
	}
}
/*
* rotate elems down in both stacks by 1
*/
void	rrr(t_stack **a, t_stack **b)
{
	rrab(a);
	rrab(b);
}
