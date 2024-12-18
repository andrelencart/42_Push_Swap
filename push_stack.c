/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:10:44 by andcarva          #+#    #+#             */
/*   Updated: 2024/12/18 21:08:26 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	split_assemble_stack(t_stack *stack, char **split_nbr)
{
	t_node	*node;
	int		i;
	int		cont;

	i = 0;
	cont = 0;
	while (split_nbr[i])
	{
		cont = ft_atoi(split_nbr[i]);
		if (check_dupes(stack, cont))
			return (stackclear(stack), false);
		node = lstnew_node(cont);
		if (!node)
			return (stackclear(stack), false);
		stackadd_back(stack, node);
		i++;
	}
	return (true);
}

t_stack	make_stack(int ac, char **av)
{
	t_stack	stack;
	char	**split_nbr;
	int		i;

	i = 0;
	stack = (t_stack){0}; // creating struct, all null;
	while (i < ac)
	{
		split_nbr = ft_split(av[i], ' ');
		if (!split_nbr)
		{	
			stackclear(&stack);
			break;
		}
		if (!check_func(split_nbr) || !split_assemble_stack(&stack, split_nbr))
		{	
			(free_s(split_nbr), stackclear(&stack));
			break;
		}
		free_s(split_nbr);
		i++;
	}
	return (stack);
}

void	print_stack(t_stack *stack, char id)
{
	t_node	*current;

	ft_printf("Stack%c:\n", id);
	if (!stack)
		return ;
	current = stack->head;
	ft_printf("Stack size = %d\n", stack->size);
	while (current)
	{
		ft_printf("stack_nodes: %d\n", current->cont);
		current = current->next;
	}
}

t_node	*lstnew_node(int cont)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->cont = cont;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}
