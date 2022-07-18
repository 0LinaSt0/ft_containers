/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testsStack.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:21:19 by marvin            #+#    #+#             */
/*   Updated: 2022/07/18 16:21:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_STACK_HPP
#define TESTS_STACK_HPP

#include "testsVec.hpp"
#include "../stack.hpp"

template <class stackType, class Container>
	// Prints all information about stack
	void	printStackParams (stackType &stack, Container& base_container){
		std::cout << "STACK_status" << std::endl;
		std::cout << "	vecAddress: " << &stack << "\n"
				<< "	count elem: " << stack.size() << "\n"
				<< "	top elem: "
					<< stack.top() << "(container top elem: "
					<< base_container.back() << ")" << "\n"
				<< "	emptyFlag: " << stack.empty() << "(container emptyFlag: "
					<< base_container.empty() << ")" << "\n"
				<< std::endl << std::endl;
	}

template <class stackType, class Container>
	void	memberFunctionsCheck(stackType &stack, Container& base_container){
		/*status*/printStackParams(stack, base_container);
		std::cout << "-> Remove last elems " << std::endl;
		stack.pop();
		std::cout << "-> Remove last elems " << std::endl;
		stack.pop();

		std::cout << "-> Add new elem '123' at the end " << std::endl;
		stack.push(123);

		/*status*/printStackParams(stack, base_container);
	}

template <class stackType>
	void	operatorsCheck(stackType &stack1, stackType &stack2){
		for (int operator = 0; operator < 6; operator++){
			switch (relation){
				case 0:
					printf("-> Stack1 == Stack2: %s\n", stack1 == stack2);
				break;
				case 1:
					printf("-> Stack1 != Stack2: %s\n", stack1 != stack2);
				break;
				case 2:
					printf("-> Stack1 < Stack2: %s\n", stack1 < stack2);
				break;
				case 3:
					printf("-> Stack1 <= Stack2: %s\n", stack1 <= stack2);
				break;
				case 4:
					printf("-> Stack1 > Stack2: %s\n", stack1 > stack2);
				break;
				case 5:
					printf("-> Stack1 >= Stack2: %s\n", stack1 >= stack2);
				break;
			}
		}
	}

#endif
