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
							? currentNode
							: ___findLeastRightChild(currentNode->nextLeft));
		}

	template <class _T, class _Compare, class _Allocator>
		void	_tree<_T, _Compare, _Allocator>::
			__deleteNode(pointer_node deletedNode){
				_freeNode(deletedNode->nextRight);
				_freeNode(deletedNode->nextLeft);
				// /*?????*/nodeAlloc.destroy(deletedNode->value);
				deletedNode->nextRight = NULL;
				deletedNode->nextLeft = NULL;
				deletedNode->color = BLACK;
				deletedNode->isItNil = true;
		}

	template <class _T, class _Compare, class _Allocator>
		void	_tree<_T, _Compare, _Allocator>::
			___nodesValueChange(pointer_node whichNode,
									pointer_node inNode){
				typedef typename tree_node::pair_type	value_pair;

				value_pair	tmp = inNode->value;

				inNode->value = whichNode->value;
				whichNode->value = tmp;
		}

	template <class _T, class _Compare, class _Allocator>
		void	_tree<_T, _Compare, _Allocator>::
			___brotherParentChange(pointer_node doubleBlackNode,
										pair<olderYangerBro,
										typename _tree<_T, _Compare, _Allocator>
										::pointer_node> bro){
				if (bro.first == OLDER){
					_leftTurn(doubleBlackNode->previous, bro.second);
				} else {
					_rightTurn(doubleBlackNode->previous, bro.second);
				}
			}

	template <class _T, class _Compare, class _Allocator>
		pair<olderYangerBro, typename _tree<_T, _Compare, _Allocator>::pointer_node>
			_tree<_T, _Compare, _Allocator>::
			___olderYangerBrother(pointer_node doubleBlackNode){
				typedef pair<olderYangerBro,
								typename _tree<_T, _Compare, _Allocator>
								::pointer_node>	_pair;

				if (doubleBlackNode->previous){
					if (doubleBlackNode->previous->nextRight != doubleBlackNode)
						{ return _pair(OLDER, doubleBlackNode->previous->nextRight); }
					return _pair(YANGER, doubleBlackNode->previous->nextLeft);
				}
				return _pair(NONE, NULL);
			}


	template <class _T, class _Compare, class _Allocator>
		void	_tree<_T, _Compare, _Allocator>::
			___blackChildrenBalancing(pointer_node doubleBlackNode,
										pair<olderYangerBro,
										typename _tree<_T, _Compare, _Allocator>
										::pointer_node> bro){
				doubleBlackNode->color = BLACK;
				bro.second->color = RED;

				if (doubleBlackNode->previous->color == RED){
					doubleBlackNode->previous->color = BLACK;
				} else {
					doubleBlackNode->previous->color = DOUBLE_BLACK;
					__blackBalancing(doubleBlackNode->previous);
				}
			}

	template <class _T, class _Compare, class _Allocator>
		void	_tree<_T, _Compare, _Allocator>::
			___redLeftChildBalancing(pointer_node doubleBlackNode,
										pair<olderYangerBro,
										typename _tree<_T, _Compare, _Allocator>
										::pointer_node> bro){
				if (!doubleBlackNode->previous->previous
						&& doubleBlackNode->isItNil){
					___brotherParentChange(doubleBlackNode, bro);
					bro.second->nextLeft->color = BLACK;
				} else {
					bro.second->color = RED;
					bro.second->nextLeft->color = BLACK;

					_rightTurn(bro.second, bro.second->nextLeft);

					___redRightChildBalancing(doubleBlackNode,
										___olderYangerBrother(doubleBlackNode));
				}
			}

	template <class _T, class _Compare, class _Allocator>
		void	_tree<_T, _Compare, _Allocator>::
			___redRightChildBalancing(pointer_node doubleBlackNode,
										pair<olderYangerBro,
										typename _tree<_T, _Compare, _Allocator>
										::pointer_node> bro){
				if (!doubleBlackNode->previous->previous
						&& doubleBlackNode->isItNil){
					bro.second->nextRight->color = BLACK;
					_leftTurn(bro.second, bro.second->nextRight);
					___brotherParentChange(doubleBlackNode,
										___olderYangerBrother(doubleBlackNode));
				} else {
					doubleBlackNode->color = BLACK;
					bro.second->color = doubleBlackNode->previous->color;
					bro.second->nextRight->color = BLACK;
					doubleBlackNode->previous->color = BLACK;
					___brotherParentChange(doubleBlackNode, bro);
				}
			}

	template <class _T, class _Compare, class _Allocator>
		void	_tree<_T, _Compare, _Allocator>::
			___redBrotherBalancing(pointer_node doubleBlackNode,
									pair<olderYangerBro,
									typename _tree<_T, _Compare, _Allocator>
									::pointer_node> bro){
				___brotherParentChange(doubleBlackNode, bro);
				bro.second->color = BLACK;
				doubleBlackNode->previous->color = RED;
				__blackBalancing(doubleBlackNode);
			}

	template <class _T, class _Compare, class _Allocator>
		void	_tree<_T, _Compare, _Allocator>::
			___blackBrotherBalancing(pointer_node doubleBlackNode,
										pair<olderYangerBro,
										typename _tree<_T, _Compare, _Allocator>
										::pointer_node> bro){
				if (bro.second->nextLeft->color == BLACK
						&& bro.second->nextRight->color == BLACK){
					___blackChildrenBalancing(doubleBlackNode, bro);
				} else if (bro.second->nextLeft->color == RED) {
					___redLeftChildBalancing(doubleBlackNode, bro);
				} else {
					___redRightChildBalancing(doubleBlackNode, bro);
				}
			}

	template <class _T, class _Compare, class _Allocator>
		void	_tree<_T, _Compare, _Allocator>::
			__blackBalancing(pointer_node doubleBlackNode){
				typedef pair<olderYangerBro,
								typename _tree<_T, _Compare, _Allocator>
								::pointer_node>	_pair;

				_pair	bro(___olderYangerBrother(doubleBlackNode));

				// if (doubleBlackNode->value.first == 32){
				// 	std::cout << bro.second << std::endl;
				// 	return ;
				// }

				if (!doubleBlackNode->previous){
					doubleBlackNode->color = BLACK;
				} else if (bro.second->color == RED){
					___redBrotherBalancing(doubleBlackNode, bro);
				} else if (bro.second->color == BLACK){
					___blackBrotherBalancing(doubleBlackNode, bro);
				} else { return ; }

		}

	template <class _T, class _Compare, class _Allocator>
		void	_tree<_T, _Compare, _Allocator>::
			__deletedWithTwoGhildren(pointer_node deletedNode){
				pointer_node	leastRightChild;

				leastRightChild = ___findLeastRightChild(deletedNode->nextRight);
				___nodesValueChange(leastRightChild, deletedNode);

				_deleteOptions(leastRightChild);
		}

	template <class _T, class _Compare, class _Allocator>
		void	_tree<_T, _Compare, _Allocator>::
			__deletedWithOneChild(pointer_node deletedNode){
				if (deletedNode->nextRight->isItNil){
					___nodesValueChange(deletedNode->nextLeft, deletedNode);
					__deleteNode(deletedNode->nextLeft);
				} else {
					___nodesValueChange(deletedNode->nextRight, deletedNode);
					__deleteNode(deletedNode->nextRight);
				}
		}

	template <class _T, class _Compare, class _Allocator>
		void	_tree<_T, _Compare, _Allocator>::
			__deletedWithoutChildren(pointer_node deletedNode){
				if (deletedNode->color == RED){
					__deleteNode(deletedNode);
				} else {
					deletedNode->color = DOUBLE_BLACK;
					__deleteNode(deletedNode);
					__blackBalancing(deletedNode);

				}
		}

}
