/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:22:44 by andcarva          #+#    #+#             */
/*   Updated: 2024/12/18 21:01:16 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// t_stack init()
// {
// 	return ((t_stack){.size=10,.head=NULL, .tail=NULL});
// }

int	main(int ac, char **av)
{
	static t_stack	stackA;
	static t_stack	stackB;
	int		i;

	i = 1;
	if (ac <= 1)
		return (0);
	while (av[i])
	{
		if (!check_spaces(av[i++]))
			return (0);
	}
	i = 1;
	stackA = make_stack(ac - 1, &av[i]);
	if (!stackA.head)
		return (0);
	print_stack(&stackA, 'A');
	push(&stackA, &stackB, 'b');
	push(&stackA, &stackB, 'b');
	push(&stackA, &stackB, 'b');
	print_stack(&stackB, 'B');
	rotate(&stackB, 'b');
	print_stack(&stackB, 'B');
	rev_rotate(&stackB, 'b');
	print_stack(&stackB, 'B');
	// swap(stackA, 'a');
	print_stack(&stackA, 'A');
	// print_stack(&stackB, 'B');
	// push_a(&stackA, &stackB);
	// push_a(&stackA, &stackB);
	// print_stack(&stackB, 'B');
	stackclear(&stackA);
	stackclear(&stackB);
}
