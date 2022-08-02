/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:02:57 by marvin            #+#    #+#             */
/*   Updated: 2022/07/27 17:02:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../containers.hpp"

namespace ft {

	/* ~~~~~~~~~~~~ USEFUL FUNCTIONS FOR ADD NODE ~~~~~~~~~~*/

	/*returns:
		1. NULL - if newNode is root
		2. newNode - if grandded is root
		3. uncle - all other */
	template <class _T, class _Compare, class _Allocator>
		typename _tree<_T, _Compare, _Allocator>::pointer_node	_tree<_T, _Compare, _Allocator>::
			__findUncle(pointer_node newNode){
				if (newNode->previous){
					if (newNode->previous->previous){
						if (newNode->previous->previous->value.first < newNode->value.first){
							return (newNode->previous->previous->nextLeft);
						} else {
							return (newNode->previous->previous->nextRight);
						}
					} else { return newNode; }
				} else { return NULL; }
			}

	template <class _T, class _Compare, class _Allocator>
		void	_tree<_T, _Compare, _Allocator>::
				___updateNodesPointers(pointer_node oldNode,
										pointer_node newNode){
			if (oldNode->previous) {
				if (oldNode->previous->value.first < oldNode->value.first) {
				oldNode->previous->nextRight = newNode;
				} else {
					oldNode->previous->nextLeft = newNode;
				}
			}
			newNode->previous = oldNode->previous;
			oldNode->previous = newNode;
			if (!newNode->previous)
				node = newNode;
		}

	template <class _T, class _Compare, class _Allocator>
		void	_tree<_T, _Compare, _Allocator>::
				___nodeMoreGranddad(pointer_node uncle, pointer_node addedNode){
			if (addedNode->previous->value.first > addedNode->value.first){
				_rightTurn(addedNode->previous, addedNode);
				_leftTurn(uncle->previous, addedNode);
				addedNode->color = BLACK;
			} else {
				_leftTurn(uncle->previous, addedNode->previous);
				addedNode->previous->color = BLACK;
			}
		}

	template <class _T, class _Compare, class _Allocator>
		void	_tree<_T, _Compare, _Allocator>::
				___nodeLessGranddad(pointer_node uncle, pointer_node addedNode){
			if (addedNode->previous->value.first < addedNode->value.first){
				_leftTurn(addedNode->previous, addedNode);
				_rightTurn(uncle->previous, addedNode);
				addedNode->color = BLACK;
			} else {
				_rightTurn(uncle->previous, addedNode->previous);
				addedNode->previous->color = BLACK;
			}
		}

	template <class _T, class _Compare, class _Allocator>
		void	_tree<_T, _Compare, _Allocator>::
				__blackUncle(pointer_node uncle, pointer_node addedNode){

			if (addedNode->value.first > uncle->previous->value.first){
				___nodeMoreGranddad(uncle, addedNode);
			} else {
				___nodeLessGranddad(uncle, addedNode);
			}
			uncle->previous->color = RED;
		}

template <class _T, class _Compare, class _Allocator>
		void	_tree<_T, _Compare, _Allocator>::
				__redUncle(pointer_node uncle, pointer_node addedNode){
			/*dad*/addedNode->previous->color = BLACK;
			/*uncle*/uncle->color = BLACK;
			if (uncle->previous->previous){
				/*grandded*/uncle->previous->color = RED;
				if (uncle->previous->previous->color == RED){
					_redDad(uncle->previous);
				}
			}
		}



	/* ~~~~~~~~~~~ USEFUL FUNCTIONS FOR DELETE NODE ~~~~~~~~~*/

	/* As argument it takes first right child of node */
	template <class _T, class _Compare, class _Allocator>
		typename _tree<_T, _Compare, _Allocator>::pointer_node	_tree<_T, _Compare, _Allocator>::
			___findLeastRightChild(pointer_node currentNode){
			return ((currentNode->nextLeft->isItNil)
						? ___findLeastRightChild(currentNode->nextLeft)
						: currentNode);
		}

	template <class _T, class _Compare, class _Allocator>
		void	_tree<_T, _Compare, _Allocator>::
			___changeNodesValue(pointer_node whichNode,
									pointer_node inNode){
			typedef typename tree_node::pair_type	value_pair;

			value_pair	tmp = inNode->value;

			inNode->value = whichNode->value;
			whichNode->value = tmp;
		}

	template <class _T, class _Compare, class _Allocator>
		void	_tree<_T, _Compare, _Allocator>::
			__deletedWithTwoGhildren(pointer_node deletedNode){
			pointer_node	leastRightChild;

			leastRightChild = ___findLeastRightChild(deletedNode->nextRight);
			___changeNodesValue(leastRightChild, deletedNode);
			
			_deleteNode(leastRightChild);
		}

	template <class _T, class _Compare, class _Allocator>
		void	_tree<_T, _Compare, _Allocator>::
			__deletedWithOneChild(pointer_node deletedNode){

		}

	template <class _T, class _Compare, class _Allocator>
		void	_tree<_T, _Compare, _Allocator>::
			__deletedWithoutChildren(pointer_node deletedNode){

		}

}
