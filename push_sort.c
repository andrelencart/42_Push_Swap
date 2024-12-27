/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:45:34 by andcarva          #+#    #+#             */
/*   Updated: 2024/12/27 17:46:49 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	master_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
	{
		if (stack_a->head->cont > stack_a->tail->cont)
			swap(stack_a, 'a', 1);
	}
	else if (stack_a->size == 3)
		sort_three_a(stack_a);
	while (stack_a->size > 3)
	{
		push(stack_a, stack_b, 'b');
		if (stack_b->size == 3)
			sort_three_b(stack_b);
	}
}

void	sort_three_a(t_stack *stack_a)
{
	if (stack_a->head->cont > stack_a->head->next->cont \
		&& stack_a->head->next->cont > stack_a->tail->cont)
	{
		swap(stack_a, 'a', 1);
		rev_rotate(stack_a, 'a', 1);
	}
	else if (stack_a->head->cont > stack_a->tail->cont \
		&& stack_a->tail->cont > stack_a->head->next->cont)
		rotate(stack_a, 'a', 1);
	else if (stack_a->head->next->cont > stack_a->head->cont \
		&& stack_a->head->cont > stack_a->tail->cont)
		rev_rotate(stack_a, 'a', 1);
	else if (stack_a->head->next->cont > stack_a->tail->cont \
		&& stack_a->tail->cont > stack_a->head->cont)
	{
		swap(stack_a, 'a', 1);
		rotate(stack_a, 'a', 1);
	}
	else if (stack_a->tail->cont > stack_a->head->cont \
		&& stack_a->head->cont > stack_a->head->next->cont)
		swap(stack_a, 'a', 1);
}

void	sort_three_b(t_stack *stack_b)
{
	if (stack_b->head->cont < stack_b->head->next->cont \
		&& stack_b->head->cont < stack_b->tail->cont)
		rotate(stack_b, 'b', 1);
	else if (stack_b->head->next->cont < stack_b->head->cont \
		&& stack_b->head->next->cont < stack_b->tail->cont)
		rev_rotate(stack_b, 'b', 1);
	if (stack_b->head->cont < stack_b->head->next->cont)
		swap(stack_b, 'b', 1);
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
