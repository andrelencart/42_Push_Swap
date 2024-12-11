/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:10:44 by andcarva          #+#    #+#             */
/*   Updated: 2024/12/11 20:04:32 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*make_stack(int ac, char **av)
{
	t_stack	*stack;
	t_node	*node;
	int		i;
	int		cont;

	i = 1;
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (free(stack), NULL);
	stack->size = 0;
	stack->head = NULL;
	stack->tail = NULL;
	while (i < ac)
	{
		cont = ft_atoi(&av[i]);
		// if (*av[i] && !is_wspace(av[i]))
		// 	break;
		node = lstnew_node(cont);
		add_node_stack(stack, node);
		i++;
	}
	return (stack);
}

void	add_node_stack(t_stack *stack, t_node *node)
{
	lstadd_back(&stack->head, node);
	stack->tail = node;
	stack->size++;
}
