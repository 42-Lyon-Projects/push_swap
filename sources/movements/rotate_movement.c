/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 21:34:42 by jbadaire          #+#    #+#             */
/*   Updated: 2023/11/09 13:28:40 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	rotate(t_stack **head, char *type, t_boolean print)
{
	t_stack	*next;
	t_stack	*new;

	new = create_node((*head)->content);
	if (!new)
		return (-1);
	next = (*head)->next;
	free(*head);
	*head = next;
	add_node_back(&next, new);
	ft_printf("%s\n", type);
	return (0);
}

void	rotate_a_and_b(t_stacks *stacks)
{
	if (stacks->stack_a)
		reverse_rotate(&stacks->stack_a);
	if (stacks->stack_b)
		reverse_rotate(&stacks->stack_b);
}
