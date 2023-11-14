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

void	rotate(t_stacks *stacks, t_stack **head, char *type, t_boolean print)
{
	t_stack	*next;
	t_stack	*new;

	new = create_node((*head)->content);
	if (!new)
		ft_free_and_exit(stacks);
	next = (*head)->next;
	free(*head);
	*head = next;
	add_node_back(&next, new);
	if (print)
		ft_printf("%s\n", type);
}

void	rotate_a_and_b(t_stacks *stacks, char *type, t_boolean print)
{
	if (stacks->stack_a)
		rotate(stacks, &stacks->stack_a, NULL, _false);
	if (stacks->stack_b)
		rotate(stacks, &stacks->stack_b, NULL, _false);
	if (print)
		ft_printf("%s\n", type);
}
