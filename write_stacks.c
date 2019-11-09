/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 17:51:43 by cauranus          #+#    #+#             */
/*   Updated: 2019/11/09 18:45:13 by cauranus         ###   ########.fr       */
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
		write(flags->fd, "sa\n", 3);
	else if (op == 2)
		write(flags->fd, "sb\n", 3);
	else if (op == 3)
		write(flags->fd, "ss\n", 3);
	else if (op == 4)
		write(flags->fd, "pa\n", 3);
	else if (op == 5)
		write(flags->fd, "pb\n", 3);
	else if (op == 6)
		write(flags->fd, "ra\n", 3);
	else if (op == 7)
		write(flags->fd, "rb\n", 3);
	else if (op == 8)
		write(flags->fd, "rr\n", 3);
	else if (op == 9)
		write(flags->fd, "rra\n", 4);
	else if (op == 10)
		write(flags->fd, "rrb\n", 4);
	else if (op == 11)
		write(flags->fd, "rrr\n", 4);
	if (flags->v || flags->c)
		write_bonus(a, b, op, flags);
}
