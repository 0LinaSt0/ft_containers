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
		std::string	input;
		{
			/* <<<<<<<<<<<<<<< Tests for fill_constructor >>>>>>>>>>>>>>>*/
			timer.start();
			ft::vector<std::string>		my_vec(3, "Hola");
			ft_time = timer.stop();

			timer.start();
			std::vector<std::string>	orig_vec(3, "Hola");
			std_time = timer.stop();

			result("constructor(fill)", my_vec, orig_vec, ft_time, std_time);
		}

		// {
		// 	/* <<<<<<<<<<<<<<< Tests for range_constructor >>>>>>>>>>>>>>>*/
		// 	ft::vector<char>	my_vec(12, 'a');
		// 	timer.start();
		// 	ft::vector<char>	my_vec1(my_vec.start(),(my_vec.stop() - 1));
		// 	ft_time = timer.stop();

		// 	std::vector<char>	orig_vec(12, 'a');
		// 	timer.start();
		// 	std::vector<char>	orig_vec1(orig_vec.start(),(orig_vec.stop() - 1));
		// 	std_time = timer.stop();

		// 	result("constructor(range)", my_vec1, orig_vec1, ft_time, std_time);
		// }

		// {
		// 	/* <<<<<<<<<<<<<<< Tests for copy_constructor >>>>>>>>>>>>>>>*/
		// 	ft::vector<int>	my_vec(3, 5);
		// 	timer.start();
		// 	ft::vector<int>	my_vec1(my_vec);
		// 	ft_time = timer.stop();

		// 	std::vector<int>	orig_vec(3, 5);
		// 	timer.start();
		// 	std::vector<int>	orig_vec1(orig_vec);
		// 	std_time = timer.stop();

		// 	result("constructor(copy)", my_vec1, orig_vec1, ft_time, std_time);
		// }
	}


	void	checkerForVector(void){
		// (void)type;
		checkVecConstructors();

		{
			// std::cout << "\t~~~~~~~~~~~~~~MY_VECTOR~~~~~~~~~~~~~~" << std::endl;

			// template <typename T>
			// 	std::vector<int> erase_test_2(std::vector<T> vector) {
			// 	std::vector<int> v;
			// 	for (int i = 0; i < 9900 * _ratio; ++i)
			// 		vector.push_back(i);
			// 	g_start1 = timer();
			// 	v.push_back(*(vector.erase(vector.begin() + 8 * _ratio, vector.end() - 1500 * _ratio)));
			// 	g_end1 = timer();
			// 	v.push_back(*(vector.begin() + 82 * _ratio));
			// 	v.push_back(vector.size());
			// 	v.push_back(vector.capacity());
			// 	return v;
			// }

			// template <typename T>
				// std::vector<int> erase_test_2(_vector<T> vector) {
				// ft::vector<int> vector;
				// std::vector<int> v;
				// for (int i = 0; i < 9900 * c; ++i)
				// 	vector.push_back(i);
				// v.push_back(*(vector.erase(vector.begin() + 8*c, vector.end() - 1500*c)));
				// v.push_back(*(vector.begin() + 82*c));
				// v.push_back(vector.size());
				// v.push_back(vector.capacity());
				// printVecParams(v, false);
		}
		{
			// std::cout << "\n\n\t~~~~~~~~~~~~~~ORIG_VECTOR~~~~~~~~~~~~~~" << std::endl;
			// 	std::vector<int> vector;
			// 	std::vector<int> v;
			// 	for (int i = 0; i < 9900 * c; ++i)
			// 		vector.push_back(i);
			// 	v.push_back(*(vector.erase(vector.begin() + 8*c, vector.end() - 1500*c)));
			// 	v.push_back(*(vector.begin() + 82*c));
			// 	v.push_back(vector.size());
			// 	v.push_back(vector.capacity());
			// 	printVecParams(v, true);
				// printVecParams(vector, false);

		}
	}

}


