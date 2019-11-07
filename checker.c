/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:49:55 by cauranus          #+#    #+#             */
/*   Updated: 2019/11/07 15:47:45 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	exec_1(char **list, t_stack **a, t_stack **b, int i)
{
	if (ft_strequ(list[i], "sa"))
		sab(a);
	else if (ft_strequ(list[i], "sb"))
		sab(b);
	else if (ft_strequ(list[i], "ss"))
		ss(a, b);
	else if (ft_strequ(list[i], "pa"))
		pab(b, a);
	else if (ft_strequ(list[i], "pb"))
		pab(a, b);
	else if (ft_strequ(list[i], "ra"))
		rab(a);
	else if (ft_strequ(list[i], "rb"))
		rab(b);
	else if (ft_strequ(list[i], "rr"))
		rr(a, b);
	else if (ft_strequ(list[i], "rra"))
		rrab(a);
	else if (ft_strequ(list[i], "rrb"))
		rrab(b);
	else if (ft_strequ(list[i], "rrr"))
		rrr(b, a);
	else
		return (0);
	return (1);
}

int			exec(char *str, t_stack *a, t_stack *b)
{
	char	**list;
	int		i;

	i = 0;
	list = ft_strsplit(str, '\n');
	while (list[i])
	{
		if (!exec_1(list, &a, &b, i))
		{
			free_exec(list, a, b);
			free(list);
			die();
		}
		i++;
	}
	i = (check(a) && !b) ? 1 : 0;
	free_exec(list, a, b);
	free(list);
	return (i);
}

int			main(int ac, char **av)
{
	t_stack	*a;
	char	*line;
	char	*str;

	if (ac < 2)
		return (0);
	a = readtostack(av);
	str = ft_strnew(0);
	while (get_next_line(0, &line) > 0)
	{
		ft_swapfree((void **)&str, ft_strjoin(str, line));
		ft_swapfree((void **)&str, ft_strjoin(str, "\n"));
		ft_strdel(&line);
	}
	ft_strdel(&line);
	if (exec(str, a, NULL))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_strdel(&str);
	return (0);
}
