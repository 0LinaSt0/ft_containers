/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testsUtils.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:38:56 by marvin            #+#    #+#             */
/*   Updated: 2022/09/18 15:16:05 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_UTILS_HPP
#define TESTS_UTILS_HPP

#include "../ft_containers.hpp"


enum	valueType{
	STRING,
	CHAR,
	INT
} ;

namespace ft {
	static int	factor = 10000;

	struct iterator{
		static int iter;
	} ;

	struct	colors{
		static const std::string	magneta;
		static const std::string	cyan;
		static const std::string	green;
		static const std::string	red;
		static const std::string	yellow;
		static const std::string	white;
		static const std::string	end;
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
			return (_stop.tv_sec * 1000 + _stop.tv_usec)
					- (_start.tv_sec * 1000 + _start.tv_usec);
		}
	} ;

	void	print_results(const std::string& fieldName,
							long ft_time, long std_time);

	void	print_mismatch(const std::string& fieldName);

	template <class ft_cont, class std_cont>
		// Compare orig and my containers
		bool	compareContainers(ft_cont& my, std_cont& orig){
			if (my.size() != orig.size()) { return false; }
			if (my.empty() != orig.empty()) { return false; }
			if (my.empty() && orig.empty()) { return true; }

			typename ft_cont::iterator	myIter(my.begin());
			typename std_cont::iterator	origIter(orig.begin());

			while (myIter != my.end() || origIter != orig.end()){
				if (*myIter != *origIter) { return false; }
				myIter++;
				origIter++;
			}
			return true;
		}

	template <class ft_cont, class std_cont, class compareFunc>
		// Compare orig and my containers using func
		bool	compareContainers(ft_cont& my, std_cont& orig,
									compareFunc func){
			if (my.size() != orig.size()) { return false; }
			if (my.empty() != orig.empty()) { return false; }
			if (my.empty() && orig.empty()) { return true; }

			typename ft_cont::iterator	myIter(my.begin());
			typename std_cont::iterator	origIter(orig.begin());

			while (myIter != my.end() || origIter != orig.end()){
				if (!(func(myIter, origIter))) { return false; }
				myIter++;
				origIter++;
			}
			return true;
		}

	template <class ft_cont, class std_cont, class print_func>
		// Print result of compare to STDOUT
		void	result(const std::string& fieldName,
						ft_cont& my, std_cont& orig,
						long ft_time, long std_time,
						bool isItCompare,
						print_func func){
			if (isItCompare){
				print_results(fieldName, ft_time, std_time);
			} else {
				print_mismatch(fieldName);
				func(my, orig);
			}
		}

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

}

#endif
