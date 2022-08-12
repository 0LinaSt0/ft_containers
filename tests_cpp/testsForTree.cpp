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

// #include "../includes/containers.hpp"
#include <iostream>
#include <string>
#include <stdio.h>
#include <map>

// template <class pointer_node>
// 	void	print_node(pointer_node treeNode){
// 		std::cout << "NODE_status" << std::endl;
// 		std::cout << "	nodeAddress: " << &treeNode << "\n";
// 		std::cout << "	nodeKey: " << treeNode->value.first << "\n";
// 		std::cout << "	nodeValue: " << treeNode->value.second << "\n";
// 		std::cout << "	isItNil: " << std::boolalpha << treeNode->isItNil << "\n";
// 		std::cout << "	color: " << (char)(treeNode->color) << "\n";

// 		std::cout << "	parent: " << "\n"
// 						<< "		adress - " << treeNode->previous << "\n";
// 		if (treeNode->previous){
// 			std::cout << "		key - " << treeNode->previous->value.first << "\n"
// 			<< "		color - " << (char)(treeNode->previous->color) << "\n";
// 		}

// 		std::cout << "	rightChild: " << "\n"
// 					<< "		adress - " << treeNode->nextRight << "\n";
// 		_printChildren(treeNode->nextRight);

// 		std::cout << "	leftChild: " << "\n"
// 					<< "		adress - " << treeNode->nextLeft << "\n";
// 		_printChildren(treeNode->nextLeft);
// 		std::cout<< std::endl << std::endl;
// 	}

// template <class pointer_node>
// 	void	print_tree(pointer_node currentNode){
// 		if (!currentNode) { std::cout << "Oopss... Tree doesn't have nodes" << std::endl; return ; }

// 		// if (currentNode) { return ; }

// 		print_tree(currentNode->nextLeft);
// 		print_node(currentNode);
// 		print_tree(currentNode->nextRight);
// 	}

void	treeChecks(void){
	{
		// typedef ft::_rb_tree<int, int, std::allocator<ft::pair<int, int> > >	tree;
		// tree	elem;

		// elem.insert(elem.createNode(15, 1));
		// elem.insert(elem.createNode(12, 2));
		// elem.insert(elem.createNode(17, 3));
		// elem.insert(elem.createNode(20, 4));
		// elem.insert(elem.createNode(11, 5));
		// elem.insert(elem.createNode(34, 6));
		// elem.insert(elem.createNode(16, 7));
		// elem.insert(elem.createNode(18, 8));
		// elem.insert(elem.createNode(19, 9));
		// elem.insert(elem.createNode(31, 10));
		// elem.insert(elem.createNode(9, 11));
		// elem.insert(elem.createNode(22, 12));
		// elem.insert(elem.createNode(32, 10));
		// elem.insert(elem.createNode(13, 11));
		// elem.insert(elem.createNode(35, 12));
		// elem.insert(elem.createNode(33, 20));

		// elem.erase(11);
		// elem.erase(17);

		// elem.erase(22);
		// elem.erase(19);
		// elem.erase(31);
		// elem.erase(15);
		// elem.erase(9);

		// elem.erase(13);
		// elem.erase(34);
		// elem.erase(35);
		// elem.erase(32);
		// elem.erase(18);
		// elem.erase(33);
		// elem.erase(16);
		// elem.erase(20);
		// elem.erase(12);
		// elem.erase(2); /*tree doesn't have this element*/


		// elem.print_tree(elem.root());
		// std::cout << "TREE_SIZE: " << elem.size() << std::endl;
	}
	{
		std::map<int, int>	map;

		map.insert(std::pair<int, int>(3, 4));
		map.insert(std::pair<int, int>(5, 5));
		map.insert(std::pair<int, int>(12, 6));
		map.insert(std::pair<int, int>(2, 7));
		map.insert(std::pair<int, int>(7, 8));
		map.insert(std::pair<int, int>(9, 9));
		map.insert(std::pair<int, int>(8, 10));
		map.insert(std::pair<int, int>(4, 11));
		map.insert(std::pair<int, int>(1, 12));

		std::map<int, int>::iterator	beg = map.begin();
		// std::map<int, int>::mapped_type	a = beg->first;
		// std::pair<int, int>	beg1 = *beg;

		// (void)beg1;
		// std::cout << &(*beg) << std::endl;
		// std::cout << beg1.first << std::endl;
			std::cout << "key "
						<< " color "
						<< "     node   "
						<< "      parent   " << std::endl;
		for (std::map<int, int>::iterator it=map.begin();
				it != map.end();
				it++){
			// const int	in = map[it._M_node->_M_parent];
			// (void)in;

			std::cout << it->first << "  ->  "
						<< it._M_node->_M_color << "  ->  "
						<< it._M_node << "  ->  "
						<< it._M_node->_M_parent << std::endl;
		}
	}
}
