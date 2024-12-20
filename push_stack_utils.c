/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:03:15 by andcarva          #+#    #+#             */
/*   Updated: 2024/12/20 17:46:11 by andcarva         ###   ########.fr       */
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

int	ft_min(t_stack *stack)
{
	int	min_value;
	t_node	*temp;
	
	if (!stack)
		return (0);
	min_value = stack->head->cont;
	temp = stack->head->next;
	while (temp)
	{
		if (temp->cont < min_value)
			min_value = temp->cont;
		temp = temp->next;
	}
		return (min_value);
}

int	ft_max(t_stack *stack)
{
	int	max_value;
	t_node	*temp;
	
	if (!stack)
		return (0);
	max_value = stack->head->cont;
	temp = stack->head->next;
	while (temp)
	{
		if (temp->cont > max_value)
			max_value = temp->cont;
		temp = temp->next;
	}
	return (max_value);	
}

// int	lstsize(t_node *lst)
// {
// 	int	i;

// 	i = 0;
// 	while (lst && lst != NULL)
// 	{
// 		i++;
// 		lst = lst->next;
// 	}
// 	return (i);
// }
