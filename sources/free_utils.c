/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 08:20:16 by jbadaire          #+#    #+#             */
/*   Updated: 2023/11/24 15:42:52 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	free_stack(t_stack *head)
{
	t_stack	*tmp;

	tmp = NULL;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(head);
}

void	ft_free(t_stacks *stacks)
{
	if (stacks->stack_a)
		free_stack(stacks->stack_a);
	if (stacks->stack_b)
		free_stack(stacks->stack_b);
}

void	ft_free_and_exit(t_stacks *stacks, int exit_code)
{
	ft_free(stacks);
	exit(exit_code);
}
