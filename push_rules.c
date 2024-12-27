/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:52:04 by andcarva          #+#    #+#             */
/*   Updated: 2024/12/27 17:39:10 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack_from, t_stack *stack_to, char id)
{
	t_node	*temp;

	if (!stack_from->head)
		return ;
	ft_printf("p%c\n", id);
	temp = stack_from->head;
	stack_from->head = stack_from->head->next;
	stackadd_front(stack_to, temp);
	stack_from->size--;
}

void	swap(t_stack *stack, char id, int flag)
{
	int	temp;

	if (stack->size == 0 || stack->size == 1)
		return ;
	if (flag)
		ft_printf("rr%c\n", id);
	temp = stack->head->cont;
	stack->head->cont = stack->head->next->cont;
	stack->head->next->cont = temp;
}

void	rotate(t_stack *stack, char id, int flag)
{
	if (flag)
		ft_printf("rr%c\n", id);
	if (stack->size <= 2)
		return ;
	stack->head->prev = stack->tail;
	stack->tail->next = stack->head;
	stack->head = stack->head->next;
	stack->tail = stack->tail->next;
	stack->head->prev = NULL;
	stack->tail->next = NULL;
}

void	rev_rotate(t_stack *stack, char id, int flag)
{
	if (flag)
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
