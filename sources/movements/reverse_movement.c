/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_movement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 21:34:26 by jbadaire          #+#    #+#             */
/*   Updated: 2023/11/20 15:43:52 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	reverse_rotate(t_stacks *stacks, t_stack **head, \
char *type, t_boolean print)
{
	t_stack	*new;

	new = create_node(last_node(*head)->content, \
	last_node(*head)->index);
	if (!new)
		ft_free_and_exit(stacks, 1);
	new->next = (*head);
	(*head) = new;
	remove_node_back(head);
	if (print)
		ft_printf("%s\n", type);
}
