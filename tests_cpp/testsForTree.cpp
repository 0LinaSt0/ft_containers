/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testsForTree.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 19:01:12 by msalena           #+#    #+#             */
/*   Updated: 2022/07/24 20:56:23 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/containers.hpp"
#include "../includes/map.hpp"
#include <map>
#include <set>

typedef ft::pair<int, int>			_pair;
typedef ft::_rb_tree<_pair, std::less<int>, std::allocator<_pair> >	_tree_int;
typedef _tree_int::iterator	_tree_iter;
typedef ft::pair<_tree_iter, _tree_iter>			_pair_iter;

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

	void	treeChecks(void){
		{
			// _tree_int	tree;

			// checkInsert(tree);


			// checkErase(tree);



			// tree.print_tree(tree.root());
			// std::cout << "TREE_SIZE: " << tree.size() << std::endl;

			// checkOperationsFuncs(tree);

			ft::map<int, int>	ppp;
		}
		{
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
