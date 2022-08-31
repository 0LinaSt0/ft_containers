/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testsUtils.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:38:56 by marvin            #+#    #+#             */
/*   Updated: 2022/08/31 19:32:09 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_UTILS_HPP
#define TESTS_UTILS_HPP

#include <sys/time.h>
#include "../containers.hpp"


namespace ft {
	static size_t	_factor_ = 10;
	
	enum	valueType{
		STRING = 0,
		CHAR = 1,
		INT = 2
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
								const std::string& color){
			std::cout << color
						<< fieldValue
						<< "\033[0m";
		}

	void	print_results(const std::string& fieldName,
							long ft_time, long std_time);

	void	print_mismatch(const std::string& fieldName);
}

#endif
