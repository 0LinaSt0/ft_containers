/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 17:43:22 by msalena           #+#    #+#             */
/*   Updated: 2022/08/26 20:27:56 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/tests_hpp/testsVec.hpp"
#include "includes/tests_hpp/testsStack.hpp"
#include "includes/tests_hpp/testsMap.hpp"
#include "includes/containers.hpp"
#include "Lapa_tests/map_tests.hpp"
#include <algorithm>
// #include <set>
// #include <iostream>

struct classcomp {
	private:
		size_t	factor;
	public:
	classcomp() : factor(1) {}
	classcomp(const size_t otherFact) : factor(otherFact){ }

	
	bool operator() (int lhs, int rhs) const
	{ 
		if (factor == 1) std::cout << "\tcomp" << std::endl;
		// if (factor == 3) std::cout << "\tcomp" << std::endl;
		return (lhs / factor) < ( rhs * factor);
	 }
};

struct A{
	std::string a;
	A(std::string a){this->a = a;}
};

int main (void){

	// std::map<int, int, classcomp> m1(classcomp(1));
	// std::map<int, int, classcomp> m2(m1);
	// std::less
	// m1.insert(std::make_pair<int, int>(1, 1));
	// m1.insert(std::make_pair<int, int>(2, 2));
	// m2.insert(std::make_pair<int, int>(1, 1));
	// m2.insert(std::make_pair<int, int>(2, 2));

	A a("asdfasdfaf");
	A b(a);
	(void)b;
	std::cout << b.a << std::endl;

	return 0;
	
	// checkerForVector();
	// checkerForStack();
	// checkForMap();

	// MAP_TESTS::RUN_MAP_TESTS();
	// std::map<int, int>	a;

	// printf("%p", &(a.beging))
	// std::cout << &(*(a.begin())) << std::endl;

	// size_t i = 1;
	// size_t f = 16;

	// for (size_t d = 8; i || d != f; d++){
	// 	std::cout << d << std::endl;
	// 	if (d == f) { break; }
	// 	else { --i; }
	// }

	{
		std::map<int,int,classcomp>	orig(classcomp(3));
		
		for (size_t i=0; i < 10; i++){
			orig[i] = i;
		}

		std::map<int, int, classcomp>	copy(orig);

		orig.insert(std::make_pair<int, int>(15, 29));
		copy.insert(std::make_pair<int, int>(15, 29));

		std::cout << "~~~~~~FIRST_MAP~~~~~~" << std::endl;
		// printMap(orig);
		std::cout << "~~~~~~COPY_MAP~~~~~~" << std::endl;
		// printMap(copy);
	}
	// 	std::cout << "\n\tLOOK AT THIS\n\n" << std::endl;
	// {
	// 	std::map<int,int,classcomp>	orig(classcomp(3));
		
	// 	for (size_t i=0; i < 10; i++){
	// 		orig[i] = i;
	// 	}

	// 	std::map<int, int, classcomp>	other;

	// 	other.insert(std::make_pair<int, int>(0, 29));
	// 	other.insert(std::make_pair<int, int>(9, 29));
	// 	other.insert(std::make_pair<int, int>(8, 29));
	// 	other.insert(std::make_pair<int, int>(7, 29));
	// 	other.insert(std::make_pair<int, int>(6, 29));
	// 	other.insert(std::make_pair<int, int>(5, 29));
	// 	other.insert(std::make_pair<int, int>(4, 29));
	// 	other.insert(std::make_pair<int, int>(3, 29));
	// 	other.insert(std::make_pair<int, int>(2, 29));
	// 	other.insert(std::make_pair<int, int>(1, 29));
		

	// 	// orig.insert(std::make_pair<int, int>(15, 29));
	// 	// other.insert(std::make_pair<int, int>(15, 29));

	// 	std::cout << "~~~~~~FIRST_MAP~~~~~~" << std::endl;
	// 	printMap(orig);
	// 	std::cout << "~~~~~~COPY_MAP~~~~~~" << std::endl;
	// 	printMap(other);
	// }
}



