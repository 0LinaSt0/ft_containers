/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 17:43:22 by msalena           #+#    #+#             */
/*   Updated: 2022/06/26 16:30:36 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/vector.hpp"
#include "includes/vectorIterator.hpp"
#include <vector>
#include <iostream>
#include <string>
#include <memory>

template <class T>
	// Prints value of vector
	void	printVecContent(T &vec, bool isItOrigVector){
		std::cout << "	vector content: ";
		if (isItOrigVector){
			for (typename T::iterator orig = vec.begin();
			orig != vec.end(); orig++){
				std::cout << *orig << "  ";
			}
		} else {
			for (typename T::iterator my(vec.begin()); 
			my != vec.end(); my++){
				std::cout << *my << "  ";
			}
		}
		(void) isItOrigVector;
		std::cout << std::endl;
	}
template <class T>
	// Prints all information about vector
	void	printVecParams (T &vec, bool isItOrigVector){
		std::cout << "STATUS" << std::endl;
		printVecContent(vec, isItOrigVector);
		std::cout << "	vecAddress: " << &vec << "\n"
				<< "	count elem: " << vec.size() << "\n"
				<< "	capaxity size: " << vec.capacity() << "\n"
				<< "	emptyFlag: " << vec.empty()
				<< std::endl << std::endl;
	}
	
template <class T>
	// Tests for RESIZE and RESERVE (reserve is called int resize)
	void	sizeNConstructor(T &vec, bool isItOrigVector){
		/*status*/printVecParams(vec, isItOrigVector);
		vec.resize(4);
		/*status*/printVecParams(vec,isItOrigVector);
		vec.resize(10);
		/*status*/printVecParams(vec, isItOrigVector);
		vec.resize(0);
		/*status*/printVecParams(vec, isItOrigVector);
	}

	template <class T>
	// Tests for ASSIGN function (two overload)
		void	assignCheck(T &vec, bool isItOrigVector){
			std::cout << "<<<<< Assign check" << std::endl << std::endl;
			
		/* <<<<<<<<<<<<<<< Tests for assign(iterator, iterator) >>>>>>>>>>>>>>>*/
			/* ~~~~~~~~~~Example 1~~~~~~~~~~ */
			// T	vec1(0);
			// typename T::iterator	wrong1Vec1(vec1.begin());
			// typename T::iterator	wrong2Vec1(vec1.end());

			// std::cout << "example # 1 assign(iterator, iterator)" << std::endl;
			// /*status*/printVecParams(vec, isItOrigVector);
			// vec.assign(wrong1Vec1, wrong2Vec1);
			// std::cout << "example # 1 assign(iterator, iterator)" << std::endl;
			// /*status*/printVecParams(vec, isItOrigVector);
			
			// /* ~~~~~~~~~~Example 2~~~~~~~~~~ */
			// T	vec2(12, 'd');
			// typename T::iterator	wrong1Vec2(vec2.begin());
			// typename T::iterator	wrong2Vec2(vec2.end());

			// std::cout << "example # 2 assign(iterator, iterator)" << std::endl;
			// /*status*/printVecParams(vec, isItOrigVector);
			// vec.assign(wrong1Vec2, wrong2Vec2);
			// std::cout << "example # 2 assign(iterator, iterator)" << std::endl;
			// /*status*/printVecParams(vec, isItOrigVector);
			
			// /* ~~~~~~~~~~Example 3~~~~~~~~~~ */
			// T	vec3(3, 'd');
			// typename T::iterator	wrong1Vec3(vec3.begin());
			// typename T::iterator	wrong2Vec3(vec3.end());

			// std::cout << "example # 3 assign(iterator, iterator)" << std::endl;
			// /*status*/printVecParams(vec, isItOrigVector);
			// vec.assign(wrong1Vec3, wrong2Vec3);
			// std::cout << "example # 3 assign(iterator, iterator)" << std::endl;
			// /*status*/printVecParams(vec, isItOrigVector);

							/* <<<<<<<<<<<<<<<>>>>>>>>>>>>>>> */

		/* <<<<<<<<<<<<<<< Tests for assign(size_type, value_type) >>>>>>>>>>>>>>>*/
								// FOR CHAR*
			// /* ~~~~~~~~~~ Example 1 for char* ~~~~~~~~~~ */
			// typedef typename T::size_type	size_type;
			// typedef typename T::value_type	value_type;

			// size_type	countElems1 = 0;
			// value_type	value1 = "hola";
			
			// std::cout << "example # 1 assign(size_type, value_type) for char*" << std::endl;
			// /*status*/printVecParams(vec, isItOrigVector);
			// vec.assign(countElems1, value1);
			// std::cout << "example # 1 assign(size_type, value_type) for char*" << std::endl;
			// /*status*/printVecParams(vec, isItOrigVector);
			
			// /* ~~~~~~~~~~Example 2 for char* ~~~~~~~~~~ */
			// size_type	countElems2 = 10;
			// value_type	value2 = "hola";

			// std::cout << "example # 2 assign(size_type, value_type) for char*" << std::endl;
			// /*status*/printVecParams(vec, isItOrigVector);
			// vec.assign(countElems2, value2);
			// std::cout << "example # 2 assign(size_type, value_type) for char*" << std::endl;
			// /*status*/printVecParams(vec, isItOrigVector);
			
			// /* ~~~~~~~~~~Example 3 for char* ~~~~~~~~~~ */
			// size_type	countElems3 = 5;
			// value_type	value3 = "gracias";

			// std::cout << "example # 3 assign(size_type, value_type) for char*" << std::endl;
			// /*status*/printVecParams(vec, isItOrigVector);
			// vec.assign(countElems3, value3);
			// std::cout << "example # 3 assign(size_type, value_type) for char*" << std::endl;
			// /*status*/printVecParams(vec, isItOrigVector);
								// FOR INT
			/* ~~~~~~~~~~ Example 1 for int* ~~~~~~~~~~ */
			typedef typename T::size_type	size_type;
			typedef typename T::value_type	value_type;

			size_type	countElems1 = 0;
			value_type	value1 = 3;
			
			std::cout << "example # 1 assign(size_type, value_type) for int*" << std::endl;
			/*status*/printVecParams(vec, isItOrigVector);
			vec.assign(countElems1, value1);
			std::cout << "example # 1 assign(size_type, value_type) for int*" << std::endl;
			/*status*/printVecParams(vec, isItOrigVector);
			
			/* ~~~~~~~~~~Example 2 for int* ~~~~~~~~~~ */
			size_type	countElems2 = 10;
			value_type	value2 = 1;

			std::cout << "example # 2 assign(size_type, value_type) for int*" << std::endl;
			/*status*/printVecParams(vec, isItOrigVector);
			vec.assign(countElems2, value2);
			std::cout << "example # 2 assign(size_type, value_type) for int*" << std::endl;
			/*status*/printVecParams(vec, isItOrigVector);
			
			/* ~~~~~~~~~~Example 3 for int* ~~~~~~~~~~ */
			size_type	countElems3 = 5;
			value_type	value3 = 156;

			std::cout << "example # 3 assign(size_type, value_type) for int*" << std::endl;
			/*status*/printVecParams(vec, isItOrigVector);
			vec.assign(countElems3, value3);
			std::cout << "example # 3 assign(size_type, value_type) for int*" << std::endl;
			/*status*/printVecParams(vec, isItOrigVector);

							/* <<<<<<<<<<<<<<<>>>>>>>>>>>>>>> */

			std::cout << "-----" << std::endl;
		}

int main (void){
	{
		ft::vector<int>	vec(5, 'a');
		// ft::vector<int>	vec1(0);
		// ft::vector<int>	vec1(12, 'd');
		// ft::vector<int>	vec1(3, 'd');

		assignCheck(vec, true);

	}
		std::cout << "\n\n~~~~~~~~~~~~~~ORIGINAL~~~~~~~~~~~~~~" << std::endl;
	{
		std::vector<int>	foo(5, 'a');
		// std::vector<int>	foo1(0);
		// std::vector<int>	foo1(12, 'd');
		// std::vector<int>	foo1(3, 'd');

		assignCheck(foo, true);
	}

}
