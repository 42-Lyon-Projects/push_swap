/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 05:12:45 by jbadaire          #+#    #+#             */
/*   Updated: 2023/11/09 22:06:44 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_boolean	has_duplicates(long *array)
{
	int	index;

	index = 0;
	while (array[index])
	{
		if (is_duplicated(array[index], array))
			return (_true);
		index++;
	}
	return (_false);
}

t_boolean	is_duplicated(long nb, const long *array)
{
	int	index;
	int	amount;

	index = 0;
	amount = 0;
	while (array[index])
	{
		if (array[index] == nb)
			amount++;
		index++;
	}
	return (amount > 1);
}

t_boolean	contains_only_int(const long *array)
{
	int	index;

	index = 0;
	while (array[index])
	{
		if (array[index] > INT_MAX || array[index] < INT_MIN)
			return (_false);
		index++;
	}
	return (_true);
}
