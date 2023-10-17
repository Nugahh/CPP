# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fwong <fwong@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/28 17:30:35 by fwong             #+#    #+#              #
#    Updated: 2023/10/17 06:45:48 by fwong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	scalarconverter

CC		=	c++

CFLAGS	=	-Wall -Wextra -Werror -MMD -MP -I includes/ -g3 -std=c++98
 
SRCS	= 	
 
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