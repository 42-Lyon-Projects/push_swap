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

int	swap(t_stack *head)
{
	int	tmp_value;

	if (!head || !head->next)
		return (-1);
	tmp_value = head->next->content;
	head->next->content = head->content;
	head->content = tmp_value;
	return (0);
}

int	swap_a_and_b(t_stacks *stacks)
{
	if (swap(stacks->stack_a) < 0)
		return (-1);
	if (swap(stacks->stack_b) < 0)
		return (-1);
	return (0);
}
