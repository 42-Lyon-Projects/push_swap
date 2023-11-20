/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 21:32:01 by jbadaire          #+#    #+#             */
/*   Updated: 2023/11/16 08:21:07 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stacks	init_stacks(void)
{
	t_stacks	stacks;

	stacks.stack_a = NULL;
	stacks.stack_b = NULL;
	stacks.array = NULL;
	stacks.length = 0;
	return (stacks);
}

void	fill_stack(t_stacks *stacks, const int *array)
{
	int	index;
	int	value;

	index = 0;
	while (index < stacks->length)
	{
		value = ((int) array[index++]);
		add_node_back(&stacks->stack_a, create_node(value));
	}
}

void	ft_indexing_stack(t_stack **head, const int *array, int array_length)
{
	int		index;
	t_stack	*tmp_stack;

	index = 1;
	if (head == NULL || *head == NULL)
		return ;
	while (index < array_length + 1)
	{
		tmp_stack = (*head);
		while (tmp_stack && tmp_stack->content != array[index - 1])
			tmp_stack = tmp_stack->next;
		if (tmp_stack)
			tmp_stack->index = index;
		index++;
	}
}
