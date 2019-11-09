/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 18:06:24 by cauranus          #+#    #+#             */
/*   Updated: 2019/11/09 18:18:45 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	write_bonus_2(t_stack *a, int op, t_flags *flags)
{
	if (((op == 1 && flags->flag < 2) ||
	(op == 3 && flags->flag < 4)) && flags->c)
	{
		flags->flag++;
		write(1, RED, 6);
	}
	if (op == 4 && !flags->flag && flags->c)
	{
		flags->flag++;
		write(1, BLU, 6);
	}
	if ((!a->next && flags->c && op == 6) ||
	(!a->next && op == 8 && flags->c))
		write(1, CYN, 6);
	if ((op == 9 && flags->c && !flags->flag) ||
	(op == 11 && flags->c && flags->flag < 2))
	{
		flags->flag++;
		write(1, LGN, 6);
	}
	ft_putnbr(a->num);
	if (flags->c)
		write(1, WHT, 6);
	write(1, "          ", 10 - ft_numlen(a->num));
}

static void	write_bonus_3(t_stack *b, int op, t_flags *flags)
{
	if (((op == 2 && flags->flag < 2) ||
	(op == 3 && flags->flag < 4)) && flags->c)
	{
		flags->flag++;
		write(1, GRN, 6);
	}
	if (op == 5 && !flags->flag && flags->c)
	{
		flags->flag++;
		write(1, MAG, 6);
	}
	if ((!b->next && flags->c && op == 7) ||
	(!b->next && op == 8 && flags->c))
		write(1, LCN, 6);
	if ((op == 10 && flags->c && !flags->flag) ||
	(op == 11 && flags->c && flags->flag < 2))
	{
		flags->flag++;
		write(1, LYL, 6);
	}
	ft_putnbr(b->num);
	if (flags->c)
		write(1, WHT, 6);
	ft_putchar('\n');
}

static void	write_bonus_4(t_stack *a, int op, t_flags *flags)
{
	if (((op == 1 && flags->flag < 2) ||
	(op == 3 && flags->flag < 4)) && flags->c)
	{
		flags->flag++;
		write(1, RED, 6);
	}
	if (op == 4 && !flags->flag && flags->c)
	{
		flags->flag++;
		write(1, BLU, 6);
	}
	if ((!a->next && flags->c && op == 6) ||
	(!a->next && op == 8 && flags->c))
		write(1, CYN, 6);
	if ((op == 9 && flags->c && !flags->flag) ||
	(op == 11 && flags->c && flags->flag < 2))
	{
		flags->flag++;
		write(1, LGN, 6);
	}
	ft_putnbr(a->num);
	if (flags->c)
		write(1, WHT, 6);
	ft_putstr("\n");
}

static void	write_bonus_5(t_stack *b, int op, t_flags *flags)
{
	ft_putstr("           ");
	if (((op == 2 && flags->flag < 2) ||
	(op == 3 && flags->flag < 4)) && flags->c)
	{
		flags->flag++;
		write(1, GRN, 6);
	}
	if (op == 5 && !flags->flag && flags->c)
	{
		flags->flag++;
		write(1, MAG, 6);
	}
	if ((!b->next && flags->c && op == 7) ||
	(!b->next && op == 8 && flags->c))
		write(1, LCN, 6);
	if ((op == 10 && flags->c && !flags->flag) ||
	(op == 11 && flags->c && flags->flag < 2))
	{
		flags->flag++;
		write(1, LYL, 6);
	}
	ft_putnbr(b->num);
	if (flags->c)
		write(1, WHT, 6);
	ft_putchar('\n');
}

void		write_bonus(t_stack *a, t_stack *b, int op, t_flags *flags)
{
	flags->flag = 0;
	ft_putchar('\n');
	while (a || b)
	{
		if (a && b)
		{
			write_bonus_2(a, op, flags);
			write_bonus_3(b, op, flags);
			a = a->next;
			b = b->next;
		}
		else if (a && !b)
		{
			write_bonus_4(a, op, flags);
			a = a->next;
		}
		else if (!a && b)
		{
			write_bonus_5(b, op, flags);
			b = b->next;
		}
	}
	ft_putstr("-          -\na          b\n\n");
}
