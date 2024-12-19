/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_lst_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:03:15 by andcarva          #+#    #+#             */
/*   Updated: 2024/12/19 20:55:12 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stackadd_back(t_stack *stack, t_node *new_node)
{
	// ft_printf("entra add_back\n");
	stack->size++;
	if (!stack->head)
	{
		stack->head = new_node;
		stack->tail = new_node;
		new_node->next = NULL;
		new_node->prev = NULL; //leaks?
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
		new_node->prev = NULL; //leaks?
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

// int	ft_min(t_stack *stack)
// {

// }
