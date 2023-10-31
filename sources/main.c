/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:47:51 by jbadaire          #+#    #+#             */
/*   Updated: 2023/10/31 00:14:05 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	long		*array;
	t_stacks	stacks;

	array = NULL;
	if (argc < 2)
		return (0);
	array = handle_inputs_digit(argv);
	if (array == NULL)
		return (0);
	if (is_ascending(array))
		return (free(array), 0);
	if (has_duplicates(array) || !contains_only_int(array))
		return (free(array), ft_printf("Error\n", 0));
	stacks = init_stacks();
	push_swap(array, &stacks);
	return (0);
}

void	push_swap(long *array, t_stacks *stacks)
{
	fill_stack(stacks, array);
	free(array);
}
