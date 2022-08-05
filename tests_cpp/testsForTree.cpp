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
#include <stdio.h>

void	treeChecks(void){
	typedef ft::_tree<int, int, std::allocator<ft::pair<int, int> > >	tree;
	tree	elem;

	elem.insert(elem.createNode(15, 1));
	elem.insert(elem.createNode(12, 2));
	elem.insert(elem.createNode(17, 3));
	elem.insert(elem.createNode(20, 4));
	elem.insert(elem.createNode(11, 5));
	elem.insert(elem.createNode(34, 6));
	elem.insert(elem.createNode(16, 7));
	elem.insert(elem.createNode(18, 8));
	elem.insert(elem.createNode(19, 9));
	elem.insert(elem.createNode(31, 10));
	elem.insert(elem.createNode(9, 11));
	elem.insert(elem.createNode(22, 12));
	elem.insert(elem.createNode(32, 10));
	elem.insert(elem.createNode(13, 11));
	elem.insert(elem.createNode(35, 12));
	elem.insert(elem.createNode(33, 20));

	elem.erase(11);
	elem.erase(17);

	elem.erase(22);
	elem.erase(19);
	elem.erase(31);
	elem.erase(15);
	elem.erase(9);

	elem.erase(13);
	elem.erase(34);
	elem.erase(35);
	elem.erase(32);
	elem.erase(18);
	elem.erase(33);
	elem.erase(16);
	elem.erase(20);
	elem.erase(12);


	elem.print_tree(elem.root());


}
