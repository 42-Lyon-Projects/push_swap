/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_transformer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 05:04:57 by jbadaire          #+#    #+#             */
/*   Updated: 2023/11/03 20:07:28 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#include "stdio.h"

long	*ft_realloc(long *array, int count, long value)
{
	long	*new;
	int		index;

	new = ft_calloc(count + 1, sizeof(long));
	index = 0;
	if (!new)
		return (NULL);
	while (index < count)
	{
		new[index] = array[index];
		index++;
	}
	new[index] = value;
	ft_printf("Count :%d\n", count + 1);
	ft_printf("Value :%d\n", index);
	free(array);
	return (new);
}

long	*handle_inputs_digit(char **input)
{
	int		input_index;
	int		splitted_index;
	int		array_index;
	char	**splitted;
	long	*array;

	input_index = 1;
	splitted_index = 0;
	array_index = 0;
	array = ft_calloc(2, sizeof(long));
	if (!array)
		return (NULL);
	while (input_index < (int) ft_str_tab_len(input))
	{
		splitted = ft_split(input[input_index++], ' ');
		while (splitted[splitted_index])
		{
			if (handle_input_digit(splitted[splitted_index]) == -1)
				return (free(splitted), ft_printf("Error\n"), NULL);
			long atoi = ft_atoi(splitted[splitted_index++]);
			array = ft_realloc(array, array_index, atoi);
			array_index++;
		}
		splitted_index = 0;
	}
	return (array);
}

long	handle_input_digit(char *input)
{
	int	index;

	index = 0;
	while (input && index < (int) ft_strlen(input))
	{
		if (!ft_isdigit(input[index]) && input[index] != '-')
			return (-1);
		index++;
	}
	return (1);
}
