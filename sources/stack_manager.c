/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 21:32:01 by jbadaire          #+#    #+#             */
/*   Updated: 2023/12/05 14:15:16 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stacks	init_stacks(void)
{
	t_stacks	stacks;

	stacks.stack_a = NULL;
	stacks.stack_b = NULL;
	stacks.length = 0;
	return (stacks);
}

void	ft_indexing_stack(t_stack **head)
{
	int		previous_value;
	int		index;
	t_stack	*tmp;
	t_stack	*lower_node;

	previous_value = INT_MAX;
	tmp = *head;
	index = 0;
	while (ft_finds_non_indexed(*head) != -1)
	{
		while (tmp)
		{
			if (previous_value >= tmp->content && tmp->index == -1)
			{
				previous_value = tmp->content;
				lower_node = tmp;
			}
			tmp = tmp->next;
		}
		previous_value = INT_MAX;
		lower_node->index = index;
		tmp = *head;
		index++;
	}
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
		if (node->next)
			node = node->next;
		else
			break ;
	}
	return (_true);
}
