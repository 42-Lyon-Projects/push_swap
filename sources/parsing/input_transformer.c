/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_transformer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 05:04:57 by jbadaire          #+#    #+#             */
/*   Updated: 2023/11/20 12:36:45 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

#include "stdio.h"

static int	contains_only_numbers(char **input)
{
	int		array_index;
	int		index;
	char	*str;

	array_index = 0;
	index = 0;
	str = NULL;
	while (input[array_index])
	{
		str = input[array_index];
		index = 0;
		while (str[index])
		{
			if (index > 0 && \
			ft_is_sign(str[index]) && ft_is_sign(str[index - 1]))
				return (-1);
			if (!ft_isdigit(str[index]) && !ft_is_sign(str[index]))
				return (-1);
			index++;
		}
		array_index++;
	}
	return (index);
}

void	handle_inputs_digit(t_stacks *stacks, char **input, int tab_index)
{
	int		index;
	int		split_index;
	char	**split;

	index = 0;
	while (index < (int) ft_str_tab_len(input))
	{
		split = ft_split(input[tab_index++], ' ');
		if (split == NULL)
			break ;
		if (contains_only_numbers(split) == -1)
		{
			ft_free_split(split);
			ft_printf("Error\n");
			ft_free_and_exit(stacks);
			return ;
		}
		split_index = 0;
		while (split[split_index])
		{
			add_node_back(&stacks->stack_a, \
			create_node((int) ft_atoi(split[split_index++])));
			stacks->length = stacks->length + 1;
		}
		ft_free_split(split);
	}
}
