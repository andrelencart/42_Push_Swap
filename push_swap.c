/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:22:44 by andcarva          #+#    #+#             */
/*   Updated: 2024/12/10 19:39:45 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int	valor;
	int	i;
	
	valor = 0;
	if (ac <= 1)
		return (0);
	i = 1;
	while (av[i])
	{
		valor = ft_atoi(&av[i]);
		if (*av[i] && !is_Wspace(av[i]))
		{
			ft_printf("ERRO\n"); //function free/print erro
			break;
		}
		ft_printf("valor : %d\n", valor);
		if (*av[i] == '\0')
			i++;
	}
}
