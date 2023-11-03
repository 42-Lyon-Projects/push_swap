/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recalc_values.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 02:30:51 by jbadaire          #+#    #+#             */
/*   Updated: 2023/11/03 15:36:45 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	recalc_a(t_stacks *stacks)
{
	t_stack		*tmp_stack;
	int			index;

	tmp_stack = stacks->stack_a;
	index = 0;
	while (tmp_stack)
	{
		if (tmp_stack->content < stacks->values.min_a || \
		stacks->values.min_a == LONG_MIN)
		{
			stacks->values.min_a = tmp_stack->content;
			stacks->values.min_a_index = index;
		}
		if (tmp_stack->content > stacks->values.max_a || \
		stacks->values.max_a == LONG_MIN)
		{
			stacks->values.max_a = tmp_stack->content;
			stacks->values.max_a_index = index;
		}
		tmp_stack = tmp_stack->next;
		index++;
	}
}

void	recalc_b(t_stacks *stacks)
{
	t_stack		*tmp_stack;
	int			index;

	tmp_stack = stacks->stack_b;
	index = 0;
	while (tmp_stack)
	{
		if (tmp_stack->content < stacks->values.min_b || \
		stacks->values.min_b == LONG_MIN)
		{
			stacks->values.min_b = tmp_stack->content;
			stacks->values.min_b_index = index;
		}
		if (tmp_stack->content > stacks->values.max_b || \
		stacks->values.max_b == LONG_MIN)
		{
			stacks->values.max_b = tmp_stack->content;
			stacks->values.max_b_index = index;
		}
		tmp_stack = tmp_stack->next;
		index++;
	}
}

void	recalc(t_stacks *stacks)
{
	recalc_a(stacks);
	recalc_b(stacks);
}

t_boolean	is_ascending(long *array, t_stacks *stacks)
{
	int	index;
	int	old;

	index = 0;
	old = 0;
	while (index < stacks->values.array_length && array[index] >= old)
		old = array[index++];
	return (index >= stacks->values.array_length);
}