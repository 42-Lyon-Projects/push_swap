/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_transformer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 05:04:57 by jbadaire          #+#    #+#             */
/*   Updated: 2023/10/28 05:04:57 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	count_integer(char **input)
{
	int		input_index;
	int		index;
	int		amount;

	input_index = 1;
	index = 0;
	amount = 0;
	while (input[input_index])
	{
		while (input[input_index][index])
		{
			if (ft_isdigit(input[input_index][index++]))
				amount++;
		}
		input_index++;
	}
	return (amount);
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
	array = malloc(sizeof(long) * count_integer(input));
	if (!array)
		return (NULL);
	while (input_index < (int) ft_str_tab_len(input))
	{
		splitted = ft_split(input[input_index++], ' ');
		while (splitted[splitted_index])
		{
			if (handle_input_digit(splitted[splitted_index]) == -1)
				return (free(splitted), ft_printf("Error"), NULL);
			array[array_index++] = ft_atoi(splitted[splitted_index++]);
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
