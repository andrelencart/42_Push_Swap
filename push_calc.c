/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:24:55 by andcarva          #+#    #+#             */
/*   Updated: 2025/01/10 21:09:47 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// -target_a procura no stack b o numero menor mais proximo do numero que quero fazer push;
// -target_b procura no stack a o numero maior mais proximo do numero que quero fazer push;
// -calc_moves calcular o total de moves para colocar o numero no target /
//	moves to top of stackA e moves of target to top of stackB;
// -find_cheap utiliza a mflag e coloca 1 no minimal cost, bool func; 

void	master_calc(t_stack *stack_a, t_stack *stack_b)
{
	assign_index(stack_a);
	assign_index(stack_b);
	target_a(stack_a, stack_b);
	calc_moves(stack_a, stack_b);
	target_b(stack_a, stack_b);
	calc_moves(stack_b, stack_a);
}


void	calc_moves(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp_a;
	// t_node	*temp_b;
	
	temp_a = stack_a->head;
	// temp_b = stack_b->head;
	// temp_a->moves = 0;
	while (temp_a)
	{
		if (temp_a->index < stack_a->size / 2)
			temp_a->moves = temp_a->index;
		else
			temp_a->moves = stack_a->size - temp_a->index;
		if (temp_a->target->index < stack_b->size / 2)
			temp_a->moves += temp_a->target->index;
		else
			temp_a->moves += stack_b->size - temp_a->target->index;

		// printf("i: %d cont %d moves: %d\n", temp_a->index, temp_a->cont, temp_a->moves);

		temp_a = temp_a->next;
	}
}

t_node	*find_cheap(t_stack *stack)
{
	t_node	*cheapest;
	t_node	*temp;
	int		best_move;

	temp = stack->head;
	cheapest = stack->head;
	best_move = INT_MAX;
	// ft_printf("---------------->\n");
	// printf("temp->moves: %d\n", temp->moves);
	while (temp)
	{
		if (temp->moves < best_move)
		{
			best_move = temp->moves;
			cheapest = temp;
		}
		temp = temp->next;
	}
	// printf("i: %d node: %d min_moves: %d\n", cheapest->index, cheapest->cont, cheapest->moves);
	return (cheapest);
}

