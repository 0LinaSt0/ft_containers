/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testsForMap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 19:01:12 by msalena           #+#    #+#             */
/*   Updated: 2022/08/23 20:50:31 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tests_hpp/testsMap.hpp"
#include "../includes/tests_hpp/testsVec.hpp"
#include <set>


// typedef ft::pair<int, int>			_pair;
// typedef ft::_rb_tree<_pair, std::less<int>, std::allocator<_pair> >	_tree_int;
// typedef _tree_int::iterator	_tree_iter;
// typedef ft::pair<_tree_iter, _tree_iter>			_pair_iter;

	// void	checkInsert(_tree_int& tree){

	// 	tree.insert(_pair(15, 1));
	// 	tree.insert(_pair(12, 2));
	// 	tree.insert(_pair(17, 3));
	// 	tree.insert(_pair(20, 4));
	// 	tree.insert(_pair(11, 5));
	// 	tree.insert(_pair(34, 6));
	// 	tree.insert(_pair(16, 7));
	// 	tree.insert(_pair(18, 8));
	// 	tree.insert(_pair(19, 9));
	// 	tree.insert(_pair(31, 10));
	// 	tree.insert(_pair(9, 11));
	// 	tree.insert(_pair(22, 12));
	// 	tree.insert(_pair(32, 10));
	// 	tree.insert(_pair(13, 11));
	// 	tree.insert(_pair(35, 12));
	// 	tree.insert(_pair(33, 20));

	// 	_tree_iter	it(tree.at(_pair(19, 9)));

	// 	tree.insert(it, _pair(20, 5));
	// 	it = _tree_iter(tree.at(_pair(22, 9)));
	// 	tree.insert(it, _pair(38, 12));
	// 	it = _tree_iter(tree.at(_pair(17, 3)));
	// 	tree.insert(it, _pair(3, 12));
	// 	it = _tree_iter(tree.at(_pair(17, 3)));
	// 	tree.insert(it, _pair(35, 12));
	// }

	// void	checkErase(_tree_int& tree){
	// 	tree.erase(_pair(11, 5));
	// 	tree.erase(_pair(17, 3));

	// 	tree.erase(_pair(22, 12));
	// 	// tree.erase(_pair(19, 9));
	// 	tree.erase(_pair(31, 10));
	// 	// tree.erase(_pair(15, 1));
	// 	// tree.erase(_pair(9, 11));

	// 	// tree.erase(_pair(13, 11));
	// 	tree.erase(_pair(34, 6));
	// 	// tree.erase(_pair(35, 12));
	// 	// tree.erase(_pair(16, 7));
	// 	// tree.erase(_pair(32, 10));
	// 	tree.erase(_pair(18, 8));

	// 	tree.erase(_pair(33, 20));
	// 	// tree.erase(_pair(31, 10));/*repeat deleting 32 */
	// 	tree.erase(_pair(20, 4));
	// 	tree.erase(_pair(12, 2));
	// 	tree.erase(_pair(2, 3)); /*tree doesn't have this element*/

	// 	_tree_iter	it(tree.at(_pair(19, 9)));

	// 	tree.erase(it);


	// 	tree.erase(_pair(3, 3));


	// 	tree.erase(tree.begin(), (--(--(--(--(--(tree.end())))))));

	// }

	// void	checkOperationsFuncs(_tree_int& tree){
	// 	_tree_iter	fifteen = tree.find(_pair(15, 4));
	// 	_tree_iter	ninety = tree.find(_pair(90, 4));
	// 	_tree_iter	thirtyTwo = tree.find(_pair(32, 4));

	// 	std::cout << "<<<<< FIND CHECK >>>>>>" << std::endl;
	// 	std::cout << "Is 15 in tree?: ";
	// 	if (fifteen.base()->isItNil) {
	// 		std::cout << std::boolalpha << false << std::endl;
	// 	} else { std::cout << std::boolalpha << true << std::endl; }

	// 	std::cout << "Is 90 in tree?: ";
	// 	if (ninety.base()->isItNil) {
	// 		std::cout << std::boolalpha << false << std::endl;
	// 	} else { std::cout << std::boolalpha << true << std::endl; }
	// 	std::cout << std::endl;

	// 	std::cout << "<<<<< COUNT CHECK >>>>>>" << std::endl;
	// 	std::cout << "Is 35 in tree?: ";
	// 	if (tree.count(_pair(35, 4))) {
	// 		std::cout << std::boolalpha << true << std::endl;
	// 	} else { std::cout << std::boolalpha << false << std::endl; }

	// 	std::cout << "Is 2 in tree?: ";
	// 	if (tree.count(_pair(2, 4))) {
	// 		std::cout << std::boolalpha << true << std::endl;
	// 	} else { std::cout << std::boolalpha << false << std::endl; }
	// 	std::cout << std::endl;

	// 	std::cout << "<<<<< LOWER_BOUND CHECK >>>>>>" << std::endl;
	// 	_tree_iter	lower = tree.lower_bound(_pair(16, 4));
	// 	std::cout << "Lower_bound for 16 (mast be 16): \n\t";
	// 	tree.print_node(lower.base());

	// 	lower = tree.lower_bound(_pair(33, 4));
	// 	std::cout << "Lower_bound for 33 (mast be 35): \n\t";
	// 	tree.print_node(lower.base());

	// 	lower = tree.lower_bound(_pair(40, 4));
	// 	std::cout << "Lower_bound for 40 (mast be end()): \n\t";
	// 	tree.print_node(lower.base());
	// 	std::cout << std::endl;

	// 	std::cout << "<<<<< UPPER_BOUND CHECK >>>>>>" << std::endl;
	// 	_tree_iter	upper = tree.upper_bound(_pair(32, 4));
	// 	std::cout << "Upper_bound for 32 (mast be 35): \n\t";
	// 	tree.print_node(upper.base());

	// 	upper = tree.upper_bound(_pair(17, 4));
	// 	std::cout << "Upper_bound for 17 (mast be 32): \n\t";
	// 	tree.print_node(upper.base());

	// 	upper = tree.upper_bound(_pair(50, 4));
	// 	std::cout << "Upper_bound for 50 (mast be end()): \n\t";
	// 	tree.print_node(upper.base());
	// 	std::cout << std::endl;

	// 	std::cout << "<<<<< EQUAL_RANGE CHECK >>>>>>" << std::endl;
	// 	_pair_iter	equal = tree.equal_range(_pair(16, 4));
	// 	std::cout << "Equal_bound for 16 (mast be [16, 32]):   ";
	// 	std::cout << equal.first.base()->value.first << "   ->   ";
	// 	std::cout << equal.second.base()->value.first << std::endl;

	// 	equal = tree.equal_range(_pair(33, 4));
	// 	std::cout << "Equal_bound for 33 (mast be [35, 35]):   ";
	// 	std::cout << equal.first.base()->value.first << "   ->   ";
	// 	std::cout << equal.second.base()->value.first << std::endl;

	// 	equal = tree.equal_range(_pair(90, 4));
	// 	std::cout << "Equal_bound for 90 (mast be [38, 38]):   ";
	// 	std::cout << equal.first.base()->value.first << "   ->   ";
	// 	std::cout << equal.second.base()->value.first << std::endl;
	// 	std::cout << std::endl;

	// }

	// typedef ft::pair<int, int>		myPair;
	typedef ft::pair<std::string, std::string>		myPair;
	// typedef ft::pair<char*, char*>		defPair;

	#include <string>

	void	checkMapConstructors(void){
		{
			std::cout << "\t~~~~~~~~~~~~~~MY_MAP~~~~~~~~~~~~~~" << std::endl;
			/* <<<<<<<<<<<<<<< Tests for constructor_default >>>>>>>>>>>>>>>*/
			ft::map<int, int>	map0;

			map0.insert(ft::pair<int, int>(5, 15));
			map0.insert(ft::pair<int, int>(12, 15));
			map0.insert(ft::pair<int, int>(94, 15));
			map0.insert(ft::pair<int, int>(8, 15));
			map0.insert(ft::pair<int, int>(64, 15));
			map0.insert(ft::pair<int, int>(33, 15));

			/* <<<<<<<<<<<<<<< Tests for constructor_iterator >>>>>>>>>>>>>>>*/
			ft::map<int, int>	map1(map0.begin(), map0.end());

			/* <<<<<<<<<<<<<<< Tests for constructor_copy >>>>>>>>>>>>>>>*/
			ft::map<int, int>	map2(map1);

			map1.clear();

			printMap(map2);
		}
		{
			std::cout << "\n\n\t~~~~~~~~~~~~~~ORIG_MAP~~~~~~~~~~~~~~" << std::endl;
			/* <<<<<<<<<<<<<<< Tests for constructor_default >>>>>>>>>>>>>>>*/
			std::map<int, int>	map0;

			map0.insert(std::pair<int, int>(5, 15));
			map0.insert(std::pair<int, int>(12, 15));
			map0.insert(std::pair<int, int>(94, 15));
			map0.insert(std::pair<int, int>(8, 15));
			map0.insert(std::pair<int, int>(64, 15));
			map0.insert(std::pair<int, int>(33, 15));

			/* <<<<<<<<<<<<<<< Tests for constructor_iterator >>>>>>>>>>>>>>>*/
			std::map<int, int>	map1(map0.begin(), map0.end());

			/* <<<<<<<<<<<<<<< Tests for constructor_copy >>>>>>>>>>>>>>>*/
			std::map<int, int>	map2(map1);

			map1.clear();

			printMap(map2);
			std::cout << std::endl << std::endl;
			std::set<int>	aaa;
		}
	}

	class MapBoolTest {
public:
	std::map<int, int> m1, m2, m3, m4;
	std::map<std::string, std::string> m5, m6, m7, m8, m9;
	ft::map<int, int> mp1, mp2, mp3, mp4;
	ft::map<std::string, std::string> mp5, mp6, mp7, mp8, mp9;

	MapBoolTest() {
		m1.insert(std::make_pair(2, 3)); mp1.insert(ft::make_pair(2, 3));
		m2.insert(std::make_pair(3, 3)); mp2.insert(ft::make_pair(3, 3));
		m3.insert(std::make_pair(3, 4)); mp3.insert(ft::make_pair(3, 4));
		m4.insert(std::make_pair(4, 4)); mp4.insert(ft::make_pair(4, 4));
		m4.insert(std::make_pair(4, 5)); mp4.insert(ft::make_pair(4, 5));
		m5.insert(std::make_pair("123", "123")); mp5.insert(ft::make_pair("123", "123"));
		m6.insert(std::make_pair("123", "124")); mp6.insert(ft::make_pair("123", "124"));
		m7.insert(std::make_pair("124", "123")); mp7.insert(ft::make_pair("124", "123"));
		m8.insert(std::make_pair("12", "123")); mp8.insert(ft::make_pair("12", "123"));
		m9.insert(std::make_pair("123", "12")); mp9.insert(ft::make_pair("123", "12"));
	}
};

	void	checkForMap(void){
		// checkMapConstructors();
		{
			// std::cout << "\t~~~~~~~~~~~~~~MY_MAP~~~~~~~~~~~~~~" << std::endl;
			// ft::map<std::string, std::string>	mp;
			// 	mp.insert(myPair("a", "3"));
			// 	mp.insert(myPair("asd", "gg"));
			// 	mp.insert(myPair("d", "gg"));
			// 	mp.insert(myPair("qrg", "gg"));
			// 	mp.insert(myPair("45h24", "gg"));
			// 	mp.insert(myPair("svd", "gg"));
			// 	mp.insert(myPair("reg", "gg"));
			// 	mp.insert(myPair("asaefd", "gg"));

				// mp.insert(myPair("23", 3));
				// mp.insert(myPair("7", 3));
				// mp.insert(myPair("19", 3));
				// mp.insert(myPair("29", 3));
				// mp.insert(myPair("41", 3));
				// mp.insert(myPair("4", 3));
				// mp.insert(myPair("11", 3));

			// printMap(mp);

			// std::cout << (map0.begin())->first << std::endl;

			std::vector<int> result, result2;
			MapBoolTest mt;
			// return ;

			result.push_back(mt.m1 == mt.m1); result.push_back(mt.m3 == mt.m3); result.push_back(mt.m5 == mt.m9);
			result.push_back(mt.m1 == mt.m2); result.push_back(mt.m3 == mt.m4); result.push_back(mt.m6 == mt.m6);
			result.push_back(mt.m1 == mt.m3); result.push_back(mt.m4 == mt.m4); result.push_back(mt.m6 == mt.m7);
			result.push_back(mt.m1 == mt.m4); result.push_back(mt.m5 == mt.m5); result.push_back(mt.m6 == mt.m8);
			result.push_back(mt.m2 == mt.m2); result.push_back(mt.m5 == mt.m6); result.push_back(mt.m6 == mt.m9);
			result.push_back(mt.m2 == mt.m3); result.push_back(mt.m5 == mt.m7); result.push_back(mt.m7 == mt.m7);
			result.push_back(mt.m2 == mt.m4); result.push_back(mt.m5 == mt.m8); result.push_back(mt.m7 == mt.m8);
			result.push_back(mt.m7 == mt.m9); result.push_back(mt.m8 == mt.m8); result.push_back(mt.m8 == mt.m9);
			result.push_back(mt.m9 == mt.m9);

			// printMap(mt.m1);

			result2.push_back(mt.mp1 == mt.mp1);


			result2.push_back(mt.mp3 == mt.mp3); result2.push_back(mt.mp5 == mt.mp9);
			result2.push_back(mt.mp1 == mt.mp2); result2.push_back(mt.mp3 == mt.mp4); result2.push_back(mt.mp6 == mt.mp6);
			result2.push_back(mt.mp1 == mt.mp3); result2.push_back(mt.mp4 == mt.mp4); result2.push_back(mt.mp6 == mt.mp7);
			result2.push_back(mt.mp1 == mt.mp4); result2.push_back(mt.mp5 == mt.mp5); result2.push_back(mt.mp6 == mt.mp8);
			result2.push_back(mt.mp2 == mt.mp2); result2.push_back(mt.mp5 == mt.mp6); result2.push_back(mt.mp6 == mt.mp9);
			result2.push_back(mt.mp2 == mt.mp3); result2.push_back(mt.mp5 == mt.mp7); result2.push_back(mt.mp7 == mt.mp7);
			result2.push_back(mt.mp2 == mt.mp4); result2.push_back(mt.mp5 == mt.mp8); result2.push_back(mt.mp7 == mt.mp8);
			result2.push_back(mt.mp7 == mt.mp9); result2.push_back(mt.mp8 == mt.mp8); result2.push_back(mt.mp8 == mt.mp9);
			result2.push_back(mt.mp9 == mt.mp9);

			printVecContent(result, true);
			printVecContent(result2, true);
		}
		{
			std::cout << "\n\n\t~~~~~~~~~~~~~~ORIG_MAP~~~~~~~~~~~~~~" << std::endl;
			// std::map<int, int>		map;

			// map.at(3);

			// map.insert(std::pair<int, int>(1, 1));
			// map.insert(std::pair<int, int>(2, 1));
			// map.insert(std::pair<int, int>(3, 1));
			// map.insert(std::pair<int, int>(4, 1));
			// map.insert(std::pair<int, int>(5, 1));
			// map.insert(std::pair<int, int>(6, 1));
			// map.insert(std::pair<int, int>(7, 1));
			// map.insert(std::pair<int, int>(8, 1));

			// std::map<int, int>::iterator	it(map.end());

			// // it--;
			// std::cout << (*(--it)).first << std::endl;

			// for(std::map<int, int>::iterator it(map.begin());
			// 			it != map.end();
			// 			it++){
			// 		std::cout << (*it).first << std::endl;
			// 	}
			// std::cout << map.begin()->first << std::endl;
			// // std::cout << set.begin()->first << std::endl;

		}
	}
