/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_movement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 21:34:26 by jbadaire          #+#    #+#             */
/*   Updated: 2023/11/09 22:08:01 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	reverse_rotate(t_stack **head)
{
	t_stack	*new;

	new = create_node(last_node(*head)->content);
	if (!new)
		return (-1);
	new->next = (*head);
	(*head) = new;
	remove_node_back(head);
	return (0);
}

void	reverse_rotate_a_and_b(t_stacks *stacks)
{
	if (stacks->stack_a)
		reverse_rotate(&stacks->stack_a);
	if (stacks->stack_b)
		reverse_rotate(&stacks->stack_b);
}
