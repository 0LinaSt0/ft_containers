# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msalena <msalena@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/09 16:24:48 by msalena           #+#    #+#              #
#    Updated: 2022/08/23 21:10:20 by msalena          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADS_DIR		=	includes

SRCS_DIR		=	tests_cpp

HEAD_CONT		=	$(addprefix $(HEADS_DIR)/, containers.hpp vector.hpp vectorIterator.hpp stack.hpp map.hpp)

HEAD_TESTS		=	$(addprefix $(HEADS_DIR)/tests_hpp/, testsVec.hpp testsStack.hpp testsMap.hpp)

TPP_FILES		=	$(addprefix $(HEADS_DIR)/tpp_format/, tree.tpp)

SRCS_MAIN		=	main.cpp

SRCS_TESTS		=	$(addprefix $(SRCS_DIR)/,testsForVec.cpp testsForStack.cpp testsForMap.cpp)

OBJS_MAIN		=	$(SRCS_MAIN:.cpp=.o)

OBJS_TESTS		=	$(SRCS_TESTS:.cpp=.o)

PROG_NAME		=	./ft_containers

C++				=	c++ -std=c++98 -Wall -Wextra -Werror -g

%.o:			%.cpp $(HEAD_CONT) $(HEAD_TESTS) $(SRCS_MAIN) $(SRCS_TESTS) $(TPP_FILES) Makefile
				$(C++) -c $< -o $@

all:			$(PROG_NAME)

${PROG_NAME}:	$(SRCS_MAIN) $(SRCS_TESTS) $(OBJS_MAIN) $(OBJS_TESTS) $(HEAD_CONT) $(HEAD_TESTS)
				$(C++) $(OBJS_MAIN) $(OBJS_TESTS) -o $(PROG_NAME)

start:			all
				$(PROG_NAME)

cate:
				$(PROG_NAME) | cat -e

leaks:			all
				leaks --atExit -- $(PROG_NAME)

clean:
				rm -r $(OBJS_MAIN) $(OBJS_TESTS)

fclean:			clean
				rm -r $(PROG_NAME)

re:				fclean all

.PHONY:			all clean fclean re
