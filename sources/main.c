/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:47:51 by jbadaire          #+#    #+#             */
/*   Updated: 2023/12/05 14:11:02 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push_swap(t_stacks *stacks)
{
	if (stacks->stack_a)
		ft_indexing_stack(&stacks->stack_a);
	if (stacks->length == 2)
		sort_two(stacks);
	else if (stacks->length == 3)
		sort_three(stacks);
	else if (stacks->length == 4)
		sort_four(stacks);
	else if (stacks->length == 5)
		sort_five(stacks);
	else if (stacks->length > 5)
		sort_more(stacks);
	ft_free_and_exit(stacks, 0);
}

int	main(int argc, char *argv[])
{
	t_stacks	stacks;

	if (argc < 2)
		return (0);
	stacks = init_stacks();
	handle_inputs_digit(&stacks, argv, 1);
	if (ft_stack_is_sorted(stacks.stack_a))
		ft_free_and_exit(&stacks, 1);
	if (ft_stack_has_duplicates(stacks.stack_a))
		return (ft_free(&stacks), ft_putstr_fd("Error\n", 2), 1);
	push_swap(&stacks);
	return (0);
}
