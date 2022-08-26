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



void	checkVecConstructors(void){
		{/* <<<<<<<<<<<<<<< Tests for constructor_value >>>>>>>>>>>>>>>*/
			ft::vector<std::string>	vec(3, "Hola");

			std::cout << "example # 1 constructor_val" << std::endl;
			/*status*/printVecParams(vec, false);
							/* <<<<<<<<<<<<<<<>>>>>>>>>>>>>>> */

			/* <<<<<<<<<<<<<<< Tests for constructor_count >>>>>>>>>>>>>>>*/
			ft::vector<char>	vec1(0);
			vec1.push_back('a');
			vec1.push_back('b');
			vec1.push_back('v');
			vec1.push_back('g');

			ft::vector<char>	vec11(vec1.begin(),( vec1.end() - 1));

			std::cout << "example # 2 constructor_iterators" << std::endl;
			/*status*/printVecParams(vec11, false);
							/* <<<<<<<<<<<<<<<>>>>>>>>>>>>>>> */

			/* <<<<<<<<<<<<<<< Tests for constructor_copy >>>>>>>>>>>>>>>*/
				ft::vector<int>	vec2(3, 5);
				ft::vector<int>	vec21(vec2);

				std::cout << "example # 3 constructor_copy" << std::endl;
				/*status*/printVecParams(vec21, false);
							/* <<<<<<<<<<<<<<<>>>>>>>>>>>>>>> */

		}
			std::cout << "\n\n~~~~~~~~~~~~~~ORIGINAL~~~~~~~~~~~~~~" << std::endl;
		{
			/* <<<<<<<<<<<<<<< Tests for constructor_value >>>>>>>>>>>>>>>*/
			std::vector<std::string>	vec(3, "Hola");

			std::cout << "example # 1 constructor_val" << std::endl;
			/*status*/printVecParams(vec, false);
							/* <<<<<<<<<<<<<<<>>>>>>>>>>>>>>> */

			/* <<<<<<<<<<<<<<< Tests for constructor_count >>>>>>>>>>>>>>>*/
			std::vector<char>	vec1(0);
			vec1.push_back('a');
			vec1.push_back('b');
			vec1.push_back('v');
			vec1.push_back('g');

			std::vector<char>	vec11(vec1.begin(), (vec1.end() - 1));

			std::cout << "example # 2 constructor_iterators" << std::endl;
			/*status*/printVecParams(vec11, false);
							/* <<<<<<<<<<<<<<<>>>>>>>>>>>>>>> */

			/* <<<<<<<<<<<<<<< Tests for constructor_copy >>>>>>>>>>>>>>>*/
				std::vector<int>	vec2(3, 5);
				std::vector<int>	vec21(vec2);

				std::cout << "example # 3 constructor_copy" << std::endl;
				/*status*/printVecParams(vec21, false);
							/* <<<<<<<<<<<<<<<>>>>>>>>>>>>>>> */
		}
	}

int c = 10000;


void	checkerForVector(void){
	// checkConstructors();

	{
		std::cout << "\t~~~~~~~~~~~~~~MY_VECTOR~~~~~~~~~~~~~~" << std::endl;

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
			ft::vector<int> vector;
			std::vector<int> v;
			for (int i = 0; i < 9900 * c; ++i)
				vector.push_back(i);
			v.push_back(*(vector.erase(vector.begin() + 8*c, vector.end() - 1500*c)));
			v.push_back(*(vector.begin() + 82*c));
			v.push_back(vector.size());
			v.push_back(vector.capacity());
			printVecParams(v, false);
	}
	{
		std::cout << "\n\n\t~~~~~~~~~~~~~~ORIG_VECTOR~~~~~~~~~~~~~~" << std::endl;
			std::vector<int> vector;
			std::vector<int> v;
			for (int i = 0; i < 9900 * c; ++i)
				vector.push_back(i);
			v.push_back(*(vector.erase(vector.begin() + 8*c, vector.end() - 1500*c)));
			v.push_back(*(vector.begin() + 82*c));
			v.push_back(vector.size());
			v.push_back(vector.capacity());
			printVecParams(v, true);
			// printVecParams(vector, false);

	}
}


