/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 21:32:01 by jbadaire          #+#    #+#             */
/*   Updated: 2023/11/20 16:09:05 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_stack_find_lower(t_stack *stack)
{
	int	index;
	int	previous_value;
	int	lower_node_pos;

	index = 0;
	previous_value = INT_MAX;
	while (stack)
	{
		if (previous_value > stack->content)
		{
			previous_value = stack->content;
			lower_node_pos = index;
		}
		stack = stack->next;
		index++;
	}
	return (lower_node_pos);
}

int	ft_stack_find_high(t_stack *stack)
{
	int	index;
	int	previous_value;
	int	bigger_node_pos;

	index = 0;
	previous_value = INT_MIN;
	while (stack)
	{
		if (stack->content > previous_value)
		{
			previous_value = stack->content;
			bigger_node_pos = index;
		}
		stack = stack->next;
		index++;
	}
	return (bigger_node_pos);
}

static t_boolean	is_duplicated(int nb, t_stack *head)
{
	int		amount;
	t_stack	*tmp;

	amount = 0;
	tmp = head;
	while (tmp)
	{
		if (tmp->content == nb)
			amount++;
		if (tmp->next)
			tmp = tmp->next;
		else
			break ;
	}
	return (amount > 1);
}

t_boolean	ft_stack_has_duplicates(t_stack *head_a)
{
	t_stack	*tmp;

	tmp = head_a;
	while (tmp)
	{
		if (is_duplicated(tmp->content, tmp))
			return (_true);
		if (tmp->next)
			tmp = tmp->next;
		else
			break ;
	}
	return (_false);
}

