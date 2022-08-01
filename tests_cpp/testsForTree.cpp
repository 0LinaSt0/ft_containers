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

size_t	tabs = 0;

template <class node>
	void	printChildrens(node& child){
		if (child){
			std::cout << "		isitNil - " << std::boolalpha
											<< child->isItNil << "\n";
			if (!(child->isItNil))
				{ std::cout << "		key - " << child->value.first << "\n"; }
		}
	}

template <class node>
	void	printAllAboutNode(node& treeNode){
		std::cout << "NODE_status" << std::endl;
		std::cout << "	nodeAddress: " << &treeNode << "\n";
		std::cout << "	nodeKey: " << treeNode->value.first << "\n";
		std::cout << "	nodeValue: " << treeNode->value.second << "\n";
		std::cout << "	isItNil: " << std::boolalpha << treeNode->isItNil << "\n";
		std::cout << "	color: " << treeNode->color << "\n";

		std::cout << "	parent: " << "\n"
						<< "		adress - " << treeNode->previous << "\n";
		if (treeNode->previous){
			std::cout << "		key - " << treeNode->previous->value.first << "\n"
			<< "		color - " << treeNode->previous->color << "\n";
		}

		std::cout << "	rightChild: " << "\n"
					<< "		adress - " << treeNode->nextRight << "\n";
		printChildrens(treeNode->nextRight);

		std::cout << "	leftChild: " << "\n"
					<< "		adress - " << treeNode->nextLeft << "\n";
		printChildrens(treeNode->nextLeft);
		std::cout<< std::endl << std::endl;
	}

// template <class tree>
// 	void printAllTree(tree all){
// 		tabs = 0;
// 		printAllTree(all->root());
// 		std::cout << "_______________________________" << std::endl;
// }

// template <class tree, class node>
// 	void	printAllTree(tree& all, node& current){
// 		if (!current) { return ; }

// 		tabs += 5;
// 		printAllTree(current->nextLeft);

// 		for (size_t i = 0; i < tabs; i++) { std::cout << " "; }

// 		std::cout << current->value.second << '('
// 						<<  ((current == all.root()) ? printAllTree(all) : current->previous->value.second)
// 						<< ", " << ((current->color == 'r') ? "red" : "black") << ')';
// 		std::cout << std::endl;
// 		printAllTree(current->nextRight);
// 		tabs -= 5;
// 	}

void	treeChecks(void){
	typedef ft::_tree<int, int, std::allocator<ft::pair<int, int> > >	tree;
	tree	elem;
	tree::pointer_node a = elem.createNode(15, 1);
	tree::pointer_node b = elem.createNode(12, 2);
	tree::pointer_node c = elem.createNode(17, 3);
	tree::pointer_node d = elem.createNode(20, 4);
	tree::pointer_node e = elem.createNode(11, 5);
	tree::pointer_node f = elem.createNode(34, 6);
	tree::pointer_node g = elem.createNode(16, 7);
	tree::pointer_node h = elem.createNode(18, 8);
	tree::pointer_node i = elem.createNode(19, 9);
	tree::pointer_node j = elem.createNode(31, 10);
	tree::pointer_node k = elem.createNode(9, 11);
	tree::pointer_node l = elem.createNode(22, 12);
	tree::pointer_node m = elem.createNode(32, 10);
	tree::pointer_node n = elem.createNode(13, 11);
	tree::pointer_node o = elem.createNode(35, 12);

	elem.insert(a);
	elem.insert(b);
	elem.insert(c);
	elem.insert(d);
	elem.insert(e);
	elem.insert(f);
	elem.insert(g);
	elem.insert(h);
	elem.insert(i);
	elem.insert(j);
	elem.insert(k);
	elem.insert(l);
	elem.insert(m);
	elem.insert(n);
	elem.insert(o);


	// std::cout << elem.size() << std::endl;
	printAllAboutNode(a);
	printAllAboutNode(b);
	printAllAboutNode(c);
	printAllAboutNode(d);
	printAllAboutNode(e);
	printAllAboutNode(f);
	printAllAboutNode(g);
	printAllAboutNode(h);
	printAllAboutNode(i);
	printAllAboutNode(j);
	printAllAboutNode(k);
	printAllAboutNode(l);
	printAllAboutNode(m);
	printAllAboutNode(n);
	printAllAboutNode(o);

}
