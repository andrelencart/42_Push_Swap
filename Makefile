# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/09 20:52:46 by andcarva          #+#    #+#              #
#    Updated: 2024/12/27 17:30:23 by andcarva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap
CC=cc
CFLAGS=-Wall -Wextra -Werror -g
OBJ_DIR=Obj
OBJ= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
SRC= push_swap.c push_utils.c push_stack_utils.c push_rules.c \
		push_stack.c ft_ptf_decfunc.c ft_printf.c ft_ptf_hexfunc.c \
		push_split.c push_check.c push_sort.c push_chunks.c \
		push_rules_doubles.c
		

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