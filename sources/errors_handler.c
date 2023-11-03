/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 05:12:45 by jbadaire          #+#    #+#             */
/*   Updated: 2023/10/28 05:15:18 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_boolean	has_duplicates(long *array, t_stacks stacks)
{
	int	index;

	index = 0;
	while (index < stacks.values.array_length)
	{
		if (is_duplicated(array[index], array, stacks))
			return (_true);
		index++;
	}
	return (_false);
}

t_boolean	is_duplicated(long nb, long *array, t_stacks stacks)
{
	int	index;
	int	amount;

	index = 0;
	amount = 0;
	while (index < stacks.values.array_length)
	{
		if (array[index] == nb)
			amount++;
		index++;
	}
	return (amount > 1);
}

t_boolean	contains_only_int(long *array, t_stacks stacks)
{
	int	index;

	index = 0;
	while (index < stacks.values.array_length)
	{
		if (array[index] > INT_MAX || array[index] < INT_MIN)
			return (_false);
		index++;
	}
	return (_true);
}
