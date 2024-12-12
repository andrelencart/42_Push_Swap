/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:06:19 by andcarva          #+#    #+#             */
/*   Updated: 2024/12/12 19:16:36 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (*str != '\0' && is_wspace(str))
		str++;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	while (*str != '\0' && is_number(str))
	{
		result = result * 10 + (*str - '0');
		str++;
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
	if (*str >= '0' && *str <= '9')
		return (1);
	return (0);
}
