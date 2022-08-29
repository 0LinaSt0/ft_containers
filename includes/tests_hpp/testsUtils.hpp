/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testUtils.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:38:56 by marvin            #+#    #+#             */
/*   Updated: 2022/08/29 15:38:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_UTILS_HPP
#define TESTS_UTILS_HPP

#include <sys/time.h>
#include "../containers.hpp"

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

namespace ft {
	enum	value_type{
		STRING,
		CHAR,
		INT
	} ;

	class	time{
	private:
		timeval	_start;
		timeval	_stop;
	public:
		time(void) { }
		~time(void) { }

		void	start(void) { gettimeofday(&_start, NULL); }
		long	stop(void) {
			gettimeofday(&_stop, NULL);
			return (_stop.tv_sec * 1e+6 + _stop.tv_usec)
					- (_start.tv_sec * 1e+6 + _start.tv_usec);
		}
	} ;

	template <class field>
		void	stdout_result(const field& fieldValue,
								const typename std::string& color){
			std::cout << color
						<< fieldValue
						<< "\033[0m";
		}

	void	print_results(const typename std::string& fieldName,
							long ft_time, long std_time){
		typename std::string	cyan = "\033[36m";
		typename std::string	green = "\033[32m";
		typename std::string	red = "\033[31m";

		stdout_result(fieldName + " -->", cyan);

		stdout_result("	ft_time: ", green);
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


	void	print_mismatch(const typename std::string& fieldName){
		typename std::string	cyan = "\033[36m";

		stdout_result(fieldName + " -->", cyan);
		std::cout << "different work: " << std::endl;
	}
}
#endif
