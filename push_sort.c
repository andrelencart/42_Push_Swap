/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:45:34 by andcarva          #+#    #+#             */
/*   Updated: 2024/12/19 20:52:00 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	master_sort(t_stack *stack)
{
	if (stack->size <= 2)
	{
		if (stack->head->cont > stack->tail->cont)
			swap(stack, 'a');
	}
	else if (stack->size == 3)
		sort_three(stack);
	// else
	// 	big_sort
}

void	sort_three(t_stack *stack)
{
	if (stack->head->cont > stack->head->next->cont \
		&& stack->head->next->cont > stack->tail->cont)
	{
		swap(stack, 'a');
		rev_rotate(stack, 'a');
	}
	else if (stack->head->cont > stack->tail->cont \
		&& stack->tail->cont > stack->head->next->cont)
		rotate(stack, 'a');
	else if (stack->head->next->cont > stack->head->cont \
		&& stack->head->cont > stack->tail->cont)
		rev_rotate(stack, 'a');
	else if (stack->head->next->cont > stack->tail->cont \
		&& stack->tail->cont > stack->head->cont)
	{
		swap(stack, 'a');
		rotate(stack, 'a');
	}
	else if (stack->tail->cont > stack->head->cont \
		&& stack->head->cont > stack->head->next->cont)
		swap(stack, 'a');
}
