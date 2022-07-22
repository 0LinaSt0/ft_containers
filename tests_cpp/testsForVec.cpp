/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testsForVec.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 11:36:43 by msalena           #+#    #+#             */
/*   Updated: 2022/07/22 17:21:31 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tests_hpp/testsVec.hpp"



void	checkVecConstructors(){
		{/* <<<<<<<<<<<<<<< Tests for constructor_iterator >>>>>>>>>>>>>>>*/
			ft::vector<std::string>	vec(3, "Hola");

			std::cout << "example # 1 constructor_val" << std::endl;
			/*status*/printVecParams(vec, false);
							/* <<<<<<<<<<<<<<<>>>>>>>>>>>>>>> */

			/* <<<<<<<<<<<<<<< Tests for constructor_iterator >>>>>>>>>>>>>>>*/
			ft::vector<char>	vec1(0);
			vec1.push_back('a');
			vec1.push_back('b');
			vec1.push_back('v');
			vec1.push_back('g');

			ft::vector<char>	vec11(vec1.begin(),( vec1.end() - 1));

			std::cout << "example # 2 constructor_iterators" << std::endl;
			/*status*/printVecParams(vec11, false);
							/* <<<<<<<<<<<<<<<>>>>>>>>>>>>>>> */

			/* <<<<<<<<<<<<<<< Tests for constructor_iterator >>>>>>>>>>>>>>>*/
				ft::vector<int>	vec2(3, 5);
				ft::vector<int>	vec21(vec2);

				std::cout << "example # 3 constructor_copy" << std::endl;
				/*status*/printVecParams(vec21, false);
							/* <<<<<<<<<<<<<<<>>>>>>>>>>>>>>> */

		}
			std::cout << "\n\n~~~~~~~~~~~~~~ORIGINAL~~~~~~~~~~~~~~" << std::endl;
		{
			/* <<<<<<<<<<<<<<< Tests for constructor_iterator >>>>>>>>>>>>>>>*/
			std::vector<std::string>	vec(3, "Hola");

			std::cout << "example # 1 constructor_val" << std::endl;
			/*status*/printVecParams(vec, false);
							/* <<<<<<<<<<<<<<<>>>>>>>>>>>>>>> */

			/* <<<<<<<<<<<<<<< Tests for constructor_iterator >>>>>>>>>>>>>>>*/
			std::vector<char>	vec1(0);
			vec1.push_back('a');
			vec1.push_back('b');
			vec1.push_back('v');
			vec1.push_back('g');

			std::vector<char>	vec11(vec1.begin(), (vec1.end() - 1));

			std::cout << "example # 2 constructor_iterators" << std::endl;
			/*status*/printVecParams(vec11, false);
							/* <<<<<<<<<<<<<<<>>>>>>>>>>>>>>> */

			/* <<<<<<<<<<<<<<< Tests for constructor_iterator >>>>>>>>>>>>>>>*/
				std::vector<int>	vec2(3, 5);
				std::vector<int>	vec21(vec2);

				std::cout << "example # 3 constructor_copy" << std::endl;
				/*status*/printVecParams(vec21, false);
							/* <<<<<<<<<<<<<<<>>>>>>>>>>>>>>> */
		}
	}

void	checkerForVector(void){
	// checkConstructors();

	{
		std::cout << "\t~~~~~~~~~~~~~~MY_VECTOR~~~~~~~~~~~~~~" << std::endl;

		// ft::vector<int>	vector(3, 5);
		// ft::vector<std::string>	vec(5, "aboba");

		// ft::vector<char>	vec1(6, 'd');
		// ft::vector<int>	vec1(10, 2);

		// eraseCheck(vec1, false);

			std::vector<int> result, result_2;
			std::vector<int> v_int1, v_int2, v_int3;
			std::vector<std::string> v_str1, v_str2;
			ft::vector<int> V_int1, V_int2, V_int3;
			ft::vector<std::string> V_str1, V_str2;
			v_int1.push_back(1);
			v_int3.push_back(1);
			v_str1.push_back("aa");
			v_str2.push_back("ab");
			result.push_back(v_int1 > v_int2);
			v_int2.push_back(2);
			result.push_back(v_int1 > v_int2);
			result.push_back(v_int1 > v_int3);
			result.push_back(v_str1 > v_str2);
			V_int1.push_back(1);
			V_int3.push_back(1);
			V_str1.push_back("aa");
			V_str2.push_back("ab");
			// std::cout << (result == result_2) << std::endl;
			result_2.push_back(V_int1 > V_int2);
			V_int2.push_back(2);
			result_2.push_back(V_int1 > V_int2);
			result_2.push_back(V_int1 > V_int3);
			result_2.push_back(V_str1 > V_str2);
			// printVecParams(result, true);
			// printVecParams(result_2, true);
			std::cout << (result == result_2) << std::endl;
	}
	{
		std::cout << "\n\n\t~~~~~~~~~~~~~~ORIG_VEC~~~~~~~~~~~~~~" << std::endl;
		// std::vector<char>	foo(5, 'a');
		// std::vector<std::string>	foo(5, "aboba");

			// std::vector<int>	vec1(10, 2);

		// eraseCheck(vec1, true);
		/*~~~~Check_itertors~~~~*/
		// std::vector<int>	myvec(5, 5);
		// std::vector<int>	vector;
		// // std::reverse_iterator<std::vector<int>::iterator>	rev;
		// for(char i=0; i<10; i++){
		// 	vec.push_back(i);
		// }

		// std::vector<int>::iterator	myvecBeg(myvec.begin());
		// std::vector<int>::iterator	myvecEnd(myvec.end());


		// printVecParams(vec, true);

		// vec.insert(vec.begin(), myvecBeg, myvecEnd);
		// printVecParams(vec, true);

		// std::vector<char>	vec;
		// std::reverse_iterator<std::vector<char>::iterator>	rev;
		// for(char i='a'; i<'i'; i++){
		// 	vec.push_back(i);
		// }

		// /*status*/printVecParams(vec, true);
		// checkIterators(vec, rev);
		/*~~~~~~~~~~~~~~~~~~~~*/

		// std::vector<char>	foo1(6, 'd');
		// // std::vector<int>	foo1(3, 'd');

		// printVecParams(foo, true);

					std::vector<int> result, result_2;
			std::vector<int> v_int1, v_int2, v_int3;
			std::vector<std::string> v_str1, v_str2;
			std::vector<int> V_int1, V_int2, V_int3;
			std::vector<std::string> V_str1, V_str2;
			v_int1.push_back(1);
			v_int3.push_back(1);
			v_str1.push_back("aa");
			v_str2.push_back("ab");
			result.push_back(v_int1 > v_int2);
			v_int2.push_back(2);
			result.push_back(v_int1 > v_int2);
			result.push_back(v_int1 > v_int3);
			result.push_back(v_str1 > v_str2);
			V_int1.push_back(1);
			V_int3.push_back(1);
			V_str1.push_back("aa");
			V_str2.push_back("ab");
			result_2.push_back(V_int1 > V_int2);
			V_int2.push_back(2);
			result_2.push_back(V_int1 > V_int2);
			result_2.push_back(V_int1 > V_int3);
			result_2.push_back(V_str1 > V_str2);
			// printVecParams(result, true);
			// printVecParams(result_2, true);
			std::cout << (result == result_2) << std::endl;

	}
}


