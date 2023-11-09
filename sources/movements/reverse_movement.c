/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_movement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 21:34:26 by jbadaire          #+#    #+#             */
/*   Updated: 2023/11/07 21:46:34 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	reverse_rotate_a(t_stacks *stacks)
{
	t_stack	*first;
	t_stack	*end;
	int		index;

	first = NULL;
	end = NULL;
	if (!stacks->stack_a)
		return (-1);
	first = stacks->stack_a;
	end = first;
	while (end->next)
		end = end->next;
	end->next = first->next;
	
}

int	reverse_rotate_b(t_stacks *stacks)
{

}

int	reverse_rotate_a_and_b(t_stacks *stacks)
{

}