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

void	checkerForStack(void);

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
		for (int _operator = 0; _operator < 6; _operator++){
			switch (_operator){
				case 0:
					std::cout << "-> Stack1 == Stack2: "
								<< std::boolalpha
								<< (stack1 == stack2)
								<< std::endl;
				break;
				case 1:
					std::cout << "-> Stack1 != Stack2: "
								<< std::boolalpha
								<< (stack1 != stack2)
								<< std::endl;
				break;
				case 2:
					std::cout << "-> Stack1 < Stack2: "
								<< std::boolalpha
								<< (stack1 < stack2)
								<< std::endl;
				break;
				case 3:
					std::cout << "-> Stack1 <= Stack2: "
								<< std::boolalpha
								<< (stack1 <= stack2)
								<< std::endl;
				break;
				case 4:
					std::cout << "-> Stack1 > Stack2: "
								<< std::boolalpha
								<< (stack1 > stack2)
								<< std::endl;
				break;
				case 5:
					std::cout << "-> Stack1 >= Stack2: "
								<< std::boolalpha
								<< (stack1 >= stack2)
								<< std::endl;
				break;
			}
		}
	}

#endif
