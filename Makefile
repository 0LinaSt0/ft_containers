# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msalena <msalena@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/09 16:24:48 by msalena           #+#    #+#              #
#    Updated: 2022/09/18 13:12:33 by msalena          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC_HEAD_DIR		=	includes

ITER_HEAD_DIR		=	$(addprefix $(INC_HEAD_DIR)/,iterators)

TEST_HEAD_DIR		=	$(addprefix $(INC_HEAD_DIR)/,tests_hpp)

TESTS_DIR			=	tests_cpp

TPP_DIR				=	useful_tpp

MAIN_HEADS			=	$(addprefix $(INC_HEAD_DIR)/, ft_containers.hpp ft_map.hpp ft_rb_tree.hpp \
													ft_set.hpp ft_stack.hpp ft_vector.hpp)

ITERS_HEADS			=	$(addprefix $(ITER_HEAD_DIR)/, rb_treeIterators.hpp vectorIterator.hpp)

TESTS_HEADS			=	$(addprefix $(TEST_HEAD_DIR)/, testsMap.hpp testsSet.hpp testsStack.hpp \
														testsTmpClasses.hpp testsUtils.hpp testsVec.hpp)

TESTS_FILES			=	$(addprefix $(TESTS_DIR)/, testsMap.cpp testsSet.cpp testsStack.cpp \
													testsUtils.cpp testsVec.cpp)

TPP_FILES			=	$(addprefix $(TPP_DIR)/, ft_rb_tree_erase.tpp ft_rb_tree_helpful.tpp \
													ft_rb_tree_insert.tpp ft_vector.tpp)

SRCS_MAIN			=	main.cpp

OBJS_MAIN			=	$(SRCS_MAIN:.cpp=.o)

OBJS_TESTS			=	$(TESTS_FILES:.cpp=.o)

PROG_NAME			=	./ft_containers

C++					=	c++ -std=c++98 -Wall -Wextra -Werror -g

%.o:				%.cpp $(MAIN_HEADS) $(ITERS_HEADS) $(TESTS_HEADS) $(TESTS_FILES) $(TPP_FILES) $(SRCS_MAIN) Makefile
					$(C++) -c $< -o $@

all:				$(PROG_NAME)

${PROG_NAME}:		$(OBJS_MAIN) $(OBJS_TESTS) Makefile
					$(C++) $(OBJS_MAIN) $(OBJS_TESTS) -o $(PROG_NAME)

start:				all
					$(PROG_NAME)

cate:
					$(PROG_NAME) | cat -e

leaks:				all
					leaks --atExit -- $(PROG_NAME)

clean:
					rm -r $(OBJS_MAIN) $(OBJS_TESTS)

fclean:				clean
					rm -r $(PROG_NAME)

re:					fclean all

.PHONY:				all clean fclean re
