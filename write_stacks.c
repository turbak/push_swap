/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 17:51:43 by cauranus          #+#    #+#             */
/*   Updated: 2019/11/09 18:19:57 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_numlen(int n)
{
	int len;

	len = -1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void		write_stacks(t_stack *a, t_stack *b, t_flags *flags, int op)
{
	if (op == 1)
		write(1, "sa\n", 3);
	else if (op == 2)
		write(1, "sb\n", 3);
	else if (op == 3)
		write(1, "ss\n", 3);
	else if (op == 4)
		write(1, "pa\n", 3);
	else if (op == 5)
		write(1, "pb\n", 3);
	else if (op == 6)
		write(1, "ra\n", 3);
	else if (op == 7)
		write(1, "rb\n", 3);
	else if (op == 8)
		write(1, "rr\n", 3);
	else if (op == 9)
		write(1, "rra\n", 4);
	else if (op == 10)
		write(1, "rrb\n", 4);
	else if (op == 11)
		write(1, "rrr\n", 4);
	if (flags->v || flags->c)
		write_bonus(a, b, op, flags);
}
