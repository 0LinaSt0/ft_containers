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
	}

	void	checkErase(_tree_int& tree){
		// tree.erase(_pair(11, 5));
		// tree.erase(_pair(17, 3));

		// tree.erase(_pair(22, 12));
		// tree.erase(_pair(19, 9));
		tree.erase(_pair(31, 10));
		// tree.erase(_pair(15, 1));
		// tree.erase(_pair(9, 11));

		tree.erase(_pair(13, 11));
		// tree.erase(_pair(34, 6));
		tree.erase(_pair(35, 12));
		tree.erase(_pair(16, 7));
		tree.erase(_pair(32, 10));
		tree.erase(_pair(18, 8));

		tree.erase(_pair(33, 20));
		// tree.erase(_pair(31, 10));/*repeat deleting 32 */
		tree.erase(_pair(20, 4));
		// tree.erase(_pair(12, 2));
		tree.erase(_pair(2, 3)); /*tree doesn't have this element*/
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
		// std::set<int>			set;

		// std::cout << map.begin()->first << std::endl;
		// // std::cout << set.begin()->first << std::endl;
	}
}
