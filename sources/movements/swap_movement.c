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

int	swap(t_stack *head, char *type, t_boolean print)
{
	int	tmp_value;

	if (!head || !head->next)
		return (-1);
	tmp_value = head->next->content;
	head->next->content = head->content;
	head->content = tmp_value;
	if (print)
		ft_printf("%s\n", type);
	return (0);
}

int	swap_a_and_b(t_stacks *stacks, char *type, t_boolean print)
{
	if (swap(stacks->stack_a, NULL, _false) < 0)
		return (-1);
	if (swap(stacks->stack_b, NULL, _false) < 0)
		return (-1);
	if (print)
		ft_printf("%s\n", type);
	return (0);
}
