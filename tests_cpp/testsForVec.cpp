/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testsForVec.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 11:36:43 by msalena           #+#    #+#             */
/*   Updated: 2022/08/26 17:57:17 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tests_hpp/testsVec.hpp"

namespace ft{
	void	checkVecConstructors(void){
		ft::time	timer;
		long	ft_time = 0, std_time = 0;
		// {
		// 	/* <<<<<<<<<<<<<<< Tests for fill_constructor >>>>>>>>>>>>>>>*/
		// 	timer.start();
		// 	vector<std::string>		my_vec(3, "Hola");
		// 	exit (0);
		// 	ft_time = timer.stop();

		// 	timer.start();
		// 	std::vector<std::string>	orig_vec(3, "Hola");
		// 	std_time = timer.stop();

		// 	result("constructor(fill)", my_vec, orig_vec, ft_time, std_time);
		// }

		{
			/* <<<<<<<<<<<<<<< Tests for range_constructor >>>>>>>>>>>>>>>*/
			ft::vector<char>	my_vec(12, 'a');
			timer.start();
			ft::vector<char>	my_vec1(my_vec.begin(),(my_vec.end() - 1));
			ft_time = timer.stop();

			std::vector<char>	orig_vec(12, 'a');
			timer.start();
			std::vector<char>	orig_vec1(orig_vec.begin(),(orig_vec.end() - 1));
			std_time = timer.stop();

			result("constructor(range)", my_vec1, orig_vec1, ft_time, std_time);
		}

		{
			/* <<<<<<<<<<<<<<< Tests for copy_constructor >>>>>>>>>>>>>>>*/
			ft::vector<int>	my_vec(3, 5);
			timer.start();
			ft::vector<int>	my_vec1(my_vec);
			ft_time = timer.stop();

			std::vector<int>	orig_vec(3, 5);
			timer.start();
			std::vector<int>	orig_vec1(orig_vec);
			std_time = timer.stop();

			result("constructor(copy)", my_vec1, orig_vec1, ft_time, std_time);
		}
	}

	void	checkerForVector(valueType type){
		// (void)type;
		checkVecConstructors();
		{
			if (type == STRING){
				ft::vector<std::string>		my_vec_str(10);
				std::vector<std::string>	orig_vec_str(10);

				for (size_t i = 0; i < 10; i++){
					my_vec_str[i] = "siempre";
					orig_vec_str[i] = "siempre";
				}

				assignCheck(my_vec_str, orig_vec_str, type);
				insertCheck(my_vec_str, orig_vec_str, type);
			} else if (type == CHAR) {
				ft::vector<char>	my_vec_char(10);
				std::vector<char>	orig_vec_char(10);

				for (size_t i = 0; i < 10; i++){
					my_vec_char[i] = 'g';
					orig_vec_char[i] = 'g';
				}

				assignCheck(my_vec_char, orig_vec_char, type);
				insertCheck(my_vec_str, orig_vec_str, type);
			} else if ((type == INT)) {
				ft::vector<int>		my_vec_int(10);
				std::vector<int>	orig_vec_int(10);

				for (size_t i = 0; i < 10; i++){
					my_vec_int[i] = i;
					orig_vec_int[i] = i;
				}

				assignCheck(my_vec_int, orig_vec_int, type);
				insertCheck(my_vec_str, orig_vec_str, type);
			} else {
				std::cout << "error: please, give me STRING, CHAR or INT type"
							<< std::endl;
			}
		}
	}
}


