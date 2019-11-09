/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 19:34:56 by cauranus          #+#    #+#             */
/*   Updated: 2019/11/09 18:00:07 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void		die(void)
{
	write(2, "Error\n", 7);
	exit(-1);
}

void		sab(t_stack **a)
{
	t_stack *buf;

	if (!(*a) || !(*a)->next)
		return ;
	buf = (*a)->next;
	(*a)->next = (*a)->next->next;
	buf->next = (*a);
	(*a) = buf;
}

void		ss(t_stack **a, t_stack **b)
{
	sab(a);
	sab(b);
}
