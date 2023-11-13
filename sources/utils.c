/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 08:33:09 by jbadaire          #+#    #+#             */
/*   Updated: 2023/11/13 10:03:59 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_boolean	ft_array_is_sorted(const int *array)
{
	int	previous_value;
	int	current;
	int	index;

	previous_value = INT_MIN;
	index = 0;
	while (array[index])
	{
		current = array[index];
		if (previous_value > current)
			return (_false);
		previous_value = current;
		index++;
	}
	return (_true);
}

t_boolean	ft_array_contains(int *array, int search)
{
	int	index;

	index = 0;
	while (array[index])
	{
		if (array[index] == search)
			return (_true);
		index++;
	}
	return (_false);
}

void	ft_stack_to_sorted_array(t_stacks *stacks , int length, int *array, int index, int sub_index)
{
	int		last_selected;
	int		current_selected;
	t_stack	*node;

	last_selected = INT_MAX;
	current_selected = INT_MAX;
	while (index < length)
	{
		while (sub_index < length)
		{
			node = get_node_at(stacks->stack_a, sub_index++);
			while (node != NULL && ft_array_contains(array, node->content))
				node = get_node_at(stacks->stack_a, sub_index++);
			if(!node)
				break;
			current_selected = node->content;
			if (current_selected < last_selected)
				last_selected = current_selected;
		}
		sub_index = 0;
		array[index++] = last_selected;
		last_selected = INT_MAX;
	}
}
