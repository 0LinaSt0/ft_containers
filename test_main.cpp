/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 17:43:22 by msalena           #+#    #+#             */
/*   Updated: 2022/06/26 18:26:58 by msalena          ###   ########.fr       */
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
		// (void)isItOrigVector;
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
// Tests for ASSIGN  (two overload)
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
							// FOR STD::STRING
			// /* ~~~~~~~~~~ Example 1 for std::string ~~~~~~~~~~ */
			// typedef typename T::size_type	size_type;
			// typedef typename T::value_type	value_type;

			// size_type	countElems1 = 0;
			// value_type	value1 = "hola";
			
			// std::cout << "example # 1 assign(size_type, value_type) for char*" << std::endl;
			// /*status*/printVecParams(vec, isItOrigVector);
			// vec.assign(countElems1, value1);
			// std::cout << "example # 1 assign(size_type, value_type) for char*" << std::endl;
			// /*status*/printVecParams(vec, isItOrigVector);
			
			// /* ~~~~~~~~~~Example 2 for std::string ~~~~~~~~~~ */
			// size_type	countElems2 = 10;
			// value_type	value2 = "hola";

			// std::cout << "example # 2 assign(size_type, value_type) for char*" << std::endl;
			// /*status*/printVecParams(vec, isItOrigVector);
			// vec.assign(countElems2, value2);
			// std::cout << "example # 2 assign(size_type, value_type) for char*" << std::endl;
			// /*status*/printVecParams(vec, isItOrigVector);
			
			// /* ~~~~~~~~~~Example 3 for std::string ~~~~~~~~~~ */
			// size_type	countElems3 = 5;
			// value_type	value3 = "gracias";

			// std::cout << "example # 3 assign(size_type, value_type) for char*" << std::endl;
			// /*status*/printVecParams(vec, isItOrigVector);
			// vec.assign(countElems3, value3);
			// std::cout << "example # 3 assign(size_type, value_type) for char*" << std::endl;
			// /*status*/printVecParams(vec, isItOrigVector);
								// FOR INT
			/* ~~~~~~~~~~ Example 1 for int ~~~~~~~~~~ */
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

template <class T>
	// Tests for PUSH_BACK 
	void	push_backCheck(T &vec, bool isItOrigVector){
		/* <<<<<<<<<<<<<<< Tests for std::string type >>>>>>>>>>>>>>>*/
			// vec.push_back("156");
			// printVecParams(vec, isItOrigVector);
			// vec.push_back("157");
			// printVecParams(vec, isItOrigVector);
			// vec.push_back("158");
			// printVecParams(vec, isItOrigVector);
			// vec.push_back("159");
			// printVecParams(vec, isItOrigVector);
				/* <<<<<<<<<<<<<<<>>>>>>>>>>>>>>> */
				
		/* <<<<<<<<<<<<<<< Tests for int type >>>>>>>>>>>>>>>*/
			vec.push_back(156);
			printVecParams(vec, isItOrigVector);
			vec.push_back(157);
			printVecParams(vec, isItOrigVector);
			vec.push_back(158);
			printVecParams(vec, isItOrigVector);
			vec.push_back(159);
			printVecParams(vec, isItOrigVector);
				/* <<<<<<<<<<<<<<<>>>>>>>>>>>>>>> */
		}

template <class T>
	// Tests for POP_BACK 
	void	pop_backCheck(T &vec, bool isItOrigVector){
		vec.pop_back();
		printVecParams(vec, isItOrigVector);
	}

int main (void){
	{
		// ft::vector<int>	vec(5, 'a');
		// std::vector<std::string>	vec(5, "aboba");
		// ft::vector<int>	vec(0);
		// ft::vector<int>	vec1(12, 'd');
		// ft::vector<int>	vec1(3, 'd');
		
		// printVecParams(vec, false);
		
		

	}
		std::cout << "\n\n~~~~~~~~~~~~~~ORIGINAL~~~~~~~~~~~~~~" << std::endl;
	{
		//мой пример
		std::vector<int>	foo(5, 'a');
		// // std::vector<std::string>	foo(5, "aboba");
		// // std::vector<int>	foo(0);
		std::vector<int>	foo1(2, 400);
		// // std::vector<int>	foo1(3, 'd');
		
		// printVecParams(foo, true);
	
		std::vector<int>::iterator	iterFoo = foo.begin()+4;
		foo.insert(iterFoo, 'f');
		
		printVecParams(foo, true);
		// foo.insert(iterFoo+1, foo1.begin(), foo.end());
		// printVecParams(foo, true);


		//пример из интрнета
		std::vector<int> myvector (3,100);
		std::vector<int>::iterator it;

		it = myvector.begin();
		it = myvector.insert ( it , 200 );
		printVecParams(myvector, true);

		// myvector.insert (it,2,300);

		// // "it" no longer valid, get a new one:
		// it = myvector.begin();

		std::vector<int> anothervector (2,400);
		myvector.insert (it+2,anothervector.begin(),anothervector.end());
		printVecParams(myvector, true);

		// int myarray [] = { 501,502,503 };
		// myvector.insert (myvector.begin(), myarray, myarray+3);

		// std::cout << "myvector contains:";
		// for (it=myvector.begin(); it<myvector.end(); it++)
		// 	std::cout << ' ' << *it;
		// std::cout << '\n';

		return 0;

	}

	// По какой-то непонятной мне причине мой пример с инсертом не работает, а из интернета пример работает
}
