/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 21:35:25 by jbadaire          #+#    #+#             */
/*   Updated: 2023/11/20 15:45:17 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	swap(t_stack *head, char *type, t_boolean print)
{
	int	tmp_value;
	int	index;

	if (!head || !head->next)
		return (-1);
	tmp_value = head->next->content;
	index = head->next->index;
	head->next->content = head->content;
	head->next->index = head->index;
	head->content = tmp_value;
	head->index = index;
	if (print)
		ft_printf("%s\n", type);
	return (0);
}
