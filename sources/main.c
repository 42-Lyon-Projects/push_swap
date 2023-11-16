/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:47:51 by jbadaire          #+#    #+#             */
/*   Updated: 2023/11/16 12:54:00 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	int			*array;
	t_stacks	stacks;

	array = NULL;
	if (argc < 2)
		return (0);
	stacks = init_stacks();
	array = handle_inputs_digit(&stacks, argv, 1, 0);
	stacks.input = array;
	if (array == NULL)
		return (0);
	if (!ft_array_contains_only_int(array, \
	stacks.length) || ft_array_has_duplicates(array, stacks.length))
		return (ft_free(&stacks), ft_printf("Error\n", 0), 0);
	fill_stack(&stacks, array);
	if (ft_stack_is_sorted(stacks.stack_a))
		ft_free_and_exit(&stacks);
	push_swap(&stacks);
	return (0);
}

void	push_swap(t_stacks *stacks)
{
	int	*mlc;

	mlc = ft_calloc(stacks->length + 1, sizeof (int ));
	if (!mlc)
		return ;
	stacks->array = mlc;
	ft_stack_to_sorted_array(stacks, mlc, 0, 0);
	re_indexing_stacks(stacks, mlc);
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
	ft_free_and_exit(stacks);
}