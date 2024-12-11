# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/09 20:52:46 by andcarva          #+#    #+#              #
#    Updated: 2024/12/11 18:11:17 by andcarva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap
CC=cc
CFLAGS=-Wall -Wextra -Werror
OBJ_DIR=Obj
OBJ= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
SRC= push_swap.c push_swap_utils.c push_lst_functions.c push_rules.c \
		push_stack.c ft_ptf_decfunc.c ft_printf.c ft_ptf_hexfunc.c \
		

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	
fclean: clean
	@rm -rf $(NAME)
	
re: fclean all