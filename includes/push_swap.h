/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:46:18 by jbadaire          #+#    #+#             */
/*   Updated: 2023/11/14 15:23:02 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../dependencies/libft/libft.h"
# include <limits.h>

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
	int					*array;
	int					length;
}						t_stacks;

int			*handle_inputs_digit(t_stacks *stacks, char **input, int orig_tab_index, int index);

t_boolean	ft_array_has_duplicates(const int *array, int length);
t_boolean	ft_array_contains_only_int(const int *array, int length);
t_boolean	ft_array_is_sorted(const int *array, int length);
t_boolean	ft_array_contains_value(const int *array, int search, int length);

// # STACKS # //
t_stacks	init_stacks(void);
t_boolean	ft_stack_is_sorted(t_stack *a_stack);
void		fill_stack(t_stacks *stacks, const int *array);
void		ft_indexing_stack(t_stack **head_a, const int *array, int array_length);
void		free_stack(t_stack *head);
void		ft_display_stacks(t_stacks stacks);
int			ft_stack_size(t_stack *stack);
void		re_indexing_stacks(t_stacks *stacks, int *mlc);
// # NODES # //
t_stack		*create_node(int content);
t_stack		*last_node(t_stack *node);
t_stack		*get_node_at(t_stack *head, int at);
void		add_node_back(t_stack **stack, t_stack *node);
void		remove_node_back(t_stack **stack);

// # PUSHS # //
int			push_a(t_stacks *stacks, char *type, t_boolean print);
int			push_b(t_stacks *stacks, char *type, t_boolean print);

// # REVERSES # //
void		reverse_rotate(t_stacks *stacks, t_stack **head, char *type, t_boolean print);
void		reverse_rotate_a_and_b(t_stacks *stacks, char *type, t_boolean print);

// # ROTATES # //
void		rotate(t_stacks *stacks, t_stack **head, char *type, t_boolean print);
void		rotate_a_and_b(t_stacks *stacks, char *type, t_boolean print);

// # SWAPS # //
int			swap(t_stacks *stacks, t_stack *head, char *type, t_boolean print);
int			swap_a_and_b(t_stacks *stacks, char *type, t_boolean print);

void		push_swap(t_stacks *stacks);

// # UTILS # //
void		ft_stack_to_sorted_array(t_stacks *stacks , int length, int *array, int index, int sub_index);
void		ft_free_and_exit(t_stacks *stacks);

// # ALGORITHMS # //
void		sort_two(t_stacks *stacks);
void		sort_three(t_stacks *stacks);
void		sort_four(t_stacks *stacks);
void		sort_five(t_stacks *stacks);
void		sort_more(t_stacks *stacks);
#endif
