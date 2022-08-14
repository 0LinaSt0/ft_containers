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

template <class _tree>
	void	checkInsert(_tree& tree){
		tree.insert(tree.createMapNode(15, 1));
		tree.insert(tree.createMapNode(12, 2));
		tree.insert(tree.createMapNode(17, 3));
		tree.insert(tree.createMapNode(20, 4));
		tree.insert(tree.createMapNode(11, 5));
		tree.insert(tree.createMapNode(34, 6));
		tree.insert(tree.createMapNode(16, 7));
		tree.insert(tree.createMapNode(18, 8));
		tree.insert(tree.createMapNode(19, 9));
		tree.insert(tree.createMapNode(31, 10));
		tree.insert(tree.createMapNode(9, 11));
		tree.insert(tree.createMapNode(22, 12));
		tree.insert(tree.createMapNode(32, 10));
		tree.insert(tree.createMapNode(13, 11));
		tree.insert(tree.createMapNode(35, 12));
		tree.insert(tree.createMapNode(33, 20));
	}

template <class _tree>
	void	checkErase(_tree& tree){
		tree.erase(_pair(11, 5));
		// tree.erase(_pair(17, 3));

		// tree.erase(_pair(22, 12));
		// tree.erase(_pair(19, 9));
		// tree.erase(_pair(31, 10));
		// tree.erase(_pair(15, 1));
		// tree.erase(_pair(9, 11));

		// tree.erase(_pair(13, 11));
		// tree.erase(_pair(34, 6));
		// tree.erase(_pair(35, 12));
		// tree.erase(_pair(32, 10));
		// tree.erase(_pair(18, 8));

		// tree.erase(_pair(33, 20));
		// tree.erase(_pair(16, 7));
		// tree.erase(_pair(20, 4));
		// tree.erase(_pair(12, 2));
		// tree.erase(_pair(2, 3)); /*tree doesn't have this element*/
	}



void	treeChecks(void){
	{
		typedef ft::_rb_tree<_pair, std::less<int>, std::allocator<ft::pair<int, int> > >	_tree;
		_tree	tree;

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
