/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:10:44 by andcarva          #+#    #+#             */
/*   Updated: 2024/12/13 19:43:11 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	split_assemble_stack(t_stack *stack, char **split_nbr)
{
	t_node	*node;
	int		i;
	int		cont;

	i = 0;
	cont = 0;
	while (split_nbr[i])
	{
		cont = ft_atoi(split_nbr[i]);
		// ft_printf("%s: %d\n", split_nbr[i], cont);
		node = lstnew_node(cont);
		if (!node)
			return ;
		add_node_stack(stack, node);
		i++;
	}
}

t_stack	*make_stack(int ac, char **av)
{
	t_stack	*stack;
	char	**split_nbr;
	int		i;

	i = 0;
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->size = 0;
	stack->head = NULL;
	stack->tail = NULL;
	while (i < ac)
	{
		split_nbr = ft_split(av[i], ' ');
		// ft_printf("%s\n", *split_nbr);
		if (!split_nbr)
			return (free(split_nbr), NULL);
		if (!check_func(split_nbr))
			return (NULL);
		split_assemble_stack(stack, split_nbr);
		free_split(split_nbr);
		i++;
	}
	return (stack);
}

void	add_node_stack(t_stack *stack, t_node *node)
{
	// ft_printf("entra add_node_stack\n");
	lstadd_back(&stack->head, node);
	stack->tail = node;
	stack->size++;
}

void	print_stack(t_stack *stack)
{
	t_node	*current;

	// ft_printf("entra print_stack\n");
	if (!stack || !stack->head)
		return ;
	current = stack->head;
	ft_printf("Stack size = %d\n", stack->size);
	while (current)
	{
		// ft_printf("enta print_stack loop\n");
		ft_printf("stack_nodes: %d\n", current->cont);
		current = current->next;
	}
}
