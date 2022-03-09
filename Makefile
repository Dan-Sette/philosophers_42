# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/08 16:29:39 by dalves-s          #+#    #+#              #
#    Updated: 2022/03/09 17:33:14 by dalves-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILES	= 	philo.c init.c ft_atoi.c utils.c start_meal.c actions.c
SRC_DIR		=	./src
OBJECT_DIR	=	./obj
INCLUDES	=	./includes

OBJECT		=	$(addprefix $(OBJECT_DIR)/,$(subst .c,.o,$(SRC_FILES)))
CC			=	clang
CFLAGS		=	-g3 -pthread -Wall -Wextra -Werror -fsanitize=thread
MAKE_DIR	=	mkdir -p
RM			=	rm -fr
NAME		=	philo

all:				$(NAME)

$(NAME):			$(OBJECT)
		$(CC) $(CFLAGS) -g -I $(INCLUDES) $(OBJECT) -o $(NAME)

$(OBJECT_DIR)/%.o:	$(SRC_DIR)/%.c
		$(MAKE_DIR) $(OBJECT_DIR)
		$(CC) $(CFLAGS) -I $(INCLUDES) -o $@ -c $<

clean:
		$(RM) $(OBJECT_DIR)

fclean:	clean
		$(RM) $(NAME)

re:	fclean	all

val:
		valgrind --leak-check=full --show-leak-kinds=all --tool=drd -s --track-origins=yes --log-file=valgrind-out.txt ./philo

.PHONY: all clean fclean re val