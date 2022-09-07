/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testsForStack.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:18:34 by marvin            #+#    #+#             */
/*   Updated: 2022/07/18 16:18:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tests_hpp/testsStack.hpp"

namespace ft{

	template <class ft_stack, class std_stack, class tmp_vec>
		void	memberTestsStack(ft_stack &my_stack, std_stack &orig_stack,
								tmp_vec &vec){
			pushCheckStack(my_stack, orig_stack, vec);
			popCheckStack(my_stack, orig_stack);
			topCheckStack(my_stack, orig_stack);
		}

	template <class ft_stack, class std_stack, class tmp_vec>
		void	checkerForStack(ft_stack &my_stack, std_stack &orig_stack,
									tmp_vec &vec){
			stdout_result("Member_functions: ", colors::yellow);
			std::cout << std::endl;
			memberTestsStack(my_stack, orig_stack, vec);
			stdout_result("Compare_stacks: ", colors::yellow);
			std::cout << std::endl;
			checkCompareStacks(my_stack, orig_stack);
		}

	void	stackChecker(valueType type){
		// typedef ft::vector<std::string>		ft_string_cont;
		typedef ft::vector<char>			ft_char_cont;
		typedef ft::vector<int>				ft_int_cont;
		// typedef std::vector<std::string>	std_string_cont;
		typedef std::vector<char>			std_char_cont;
		typedef std::vector<int>			std_int_cont;

		tmpVectors	tmp_vec;
		iter = 1;

		if (type == STRING){
			// typedef ft::stack<std::string, ft_string_cont>		ft_stack;
			// typedef std::stack<std::string, std_string_cont>	std_stack;

			// tmpStackString<ft_string_cont, std_string_cont>	tmp_stacks(tmp_vec);

			// ft_stack		my_stack_str(tmp_stacks.getFtStringStack());
			// std_stack		orig_stack_str(tmp_stacks.getStdStringStack());
			// std::vector<std::string>	vec;
			// vec.push_back("camisa");
			// vec.push_back("camiseta");
			// vec.push_back("vestido");
			// vec.push_back("ropa");

			// checkerForStack(my_stack_str, orig_stack_str, vec);
		} else if (type == CHAR) {
			typedef ft::stack<char, ft_char_cont>	ft_stack_char;
			typedef std::stack<char, std_char_cont>	std_stack_char;

			tmpStackChar<ft_char_cont, std_char_cont>	tmp_stacks(tmp_vec);

			ft_stack_char	my_stack_char(tmp_stacks.getFtCharStack());
			std_stack_char	orig_stack_char(tmp_stacks.getStdCharStack());
			std::vector<char>	vec;
			vec.push_back('r');
			vec.push_back('w');
			vec.push_back('s');
			vec.push_back('f');

			checkerForStack(my_stack_char, orig_stack_char, vec);
		} else if (type == INT) {
			typedef ft::stack<int, ft_int_cont>		ft_stack_int;
			typedef std::stack<int, std_int_cont>	std_stack_int;

			tmpStackInt<ft_int_cont, std_int_cont>	tmp_stacks(tmp_vec);

			ft_stack_int	my_stack_int(tmp_stacks.getFtIntStack());
			std_stack_int	orig_stack_int(tmp_stacks.getStdIntStack());
			std::vector<int>	vec;
			vec.push_back(585);
			vec.push_back(1065);
			vec.push_back(123456);
			vec.push_back(123);

			checkerForStack(my_stack_int, orig_stack_int, vec);
		} else {
			std::cout << "error: please, give me STRING, CHAR or INT type"
							<< std::endl;
		}
	}
}
