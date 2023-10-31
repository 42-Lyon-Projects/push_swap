/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:46:18 by jbadaire          #+#    #+#             */
/*   Updated: 2023/10/27 17:46:18 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../dependencies/libft/libft.h"
# include <values.h>

typedef struct s_stack_values
{
	long				min_a;
	int					min_a_index;
	long				max_a;
	int					max_a_index;
	long				min_b;
	int					min_b_index;
	long				max_b;
	int					max_b_index;
}						t_stack_values;

typedef struct s_stack
{
	int					content;
	struct s_stack		*next;
}						t_stack;

typedef struct s_stacks
{
	t_stack				*stack_a;
	t_stack				*stack_b;
	t_stack_values		values;
}						t_stacks;

long		*handle_inputs_digit(char **input);
long		handle_input_digit(char *input);

t_boolean	has_duplicates(long *array);
t_boolean	is_duplicated(long nb, long *array);
t_boolean	contains_only_int(long *array);

t_stacks	init_stacks(void);
t_stack		*create_stack_node(int content);
void		add_node_back(t_stack **stack, t_stack *node);
void		fill_stack(t_stacks *stacks, long *array);

void		recalc_a(t_stacks *stacks);
void		recalc_b(t_stacks *stacks);
void		recalc(t_stacks *stacks);
t_boolean	is_ascending(long *array);

// # PUSHS # //
int 		push_a(t_stacks *stacks);
int			push_b(t_stacks *stacks);

// # REVERSES # //
int			reverse_rotate_a(t_stacks *stacks);
int			reverse_rotate_b(t_stacks *stacks);
int			reverse_rotate_a_and_b(t_stacks *stacks);

// # ROTATES # //
int			rotate_a(t_stacks *stacks);
int			rotate_b(t_stacks *stacks);
int			rotate_a_and_b(t_stacks *stacks);

// # SWAPS # //
int			swap_a(t_stacks *stacks);
int			swap_b(t_stacks *stacks);
int			swap_a_and_b(t_stacks *stacks);

void		push_swap(long	*array, t_stacks *stacks);

#endif
