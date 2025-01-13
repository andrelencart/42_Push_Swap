/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:21:57 by andcarva          #+#    #+#             */
/*   Updated: 2025/01/13 15:19:43 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_non_num(char **split_nbr)
{
	int	i;
	int	j;

	j = 0;
	while (split_nbr[j] != NULL)
	{
		i = 0;
		if (split_nbr[j][i] == '-' && \
			(split_nbr[j][i + 1] == ' ' || split_nbr[j][i + 1] == '\0'))
			return (false);
		if (split_nbr[j][i] == '-' || split_nbr[j][i] == '+')
			i++;
		while (is_number(split_nbr[j][i]) && split_nbr[j][i] != '\0')
			i++;
		if (split_nbr[j][i] != '\0')
			return (false);
		j++;
	}
	return (true);
}

bool	check_spaces(char *str)
{
	int	j;

	j = 0;
	while (str[j] && is_wspace(str[j]))
		j++;
	if (str[j] == '\0')
		return (false);
	return (true);
}

bool	check_dupes(t_stack *stack, int num)
{
	t_node	*temp;

	temp = stack->head;
	while (temp)
	{
		if (temp->cont == num)
			return (true);
		temp = temp->next;
	}
	return (false);
}

bool	check_sorted(t_stack *stack)
{
	int		cont;
	t_node	*temp;

	if (!stack)
		return (false);
	cont = stack->head->cont;
	temp = stack->head->next;
	while (temp)
	{
		if (cont < temp->cont)
			cont = temp->cont;
		else
			return (false);
		temp = temp->next;
	}
	return (true);
}
