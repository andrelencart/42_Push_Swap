/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:06:19 by andcarva          #+#    #+#             */
/*   Updated: 2024/12/19 20:57:43 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (*str != '\0' && is_wspace(*str))
		str++;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	while (*str != '\0' && is_number(*str))
	{
		result = result * 10 + (*str - '0');
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
