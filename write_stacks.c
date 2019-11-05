/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 17:58:33 by cauranus          #+#    #+#             */
/*   Updated: 2019/11/05 16:41:09 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check(t_stack *a)
{
	if (a && !a->next)
		return (1);
	while (a->next)
	{
		if (a->num > a->next->num)
			return (0);
		a = a->next;
	}
	return (1);
}


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

int	check_reversed(t_stack *a)
{
	while (a->next)
	{
		if (a->num < a->next->num)
			return (0);
		a = a->next;
	}
	return (1);
}


void	write_stacks(t_stack *a, t_stack *b)
{
	while (a || b)
	{
		if (a && b)
		{
			printf("%d %d\n", a->num, b->num);
			a = a->next;
			b = b->next;
		}
		else if (a && !b)
		{
			printf("%d  \n", a->num);
			a = a->next;
		}
		else if (!a && b)
		{
			printf("   %d\n", b->num);
			b = b->next;
		}
	}
	printf("- -\na b\n");
}