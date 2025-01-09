/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:24:55 by andcarva          #+#    #+#             */
/*   Updated: 2025/01/09 19:34:12 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// -target_a procura no stack b o numero menor mais proximo do numero que quero fazer push;
// -target_b procura no stack a o numero maior mais proximo do numero que quero fazer push;
// -calc_moves calcular o total de moves para colocar o numero no target /
//	moves to top of stackA e moves of target to top of stackB;
// -find_cheap utiliza a mflag e coloca 1 no minimal cost, bool func; 

void	calc_moves(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp_a;
	t_node	*temp_b;
	
	temp_a = stack_a->head;
	temp_b = stack_b->head;
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

		printf("i: %d cont %d moves: %d\n", temp_a->index, temp_a->cont, temp_a->moves);
		ft_printf("---------------->\n");

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
	while (temp)
	{
		if (temp->moves < best_move)
		{
			best_move = temp->moves;	
			cheapest = temp;
		}
		temp = temp->next;
	}
	printf("i: %d min_moves: %d\n", cheapest->index, cheapest->moves);
	return (cheapest);
}



// t_moves calc_total_moves(t_stack *stack_a, t_stack *stack_b, int num)
// {
// 	t_moves moves;

// 	position_a = 
// 	position_b = 
	
// 	moves.mov_toa = calc_moves(stack_a, position_a);
// 	moves.mov_pnb = calc_moves(stack_b, position_b);
// 	// if (moves.mov_toa > stack_a->size / 2)
// 	// 	moves.mov_toa -= stack_a->size;
// 	// if (moves.mov_pnb > stack_b->size / 2)
// 	// 	moves.mov_pnb -= stack_b->size;
// 	moves.total_mov = abs_value(moves.mov_toa) + abs_value(moves.mov_pnb);
// 	// printf("Calculating moves for num=%d:\n", num);
//     // printf("  position_a=%d, mov_toa=%d\n", position_a, moves.mov_toa);
//     // printf("  position_b=%d, mov_pnb=%d\n", position_b, moves.mov_pnb);
//     // printf("  total_mov=%d\n", moves.total_mov);
// 	return (moves);
// }



// t_moves	find_best_move(t_stack *stack_from, t_stack *stack_to)
// {
// 	t_moves	curr_move;
// 	t_moves	best_move;
// 	t_node	*current;
	

// 	current = stack_from->head;
// 	best_move.min_mov = INT_MAX;
// 	ft_printf("Finding best move stack print\n");
// 	print_stack(stack_from, 'A');
// 	while (current)
// 	{
// 		ft_printf("Finding best move stack print loop\n");
// 		print_stack(stack_from, 'A');
// 		// ft_printf("Current node: %d\n", current->cont);
// 		curr_move = calc_total_moves(stack_from, stack_to, current->cont);
// 		// ft_printf("Current move: num=%d, toa=%d, pnb=%d, total=%d\n", 
//         //         current->cont, curr_move.mov_toa, curr_move.mov_pnb, curr_move.total_mov);
// 		if (curr_move.total_mov < best_move.min_mov)
// 		{
// 			best_move = curr_move;
// 			best_move.min_mov = curr_move.total_mov;
// 		}
// 		current = current->next;
// 	}
// 	// ft_printf("New best move: min_move=%d, toa=%d, pnb=%d\n", 
// 	// 			curr_move.min_mov, curr_move.mov_toa, curr_move.mov_pnb);
// 	ft_printf("Finding best move stack print after loop\n");
// 	print_stack(stack_from, 'A');
// 	// print_stack(stack_to, 'B');
// 	return (best_move);
// }




// void	execute_best_mov(t_stack *stack_a, t_stack *stack_b, t_moves best_move)
// {
// 	// printf("Executing best move: toa=%d, pnb=%d\n", best_move.mov_toa, best_move.mov_pnb);
// 	ft_printf("Finding best move stack print execute func\n");
// 	print_stack(stack_a, 'A');
// 	while (best_move.mov_toa > 0)
// 	{
// 		rotate(stack_a, 'a', 1);
// 		best_move.mov_toa--;
// 	}
// 	while (best_move.mov_toa < 0)
// 	{
// 		rev_rotate(stack_a, 'a', 1);
// 		best_move.mov_toa++;
// 	}
// 	while (best_move.mov_pnb > 0)
// 	{
// 		rotate(stack_b, 'b', 1);
// 		best_move.mov_pnb--;
// 	}
// 	while (best_move.mov_pnb < 0)
// 	{
// 		rev_rotate(stack_b, 'b', 1);
// 		best_move.mov_pnb++;
// 	}
// 	// printf("Performing push from A to B\n");
// 	push(stack_a, stack_b, 'b');
// 	// print_stack(stack_a, 'A');
//     // print_stack(stack_b, 'B');
// 	// printf("Move executed.\n");
// }

		// static int	abs_value(int num)
		// {
		// 	if (num < 0)
		// 		return (-num);
		// 	else
		// 		return (num);
		// }

