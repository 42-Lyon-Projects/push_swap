/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 23:37:21 by jbadaire          #+#    #+#             */
/*   Updated: 2023/10/30 23:42:06 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

t_stacks	init_stacks(void)
{
	t_stack_values	stack_values;
	t_stacks		stacks;

	stacks.stack_a = NULL;
	stacks.stack_b = NULL;
	stack_values.max_b = LONG_MIN;
	stack_values.min_b = LONG_MIN;
	stack_values.max_a = LONG_MIN;
	stack_values.min_a = LONG_MIN;
	stack_values.min_a_index = 0;
	stack_values.min_b_index = 0;
	stack_values.max_a_index = 0;
	stack_values.max_b_index = 0;
	stacks.values = stack_values;
	return (stacks);
}

t_stack	*create_stack_node(int content)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack *));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

void	add_node_back(t_stack **stack, t_stack *node)
{
	t_stack	*tmp_stack;

	tmp_stack = *stack;
	if (!tmp_stack)
	{
		*stack = node;
		return ;
	}
	while (tmp_stack && tmp_stack->next)
		tmp_stack = tmp_stack->next;
	tmp_stack->next = node;
}

void	fill_stack(t_stacks *stacks, long *array)
{
	int			index;
	int			value;
	t_boolean	is_first;

	index = 0;
	is_first = _true;
	value = 0;
	while (array[index])
	{
		value = (int) array[index++];
		add_node_back(&stacks->stack_a, create_stack_node(value));
	}
	recalc_a(stacks);
}