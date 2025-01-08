/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:45:34 by andcarva          #+#    #+#             */
/*   Updated: 2025/01/08 16:54:53 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	master_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_moves best_mov_atob;
	t_moves best_mov_btoa;
	int	i;
	
	i = 0;
	if (stack_a->size == 2)
	{
		if (stack_a->head->cont > stack_a->tail->cont)
			swap(stack_a, 'a', 1);
	}
	else if (stack_a->size == 3)
		sort_three_a(stack_a);
	while (i < 2)
	{
		// ft_printf("---------------->\n");
		push(stack_a, stack_b, 'b');
		// ft_printf("---------------->\n");
		// print_stack(stack_a, 'A');
		// ft_printf("---------------->\n");
		// print_stack(stack_b, 'B');
		i++;
	}
	while (stack_a->size > 3)
	{
		ft_printf("Finding best move stack print before find best move\n");
		print_stack(stack_a, 'A');
		best_mov_atob = find_best_move(stack_a, stack_b);
		// execute_best_mov(stack_a, stack_b, best_mov_atob);
	}
	sort_three_a(stack_a);
	while (stack_b->size > 0)
	{
		best_mov_btoa = find_best_move(stack_b, stack_a);
		execute_best_mov(stack_a, stack_b, best_mov_btoa);
	}
}

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

int	find_position_in_b(t_stack *stack_b, int num)
{
	int		position;
	t_node	*current;

	position = 0;
	current = stack_b->head;
	// printf("Finding position for %d in stack_b\n", num);
	// print_stack(stack_b, 'B');
	if (!stack_b->head)
		return (position);
	while(current)
	{
		// ft_printf("Checking node with cont: %d\n", current->cont);
		// printf("Comparing %d with %d\n", num, current->cont);
		if (num <= current->cont)
			break ;
		position++;
		current = current->next;
	}
	// printf("Position in B for %d: %d\n", num, position);
	return (position);
}

int	find_position_in_a(t_stack *stack_a, int num)
{
	int		position;
	t_node	*current;

	position = 0;
	current = stack_a->head;
	while (current)
	{
		if (current->cont == num)		// print_stack(stack_a, 'A');
		// ft_printf("---------------->\n");
		// print_stack(stack_b, 'B');
			return (position);
		position++;
		current = current->next;
	}
	return (-1);
}
