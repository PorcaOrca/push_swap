# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/12 12:48:48 by lspazzin          #+#    #+#              #
#    Updated: 2021/05/12 14:31:23 by lspazzin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	srcs/main.c

NAME	=	push_swap

CFLAGS	=	-Wall -Werror -Wextra

OBJCS	=	$(SRCS:.c=.o)

CC		=	gcc

%.o		:	%.c
			@echo "\033[0;33mcreating objects..."
			@$(CC) $(CFLAGS) -c -o ./$@ $<

all		:	$(NAME)

$(NAME)	:	$(OBJCS)
			@echo "\033[0;33mcompiling libft..."
			@make bonus -s -C ./libft
			@echo "\033[0;33mcompiling push_swap...\033[0m"
			@gcc $(CFLAGS) $(OBJCS) -Llibft -lft -o $(NAME)

clean	:
			@make fclean -C ./libft
			@rm -f $(OBJCS)
			@echo "\033[0;33mclean done!!"

fclean	:	clean
			@rm -f $(NAME)
			@echo "\033[0;33mfclean done!!"

re		:	fclean all

.PHONY	:	all re clean fclean
