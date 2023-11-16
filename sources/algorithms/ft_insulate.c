/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insulates.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 08:48:21 by jbadaire          #+#    #+#             */
/*   Updated: 2023/11/16 09:18:07 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_insulate_min_a(t_stacks *stacks)
{
	int	node_pos;

	if (node_pos == 0)
		return ;
	else if (node_pos == stacks->length - 1)
	{
		reverse_rotate(stacks, &stacks->stack_a, "rra", _true);
		return ;
	}
	while (node_pos != 0)
	{
		if (node_pos <= stacks->length / 2)
			rotate(stacks, &stacks->stack_a, "ra", _true);
		else
			reverse_rotate(stacks, &stacks->stack_a, "rra", _true);
		node_pos = ft_stack_find_lower(stacks->stack_a);
	}
}
