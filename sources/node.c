/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:51:55 by jbadaire          #+#    #+#             */
/*   Updated: 2023/11/09 13:27:10 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*create_node(int content)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

t_stack	*last_node(t_stack *node)
{
	t_stack *tmp_stack;
	tmp_stack = node;
	if (!tmp_stack)
		return (tmp_stack);
	while (tmp_stack->next)
		tmp_stack = tmp_stack->next;
	return (tmp_stack);
}

void	add_node_back(t_stack **stack, t_stack *node)
{
	t_stack	*tmp_stack;

	if (!*stack)
	{
		*stack = node;
		return ;
	}
	tmp_stack = *stack;
	while (tmp_stack && tmp_stack->next)
		tmp_stack = tmp_stack->next;
	tmp_stack->next = node;
}

void	add_node_front(t_stack *stack, t_stack *new)
{
	new->next = stack;
	stack = new;
}

void	remove_node_back(t_stack **stack)
{
	t_stack	*tmp_stack;
	t_stack	*last_node;
	if(!*stack)
		return ;
	if(!(*stack)->next)
	{
		*stack = NULL;
		return ;
	}
	tmp_stack = *stack;
	while (tmp_stack->next->next)
		tmp_stack = tmp_stack->next;
	last_node = tmp_stack->next;
	tmp_stack->next = NULL;
	free(last_node);
}