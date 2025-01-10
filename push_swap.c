/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:22:44 by andcarva          #+#    #+#             */
/*   Updated: 2025/01/10 22:35:44 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	static t_stack	stack_a;
	static t_stack	stack_b;
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
	master_sort(&stack_a, &stack_b);
	ft_printf("---------------->\n");
	print_stack(&stack_a, 'A');
	stackclear(&stack_a);
	stackclear(&stack_b);
}
