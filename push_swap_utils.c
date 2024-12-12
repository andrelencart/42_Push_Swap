/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:06:19 by andcarva          #+#    #+#             */
/*   Updated: 2024/12/12 16:07:43 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str)
{
	int	sign;
	int	result;
	static int	i;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] != '\0' && is_wspace(str))
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	if (!(str[i] != '\0' && is_number(str)))
		str[i] = 'e';
	while (str[i] != '\0' && is_number(str))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	is_wspace(char *str)
{
	if (*str == ' ' || (*str >= 9 && *str <= 13))
		return (1);
	return (0);
}

int	is_number(char *str)
{
	if ((*str >= '0' && *str <= '9'))
		return (1);
	return (0);
}
