/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 21:34:03 by jbadaire          #+#    #+#             */
/*   Updated: 2023/11/14 13:11:48 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	push_a(t_stacks *stacks, char *type, t_boolean print)
{
	int		value;
	int		index;
	t_stack	*tmp;
	t_stack	*new_first_a;

	if (!stacks->stack_b)
		return (-1);
	value = stacks->stack_b->content;
	index = stacks->stack_b->index;
	tmp = stacks->stack_b->next;
	free(stacks->stack_b);
	stacks->stack_b = tmp;
	new_first_a = create_node(value, index);
	if (!new_first_a)
		ft_free_and_exit(stacks, 1);
	new_first_a->next = stacks->stack_a;
	stacks->stack_a = new_first_a;
	if (print)
		ft_printf("%s\n", type);
	return (0);
}

int	push_b(t_stacks *stacks, char *type, t_boolean print)
{
	int		value;
	int		index;
	t_stack	*tmp;
	t_stack	*new_first_b;

	if (!stacks->stack_a)
		return (-1);
	value = stacks->stack_a->content;
	index = stacks->stack_a->index;
	tmp = stacks->stack_a->next;
	free(stacks->stack_a);
	stacks->stack_a = tmp;
	new_first_b = create_node(value, index);
	if (!new_first_b)
		ft_free_and_exit(stacks, 1);
	new_first_b->next = stacks->stack_b;
	stacks->stack_b = new_first_b;
	if (print)
		ft_printf("%s\n", type);
	return (0);
}
