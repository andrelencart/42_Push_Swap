/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:22:44 by andcarva          #+#    #+#             */
/*   Updated: 2024/12/19 20:46:14 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// t_stack init()
// {
// 	return ((t_stack){.size=10,.head=NULL, .tail=NULL});
// }

int	main(int ac, char **av)
{
	static t_stack	stack_a;
	static t_stack	stack_b;
	int				i;

	i = 1;
	if (ac <= 1)
		return (0);
	while (av[i])
	{
		if (!check_spaces(av[i++]))
			return (0);
	}
	i = 1;
	stack_a = make_stack(ac - 1, &av[i]);
	if (!stack_a.head)
		return (0);
	print_stack(&stack_a, 'A');
	// rev_rotate(&stack_a, 'a');
	master_sort(&stack_a);
	print_stack(&stack_a, 'A');
	stackclear(&stack_a);
	stackclear(&stack_b);
}
