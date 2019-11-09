/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:41:13 by cauranus          #+#    #+#             */
/*   Updated: 2019/11/09 18:13:06 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define RED "\x1B[31m"
# define GRN "\x1B[32m"
# define YEL "\x1B[33m"
# define BLU "\x1B[34m"
# define MAG "\x1B[35m"
# define CYN "\x1B[36m"
# define WHT "\x1B[39m"
# define LCN "\x1B[96m"
# define LGN "\x1B[92m"
# define LYL "\x1B[93m"
# define LBU "\x1B[93m"
# include "libft/libft.h"

typedef struct			s_stack
{
	int					num;
	struct s_stack		*next;
}						t_stack;

typedef struct			s_flags
{
	char				v;
	char				c;
	char				stack;
	int					flag;
	t_stack				**b;
	int					*sort;
}						t_flags;

long					ft_atol(const char *str);
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
t_stack					*readtostack(char **argv, t_flags *flags);
void					die(void);
void					validate_arr(int *arg, int size);
int						validate_string(char *str);
t_stack					*find_biggest(t_stack *b);
t_stack					*find_smallest(t_stack *a);
int						get_ptr_pos(t_stack *a, t_stack *num);
void					move_num_up(t_stack **a, t_stack *num,
						int size, t_flags *flags);
void					push_swap(t_stack *a, t_stack *b,
						int size, t_flags *flags);
void					sort_arr(int **arg, int size);
int						*readtoarr(char **av, int size);
int						count_operations(t_stack *a, int num, int size);
t_stack					*find_num(t_stack *a, int number);
t_stack					*find_min_ops(t_stack *a, int *sort,
						int max, int start);
int						get_size(t_stack *a);
void					free_stack(t_stack **a);
void					free_exec(char **str, t_stack *a, t_stack *b);
t_stack					*stackcpy(t_stack *a);
char					**read_to_arr(char **av, t_flags *flags);
int						validate_str(char *str);
void					less_5(t_stack **a, t_stack **b,
						int size, t_flags *flags);
void					get_flags(char **av, t_flags *flags);
void					write_stacks(t_stack *a, t_stack *b,
						t_flags *flags, int op);
int						ft_numlen(int n);
void					write_bonus(t_stack *a, t_stack *b,
						int op, t_flags *flags);

#endif
