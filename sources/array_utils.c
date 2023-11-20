/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:45:11 by jbadaire          #+#    #+#             */
/*   Updated: 2023/11/19 15:22:30 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_boolean	is_duplicated(int nb, t_stack *head)
{
	int		amount;
	t_stack	*tmp;

	amount = 0;
	tmp = head;
	while (tmp)
	{
		if (tmp->content == nb)
			amount++;
		if (tmp->next)
			tmp = tmp->next;
		else
			break ;
	}
	return (amount > 1);
}

t_boolean	ft_stack_contains_value(t_stack *head, int search)
{
	t_stack	*tmp;

	tmp = head;
	while (tmp)
	{
		if (tmp->content == search)
			return (_true);
		if (tmp->next)
			tmp = tmp->next;
		else
			break ;
	}
	return (_false);
}

t_boolean	ft_stack_has_duplicates(t_stack *head_a)
{
	t_stack	*tmp;

	tmp = head_a;
	while (tmp)
	{
		if (is_duplicated(tmp->content, tmp))
			return (_true);
		if (tmp->next)
			tmp = tmp->next;
		else
			break ;
	}
	return (_false);
}

int	*ft_stack_to_array(t_stack *a)
{
	int		*array;
	int		lst_size;
	int		index;
	t_stack	*tmp;

	lst_size = ft_stack_size(a);
	array = ft_calloc(lst_size, sizeof(int));
	if (!array)
		return (NULL);
	index = 0;
	tmp = a;
	while (index < lst_size)
	{
		array[index] = tmp->content;
		tmp = tmp->next;
		index++;
	}
	return (array);
}
