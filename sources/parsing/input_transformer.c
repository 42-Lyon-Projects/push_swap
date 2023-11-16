/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_transformer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 05:04:57 by jbadaire          #+#    #+#             */
/*   Updated: 2023/11/16 18:31:44 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

#include "stdio.h"

static int	contains_only_numbers(char **input)
{
	int	array_index;
	int index;
	char *str;

	array_index = 0;
	index = 0;
	str = NULL;
	while (input[array_index])
	{
		str = input[array_index];
		index = 0;
		while (str[index])
		{
			if (!ft_isdigit(str[index]) && str[index] != '-' && str[index] != '+')
				return (-1);
			index++;
		}
		array_index++;
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
		if (splitted == NULL)
			break ;
		if (contains_only_numbers(splitted) == -1)
			return (ft_free_split(splitted), 0);
		while (splitted[split_index++])
			;
		tab_len += split_index;
		original_array_index++;
		split_index = 0;
		ft_free_split(splitted);
	}
	return (tab_len);
}

int	*handle_inputs_digit(t_stacks *stacks, char **input, \
int original_array_index, int index)
{
	int		split_index;
	char	**split;
	int		*array;

	array = malloc((stacks->length = ft_array_len(input)) * sizeof(int));
	if (!array)
		return (NULL);
	while (index < (int) ft_str_tab_len(input))
	{
		split = ft_split(input[original_array_index++], ' ');
		if (split == NULL)
			break ;
		if (contains_only_numbers(split) == -1)
			return (ft_free_split(split), free(array), ft_printf("Error\n"), NULL);
		split_index = 0;
		while (split[split_index] && contains_only_numbers(split) != -1)
		{
			int t = (int) ft_atoi(split[split_index++]);;
			array[index++] = t;
		}
		ft_free_split(split);
	}
	return (array);
}
