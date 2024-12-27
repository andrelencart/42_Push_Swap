/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:22:44 by andcarva          #+#    #+#             */
/*   Updated: 2024/12/27 17:54:31 by andcarva         ###   ########.fr       */
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
	// static t_stack	stack_b;
	int				i;
	// int j = 0;

	i = 1;
	if (ac <= 1)
		return (0);
	while (av[i])
	{
		if (!check_spaces(av[i++]))
			return (ft_printf("Error\n"), 0);
	}
	i = 1;
	stack_a = make_stack(ac - 1, &av[i]);
	if (!stack_a.head)
		return (0);
	// j = ft_max(&stack_a);
	// ft_printf("%d\n", j);
	print_stack(&stack_a, 'A');
	ft_printf("---------------->\n");
	// double_rev_rot(&stack_a);
	// master_sort(&stack_a, &stack_b);
	// sort_stack_b(&stack_a, &stack_b);
	// print_stack(&stack_b, 'B');
	ft_printf("---------------->\n");
	print_stack(&stack_a, 'A');
	// stackclear(&stack_a);
	// stackclear(&stack_b);
}
