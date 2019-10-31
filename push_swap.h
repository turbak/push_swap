/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:41:13 by cauranus          #+#    #+#             */
/*   Updated: 2019/10/31 19:02:39 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP
# include "libft/libft.h"
# include <stdio.h>

typedef struct			s_stack
{
	int					num;
	struct s_stack		*next;
}						t_stack;

t_stack					*atostack(int *arg, int size);
void					write_stacks(t_stack *a, t_stack *b);
t_stack					*atostack(int *arg, int size);
void					sab(t_stack **a);
void					ss(t_stack **a, t_stack **b);
void					pab(t_stack **a, t_stack **b);
void					rab(t_stack **a);
void					rr(t_stack **a, t_stack **b);
void					rrab(t_stack **a);
void					rrr(t_stack **a, t_stack **b);
int						check(t_stack *a);
int						check_reversed(t_stack *a);
t_stack					*readtostack(char **av);
void					die(void);
void					validate_arr(int *arg, int size);
t_stack					find_smallest(t_stack *a);
#endif