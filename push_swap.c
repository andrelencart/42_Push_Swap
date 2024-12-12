/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:22:44 by andcarva          #+#    #+#             */
/*   Updated: 2024/12/12 16:43:30 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack *stack;
	int	i;
	// int valor = 0;

	i = 1;
	if (ac <= 1)
		return (0);
	// ft_printf("entra main\n");
		// ft_printf("entra loop\n");
	stack = make_stack(ac - 1, &av[i]);
	if (!stack)
		return (0);
	print_stack(stack);
	// ft_printf("----------------------------------------------\n");
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