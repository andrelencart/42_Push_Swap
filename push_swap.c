/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:22:44 by andcarva          #+#    #+#             */
/*   Updated: 2024/12/13 19:57:37 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack *stack;
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
		stack = make_stack(ac - 1, &av[i]);
		if (!stack)
			return (0);
		print_stack(stack);
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