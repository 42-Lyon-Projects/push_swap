/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:46:18 by jbadaire          #+#    #+#             */
/*   Updated: 2023/11/13 09:21:28 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../dependencies/libft/libft.h"
# include <values.h>

typedef struct s_stack
{
	int					content;
	int					index;
	struct s_stack		*next;
}						t_stack;

typedef struct s_stacks
{
	t_stack				*stack_a;
	t_stack				*stack_b;
	int					length;
}						t_stacks;

long		*handle_inputs_digit(char **input, int orig_tab_index, int index);

t_boolean	has_duplicates(long *array);
t_boolean	is_duplicated(long nb, const long *array);
t_boolean	contains_only_int(const long *array);

// # STACKS # //

t_stacks	init_stacks(void);
void		fill_stack(t_stacks *stacks, const long *array);
void		free_stack(t_stack *head);
void		ft_indexing_stack(t_stack **head_a, const int *array);
t_boolean	is_sorted(t_stack a_stack);
void		ft_display_stacks(t_stacks stacks);

// # NODES # //
t_stack		*create_node(int content);
t_stack		*last_node(t_stack *node);
t_stack		*get_node_at(t_stack *head, int at);
void		add_node_back(t_stack **stack, t_stack *node);
void		remove_node_back(t_stack **stack);

// # PUSHS # //
int			push_a(t_stacks *stacks);
int			push_b(t_stacks *stacks);

// # REVERSES # //
int			reverse_rotate(t_stack **head);
void		reverse_rotate_a_and_b(t_stacks *stacks);

// # ROTATES # //
int			rotate(t_stack **head);
void		rotate_a_and_b(t_stacks *stacks);

// # SWAPS # //
int			swap(t_stack *head);
int			swap_a_and_b(t_stacks *stacks);

void		push_swap(t_stacks *stacks);

// # UTILS # //
t_boolean	ft_array_is_sorted(const int *array);
void		ft_stack_to_sorted_array(t_stacks *stacks , int length, int *array, int index, int sub_index);
#endif
