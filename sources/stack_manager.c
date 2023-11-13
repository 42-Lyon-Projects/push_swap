/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 21:32:01 by jbadaire          #+#    #+#             */
/*   Updated: 2023/11/13 14:21:30 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stacks init_stacks(void)
{
	t_stacks stacks;

	stacks.stack_a = NULL;
	stacks.stack_b = NULL;
	stacks.length = 0;
	return (stacks);
}

void fill_stack(t_stacks *stacks, const long *array)
{
	int index;
	int value;

	index = 0;
	while (array[index])
	{
		value = ((int) array[index++]);
		add_node_back(&stacks->stack_a, create_node(value));
		stacks->length = index;
	}
}

void free_stack(t_stack *head)
{
	t_stack *tmp;

	tmp = NULL;
	while (head->next)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(head);
}

void ft_indexing_stack(t_stack **head_a, const int *array)
{
	int index;
	t_stack *tmp_stack;

	index = 0;
	while (array[index])
	{
		tmp_stack = (*head_a);
		while (tmp_stack->content != array[index])
			tmp_stack = tmp_stack->next;
		tmp_stack->index = index++;
	}
}
