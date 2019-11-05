/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:41:13 by cauranus          #+#    #+#             */
/*   Updated: 2019/11/05 17:34:30 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP
# include "libft/libft.h"
# include <stdio.h>
# include <limits.h>

typedef struct			s_stack
{
	int					num;
	struct s_stack		*next;
}						t_stack;

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
t_stack					*readtostack(char **argv);
void					die(void);
void					validate_arr(int *arg, int size);
int						validate_string(char *str);
t_stack					*find_biggest(t_stack *b);
t_stack					*find_smallest(t_stack *a);
int						get_ptr_pos(t_stack *a, t_stack *num);
void					move_num_up(t_stack **a, t_stack *num, int size, char stack);
void					push_swap(t_stack *a, t_stack *b, int size, int *sort);
void					sort_arr(int *arg, int size);
int						*readtoarr(char **av, int size);
int						count_operations(t_stack *a, int num, int size);
t_stack					*find_num(t_stack *a, int number);
t_stack					*find_min_ops(t_stack *a, int *sort, int max, int start);
int						get_size(t_stack *a);
void					free_stack(t_stack *a);
void					free_array(char **arr);
t_stack					*stackcpy(t_stack *a);
char					**read_to_arr(char **av);
int						validate_str(char *str);

#endif