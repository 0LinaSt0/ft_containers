# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msalena <msalena@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/09 16:24:48 by msalena           #+#    #+#              #
#    Updated: 2022/07/13 18:32:31 by msalena          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADS_DIR		=	includes

HEADS			=	$(addprefix $(HEADS_DIR)/, containers.hpp testsVec.hpp vector.hpp vectorIterator.hpp)

SRCS			=	testsForVec.cpp main.cpp

OBJS			=	$(SRCS:.cpp=.o)

PROG_NAME		=	./ft_containers

C++				=	c++ -std=c++98 -Wall -Wextra -Werror

%.o:			%.cpp $(HEADS) $(SRCS) Makefile
				$(C++) -c $< -o $@

all:			$(PROG_NAME)

${PROG_NAME}:	$(SRCS) $(OBJS)
				$(C++) $(OBJS) -o $(PROG_NAME)

start:			all
				$(PROG_NAME)

cate:
				$(PROG_NAME) | cat -e

leaks:
				leaks --atExit -- $(PROG_NAME)

clean:
				rm -r $(OBJS)

fclean:			clean
				rm -r $(PROG_NAME)

re:				fclean all

.PHONY:			all clean fclean re
