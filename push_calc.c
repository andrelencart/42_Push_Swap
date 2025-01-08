/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:24:55 by andcarva          #+#    #+#             */
/*   Updated: 2025/01/08 16:34:13 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	abs_value(int num)
{
	if (num < 0)
		return (-num);
	else
		return (num);
}
int	calc_moves(t_stack *stack, int position)
{
	// ft_printf("stack->size: %d\n", stack->size);
	if (position <= stack->size / 2)
		return (position);
	else
		return (stack->size - position);
}

t_moves calc_total_moves(t_stack *stack_a, t_stack *stack_b, int num)
{
	t_moves moves;
	int 	position_a;
	int 	position_b;

	position_a = find_position_in_a(stack_a, num);
	position_b = find_position_in_b(stack_b, num);
	
	moves.mov_toa = calc_moves(stack_a, position_a);
	moves.mov_pnb = calc_moves(stack_b, position_b);
	// if (moves.mov_toa > stack_a->size / 2)
	// 	moves.mov_toa -= stack_a->size;
	// if (moves.mov_pnb > stack_b->size / 2)
	// 	moves.mov_pnb -= stack_b->size;
	moves.total_mov = abs_value(moves.mov_toa) + abs_value(moves.mov_pnb);
	// printf("Calculating moves for num=%d:\n", num);
    // printf("  position_a=%d, mov_toa=%d\n", position_a, moves.mov_toa);
    // printf("  position_b=%d, mov_pnb=%d\n", position_b, moves.mov_pnb);
    // printf("  total_mov=%d\n", moves.total_mov);
	return (moves);
}

t_moves	find_best_move(t_stack *stack_from, t_stack *stack_to)
{
	t_moves	curr_move;
	t_moves	best_move;
	t_node	*current;
	

	current = stack_from->head;
	best_move.min_mov = INT_MAX;
	ft_printf("Finding best move stack print\n");
	print_stack(stack_from, 'A');
	while (current)
	{
		ft_printf("Finding best move stack print loop\n");
		print_stack(stack_from, 'A');
		// ft_printf("Current node: %d\n", current->cont);
		curr_move = calc_total_moves(stack_from, stack_to, current->cont);
		// ft_printf("Current move: num=%d, toa=%d, pnb=%d, total=%d\n", 
        //         current->cont, curr_move.mov_toa, curr_move.mov_pnb, curr_move.total_mov);
		if (curr_move.total_mov < best_move.min_mov)
		{
			best_move = curr_move;
			best_move.min_mov = curr_move.total_mov;
		}
		current = current->next;
	}
	// ft_printf("New best move: min_move=%d, toa=%d, pnb=%d\n", 
	// 			curr_move.min_mov, curr_move.mov_toa, curr_move.mov_pnb);
	ft_printf("Finding best move stack print after loop\n");
	print_stack(stack_from, 'A');
	// print_stack(stack_to, 'B');
	return (best_move);
}

void	execute_best_mov(t_stack *stack_a, t_stack *stack_b, t_moves best_move)
{
	// printf("Executing best move: toa=%d, pnb=%d\n", best_move.mov_toa, best_move.mov_pnb);
	ft_printf("Finding best move stack print execute func\n");
	print_stack(stack_a, 'A');
	while (best_move.mov_toa > 0)
	{
		rotate(stack_a, 'a', 1);
		best_move.mov_toa--;
	}
	while (best_move.mov_toa < 0)
	{
		rev_rotate(stack_a, 'a', 1);
		best_move.mov_toa++;
	}
	while (best_move.mov_pnb > 0)
	{
		rotate(stack_b, 'b', 1);
		best_move.mov_pnb--;
	}
	while (best_move.mov_pnb < 0)
	{
		rev_rotate(stack_b, 'b', 1);
		best_move.mov_pnb++;
	}
	// printf("Performing push from A to B\n");
	push(stack_a, stack_b, 'b');
	// print_stack(stack_a, 'A');
    // print_stack(stack_b, 'B');
	// printf("Move executed.\n");
}

// int	*gen_chunks(t_stack *stack, int chunk_size)
// {
// 	int	num_chunks;
// 	int	*chunks;
// 	int	i;
// 	int	curr_min;ents can
	
// 	i = 0;
// 	num_chunks = (stack->size + chunk_size - 1) / chunk_size; 
// 	curr_min = ft_min(stack);
// 	chunks = malloc(sizeof(int) * (num_chunks + 1));
// 	if (!chunks)ein
// 		return (0);
// 	while (i < num_chunks)
// 	{    if (num < 0)
// 		chunks[i] = curr_min + chunk_size * (i + 1);
// 		i++; 
// 	}
// 	chunks[i] = INT_MAX;
// 	return (chunks);
// }
