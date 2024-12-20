/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:45:34 by andcarva          #+#    #+#             */
/*   Updated: 2024/12/20 18:24:32 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	master_sort(t_stack *stack)
{
	if (stack->size == 2)
	{
		if (stack->head->cont > stack->tail->cont)
			swap(stack, 'a');
	}
	else if (stack->size == 3)
		sort_three(stack);
}

void	sort_three(t_stack *stack_a)
{
	if (stack_a->head->cont > stack_a->head->next->cont \
		&& stack_a->head->next->cont > stack_a->tail->cont)
	{
		swap(stack_a, 'a');
		rev_rotate(stack_a, 'a');
	}
	else if (stack_a->head->cont > stack_a->tail->cont \
		&& stack_a->tail->cont > stack_a->head->next->cont)
		rotate(stack_a, 'a');
	else if (stack_a->head->next->cont > stack_a->head->cont \
		&& stack_a->head->cont > stack_a->tail->cont)
		rev_rotate(stack_a, 'a');
	else if (stack_a->head->next->cont > stack_a->tail->cont \
		&& stack_a->tail->cont > stack_a->head->cont)
	{
		swap(stack_a, 'a');
		rotate(stack_a, 'a');
	}
	else if (stack_a->tail->cont > stack_a->head->cont \
		&& stack_a->head->cont > stack_a->head->next->cont)
		swap(stack_a, 'a');
}

// void	sort_stack_b(t_stack *stack_a, t_stack *stack_b)
// {
// 	while (stack_b->size < 2 && !check_sorted(stack_a))
// 		push(stack_a, stack_b, 'b');
// 	while (stack_a->size > 3 && !check_sorted(stack_a))
// 	{
// 		if (stack_a->head->cont > ft_max(stack_b) \
// 			|| stack_a->head->cont > ft_min(stack_b))
// 		push(stack_a, stack_b, 'b');
// 	}
// }
