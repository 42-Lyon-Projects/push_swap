/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:29:33 by jbadaire          #+#    #+#             */
/*   Updated: 2023/11/16 09:17:40 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_four(t_stacks *stacks)
{
	int	index;

	index = 0;
	while (index != stacks->length -2)
	{
		ft_insulate_min_a(stacks);
		push_b(stacks, "pb", _true);
		index++;
	}
	sort_two(stacks);
	while (stacks->stack_b)
		push_a(stacks, "pa", _true);
}
