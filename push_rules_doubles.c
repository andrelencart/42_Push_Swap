/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rules_doubles.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:30:28 by andcarva          #+#    #+#             */
/*   Updated: 2025/01/10 23:04:04 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	double_swap(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("ss\n");
	swap(stack_a, 'a', 0);
	swap(stack_b, 'b', 0);
}

void	double_rotate(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("rr\n");
	rotate(stack_a, 'a', 0);
	rotate(stack_b, 'b', 0);
}

void	double_rev_rot(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("rrr\n");
	rev_rotate(stack_a, 'a', 0);
	rev_rotate(stack_b, 'b', 0);
}

void	excute_double_rot_to_b(t_stack *stack_a, t_stack *stack_b, t_node *min_move)
{
	if (min_move->index < stack_a->size / 2 \
		&& min_move->target->index < stack_b->size / 2)
		
		double_rotate(stack_a, stack_b);
	else if (min_move->index >= stack_a->size / 2 \
		&& min_move->target->index >= stack_b->size / 2)
		double_rev_rot(stack_a, stack_b);
}

void	excute_double_rot_to_a(t_stack *stack_a, t_stack *stack_b, t_node *min_move)
{
	if (min_move->index < stack_b->size / 2 \
		&& min_move->target->index < stack_a->size / 2)
		double_rotate(stack_a, stack_b);
	else if (min_move->index >= stack_b->size / 2 \
		&& min_move->target->index >= stack_a->size / 2)
		double_rev_rot(stack_a, stack_b);
}
