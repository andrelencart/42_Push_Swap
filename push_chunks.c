/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_chunks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:24:55 by andcarva          #+#    #+#             */
/*   Updated: 2024/12/27 14:37:30 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*gen_chunks(t_stack *stack, int chunk_size)
{
	int	num_chunks;
	int	*chunks;
	int	i;
	int	curr_min;
	
	i = 0;
	num_chunks = (stack->size + chunk_size - 1) / chunk_size; 
	curr_min = ft_min(stack);
	chunks = malloc(sizeof(int) * (num_chunks + 1));
	if (!chunks)
		return (0);
	while (i < num_chunks)
	{
		chunks[i] = curr_min + chunk_size * (i + 1);
		i++; 
	}
	chunks[i] = INT_MAX;
	return (chunks);
}

