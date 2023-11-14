/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:45:11 by jbadaire          #+#    #+#             */
/*   Updated: 2023/11/13 17:45:11 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_boolean	is_duplicated(int nb, const int *array, int length)
{
	int	index;
	int	amount;

	index = 0;
	amount = 0;
	while (index < length)
	{
		if (array[index] == nb)
			amount++;
		index++;
	}
	return (amount > 1);
}

t_boolean	ft_array_contains_value(const int *array, int search, int length)
{
	int	index;

	index = 0;
	while (index < length)
	{
		if (array[index] == search)
			return (_true);
		index++;
	}
	return (_false);
}

t_boolean	ft_array_contains_only_int(const int *array, int length)
{
	int	index;

	index = 0;
	while (index < length)
	{
		if (array[index] > INT_MAX || array[index] < INT_MIN)
			return (_false);
		index++;
	}
	return (_true);
}

t_boolean	ft_array_is_sorted(const int *array, int length)
{
	int	previous_value;
	int	current;
	int	index;

	previous_value = INT_MIN;
	index = 0;
	while (index < length)
	{
		current = array[index];
		if (previous_value > current)
			return (_false);
		previous_value = current;
		index++;
	}
	return (_true);
}

t_boolean	ft_array_has_duplicates(const int *array, int length)
{
	int	index;

	index = 0;
	while (index < length)
	{
		if (is_duplicated(array[index], array, length))
			return (_true);
		index++;
	}
	return (_false);
}