/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_transformer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 05:04:57 by jbadaire          #+#    #+#             */
/*   Updated: 2023/11/23 09:09:08 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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
			if (ft_is_sign(str[index]) && ft_isdigit(str[index - 1]))
				return (-1);
			if (!ft_isdigit(str[index]) && !ft_is_sign(str[index]))
				return (-1);
			index++;
		}
		array_index++;
	}
	return (index);
}

static void	ft_contains_error(char **split, t_stacks *stacks, int content)
{
	int		index;
	size_t	len;

	index = 0;
	if (contains_only_numbers(split) == -1)
	{
		ft_free_split(split);
		ft_putstr_fd("Error\n", 2);
		ft_free_and_exit(stacks);
	}
	if (content <= INT_MIN || content >= INT_MAX)
	{
		while (split[index])
		{
			len = ft_strlen(split[index]);
			if (!ft_strnstr(split[index], "2147483647", len) || \
			!ft_strnstr(split[index++], "-2147483648", len))
			{
				ft_free_split(split);
				ft_putstr_fd("Error\n", 2);
				ft_free_and_exit(stacks);
			}
		}
	}
}

void	handle_inputs_digit(t_stacks *stacks, char **input, int tab_index)
{
	int		index;
	int		s_index;
	char	**split;
	int		content;

	index = 0;
	while (index < (int) ft_str_tab_len(input))
	{
		split = ft_split(input[tab_index++], ' ');
		if (split == NULL)
			break ;
		ft_contains_error(split, stacks, 0);
		s_index = 0;
		while (split[s_index])
		{
			content = ft_overflow_atoi(split[s_index++]);
			ft_contains_error(split, stacks, content);
			add_node_back(&stacks->stack_a, create_node(content, -1));
			stacks->length = stacks->length + 1;
		}
		ft_free_split(split);
	}
}
