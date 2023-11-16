/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 21:32:01 by jbadaire          #+#    #+#             */
/*   Updated: 2023/11/14 15:44:08 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_boolean	ft_stack_is_sorted(t_stack *a_stack)
{
	t_stack	*node;
	long	previous_value;

	previous_value = LONG_MIN;
	node = a_stack;
	while (node)
	{
		if (previous_value > node->content)
			return (_false);
		previous_value = node->content;
		node = node->next;
	}
	return (_true);
}

int	ft_stack_size(t_stack *stack)
{
	int		size;
	t_stack	*tmp;

	size = 0;
	tmp = stack;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

int	ft_stack_find_lower(t_stack *stack)
{
	int	index;
	int	previous_value;
	int	lower_node_pos;

	index = 0;
	previous_value = INT_MAX;
	while (stack)
	{
		if (stack->content < previous_value)
		{
			previous_value = stack->content;
			lower_node_pos = index;
		}
		stack = stack->next;
		index++;
	}
	return (lower_node_pos);
}
