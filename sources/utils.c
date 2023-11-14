/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:20:01 by jbadaire          #+#    #+#             */
/*   Updated: 2023/11/13 15:20:01 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../includes/push_swap.h"

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
			while (node != NULL && ft_array_contains_value(array, node->content, stacks->length))
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


void	re_indexing_stacks(t_stacks *stacks, int *mlc)
{
	if (stacks->stack_a)
		ft_indexing_stack(&stacks->stack_a, mlc, stacks->length);
	if (stacks->stack_b)
		ft_indexing_stack(&stacks->stack_b, mlc, stacks->length);
	//ft_display_stacks(*stacks);

}

void	ft_free(t_stacks *stacks)
{
	if (stacks->array)
		free(stacks->array);
	if (stacks->input)
		free(stacks->input);
	if (stacks->stack_a)
		free_stack(stacks->stack_a);
	if (stacks->stack_b)
		free_stack(stacks->stack_b);
}

void	ft_free_and_exit(t_stacks *stacks)
{
	ft_free(stacks);
	exit(0);
}