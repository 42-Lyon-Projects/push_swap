/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:19:19 by jbadaire          #+#    #+#             */
/*   Updated: 2023/11/16 09:04:44 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_three(t_stacks *stacks)
{
	t_stack	*f;
	t_stack	*s;
	t_stack	*t;

	f = stacks->stack_a;
	s = stacks->stack_a->next;
	t = stacks->stack_a->next->next;
	if (t->content > f->content && f->content > s->content)
		sort_two(stacks);
	else if (s->content > f->content && f->content > t->content)
		reverse_rotate(stacks, &stacks->stack_a, "rra", _true);
	else if (f->content > t->content && t->content > s->content)
		rotate(stacks, &stacks->stack_a, "ra", _true);
	else if (f->content > s->content && s->content > t->content)
	{
		sort_two(stacks);
		reverse_rotate(stacks, &stacks->stack_a, "rra", _true);
	}
	else if (s->content > t->content && t->content > f->content)
	{
		rotate(stacks, &stacks->stack_a, "ra", _true);
		sort_two(stacks);
		reverse_rotate(stacks, &stacks->stack_a, "rra", _true);
	}
}
