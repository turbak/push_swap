/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 17:58:33 by cauranus          #+#    #+#             */
/*   Updated: 2019/10/29 21:46:45 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	write_stacks(t_stack *a, t_stack *b)
{
	sab(&a);
	pab(&a, &b);
	pab(&a, &b);
	pab(&a, &b);
	rab(&a);
	rab(&b);
	rrab(&a);
	rrab(&b);
	sab(&a);
	pab(&b, &a);
	pab(&b, &a);
	pab(&b, &a);
	printf("[%d]\n", check(a));
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