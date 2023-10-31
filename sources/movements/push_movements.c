/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_movements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 05:31:41 by jbadaire          #+#    #+#             */
/*   Updated: 2023/10/31 15:43:12 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	push_a(t_stacks *stacks)
{
	t_stack	*tmp;
	t_stack *tmp_2;

	tmp = NULL;
	tmp_2 = NULL;
	if(!stacks->stack_b)
		return (-1);
	tmp = stacks->stack_b;
	tmp_2 = stacks->stack_b;
	if (stacks->stack_a)
		tmp->next = stacks->stack_a;
	stacks->stack_a = tmp;
	stacks->stack_b = stacks->stack_b->next;
	free(tmp_2);
	return (0);
}

int	push_b(t_stacks *stacks)
{
	t_stack	*tmp;
	t_stack *tmp_2;

	tmp = NULL;
	tmp_2 = NULL;
	if(!stacks->stack_a)
		return (-1);
	tmp = stacks->stack_a;
	tmp_2 = stacks->stack_a;
	if (stacks->stack_b)
		tmp->next = stacks->stack_b;
	stacks->stack_b = tmp;
	stacks->stack_a = stacks->stack_a->next;
	free(tmp_2);
	return (0);
}