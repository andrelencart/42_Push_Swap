/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:52:31 by andcarva          #+#    #+#             */
/*   Updated: 2024/12/20 20:17:33 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include <stdbool.h>
# include <limits.h>

# define HEX_LB "0123456789abcdef"
# define HEX_UPB "0123456789ABCDEF"

typedef struct s_node
{
	int				cont;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	int		size;
	t_node	*head;
	t_node	*tail;
}	t_stack;

// Push_Swap
int		ft_atoi(char *str);
int		ft_strcmp(char *s1, char *s2);
char	**ft_split(char *s, char c);
void	free_s(char **split);
t_node	*lstnew_node(int cont);
void	stackadd_back(t_stack *stack, t_node *new_node);
void	stackadd_front(t_stack *t_stack, t_node *new_node);
void	stackclear(t_stack *stack);
t_stack	make_stack(int ac, char **av);
void	print_stack(t_stack *stack, char id);
// int		lstsize(t_node *lst);
// void	delnode(t_node *node);
// void	stackdelnode(t_node *node, void (*del)(void*));
// void	add_node_stack(t_stack *stack, t_node *node);

// Checks
bool	check_dupes(t_stack *stack, int num);
bool	check_non_num(char **split_nbr);
bool	check_spaces(char *str);
bool	is_wspace(char c);
bool	is_number(char c);
bool	check_sorted(t_stack *stack);

// Rules
void	push(t_stack *stack_from, t_stack *stack_to, char id);
void	swap(t_stack *stack, char id);
void	rotate(t_stack *stack, char id);
void	rev_rotate(t_stack *stack, char id);

// Sort
void	sort_three(t_stack *stack);
void	master_sort(t_stack *stack);
int		ft_min(t_stack *stack);
int		ft_max(t_stack *stack);
// void	sort_stack_b(t_stack *stack_a, t_stack *stack_b);

// Printf
int		ft_printf(const char *str, ...);
int		ft_printf_rules(const char spec, va_list list);
int		ft_putchartf(int c);
int		ft_putstrtf(char *str);
int		ft_put_nbr_tf(int nbr);
int		ft_put_un_nbr(unsigned int n);
int		ft_put_nbr_base(unsigned int nbr, char *base);
int		ft_put_ptr(uintptr_t ptr);
size_t	ft_strlen(const char *str);
char	*ft_itoa(int n);
// int		ft_ulength(unsigned int n);
// char	*ft_unitoa(unsigned int n);
// int		ft_percentage(void);
// int		ft_put_nbr_ptr(uintptr_t nbr, char *base);

#endif //PUSH_SWAP_H