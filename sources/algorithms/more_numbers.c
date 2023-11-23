/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:20:20 by jbadaire          #+#    #+#             */
/*   Updated: 2023/11/20 16:05:08 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_more(t_stacks *stacks)
{
	int	bits_index;
	int	index;
	int	stack_length;

	stack_length = ft_stack_size(stacks->stack_a);
	bits_index = 0;
	while (!ft_stack_is_sorted(stacks->stack_a))
	{
		index = 0;
		while (index < stack_length)
		{
			if ((stacks->stack_a->index >> bits_index) & 1)
				rotate(stacks, &stacks->stack_a, "ra", _true);
			else
				push_b(stacks, "pb", _true);
			index++;
		}
		while (stacks->stack_b)
			push_a(stacks, "pa", _true);
		bits_index++;
	}
}
