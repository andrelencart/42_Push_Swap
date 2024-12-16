/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:22:44 by andcarva          #+#    #+#             */
/*   Updated: 2024/12/16 20:24:07 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack *stackA;
	t_stack *stackB;
	int	i;
	int	j;

	i = 1;
	if (ac <= 1)
		return (0);
	while (av[i])
	{
		j = 0;
		while (is_wspace(av[i][j]))
		{
			if (av[i][j + 1] == '\0')
				return (0);
			j++;
		}
		i++;
	}
	i = 1;
	stackA = make_stack(ac - 1, &av[i]);
	stackB = make_stack(0, NULL);
	if (!stackA)
		return (0);
	print_stack(stackA);
	stackclear(stackA);
	print_stack(stackA);
	// push_b(stackA, stackB);
	// push_b(stackA, stackB);
	// push_b(stackA, stackB);
	// push_b(stackA, stackB);
	// print_stack(stackB);
}



		// valor = ft_atoi(&av[i]);
		// if (*av[i] && !is_wspace(av[i]))
		// {
		// 	ft_printf("ERRO\n"); //function free/print erro
		// 	break;
		// }
		// ft_printf("valor : %d\n", valor);
		// if (*av[i] == '\0')
		// 	i++;

		// if (*av[i] == '\0')
	// 		i++;