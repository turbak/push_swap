/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_misc_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 16:41:25 by cauranus          #+#    #+#             */
/*   Updated: 2019/11/04 17:24:09 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *find_min_ops(t_stack *a, int *sort, int max, int start)
{
    t_stack *number;
    int     ops;
    int     counter;
    int     flag;

    number = NULL;
    ops = 0;
    counter = 0;
    flag = 1;
    while (start < max)
    {
        while (!find_num(a, sort[start]) && start < max)
            start++;
        if ((flag || ops > count_operations(a, sort[start], get_size(a))) && start < max)
        {
            ops = count_operations(a, sort[start], get_size(a));
            number = find_num(a, sort[start]);
            flag = 0;
        }
        start++;
    }
    return (number);
}

//void    sort_b(t_stack *b, t_stack *num)
//{
//    
//}

t_stack *stackcpy(t_stack *a)
{
    t_stack *dest;
    t_stack *head;

    if (!a)
        return (NULL);
    dest = malloc(sizeof(t_stack));
    dest->num = a->num;
    head = dest;
    a = a->next;
    while (a)
    {
        dest->next = malloc(sizeof(t_stack));
        dest = dest->next;
        dest->num = a->num;
        a = a->next;
    }
    dest->next = NULL;
    return (head);
}
