/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 17:54:37 by cauranus          #+#    #+#             */
/*   Updated: 2019/11/07 13:28:36 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **a)
{
	t_stack *buf;

	while (*a)
	{
		buf = (*a)->next;
		free(*a);
		*a = buf;
	}
	*a = NULL;
}

void	free_exec(char **str, t_stack *a, t_stack *b)
{
	int i;

	i = 0;
	if (a)
		free_stack(&a);
	if (b)
		free_stack(&b);
	while (str[i])
	{
		ft_strdel(&str[i]);
		i++;
	}
}
