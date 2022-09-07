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

#include "testsTmpClasses.hpp"
#include "../ft_stack.hpp"
#include "../ft_containers.hpp"

namespace ft{
	void	stackChecker(valueType type);

	//~~~~~~~~~~~~~~~~~~ HELPFUL_UTILS ~~~~~~~~~~~~~~~~~~

	template <class stack>
		// Prints all information about stacktor
		void	printStackParams(stack &stack_cont, bool isItOrigStacktor){
			std::cout << "\033[33m";
			(isItOrigStacktor) ? (std::cout << "STD_") : (std::cout << "FT_");
			std::cout << "STACK_status" << "\033[0m" << std::endl;
			std::cout << "	count elem: " << stack_cont.size() << "\n"
						<< "	emptyFlag: " << stack_cont.empty()
						<< std::endl << std::endl;
		}

	template <class ft_stack, class std_stack>
		void	printStacks(ft_stack &my, std_stack &orig){
			printStackParams(my, false);
			printStackParams(orig, true);
		}

	template <class ft_stack, class std_stack>
		bool	compareStacks(ft_stack &my_stack, std_stack &orig_stack){
			if (my_stack.empty() != orig_stack.empty()) { return false; }
			if (my_stack.size() != orig_stack.size()) { return false; }
			if (my_stack.top() != orig_stack.top()) { return false; }
			return true;
		}

	//~~~~~~~~~~~ CHECKS_FOR_MEMBER_FUNCTIONS ~~~~~~~~~~~

	template <class ft_stack, class std_stack, class tmp_vec>
		void	pushCheckStack(ft_stack &my_stack, std_stack &orig_stack,
									tmp_vec &vec){
			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			timer.start();
			my_stack.push(vec[0]);
			my_stack.push(vec[1]);
			my_stack.push(vec[2]);
			ft_time = timer.stop();

			timer.start();
			orig_stack.push(vec[0]);
			orig_stack.push(vec[1]);
			orig_stack.push(vec[2]);
			std_time = timer.stop();

			result("push           ", my_stack, orig_stack, ft_time, std_time,
					compareStacks(my_stack, orig_stack), printStacks<ft_stack, std_stack>);
		}

	template <class ft_stack, class std_stack>
		void	popCheckStack(ft_stack &my_stack, std_stack &orig_stack){
			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			timer.start();
			my_stack.pop();
			my_stack.pop();
			my_stack.pop();
			ft_time = timer.stop();

			timer.start();
			orig_stack.pop();
			orig_stack.pop();
			orig_stack.pop();
			std_time = timer.stop();

			result("pop            ", my_stack, orig_stack, ft_time, std_time,
					compareStacks(my_stack, orig_stack), printStacks<ft_stack, std_stack>);
		}

	template <class ft_stack, class std_stack>
		void	topCheckStack(ft_stack &my_stack, std_stack &orig_stack){
			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			timer.start();
			typename ft_stack::value_type myValue = my_stack.top();
			ft_time = timer.stop();

			timer.start();
			typename std_stack::value_type origValue = orig_stack.top();
			std_time = timer.stop();

			result("top            ", my_stack, orig_stack, ft_time, std_time,
					(myValue == origValue), printStacks<ft_stack, std_stack>);
		}

	template <class ft_stack, class std_stack>
		void	checkCompareStacks(ft_stack& my_stack, std_stack& orig_stack){
			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			{
				timer.start();
				bool	myComp = (my_stack == my_stack);
				ft_time = timer.stop();

				timer.start();
				bool	origComp = (orig_stack == orig_stack);
				std_time = timer.stop();

				result("stack==stack   ", my_stack, orig_stack, ft_time, std_time,
						(myComp == origComp), printStacks<ft_stack, std_stack>);
			}

			{
				timer.start();
				bool	myComp = (my_stack != my_stack);
				ft_time = timer.stop();

				timer.start();
				bool	origComp = (orig_stack != orig_stack);
				std_time = timer.stop();

				result("stack!=stack   ", my_stack, orig_stack, ft_time, std_time,
						(myComp == origComp), printStacks<ft_stack, std_stack>);
			}

			{
				timer.start();
				bool	myComp = (my_stack < my_stack);
				ft_time = timer.stop();

				timer.start();
				bool	origComp = (orig_stack < orig_stack);
				std_time = timer.stop();

				result("stack<stack    ", my_stack, orig_stack, ft_time, std_time,
						(myComp == origComp), printStacks<ft_stack, std_stack>);
			}

			{
				timer.start();
				bool	myComp = (my_stack > my_stack);
				ft_time = timer.stop();

				timer.start();
				bool	origComp = (orig_stack > orig_stack);
				std_time = timer.stop();

				result("stack>stack    ", my_stack, orig_stack, ft_time, std_time,
						(myComp == origComp), printStacks<ft_stack, std_stack>);
			}

			{
				timer.start();
				bool	myComp = (my_stack <= my_stack);
				ft_time = timer.stop();

				timer.start();
				bool	origComp = (orig_stack <= orig_stack);
				std_time = timer.stop();

				result("stack<=stack   ", my_stack, orig_stack, ft_time, std_time,
						(myComp == origComp), printStacks<ft_stack, std_stack>);
			}

			{
				timer.start();
				bool	myComp = (my_stack != my_stack);
				ft_time = timer.stop();

				timer.start();
				bool	origComp = (orig_stack != orig_stack);
				std_time = timer.stop();

				result("stack>=stack   ", my_stack, orig_stack, ft_time, std_time,
						(myComp == origComp), printStacks<ft_stack, std_stack>);
			}
	}

}

#endif
