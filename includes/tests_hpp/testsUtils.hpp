/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testsUtils.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:38:56 by marvin            #+#    #+#             */
/*   Updated: 2022/09/03 13:05:51 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_UTILS_HPP
#define TESTS_UTILS_HPP

#include <sys/time.h>
#include "../containers.hpp"


namespace ft {
	/*TESTING: IT'S BROKING IN HIGHEST FACTOR*/
	static size_t	factor = 100;
	/*TESTING: IT'S BROKING IN HIGHEST FACTOR*/
	static int	iter = 1;

	enum	valueType{
		STRING = 0,
		CHAR = 1,
		INT = 2
	} ;

	struct	colors{
		static const std::string	cyan;
		static const std::string	green;
		static const std::string	red;
		static const  std::string	yellow;
		static const  std::string	end;
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
			return (_stop.tv_sec * 1000000 + _stop.tv_usec)
					- (_start.tv_sec * 1000000 + _start.tv_usec);
		}
	} ;

	template <class field>
		void	stdout_result(const field& fieldValue,
								const std::string& color){
			std::cout << color
						<< fieldValue
						<< colors::end;
		}

	template <class T>
		// Compare two types which come as arguments
		bool	compareComings(T first, T second){
			if (first == second) { return true; }
			return false;
		}

	void	print_results(const std::string& fieldName,
							long ft_time, long std_time);

	void	print_mismatch(const std::string& fieldName);
}

#endif
