/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 17:43:22 by msalena           #+#    #+#             */
/*   Updated: 2022/07/03 19:19:42 by msalena          ###   ########.fr       */
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
		std::cout << "status" << std::endl;
		printVecContent(vec, isItOrigVector);
		std::cout << "	vecAddress: " << &vec << "\n"
				<< "	count elem: " << vec.size() << "\n"
				<< "	capaxity size: " << vec.capacity() << "\n"
				<< "	emptyFlag: " << vec.empty()
				<< std::endl << std::endl;
	}

	void	checkConstructors(){
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
// Tests for ASSIGN  (two overloads)
	void	assignCheck(T &vec, bool isItOrigVector){
			std::cout << "<<<<< ASSIGN CHECK" << std::endl << std::endl;
			
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
			
			// std::cout << "example # 1 assign(size_type, value_type) for std::string" << std::endl;
			// /*status*/printVecParams(vec, isItOrigVector);
			// vec.assign(countElems1, value1);
			// std::cout << "example # 1 assign(size_type, value_type) for std::string" << std::endl;
			// /*status*/printVecParams(vec, isItOrigVector);
			
			// /* ~~~~~~~~~~Example 2 for std::string ~~~~~~~~~~ */
			// size_type	countElems2 = 10;
			// value_type	value2 = "hola";

			// std::cout << "example # 2 assign(size_type, value_type) std::string" << std::endl;
			// /*status*/printVecParams(vec, isItOrigVector);
			// vec.assign(countElems2, value2);
			// std::cout << "example # 2 assign(size_type, value_type) std::string" << std::endl;
			// /*status*/printVecParams(vec, isItOrigVector);
			
			// /* ~~~~~~~~~~Example 3 for std::string ~~~~~~~~~~ */
			// size_type	countElems3 = 5;
			// value_type	value3 = "gracias";

			// std::cout << "example # 3 assign(size_type, value_type) std::string" << std::endl;
			// /*status*/printVecParams(vec, isItOrigVector);
			// vec.assign(countElems3, value3);
			// std::cout << "example # 3 assign(size_type, value_type) std::string" << std::endl;
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

template <class T>
	// Tests for INSERT (three overloads) 
	void	insertCheck(T &vec, bool isItOrigVector){
		std::cout << "<<<<< INSERT CHECK" << std::endl << std::endl;
		typedef typename T::iterator	iterator;
		iterator	iterVec = vec.begin();
		/* <<<<<<<<<<<<<<< Tests for char type >>>>>>>>>>>>>>>*/
		iterVec = vec.insert(iterVec+2, 'h');
		std::cout << "example # 1 insert: add char " << std::endl;
		/*status*/printVecParams(vec, isItOrigVector);
	
		vec.insert(iterVec, 4, '~');
		std::cout << "example # 2 insert: add chars " << std::endl;
		/*status*/printVecParams(vec, isItOrigVector);
		
		T	newVec(8, '+');
		iterVec = vec.end();
		vec.insert(iterVec, newVec.begin(), newVec.end());
		std::cout << "example # 3 insert: add distance " << std::endl;
		/*status*/printVecParams(vec, isItOrigVector);
				/* <<<<<<<<<<<<<<<>>>>>>>>>>>>>>> */

		/* <<<<<<<<<<<<<<< Tests for std::string type >>>>>>>>>>>>>>>*/
		// iterVec = vec.insert(iterVec+2, "aaa");
		// std::cout << "example # 1 insert: add char " << std::endl;
		// /*status*/printVecParams(vec, isItOrigVector);
	
		// vec.insert(iterVec, 2, "bbb");
		// std::cout << "example # 2 insert: add some chars " << std::endl;
		// /*status*/printVecParams(vec, isItOrigVector);
		
		// T	newVec(8, "new");
		// iterVec = vec.end();
		// vec.insert(iterVec, newVec.begin(), newVec.end());
		// std::cout << "example # 3 insert: add distance " << std::endl;
		// /*status*/printVecParams(vec, isItOrigVector);
				/* <<<<<<<<<<<<<<<>>>>>>>>>>>>>>> */
				
		std::cout << ">>>>>" << std::endl;
	}

template <class T>
	// Tests for ERASE (two overloads) 
	void	eraseCheck(T &vec, bool isItOrigVector){
		std::cout << "<<<<< EARASE CHECK" << std::endl << std::endl;
		typedef typename T::iterator	iterator;
		iterator	iterVecBegin = vec.begin();
		iterator	returnIter;
		/* <<<<<<<<<<<<<<< Tests for int type >>>>>>>>>>>>>>>*/
		returnIter = vec.erase(iterVecBegin+2);
		std::cout << "example # 1 earse: remove elem " << std::endl;
		/*status*/printVecParams(vec, isItOrigVector);
		/*print_return*/std::cout << "	earse_return: "
								<< (*returnIter) 
								<< std::endl << std::endl;
	
		// std::cout << *iterVecBegin << std::endl;
		iterVecBegin = vec.begin();
		returnIter = vec.erase(iterVecBegin, iterVecBegin+5);
		std::cout << "example # 2 earse: remove elems " << std::endl;
		/*status*/printVecParams(vec, isItOrigVector);
		/*print_return*/std::cout << "	earse_return: "
								<< (*returnIter) 
								<< std::endl << std::endl;
				/* <<<<<<<<<<<<<<<>>>>>>>>>>>>>>> */
				
		std::cout << ">>>>>" << std::endl;
	}

int main (void){
		// checkConstructors();
	{
		ft::vector<char>	vec(5, 'a');
		// std::vector<std::string>	vec(5, "aboba");
		// ft::vector<char>	vec(0);
		// vec.push_back('a');
		// vec.push_back('b');
		// vec.push_back('v');
		// vec.push_back('g');
		// vec.push_back('d');
		// vec.push_back('e');
		// vec.push_back('j');
		// vec.push_back('z');
		// vec.push_back('i');
		// vec.push_back('k');
		// ft::vector<char>	vec1(6, 'd');
		// ft::vector<int>	vec1(3, 'd');
		
		// printVecParams(vec, false);
		

		// <<<<<<<<<<<<<<<<< my reverse tests >>>>>>>>>>>>>>>>>>>>
		ft::vector<int> myvector;
		for (int i=0; i<10; i++){
			myvector.push_back(i);
			std::cout << myvector[i] << ' ';
		} 
		std::cout << std::endl;

		typedef ft::vector<int>::iterator iter_type;
																// ? 9 8 7 6 5 4 3 2 1 0 ?
		iter_type from (myvector.begin());                      //   ^
		std::cout << *(from.base() - 1) << std::endl;
		iter_type until (myvector.end());                       //                       ^
		std::cout << *(until.base() - 1) << std::endl;
		ft::reverse_iterator<iter_type> rev_until (from);      // ^

		ft::reverse_iterator<iter_type> rev_from (until);      //                     ^
		
		
		for (ft::reverse_iterator<iter_type> it(rev_from); it != rev_until; ++it){
			std::cout << (*it) <<  "   ";
		}
		std::cout << std::endl; 

		std::cout << "OPERATOR-: " << *(rev_from+3) << std::endl;
		
		std::cout << "myvector:";
		while (rev_from != rev_until)
			std::cout << ' ' << *rev_from++;
		std::cout << '\n';

		// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	}
	{
		std::cout << "\n\n~~~~~~~~~~~~~~ORIGINAL~~~~~~~~~~~~~~" << std::endl;
		// std::vector<char>	foo(5, 'a');
		// std::vector<std::string>	foo(5, "aboba");
		// std::vector<char>	foo(0);
		// foo.push_back('a');
		// foo.push_back('b');
		// foo.push_back('v');
		// foo.push_back('g');
		// foo.push_back('d');
		// foo.push_back('e');
		// foo.push_back('j');
		// foo.push_back('z');
		// foo.push_back('i');
		// foo.push_back('k');
		// std::vector<char>	foo1(6, 'd');
		// // std::vector<int>	foo1(3, 'd');

		// printVecParams(foo, true);


		// std::vector<int> myvector;
		// for (int i=0; i<10; i++){
		// 	myvector.push_back(i);
		// 	std::cout << myvector[i] << ' ';
		// } 
		// std::cout << std::endl;

		// typedef std::vector<int>::iterator iter_type;

		// std::reverse_iterator<iter_type> rev_end (myvector.begin());
		// std::reverse_iterator<iter_type> rev_begin (myvector.end());

		// // printf("\n%p   /   %p", &(*rev_begin), &(*rev_end));
		// std::cout << "from *: " << *rev_end << "   /   ";
		// std::cout << *rev_begin << std::endl;
		
		// std::cout << "from base: " << *(rev_end.base()) << "   /   ";
		// std::cout << *(rev_begin.base() - 1) << std::endl;

		// // std::cout << "myvector:";
		// // for (iter_type it = rev_end.base(); it != rev_begin.base(); ++it)
		// // 	std::cout << ' ' << *it;
		// // std::cout << '\n';

		// return 0;










		std::vector<int> myvector;
		for (int i=0; i<10; i++){
			myvector.push_back(i);
			std::cout << myvector[i] << ' ';
		} 
		std::cout << std::endl;

		typedef std::vector<int>::iterator iter_type;
																// ? 9 8 7 6 5 4 3 2 1 0 ?
		iter_type from (myvector.begin());                      //   ^
		std::cout << *(from.base() - 1) << std::endl;
		iter_type until (myvector.end());                       //                       ^
		std::cout << *(until.base() - 1) << std::endl;
		std::reverse_iterator<iter_type> rev_until (from);      // ^

		std::reverse_iterator<iter_type> rev_from (until);      //                     ^

		// for (std::reverse_iterator<iter_type> it(rev_from); it != rev_until; ++it){
		// 	std::cout << (*it) <<  "   ";
		// }
		// std::cout << std::endl; 
		
		std::cout << "OPERATOR-: " << *(rev_from+3) << std::endl;
		
		std::cout << "myvector:";
		while (rev_from != rev_until)
			std::cout << ' ' << *rev_from++;
		std::cout << '\n';

		return 0;

	}
}
