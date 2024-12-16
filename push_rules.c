/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:52:04 by andcarva          #+#    #+#             */
/*   Updated: 2024/12/16 20:27:19 by andcarva         ###   ########.fr       */
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

void	push_b(t_stack *stackA, t_stack *stackB) 
{
	t_node *temp;
	
	if (!stackA)
		return ;
	temp = stackA->head;
	stackA->head = stackA->head->next;
	stackadd_front(stackB, temp);
	// free(stackA->head->cont);
	// free(temp->cont); // need to free the node of the stackA
}

