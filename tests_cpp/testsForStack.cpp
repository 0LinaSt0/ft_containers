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
#include "../includes/stack.hpp"

void	checkerForStack(void){
	{
		std::cout << "\t~~~~~~~~~~~~~~MY_STACK~~~~~~~~~~~~~~" << std::endl;

		ft::vector<int>	vec1;
		for(char i = 0; i < 15; i++){
			vec1.push_back(i);
		}
		ft::vector<int>	vec2(vec1);
		ft::stack< int, ft::vector<int> >	stack1(vec1), stack2(vec2);

		memberFunctionsCheck(stack1, vec1);

		std::cout << "-> Let's compare this stack(Stack1) "
					<< "with other stack(Stack2): "
					<< "Stack2 is copy to Stack1 before changing" << std::endl << std::endl;

		operatorsCheck(stack1, stack2);
	}
	{
		std::cout << "\n\n\t~~~~~~~~~~~~~~ORIG_STACK~~~~~~~~~~~~~~" << std::endl;

		std::vector<int>	vec1;
		for(char i = 0; i < 15; i++){
			vec1.push_back(i);
		}
		std::vector<int>	vec2(vec1);
		std::stack< int, std::vector<int> >	stack1(vec1), stack2(vec2);

		memberFunctionsCheck(stack1, vec1);

		std::cout << "-> Let's compare this stack(Stack1) "
					<< "with other stack(Stack2): "
					<< "Stack2 is copy to Stack1 before changing" << std::endl << std::endl;

		operatorsCheck(stack1, stack2);
	}
}
