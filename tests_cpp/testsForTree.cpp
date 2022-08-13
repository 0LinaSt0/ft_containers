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

template <class _tree>
	void	checkInsert(_tree& tree){
		tree.insert(tree.createNode(15, 1));
		tree.insert(tree.createNode(12, 2));
		tree.insert(tree.createNode(17, 3));
		tree.insert(tree.createNode(20, 4));
		tree.insert(tree.createNode(11, 5));
		tree.insert(tree.createNode(34, 6));
		tree.insert(tree.createNode(16, 7));
		tree.insert(tree.createNode(18, 8));
		tree.insert(tree.createNode(19, 9));
		tree.insert(tree.createNode(31, 10));
		tree.insert(tree.createNode(9, 11));
		tree.insert(tree.createNode(22, 12));
		tree.insert(tree.createNode(32, 10));
		tree.insert(tree.createNode(13, 11));
		tree.insert(tree.createNode(35, 12));
		tree.insert(tree.createNode(33, 20));
	}

template <class _tree>
	void	checkErase(_tree& tree){
		tree.erase(11);
		tree.erase(17);

		tree.erase(22);
		tree.erase(19);
		tree.erase(31);
		tree.erase(15);
		tree.erase(9);

		tree.erase(13);
		tree.erase(34);
		tree.erase(35);
		tree.erase(32);
		tree.erase(18);

		tree.erase(33);
		tree.erase(16);
		tree.erase(20);
		tree.erase(12);
		tree.erase(2); /*tree doesn't have this element*/
	}

void	treeChecks(void){
	{
		typedef ft::_rb_tree<int, int, std::allocator<ft::pair<int, int> > >	_tree;
		_tree	tree;

		checkInsert(tree);

		// checkErase(tree);


		tree.print_tree(tree.root());
		// std::cout << "TREE_SIZE: " << tree.size() << std::endl;
	}
}
