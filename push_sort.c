/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:45:34 by andcarva          #+#    #+#             */
/*   Updated: 2025/01/09 19:33:05 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	master_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2 && !check_sorted(stack_a))
	{
		if (stack_a->head->cont > stack_a->tail->cont)
			swap(stack_a, 'a', 1);
	}
	if (stack_a->size > 3)
		push(stack_a, stack_b, 'b');
	if (stack_a->size > 3)
		push(stack_a, stack_b, 'b');
	if (stack_a->size == 3 && !check_sorted(stack_a))
		sort_three_a(stack_a);
	while (stack_a->size > 3 && !check_sorted(stack_a))
	{
		master_calc_a(stack_a, stack_b);
		// execute_move();
		push(stack_a, stack_b, 'b');
	}
	sort_three_a(stack_a);
	// if (stack_b->size == 3)
	// 	sort_three_b(stack_b);
}

// void	butler_sort()
// {
	
// }

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

void	master_calc_a(t_stack *stack_a, t_stack *stack_b)
{
	assign_index(stack_a);
	assign_index(stack_b);
	target_a(stack_a, stack_b);
	calc_moves(stack_a, stack_b);
	find_cheap(stack_a);
}

// int	master_calc_b(t_stack *stack_a, t_stack *stack_b)
// {
// 	assign_index(stack_a);
// 	assign_index(stack_b);
// 	target_b(stack_a, stack_b);
// }

