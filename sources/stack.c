/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 21:32:01 by jbadaire          #+#    #+#             */
/*   Updated: 2023/11/09 12:28:14 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stacks	init_stacks(void)
{
	t_stacks	stacks;

	stacks.stack_a = NULL;
	stacks.stack_b = NULL;
	return (stacks);
}

void	fill_stack(t_stacks *stacks, const long *array)
{
	int			index;
	int			value;

	index = 0;
	value = 0;
	while (array[index])
	{
		value = ((int) array[index++]);
		add_node_back(&stacks->stack_a, create_node(value));
	}
}

t_boolean	is_sorted(t_stack a_stack)
{
	t_stack	*node;
	long	previous_value;

	previous_value = LONG_MIN;
	node = &a_stack;
	while (node)
	{
		if(previous_value > node->content)
			return (_false);
		previous_value = node->content;
		node = node->next;
	}
	return (_true);
}

void	free_stack(t_stack *head)
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

void	ft_display_stacks(t_stacks stacks)
{
	ft_printf("STACKS :\n");
	ft_printf("-> A :\n");
	t_stack	*tmp_a = stacks.stack_a;
	int		index = 0;
	while (tmp_a)
	{
		ft_printf("Position [%d] | Content : %d\n", index, tmp_a->content);
		index++;
		tmp_a = tmp_a->next;
	}
	ft_printf("\n-> B :\n");
	t_stack	*tmp_b = stacks.stack_b;
	index = 0;
	while (tmp_b)
	{
		ft_printf("Position [%d] | Content : %d\n", index, tmp_b->content);
		index++;
		tmp_b = tmp_b->next;
	}

}
