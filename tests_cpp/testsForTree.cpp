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
#include <map>
#include <set>

typedef ft::pair<int, int>			_pair;
typedef ft::_rb_tree<_pair, std::less<int>, std::allocator<_pair> >	_tree_int;
typedef _tree_int::iterator	_tree_iter;

	void	checkInsert(_tree_int& tree){

		tree.insert(_pair(15, 1));
		tree.insert(_pair(12, 2));
		tree.insert(_pair(17, 3));
		tree.insert(_pair(20, 4));
		tree.insert(_pair(11, 5));
		tree.insert(_pair(34, 6));
		tree.insert(_pair(16, 7));
		tree.insert(_pair(18, 8));
		tree.insert(_pair(19, 9));
		tree.insert(_pair(31, 10));
		tree.insert(_pair(9, 11));
		tree.insert(_pair(22, 12));
		tree.insert(_pair(32, 10));
		tree.insert(_pair(13, 11));
		tree.insert(_pair(35, 12));
		tree.insert(_pair(33, 20));

		_tree_iter	it(tree.at(_pair(19, 9)));

		tree.insert(it, _pair(20, 5));
		it = _tree_iter(tree.at(_pair(22, 9)));
		tree.insert(it, _pair(38, 12));
		it = _tree_iter(tree.at(_pair(17, 3)));
		tree.insert(it, _pair(3, 12));
		it = _tree_iter(tree.at(_pair(17, 3)));
		tree.insert(it, _pair(35, 12));
	}

	void	checkErase(_tree_int& tree){
		tree.erase(_pair(11, 5));
		tree.erase(_pair(17, 3));

		tree.erase(_pair(22, 12));
		// tree.erase(_pair(19, 9));
		tree.erase(_pair(31, 10));
		// tree.erase(_pair(15, 1));
		// tree.erase(_pair(9, 11));

		tree.erase(_pair(13, 11));
		tree.erase(_pair(34, 6));
		tree.erase(_pair(35, 12));
		tree.erase(_pair(16, 7));
		tree.erase(_pair(32, 10));
		tree.erase(_pair(18, 8));

		tree.erase(_pair(33, 20));
		// tree.erase(_pair(31, 10));/*repeat deleting 32 */
		tree.erase(_pair(20, 4));
		tree.erase(_pair(12, 2));
		tree.erase(_pair(2, 3)); /*tree doesn't have this element*/

		_tree_iter	it(tree.at(_pair(19, 9)));

		tree.erase(it);


		tree.erase(_pair(3, 3));
		

		tree.erase(tree.begin(), --(--(tree.end())));

	}



void	treeChecks(void){
	{
		_tree_int	tree;

		checkInsert(tree);


		checkErase(tree);



		tree.print_tree(tree.root());
		std::cout << "TREE_SIZE: " << tree.size() << std::endl;
	}
	{
		// std::map<int, int>		map;

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
