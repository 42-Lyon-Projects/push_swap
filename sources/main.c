/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:47:51 by jbadaire          #+#    #+#             */
/*   Updated: 2023/11/07 16:55:09 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	long		*array;

	array = NULL;
	if (argc < 2)
		return (0);
	array = handle_inputs_digit(argv, 1, 0);
	if (array == NULL)
		return (0);
	if (has_duplicates(array) || !contains_only_int(array))
		return (free(array), ft_printf("ErrLAor\n", 0));
	//if (is_ascending(array))
	//	return (free(array), 0);
	push_swap(array);
	return (0);
}


void print_array(long *array)
{
	int index = 0;
	while (array[index])
	{
		ft_printf("%d", array[index]);
		index++;
	}
}

void	push_swap(long *array)
{
	print_array(array);
	ft_printf("ALGO\n");
	free(array);
}
