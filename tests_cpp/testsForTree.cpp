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


void	treeChecks(void){
	typedef ft::_tree<int, int, std::allocator<ft::pair<int, int> > >	tree;
	tree	elem;
	tree::pointer_node a = elem.createNode(1, 12);
	tree::pointer_node b = elem.insert(a);

	std::cout << elem.empty() << std::endl;
	std::cout << a->value.second << std::endl;
	std::cout << b->nextRight->color << std::endl;
}
