/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:47:51 by jbadaire          #+#    #+#             */
/*   Updated: 2023/11/09 13:57:19 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
void	tests_movements(t_stacks *stacks);

int	main(int argc, char *argv[])
{
	long		*array;
	t_stacks	stacks;

	array = NULL;
	if (argc < 2)
		return (0);
	array = handle_inputs_digit(argv, 1, 0);
	if (array == NULL)
		return (0);
	if (has_duplicates(array) || !contains_only_int(array))
		return (free(array), ft_printf("Error 2\n", 0));
	stacks = init_stacks();
	fill_stack(&stacks, array);
	free(array);
	if (is_sorted(*stacks.stack_a))
		return (free_stack(stacks.stack_a), 0);

	tests_movements(&stacks);

	//push_swap(array);
	return (0);
}

void	push_swap(t_stacks *stacks)
{
	(void) stacks;
	ft_printf("ALGO\n");
	//free(array);
}


void	tests_movements(t_stacks *stacks)
{
	ft_display_stacks(*stacks);
	push_b(stacks);
	ft_display_stacks(*stacks);
	push_a(stacks);
	ft_display_stacks(*stacks);
	free_stack(stacks->stack_a);
}