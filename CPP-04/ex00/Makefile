# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fwong <fwong@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/28 17:30:35 by fwong             #+#    #+#              #
#    Updated: 2023/07/28 19:10:02 by fwong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	polymorphism

CC		=	c++

CFLAGS	=	-Wall -Wextra -Werror -MMD -MP -I includes/ -g3 -std=c++98

SRCS	= 	animal.cpp dog.cpp cat.cpp wrongAnimal.cpp wrongCat.cpp main.cpp
 
OBJS	:=	${addprefix ./objs/,${SRCS:%.cpp=%.o}}

DEP		=	$(addprefix ./objs/,$(OBJS:%.o=%.d))

all: ${NAME}

-include $(DEP)

./objs/%.o: src/%.cpp
	@@mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ -c $<

${NAME}: ${OBJS}
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -rf objs/
	rm -f ${OBJS}

fclean: 
	rm -rf objs/
	rm -f ${NAME}
	rm -f ${OBJS}

re:	fclean all

.PHONY: all clean fclean re