/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:45:34 by andcarva          #+#    #+#             */
/*   Updated: 2025/01/13 15:18:32 by andcarva         ###   ########.fr       */
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
		master_calc(stack_a, stack_b);
		execute_move_to_b(stack_a, stack_b);
		push(stack_a, stack_b, 'b');
	}
	sort_three_a(stack_a);
	while (stack_b->size > 0)
	{
		master_calc(stack_a, stack_b);
		execute_move_to_a(stack_a, stack_b);
		push(stack_b, stack_a, 'a');
	}
	last_rotate(stack_a);
}

void	execute_move_to_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*min_move;

	min_move = find_cheap(stack_a);
	while (min_move != stack_a->head || min_move->target != stack_b->head)
	{
		if (!excute_double(stack_a, stack_b, min_move))
		{
			if (min_move != stack_a->head)
			{
				if (min_move->index < stack_a->size / 2)
					rotate(stack_a, 'a', 1);
				else
					rev_rotate(stack_a, 'a', 1);
			}
			if (min_move->target != stack_b->head)
			{
				if (min_move->target->index < stack_b->size / 2)
					rotate(stack_b, 'b', 1);
				else
					rev_rotate(stack_b, 'b', 1);
			}
		}
	}
	assign_index(stack_b);
}

void	execute_move_to_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*min_move;

	min_move = find_cheap(stack_b);
	while (min_move != stack_b->head || min_move->target != stack_a->head)
	{
		if (!excute_double(stack_b, stack_a, min_move))
		{
			if (min_move != stack_b->head)
			{
				if (min_move->index < stack_b->size / 2)
					rotate(stack_b, 'b', 1);
				else
					rev_rotate(stack_b, 'b', 1);
			}
			if (min_move->target != stack_a->head)
			{
				if (min_move->target->index < stack_a->size / 2)
					rotate(stack_a, 'a', 1);
				else
					rev_rotate(stack_a, 'a', 1);
			}
		}
	}
	assign_index(stack_a);
}

void	sort_three_a(t_stack *stack_a)
{
	if (!check_sorted(stack_a))
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
}

void	last_rotate(t_stack *stack_a)
{
	t_node	*temp;

	assign_index(stack_a);
	temp = ft_min(stack_a);
	while (temp != stack_a->head)
	{
		if (temp->index < stack_a->size / 2)
			rotate(stack_a, 'a', 1);
		else
			rev_rotate(stack_a, 'a', 1);
	}
	assign_index(stack_a);
}
