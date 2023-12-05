/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:46:18 by jbadaire          #+#    #+#             */
/*   Updated: 2023/12/05 14:10:59 by jbadaire         ###   ########.fr       */
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
	int					length;
}						t_stacks;

void		handle_inputs_digit(t_stacks *stacks, char **input, int tab_index);

t_boolean	ft_stack_has_duplicates(t_stack *head_a);

// # STACKS # //
t_stacks	init_stacks(void);
t_boolean	ft_stack_is_sorted(t_stack *a_stack);
void		ft_indexing_stack(t_stack **head_a);
int			ft_stack_size(t_stack *stack);
int			ft_stack_find_lower(t_stack *stack);
int			ft_finds_non_indexed(t_stack *stack);
// # NODES # //
t_stack		*create_node(int content, int index);
t_stack		*last_node(t_stack *node);
void		add_node_back(t_stack **stack, t_stack *node);
void		remove_node_back(t_stack **stack);

// # PUSHS # //
int			push_a(t_stacks *stacks, char *type, t_boolean print);
int			push_b(t_stacks *stacks, char *type, t_boolean print);

// # REVERSES # //
void		reverse_rotate(t_stacks *stacks, t_stack **head, \
char *type, t_boolean print);

// # ROTATES # //
void		rotate(t_stacks *stacks, t_stack **head, \
char *type, t_boolean print);

// # SWAPS # //
int			swap(t_stack *head, char *type, t_boolean print);

void		ft_insulate_min_a(t_stacks *stacks);

// # UTILS # //
void		ft_free(t_stacks *stacks);
void		ft_free_and_exit(t_stacks *stacks, int exit_code);

// # ALGORITHMS # //
void		sort_two(t_stacks *stacks);
void		sort_three(t_stacks *stacks);
void		sort_four(t_stacks *stacks);
void		sort_five(t_stacks *stacks);
void		sort_more(t_stacks *stacks);
#endif
