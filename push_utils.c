/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:06:19 by andcarva          #+#    #+#             */
/*   Updated: 2024/12/27 16:40:35 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *str)
{
	long	sign;
	long	result;
	long	max;
	
	sign = 1;
	result = 0;
	max = (long)INT_MAX + 1;
	while (*str != '\0' && is_wspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str != '\0' && is_number(*str))
	{
		result = result * 10 + (*str - '0');
		if (result > max)
			break ;
		str++;
	}
	return (result * sign);
}

bool	is_wspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (true);
	return (false);
}

bool	is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s2 && *s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
