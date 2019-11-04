/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 18:59:07 by cauranus          #+#    #+#             */
/*   Updated: 2019/11/04 17:31:04 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*find_biggest(t_stack *b)
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

t_stack		*find_num(t_stack *a, int number)
{
	t_stack *numb;
	
	numb = NULL;
	while (a)
	{
		if (a->num == number)
			numb = a;
		a = a->next;
	}
	return (numb);
}

int			count_operations(t_stack *a, int num, int size)
{
	int ops;
	t_stack *cpy;
	t_stack *numb;

	ops = 0;
	cpy = stackcpy(a);
	numb = find_num(cpy, num);
	if (numb == NULL)
		return (-1);
	if (get_ptr_pos(cpy, numb) > size / 2)
	{
		while (cpy != numb)
		{
			if (cpy->next == numb)
				sab(&cpy);
			else
				rrab(&cpy);
			ops++;
		}
	}
	else
	{
		while (cpy != numb)
		{
			if (cpy->next == numb)
				sab(&cpy);
			else
				rab(&cpy);
			ops++;
		}
	}
	free_stack(&cpy);
	return (ops);
}

void		move_num_up(t_stack **a, t_stack *num, int size, char stack)
{
	if (!(*a)->next)
		return ;
	if (get_ptr_pos(*a, num) > size / 2)
	{
		while (*a != num)
		{
			if ((*a)->next == num)
			{
				sab(a);
				ft_putendl(stack == 'a' ? "sa" : "sb");
			}
			else
			{
				rrab(a);
				ft_putendl(stack == 'a' ? "rra" : "rrb");
			}
		}
	}
	else
	{
		while (*a != num)
		{
			if ((*a)->next == num)
			{
				sab(a);
				ft_putendl(stack == 'a' ? "sa" : "sb");
			}
			else
			{
				rab(a);
				ft_putendl(stack == 'a' ? "ra" : "rb");
			}
		}
	}
}
