/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:52:31 by andcarva          #+#    #+#             */
/*   Updated: 2024/12/10 18:29:12 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdio.h>
# include <stdint.h>

typedef struct s_node
{
	int				cont;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack //rotate head -> tail | tail -> head
{
	int		size;
	t_node	*head;
	t_node	*tail;
}	t_stack;

//Push_Swap
int	ft_atoi(char **str);
int is_Wspace(char *str);
int is_number(char *str);

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