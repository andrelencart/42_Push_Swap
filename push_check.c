/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:21:57 by andcarva          #+#    #+#             */
/*   Updated: 2024/12/16 17:10:58 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_func(char **split_nbr)
{
	int	i;
	int	j;

	j = 0;
	while (split_nbr[j] != NULL)
	{
		i = 0;
		if (split_nbr[j][i] == '-' && 
			(split_nbr[j][i + 1] == ' ' || split_nbr[j][i + 1] == '\0'))
			return (false);
		if (split_nbr[j][i] == '-' || split_nbr[j][i] == '+')
			i++;
		while (is_number(split_nbr[j][i]) && split_nbr[j][i] != '\0')
			i++;
		if(split_nbr[j][i] != '\0')
			return (false);
		j++;
	}
	return (true);
}
