/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testsUtils.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 10:45:53 by marvin            #+#    #+#             */
/*   Updated: 2022/09/02 18:52:36 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tests_hpp/testsUtils.hpp"

/*
		colors:
	black        30
	red          31
	green        32
	yellow       33
	blue         34
	magenta      35
	cyan         36
	white        37
*/

namespace ft{
	const std::string	colors::cyan = "\033[36m";
	const std::string	colors::green = "\033[32m";
	const std::string	colors::red = "\033[31m";
	const std::string	colors::yellow = "\033[33m";
	const std::string	colors::end = "\033[0m";

	void	print_results(const std::string& fieldName,
							long ft_time, long std_time){

		std::cout << colors::yellow << iter++ << ". " << colors::end;
		stdout_result(fieldName + " -->	", colors::cyan);

		stdout_result("ft_time: ", colors::green);
		if (ft_time != std_time){
			if (ft_time > std_time){
				stdout_result(ft_time, colors::red);
				stdout_result("	std_time: ", colors::green);
				stdout_result(std_time, colors::green);
			} else {
				stdout_result(ft_time, colors::green);
				stdout_result("	std_time: ", colors::green);
				stdout_result(std_time, colors::red);
			}
		} else {
			stdout_result(ft_time, colors::green);
			stdout_result("	std_time: ", colors::green);
			stdout_result(std_time, colors::green);
		}
		std::cout << std::endl;
	}


	void	print_mismatch(const std::string& fieldName){
		std::cout << colors::yellow << iter++ << ". " << colors::end;
		stdout_result(fieldName + " -->	", colors::cyan);
		stdout_result("error: std & ft not the same ", colors::red);
		std::cout << std::endl << std::endl;
	}
}

