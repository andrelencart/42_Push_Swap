/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:52:04 by andcarva          #+#    #+#             */
/*   Updated: 2024/12/11 19:04:39 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *stackA)
{
	int	temp;

	temp = stackA->head->cont;
	stackA->head->next->cont = temp;
	stackA->head->cont = stackA->head->next->cont;
	write(1, "sa", 2);
}

// void	swap_a(t_stack *stackB)
// {
// 	int	temp;

// 	temp = stackB->head->cont;
// 	stackB->head->next->cont = temp;
// 	stackB->head->cont = stackB->head->next->cont;
// }

// void	push_b(t_stack *stackA, t_stack stackB)
// {
// }
