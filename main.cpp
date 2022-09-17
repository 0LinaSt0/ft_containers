/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 17:43:22 by msalena           #+#    #+#             */
/*   Updated: 2022/09/10 20:16:24 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/tests_hpp/testsVec.hpp"
#include "includes/tests_hpp/testsStack.hpp"
#include "includes/tests_hpp/testsMap.hpp"
#include "includes/tests_hpp/testsSet.hpp"

	void	print_separator(void){
		std::cout << ft::colors::red
						<< "\n    ~~~~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~~~~"
						<< ft::colors::end
						<< std::endl;
	}

	void	print_preview(const std::string& outString,
							valueType type){
		std::cout << ft::colors::magneta
				<< "\n\t ~~~~~~~~~~~~TESTS_FOR_"
				<< outString;
		if (type == STRING){
			std::cout << "(STRING)~~~~~~~~~~~~";
		} else if (type == CHAR) {
			std::cout << "(CHAR)~~~~~~~~~~~~";
		} else {
			std::cout << "(INT)~~~~~~~~~~~~";
		}
		std::cout << ft::colors::end
					<< "\n"
					<< std::endl;
	}

	int main (void){
		{
			valueType	type = STRING;
			print_preview("VECTOR", type);
			ft::vectorChecker(type);
			print_preview("STACK", type);
			ft::stackChecker(type);
			print_preview("MAP", type);
			ft::mapChecker(type);
			print_preview("SET", type);
			ft::setChecker(type);
		}
			print_separator();
		{
			valueType	type = CHAR;
			print_preview("VECTOR", type);
			ft::vectorChecker(type);
			print_preview("STACK", type);
			ft::stackChecker(type);
			print_preview("MAP", type);
			ft::mapChecker(type);
			print_preview("SET", type);
			ft::setChecker(type);
		}
			print_separator();
		{
			valueType	type = INT;
			print_preview("VECTOR", type);
			ft::vectorChecker(type);
			print_preview("STACK", type);
			ft::stackChecker(type);
			print_preview("MAP", type);
			ft::mapChecker(type);
			print_preview("SET", type);
			ft::setChecker(type);
		}
	}



