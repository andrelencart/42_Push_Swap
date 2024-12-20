/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_chunks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:24:55 by andcarva          #+#    #+#             */
/*   Updated: 2024/12/20 20:20:05 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*gen_chunks(t_stack *stack, int chunk_size)
{
	int	*chunks;
	int	i;
	int	curr_min;
	
	i = 0;
	curr_min = ft_min(stack);
	chunks = malloc(sizeof(int) * \
	((stack->size + chunk_size - 1) / chunk_size));
	if (!chunks)
		return (0);
	while (i < (stack->size + chunk_size - 1) / chunk_size)
	{
		chunks[i] = curr_min + chunk_size * (i + 1);
		i++; 
	}
	chunks[i] = INT_MAX;
	return (chunks);
}

