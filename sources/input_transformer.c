/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_transformer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 05:04:57 by jbadaire          #+#    #+#             */
/*   Updated: 2023/11/07 17:24:10 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#include "stdio.h"

static long	handle_input_digit(char *input)
{
	long	index;

	index = 0;
	while (input && index < (int) ft_strlen(input))
	{
		if (!ft_isdigit(input[index]) && input[index] != '-')
			return (-1);
		index++;
	}
	return (index);
}

static int	ft_array_len(char **input)
{
	int		original_array_index;
	int		split_index;
	int		tab_len;
	char	**splitted;

	original_array_index = 1;
	split_index = 0;
	tab_len = 0;
	while (original_array_index < (int) ft_str_tab_len(input))
	{
		splitted = ft_split(input[original_array_index], ' ');
		while (splitted[split_index])
		{
			if (handle_input_digit(splitted[split_index]) == -1)
				return (0);
			split_index++;
		}
		tab_len += split_index;
		original_array_index++;
		split_index = 0;
		ft_free_split(splitted);
	}
	return (tab_len);
}

long	*handle_inputs_digit(char **input, int original_array_index, int index)
{
	int		split_index;
	char	**split;
	long	*array;

	split_index = 0;
	array = ft_calloc(ft_array_len(input) + 1, sizeof(long));
	if (!array)
		return (NULL);
	while (index < (int) ft_str_tab_len(input))
	{
		split = ft_split(input[original_array_index++], ' ');
		if (split == NULL)
			break ;
		while (split[split_index])
		{
			if (handle_input_digit(split[split_index]) == -1)
				return (ft_free_split(split), free(array), \
				ft_printf("Error\n"), NULL);
			array[index++] = ft_atoi(split[split_index++]);
		}
		ft_free_split(split);
		split_index = 0;
	}
	return (array);
}
