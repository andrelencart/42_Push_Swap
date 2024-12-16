/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_lst_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:03:15 by andcarva          #+#    #+#             */
/*   Updated: 2024/12/16 20:11:19 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*lstnew_node(int cont)
{
	t_node	*new_node;

	// ft_printf("enta new_node\n");
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->cont = cont;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

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
	// temp = *lst;
	// while (temp->next != NULL)
	// 	temp = temp->next;
	// temp->next = new_node;
	// new_node->prev = temp;
	// new_node->next = NULL;
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

int	lstsize(t_node *lst)
{
	int	i;

	i = 0;
	while (lst && lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

void	stackclear(t_stack *stack)
{
	t_node	*temp;

	if (!stack || !stack->head)
		return ;
	while (stack->head != NULL)
	{
		temp = stack->head->next;
		free(stack->head);
		stack->head = temp;
	}
	stack->tail = NULL;
	stack->size = 0;
}

