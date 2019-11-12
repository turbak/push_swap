/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:41:01 by cauranus          #+#    #+#             */
/*   Updated: 2019/11/11 19:34:10 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	clear_b(t_stack **a, t_stack **b, t_flags *flags)
{
	while (*b)
	{
		move_num_up(b, find_biggest(*b), get_size(*b), flags);
		pab(b, a);
		write_stacks(*flags->a, *flags->b, flags, 4);
	}
}

static void	less_100(t_stack **a, t_stack **b, int size, t_flags *flags)
{
	int		start;
	int		max;
	int		counter;
	t_stack	*number;

	start = 0;
	max = size / 5;
	counter = 0;
	while (*a)
	{
		flags->stack = 'a';
		number = find_min_ops(*a, flags->sort, max, start);
		move_num_up(a, number, get_size(*a), flags);
		counter++;
		if (counter == max)
		{
			start = start + size / 5 > size ? size : start + size / 5;
			max = max + size / 5 > size ? size : max + size / 5;
		}
		pab(a, b);
		write_stacks(*a, *b, flags, 5);
	}
	flags->stack = 'b';
	clear_b(a, b, flags);
}

static void	more(t_stack **a, t_stack **b, int size, t_flags *flags)
{
	int		start;
	int		max;
	int		counter;
	t_stack	*number;

	start = 0;
	max = size / 11;
	counter = 0;
	while (*a)
	{
		flags->stack = 'a';
		number = find_min_ops(*a, flags->sort, max, start);
		move_num_up(a, number, get_size(*a), flags);
		counter++;
		if (counter == max)
		{
			start = start + size / 11 > size ? size : start + size / 11;
			max = max + size / 11 > size ? size : max + size / 11;
		}
		pab(a, b);
		write_stacks(*a, *b, flags, 5);
	}
	flags->stack = 'b';
	clear_b(a, b, flags);
}

void		push_swap(t_stack *a, t_stack *b, int size, t_flags *flags)
{
	flags->b = &b;
	flags->a = &a;
	if (size <= 5 || check(a))
		less_5(&a, &b, size, flags);
	else if (size <= 101)
		less_100(&a, &b, size, flags);
	else
		more(&a, &b, size, flags);
	free_stack(&a);
	a = NULL;
}

int			main(int ac, char **av)
{
	t_stack	*a;
	int		size;
	t_flags	flags;

	if (ac < 2)
		return (0);
	flags.fd = 1;
	flags.stack = 'a';
	a = readtostack(av, &flags);
	if (flags.w)
		flags.fd = open("operations", O_WRONLY | O_CREAT |
		O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	size = get_size(a);
	flags.sort = readtoarr(read_to_arr(av, &flags), size);
	sort_arr(&flags.sort, size);
	push_swap(a, NULL, size, &flags);
	ft_memdel((void **)&flags.sort);
	return (0);
}
