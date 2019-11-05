/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_stack_funcs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 17:58:33 by cauranus          #+#    #+#             */
/*   Updated: 2019/11/05 19:45:37 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check(t_stack *a)
{
	if (!a)
		return (0);
	else if (a && !a->next)
		return (1);
	while (a->next)
	{
		if (a->num > a->next->num)
			return (0);
		a = a->next;
	}
	return (1);
}

int		get_size(t_stack *a)
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

int		check_reversed(t_stack *a)
{
	while (a->next)
	{
		if (a->num < a->next->num)
			return (0);
		a = a->next;
	}
	return (1);
}

t_stack	*find_biggest(t_stack *b)
{
	t_stack *biggest;

	biggest = b;
	while (b)
	{
		if (b->num > biggest->num)
			biggest = b;
		b = b->next;
	}
	return (biggest);
}

t_stack	*find_smallest(t_stack *a)
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
