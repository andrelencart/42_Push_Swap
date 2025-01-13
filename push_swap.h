/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:52:31 by andcarva          #+#    #+#             */
/*   Updated: 2025/01/13 15:15:18 by andcarva         ###   ########.fr       */
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
	int				index;
	int				moves;
	struct s_node	*target;
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
long	ft_atol(char *str);
int		ft_strcmp(char *s1, char *s2);
char	**ft_split(char *s, char c);
void	free_s(char **split);
t_node	*lstnew_node(int cont);
void	stackadd_back(t_stack *stack, t_node *new_node);
void	stackadd_front(t_stack *t_stack, t_node *new_node);
void	stackclear(t_stack *stack);
t_stack	make_stack(int ac, char **av);
void	print_stack(t_stack *stack, char id);
void	assign_index(t_stack *stack);

// Checks
bool	check_dupes(t_stack *stack, int num);
bool	check_non_num(char **split_nbr);
bool	check_spaces(char *str);
bool	is_wspace(char c);
bool	is_number(char c);
bool	check_sorted(t_stack *stack);

// Rules
void	push(t_stack *stack_from, t_stack *stack_to, char id);
void	swap(t_stack *stack, char id, int flag);
void	double_swap(t_stack *stack_a, t_stack *stack_b);
void	rotate(t_stack *stack, char id, int flag);
void	double_rotate(t_stack *stack_a, t_stack *stack_b);
void	rev_rotate(t_stack *stack, char id, int flag);
void	double_rev_rot(t_stack *stack_a, t_stack *stack_b);

// Sort
void	sort_three_a(t_stack *stack);
void	master_sort(t_stack *stack_a, t_stack *stack_b);
t_node	*ft_min(t_stack *stack);
t_node	*ft_max(t_stack *stack);
void	target_a(t_stack *stack_a, t_stack *stack_b);
void	target_b(t_stack *stack_a, t_stack *stack_b);
void	calc_moves(t_stack *stack_a, t_stack *stack_b);
void	master_calc(t_stack *stack_a, t_stack *stack_b);
t_node	*find_cheap(t_stack *stack);
void	execute_move_to_b(t_stack *stack_a, t_stack *stack_b);
void	execute_move_to_a(t_stack *stack_a, t_stack *stack_b);
bool	excute_double(t_stack *stack_a, t_stack *stack_b, t_node *min_move);
void	last_rotate(t_stack *stack_a);

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

#endif //PUSH_SWAP_H