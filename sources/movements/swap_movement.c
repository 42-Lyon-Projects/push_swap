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

int	swap(t_stacks *stacks, t_stack *head, char *type, t_boolean print)
{
	int	tmp_value;

	if (!head || !head->next)
		return (-1);
	tmp_value = head->next->content;
	head->next->content = head->content;
	head->content = tmp_value;
	if (print)
		ft_printf("%s\n", type);
	if (stacks)
		re_indexing_stacks(stacks, stacks->array);
	return (0);
}
