/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 18:06:24 by cauranus          #+#    #+#             */
/*   Updated: 2019/11/10 16:27:15 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	write_bonus_2(t_stack *a, int op, t_flags *flags)
{
	if (((op == 1 && flags->flag < 2) ||
	(op == 3 && flags->flag < 4)) && flags->c)
	{
		flags->flag++;
		write(flags->fd, RED, 6);
	}
	if (op == 4 && !flags->flag && flags->c)
	{
		flags->flag++;
		write(flags->fd, BLU, 6);
	}
	if ((!a->next && flags->c && op == 6) ||
	(!a->next && op == 8 && flags->c))
		write(flags->fd, CYN, 6);
	if ((op == 9 && flags->c && !flags->flag) ||
	(op == 11 && flags->c && flags->flag < 2))
	{
		flags->flag++;
		write(flags->fd, LGN, 6);
	}
	ft_putnbr_fd(a->num, flags->fd);
	if (flags->c)
		write(flags->fd, WHT, 6);
	write(flags->fd, "          ", 10 - ft_numlen(a->num));
}

static void	write_bonus_3(t_stack *b, int op, t_flags *flags)
{
	if (((op == 2 && flags->flag < 2) ||
	(op == 3 && flags->flag < 4)) && flags->c)
	{
		flags->flag++;
		write(flags->fd, GRN, 6);
	}
	if (op == 5 && !flags->flag && flags->c)
	{
		flags->flag++;
		write(flags->fd, MAG, 6);
	}
	if ((!b->next && flags->c && op == 7) ||
	(!b->next && op == 8 && flags->c))
		write(flags->fd, LCN, 6);
	if ((op == 10 && flags->c && !flags->flag) ||
	(op == 11 && flags->c && flags->flag < 2))
	{
		flags->flag++;
		write(flags->fd, LYL, 6);
	}
	ft_putnbr_fd(b->num, flags->fd);
	if (flags->c)
		write(flags->fd, WHT, 6);
	ft_putchar_fd('\n', flags->fd);
}

static void	write_bonus_4(t_stack *a, int op, t_flags *flags)
{
	if (((op == 1 && flags->flag < 2) ||
	(op == 3 && flags->flag < 4)) && flags->c)
	{
		flags->flag++;
		write(flags->fd, RED, 6);
	}
	if (op == 4 && !flags->flag && flags->c)
	{
		flags->flag++;
		write(flags->fd, BLU, 6);
	}
	if ((!a->next && flags->c && op == 6) ||
	(!a->next && op == 8 && flags->c))
		write(flags->fd, CYN, 6);
	if ((op == 9 && flags->c && !flags->flag) ||
	(op == 11 && flags->c && flags->flag < 2))
	{
		flags->flag++;
		write(flags->fd, LGN, 6);
	}
	ft_putnbr_fd(a->num, flags->fd);
	if (flags->c)
		write(flags->fd, WHT, 6);
	ft_putstr_fd("\n", flags->fd);
}

static void	write_bonus_5(t_stack *b, int op, t_flags *flags)
{
	ft_putstr("           ");
	if (((op == 2 && flags->flag < 2) ||
	(op == 3 && flags->flag < 4)) && flags->c)
	{
		flags->flag++;
		write(flags->fd, GRN, 6);
	}
	if (op == 5 && !flags->flag && flags->c)
	{
		flags->flag++;
		write(flags->fd, MAG, 6);
	}
	if ((!b->next && flags->c && op == 7) ||
	(!b->next && op == 8 && flags->c))
		write(flags->fd, LCN, 6);
	if ((op == 10 && flags->c && !flags->flag) ||
	(op == 11 && flags->c && flags->flag < 2))
	{
		flags->flag++;
		write(flags->fd, LYL, 6);
	}
	ft_putnbr_fd(b->num, flags->fd);
	if (flags->c)
		write(flags->fd, WHT, 6);
	ft_putchar_fd('\n', flags->fd);
}

void		write_bonus(t_stack *a, t_stack *b, int op, t_flags *flags)
{
	flags->flag = 0;
	ft_putchar_fd('\n', flags->fd);
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
	ft_putstr_fd("-          -\na          b\n\n", flags->fd);
}
