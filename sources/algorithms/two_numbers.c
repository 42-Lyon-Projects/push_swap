/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:18:53 by jbadaire          #+#    #+#             */
/*   Updated: 2023/11/13 15:21:12 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void sort_two(t_stacks *stacks)
{
	if (stacks->stack_a->content > stacks->stack_a->next->content)
		swap(stacks, stacks->stack_a, "sa", _true);
}