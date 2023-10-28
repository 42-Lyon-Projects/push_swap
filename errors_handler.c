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

#include "push_swap.h"

t_boolean check_duplicates(int *array)
{
	int	index;

	index = 0;
	while (array[index])
	{
		if (is_duplicated(array[index], array))
			return (_true);
	}
	return (_false);
}

t_boolean is_duplicated(int nb, int *array)
{
	int	index;
	int amount;

	index = 0;
	amount = 0;
	while (array[index])
		if (array[index++] == nb)
			amount++;
	return (amount > 1);
}
