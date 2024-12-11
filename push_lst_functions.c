/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_lst_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:03:15 by andcarva          #+#    #+#             */
/*   Updated: 2024/12/11 19:15:07 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*lstnew_node(int cont)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (free(new_node), NULL);
	new_node->cont = cont;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	lstadd_back(t_node **lst, t_node *new_node)
{
	t_node	*temp;

	if (!*lst)
	{
		*lst = new_node;
		new_node->next = NULL;
		new_node->prev = NULL;
		return ;
	}
	temp = *lst;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new_node;
	new_node->prev = temp;
	new_node->next = NULL;
}

int	lstsize(t_node *lst)
{
	int	i;

	i = 0;
	while (lst && lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
