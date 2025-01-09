/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:54:47 by andcarva          #+#    #+#             */
/*   Updated: 2025/01/09 18:17:19 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	target_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp_a;
	t_node	*temp_b;
	long	best_target;

	temp_a = stack_a->head;
	while (temp_a)
	{
		temp_b = stack_b->head;
		best_target = LONG_MIN;
		while (temp_b)
		{
			if (temp_a->cont > temp_b->cont && best_target < temp_b->cont)
			{
				best_target = temp_b->cont;
				temp_a->target = temp_b;
			}
			temp_b = temp_b->next;
		}
		if (best_target == LONG_MIN)
			temp_a->target = ft_max(stack_b);
		printf("i: %d target of %d: %d\n", temp_a->index, temp_a->cont, temp_a->target->cont);
		temp_a = temp_a->next;
	}
	print_stack(stack_b, 'B');
	ft_printf("---------------->\n");
}

void	target_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp_a;
	t_node	*temp_b;
	long	best_target;

	temp_b = stack_b->head;
	while (temp_b)
	{
		temp_a = stack_a->head;
		best_target = LONG_MAX;
		while (temp_a)
		{
			if (temp_b->cont < temp_a->cont && best_target > temp_a->cont)
			{
					best_target = temp_a->cont;
					temp_b->target = temp_a;
			}
			temp_a = temp_a->next;
		}
		if (best_target == LONG_MAX)
			temp_b->target = ft_min(stack_a);
		printf("target of %d: %d\n", temp_b->cont, temp_b->target->cont);
		temp_b = temp_b->next;
	}
}
// static int	abs_value(int num)
// {
// 	if (num < 0)
// 		return (-num);
// 	else
// 		return (num);
// }

