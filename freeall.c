/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 17:54:37 by cauranus          #+#    #+#             */
/*   Updated: 2019/11/05 17:34:25 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    free_stack(t_stack *a)
{
    t_stack *buf;

    while (a)
    {
        buf = a->next;
        free(a);
        a = buf;
    }
    a = NULL;
}

void    free_array(char **arr)
{
    int i;

    i = 0;
    while (arr[i])
    {
        ft_strdel(&arr[i]);
        i++;
    }
}
