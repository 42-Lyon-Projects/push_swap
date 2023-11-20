/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 21:32:01 by jbadaire          #+#    #+#             */
/*   Updated: 2023/11/20 16:09:17 by jbadaire         ###   ########.fr       */
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
	int		lower;
	int		higher;
	int		index;
	t_stack	*tmp_stack;

	index = 0;
	if (head == NULL || *head == NULL)
		return ;
	tmp_stack = *head;
	lower = get_node_at((*head), ft_stack_find_lower(tmp_stack))->content;
	higher = get_node_at((*head), ft_stack_find_high(tmp_stack))->content;

	while (lower <= higher)
	{
		while (tmp_stack)
		{
			if (tmp_stack->content == lower)
				tmp_stack->index = index++;
			tmp_stack = tmp_stack->next;
		}
		tmp_stack = *head;
		lower++;
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

void	ft_display_stacks(t_stacks stacks)
{
	ft_printf("STACKS :\n");
	ft_printf("-> A :\n");
	t_stack *tmp_a = stacks.stack_a;
	int index = 0;
	while (tmp_a)
	{
		ft_printf("Position [%d] | Content : %d\n", tmp_a->index, tmp_a->content);
		index++;
		tmp_a = tmp_a->next;
	}
	ft_printf("\n-> B :\n");
	t_stack *tmp_b = stacks.stack_b;
	index = 0;
	while (tmp_b)
	{
		ft_printf("Position [%d] | Content : %d\n", index, tmp_b->content);
		index++;
		tmp_b = tmp_b->next;
	}
}