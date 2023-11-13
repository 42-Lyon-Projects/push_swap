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

t_boolean	ft_stack_is_sorted(t_stack a_stack)
{
	t_stack *node;
	long previous_value;

	previous_value = LONG_MIN;
	node = &a_stack;
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

void	ft_display_stacks(t_stacks stacks)
{
	ft_printf("STACKS :\n");
	ft_printf("-> A :\n");
	t_stack *tmp_a = stacks.stack_a;
	int index = 0;
	while (tmp_a)
	{
		ft_printf("Position [%d] | Content : %d\n", index, tmp_a->content);
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
