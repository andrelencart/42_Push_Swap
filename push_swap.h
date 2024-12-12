/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:52:31 by andcarva          #+#    #+#             */
/*   Updated: 2024/12/12 18:54:52 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>

typedef struct s_node
{
	int				cont;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

//rotate head -> tail | tail -> head
typedef struct s_stack
{
	int		size;
	t_node	*head;
	t_node	*tail;
}	t_stack;

//Push_Swap
int		ft_atoi(char *str);
int		is_wspace(char *str);
int		is_number(char *str);
char	**ft_split(char *s, char c);
void	free_split(char **split);
t_node	*lstnew_node(int cont);
void	lstadd_back(t_node **lst, t_node *new_node);
int		lstsize(t_node *lst);
void	add_node_stack(t_stack *stack, t_node *node);
t_stack	*make_stack(int ac, char **av);
void	print_stack(t_stack *stack);

//Printf
# define HEX_LB "0123456789abcdef"
# define HEX_UPB "0123456789ABCDEF"

int		ft_printf(const char *str, ...);
int		ft_printf_rules(const char spec, va_list list);
int		ft_putchartf(int c);
int		ft_putstrtf(char *str);
int		ft_put_nbr_tf(int nbr);
// int		ft_ulength(unsigned int n);
// char	*ft_unitoa(unsigned int n);
int		ft_put_un_nbr(unsigned int n);
// int		ft_percentage(void);
int		ft_put_nbr_base(unsigned int nbr, char *base);
// int		ft_put_nbr_ptr(uintptr_t nbr, char *base);
int		ft_put_ptr(uintptr_t ptr);
size_t	ft_strlen(const char *str);
char	*ft_itoa(int n);

#endif //PUSH_SWAP_H