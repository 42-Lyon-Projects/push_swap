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

void	reverse_rotate(t_stacks *stacks, t_stack **head, char *type, t_boolean print)
{
	t_stack	*new;

	new = create_node(last_node(*head)->content);
	if (!new)
		ft_free_and_exit(stacks);
	new->next = (*head);
	(*head) = new;
	remove_node_back(head);
	if (print)
		ft_printf("%s\n", type);
}

void	reverse_rotate_a_and_b(t_stacks *stacks, char *type, t_boolean print)
{
	if (stacks->stack_a)
		reverse_rotate(stacks, &stacks->stack_a, NULL, _false);
	if (stacks->stack_b)
		reverse_rotate(stacks, &stacks->stack_b, NULL, _false);
	if (print)
		ft_printf("%s\n", type);
}
