/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:22:44 by andcarva          #+#    #+#             */
/*   Updated: 2024/12/11 20:04:13 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack *stack;
	int	i;

	if (ac <= 1)
		return (0);
	i = 1;
	while (av[i])
	{
		stack = make_stack(ac, &av[i]);
		// if (*av[i] && !is_wspace(av[i]))
		// 	break;
		ft_printf("stack:%d", stack);
		i++;
	}
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