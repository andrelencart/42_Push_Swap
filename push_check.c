/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:21:57 by andcarva          #+#    #+#             */
/*   Updated: 2024/12/13 16:49:09 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_func(char **split_nbr)
{
	int	i;
	int	j;

	j = 0;
	// ft_printf("a");
	while (split_nbr[j] != NULL)
	{
		i = 0;
		// ft_printf("a");
		if (split_nbr[j][i] == '-' || split_nbr[j][i] == '+')
			i++;
		// ft_printf("a");
		while (is_number(split_nbr[j][i]) && split_nbr[j][i] != '\0')
			i++;
		if(split_nbr[j][i] != '\0') 
			return (false);
		j++;
	}
	return (true);
}
