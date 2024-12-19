/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:52:04 by andcarva          #+#    #+#             */
/*   Updated: 2024/12/19 20:58:49 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack1, t_stack *stack2, char id)
{
	t_node	*temp;

	if (!stack1->head)
		return ;
	ft_printf("p%c\n", id);
	temp = stack1->head;
	stack1->head = stack1->head->next;
	stackadd_front(stack2, temp);
	stack1->size--;
}

void	swap(t_stack *stack, char id)
{
	int	temp;

	if (stack->size == 0 || stack->size == 1)
		return ;
	ft_printf("s%c\n", id);
	temp = stack->head->cont;
	stack->head->cont = stack->head->next->cont;
	stack->head->next->cont = temp;
}

void	rotate(t_stack *stack, char id)
{
	ft_printf("r%c\n", id);
	if (stack->size <= 2)
		return ;
	stack->head->prev = stack->tail;
	stack->tail->next = stack->head;
	stack->head = stack->head->next;
	stack->tail = stack->tail->next;
	stack->head->prev = NULL;
	stack->tail->next = NULL;
}

void	rev_rotate(t_stack *stack, char id)
{
	ft_printf("rr%c\n", id);
	if (stack->size <= 2)
		return ;
	stack->tail->next = stack->head;
	stack->head->prev = stack->tail;
	stack->tail = stack->tail->prev;
	stack->head = stack->head->prev;
	stack->head->prev = NULL;
	stack->tail->next = NULL;
}
