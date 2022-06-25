/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 17:43:22 by msalena           #+#    #+#             */
/*   Updated: 2022/06/25 19:46:28 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/vector.hpp"
#include "includes/vectorIterator.hpp"
#include <vector>
#include <iostream>
#include <string>
// #include <stddef.h>
#include <memory>

template <class T>
	void	printVecContent(T &vec, bool isItOrigVector){
		std:: cout << "	vector content: ";
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
	void	printVecParams (T &vec, bool isItOrigVector){
		std::cout << "\nSTATUS\n" << std::endl;
		printVecContent(vec, isItOrigVector);
		std::cout << "	vecAddress: " << &vec << "\n"
				<< "	count elem: " << vec.size() << "\n"
				<< "	capaxity size: " << vec.capacity() << "\n"
				<< "	emptyFlag: " << vec.empty()
				<< std::endl;
	}
	
template <class T>
	// tests for RESIZE and RESERVE (reserve is called int resize)
	void	sizeNConstructor(T &vec, bool isItOrigVector){
		/*status*/printVecParams(vec, isItOrigVector);
		vec.resize(4);
		/*status*/printVecParams(vec,isItOrigVector);
		vec.resize(10);
		/*status*/printVecParams(vec, isItOrigVector);
		vec.resize(0);
		/*status*/printVecParams(vec, isItOrigVector);
	}

int main (void){
	{		
		// ft::vector<int>	vec1;
		// defaultConstructor(&vec1);

		// ft::vector<int>	vec2(0);
		ft::vector<int>	vec2(0);
		vec2[0] = 1; vec2[1] = 2; vec2[2] = 3;

		// std::cout << vec2.at(0) << std::endl;		
		// std::cout << vec2.front() << std::endl;		
		// std::cout << vec2.back() << std::endl;		
		
		sizeNConstructor(vec2, false);
		// printVecParams(&vec2);
		// vec2.clear();
		// vec2.swap(vec);
		// printVecParams(&vec2);
		// sizeNConstructor(&vec2);
		
	}
		std::cout << "\n\n~~~~~~~~~~~~~~ORIGINAL~~~~~~~~~~~~~~" << std::endl;
	// {
		// std::vector<int>	vec1;
		// defaultConstructor(&vec1);
		
		// std::vector<char>	vec2(5, 'a');
		// std::cout << "myvector contains:";
		// 	for (unsigned i=0; i<vec2.size(); i++)
		// 		std::cout << ' ' << vec2[i];
		// 	std::cout << '\n';
		
		// printVecParams(&vec2);
		// vec2.erase (vec2.begin()+4);
		// vec2.clear();
		// printVecParams(&vec2);
		
		// sizeNConstructor(&vec2);
		// std::vector<char> foo(5, 'a');
		std::vector<int> foo(0);
		foo[0] = 1; foo[1] = 2; foo[2] = 3;

		std::cout << foo.at(0) << std::endl;		
		sizeNConstructor(foo, true);
	// 	std::vector<int> foo1(400);
		
	// 	foo.swap(foo1);
	// 	printVecParams(&foo);
	// 	foo1.clear();
	// 	printVecParams(&foo);
	// }

}
