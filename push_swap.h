/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:41:13 by cauranus          #+#    #+#             */
/*   Updated: 2019/11/03 18:32:20 by cauranus         ###   ########.fr       */
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
t_stack					*find_smallest(t_stack *a);
int						get_ptr_pos(t_stack *a, t_stack *num);
void					move_num_up(t_stack **a, t_stack *num, int size);
void					push_swap(t_stack *a, t_stack *b, int size, int *sort);
int						*sorted_arr(int *arg, int size);
int						*readtoarr(char **av, int size);
int						count_operations(t_stack *a, int num, int size);
t_stack					*find_num(t_stack *a, int number);
t_stack					*find_min_ops(t_stack *a, int *sort, int max, int start);
int						get_size(t_stack *a);
void					free_stack(t_stack **a);
t_stack					*stackcpy(t_stack *a);

#endif