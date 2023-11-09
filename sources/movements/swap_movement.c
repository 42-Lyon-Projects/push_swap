/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 21:35:25 by jbadaire          #+#    #+#             */
/*   Updated: 2023/11/07 21:40:34 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	swap_a(t_stacks *stacks)
{
	int	tmp_value;

	if (!stacks->stack_a || !stacks->stack_a->next)
		return (-1);
	tmp_value = stacks->stack_a->next->content;
	stacks->stack_a->next->content = stacks->stack_a->content;
	stacks->stack_a->content = tmp_value;
	return (0);
}

int swap_b(t_stacks *stacks)
{
	int	tmp_value;

	if (!stacks->stack_b || !stacks->stack_b->next)
		return (-1);
	tmp_value = stacks->stack_b->next->content;
	stacks->stack_b->next->content = stacks->stack_b->content;
	stacks->stack_b->content = tmp_value;
	return (0);
}

int	swap_a_and_b(t_stacks *stacks)
{
	if (swap_a(stacks) < 0)
		return (-1);
	if (swap_b(stacks) < 0)
		return (-1);
	return (0);
}
