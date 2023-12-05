/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_transformer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 05:04:57 by jbadaire          #+#    #+#             */
/*   Updated: 2023/12/05 14:00:20 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	contains_only_numbers(char **input)
{
	int		array_index;
	int		i;
	char	*str;

	array_index = 0;
	i = 0;
	str = NULL;
	while (input[array_index])
	{
		str = input[array_index++];
		i = 0;
		while (str[i])
		{
			if (i > 0 && ft_is_sign(str[i]) && ft_is_sign(str[i - 1]))
				return (-1);
			if (ft_is_sign(str[i]) && !ft_isdigit(str[i + 1]))
				return (-1);
			if (ft_is_sign(str[i]) && (i > 0 && ft_isdigit(str[i - 1])))
				return (-1);
			if (!ft_isdigit(str[i]) && !ft_is_sign(str[i]))
				return (-1);
			i++;
		}
	}
	return (i);
}

static void	ft_contains_error(char **split, t_stacks *stacks, long long content)
{
	int		index;
	size_t	len;

	index = 0;
	if (contains_only_numbers(split) == -1)
	{
		ft_free_split(split);
		ft_putstr_fd("Error\n", 2);
		ft_free_and_exit(stacks, 1);
	}
	if (content > INT_MAX || content < INT_MIN)
	{
		while (split[index])
		{
			len = ft_strlen(split[index]);
			if (!ft_strnstr(split[index], "2147483647", len) || \
			!ft_strnstr(split[index++], "-2147483647", len))
			{
				ft_free_split(split);
				ft_putstr_fd("Error\n", 2);
				ft_free_and_exit(stacks, 1);
			}
		}
	}
}

static void	ft_replace_spaces(char **strs)
{
	int	index_str;
	int	index_char;

	index_str = 0;
	index_char = 0;
	while (strs[index_str])
	{
		while (strs[index_str][index_char])
		{
			if (ft_is_space(strs[index_str][index_char]))
				strs[index_str][index_char] = ' ';
			index_char++;
		}
		index_char = 0;
		index_str++;
	}
}

void	handle_inputs_digit(t_stacks *stacks, char **input, int tab_index)
{
	int				s_index;
	char			**split;
	long long		content;

	if (input)
		ft_replace_spaces(input);
	while (_true)
	{
		split = ft_split(input[tab_index++], ' ');
		if (split == NULL)
			break ;
		s_index = 0;
		while (split[s_index])
		{
			content = ft_ll_overflow_atoi(split[s_index++]);
			ft_contains_error(split, stacks, content);
			add_node_back(&stacks->stack_a, create_node((int)content, -1));
			stacks->length = stacks->length + 1;
		}
		ft_free_split(split);
	}
}
