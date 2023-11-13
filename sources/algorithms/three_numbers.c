/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:19:19 by jbadaire          #+#    #+#             */
/*   Updated: 2023/11/13 15:19:19 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void sort_three(t_stacks *stacks)
{
	int a;
	int b;
	int c;

	a = stacks->stack_a->content;
	b = stacks->stack_a->next->content;
	c = stacks->stack_a->next->next->content;
	if (a > b && b < c && a < c)
		swap(stacks->stack_a);
	else if (a > b && b > c && a > c)
	{
		swap(stacks->stack_a);
		reverse_rotate(&stacks->stack_a);
	}
	else if (a > b && b < c && a > c)
		rotate(&stacks->stack_a);
	else if (a < b && b > c && a < c)
	{
		swap(stacks->stack_a);
		rotate(&stacks->stack_a);
	}
	else if (a < b && b > c && a > c)
		reverse_rotate(&stacks->stack_a);
}