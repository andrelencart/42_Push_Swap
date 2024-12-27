/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rules_doubles.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:30:28 by andcarva          #+#    #+#             */
/*   Updated: 2024/12/27 17:49:17 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	double_swap(t_stack *stack)
{
	ft_printf("ss\n");
	swap(stack, 'a', 0);
	swap(stack, 'b', 0);
}

void	double_rotate(t_stack *stack)
{
	ft_printf("rr\n");
	rotate(stack, 'a', 0);
	rotate(stack, 'b', 0);
}

void	double_rev_rot(t_stack *stack)
{
	ft_printf("rrr\n");
	rev_rotate(stack, 'a', 0);
	rev_rotate(stack, 'b', 0);
}
