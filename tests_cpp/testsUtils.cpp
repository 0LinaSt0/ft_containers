/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testsUtils.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 10:45:53 by marvin            #+#    #+#             */
/*   Updated: 2022/08/31 19:12:46 by msalena          ###   ########.fr       */
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
	void	print_results(const std::string& fieldName,
							long ft_time, long std_time){
		std::string	cyan = "\033[36m";
		std::string	green = "\033[32m";
		std::string	red = "\033[31m";

		stdout_result(fieldName + " -->	", cyan);

		stdout_result("ft_time: ", green);
		if (ft_time && std_time){
			if (ft_time > std_time){
				stdout_result(ft_time, red);
				stdout_result("	std_time: ", green);
				stdout_result(std_time, green);
			} else {
				stdout_result(ft_time, green);
				stdout_result("	std_time: ", green);
				stdout_result(std_time, red);
			}
		} else {
			stdout_result(ft_time, green);
			stdout_result("	std_time: ", green);
			stdout_result(std_time, green);
		}
		std::cout << std::endl;
	}


	void	print_mismatch(const std::string& fieldName){
		std::string	cyan = "\033[36m";
		std::string	red = "\033[31m";

		stdout_result(fieldName + " -->	", cyan);
		stdout_result("error: std & ft not the same ", red);
		std::cout << std::endl << std::endl;
	}
}

