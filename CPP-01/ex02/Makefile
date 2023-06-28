# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fwong <fwong@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/13 20:39:07 by fwong             #+#    #+#              #
#    Updated: 2023/06/27 18:03:30 by fwong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	brain

CC		=	c++

CFLAGS	=	-Wall -Wextra -Werror -MMD -MP -std=c++98

SRCS	= 	main.cpp
 
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