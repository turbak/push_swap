/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 18:59:07 by cauranus          #+#    #+#             */
/*   Updated: 2019/11/05 20:32:23 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				get_ptr_pos(t_stack *a, t_stack *num)
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

static int		count_ops2(t_stack **cpy, t_stack *numb, int ops, int size)
{
	if (get_ptr_pos(*cpy, numb) > size / 2)
	{
		while (*cpy != numb)
		{
			if ((*cpy)->next == numb)
				sab(cpy);
			else
				rrab(cpy);
			ops++;
		}
	}
	else
	{
		while (*cpy != numb)
		{
			if ((*cpy)->next == numb)
				sab(cpy);
			else
				rab(cpy);
			ops++;
		}
	}
	return (ops);
}

int				count_operations(t_stack *a, int num, int size)
{
	int		ops;
	t_stack	*cpy;
	t_stack	*numb;

	ops = 0;
	cpy = stackcpy(a);
	numb = find_num(cpy, num);
	if (numb == NULL)
		return (-1);
	ops += count_ops2(&cpy, numb, ops, size);
	free_stack(cpy);
	return (ops);
}

static void		rrab_up(t_stack **a, t_stack *num, char stack)
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

void			move_num_up(t_stack **a, t_stack *num, int size, char stack)
{
	if (!(*a)->next)
		return ;
	if (get_ptr_pos(*a, num) > size / 2)
		rrab_up(a, num, stack);
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
