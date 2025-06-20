/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:03:15 by andcarva          #+#    #+#             */
/*   Updated: 2025/01/13 15:18:57 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stackadd_back(t_stack *stack, t_node *new_node)
{
	stack->size++;
	if (!stack->head)
	{
		stack->head = new_node;
		stack->tail = new_node;
		new_node->next = NULL;
		new_node->prev = NULL;
		return ;
	}
	stack->tail->next = new_node;
	new_node->prev = stack->tail;
	new_node->next = NULL;
	stack->tail = new_node;
}

void	stackadd_front(t_stack *stack, t_node *new_node)
{
	stack->size++;
	if (!stack->head)
	{
		stack->head = new_node;
		stack->tail = new_node;
		new_node->next = NULL;
		new_node->prev = NULL;
		return ;
	}
	new_node->next = stack->head;
	stack->head->prev = new_node;
	stack->head = new_node;
	new_node->prev = NULL;
}

void	stackclear(t_stack *stack)
{
	t_node	*temp;

	while (stack->head != NULL)
	{
		temp = stack->head->next;
		free(stack->head);
		stack->head = temp;
	}
	stack->tail = NULL;
	stack->head = NULL;
	stack->size = 0;
}

t_node	*ft_min(t_stack *stack)
{
	t_node	*min_value;
	t_node	*temp;

	if (!stack->head)
		return (NULL);
	min_value = stack->head;
	temp = stack->head->next;
	while (temp)
	{
		if (temp->cont < min_value->cont)
			min_value = temp;
		temp = temp->next;
	}
	return (min_value);
}

t_node	*ft_max(t_stack *stack)
{
	t_node	*max_value;
	t_node	*temp;

	if (!stack->head)
		return (NULL);
	max_value = stack->head;
	temp = stack->head->next;
	while (temp)
	{
		if (temp->cont > max_value->cont)
			max_value = temp;
		temp = temp->next;
	}
	return (max_value);
}
