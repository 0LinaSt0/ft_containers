/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:02:57 by marvin            #+#    #+#             */
/*   Updated: 2022/08/31 22:19:16 by msalena          ###   ########.fr       */
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
		typename _rb_tree<_T, _Compare, _Allocator>::pointer_node
			_rb_tree<_T, _Compare, _Allocator>::
			__findUncle(pointer_node newNode){
				if (newNode->previous){
					if (newNode->previous->previous){
						if (newNode->previous->previous->nextLeft != newNode->previous){
							return (newNode->previous->previous->nextLeft);
						} else {
							return (newNode->previous->previous->nextRight);
						}
					} else { return newNode; }
				} else { return NULL; }
			}

	template <class _T, class _Compare, class _Allocator>
		void	_rb_tree<_T, _Compare, _Allocator>::
				___updateNodesPointers(pointer_node oldNode,
										pointer_node newNode){
			if (oldNode->previous) {
				if (oldNode->previous->nextLeft != oldNode) {
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
		void	_rb_tree<_T, _Compare, _Allocator>::
				___nodeMoreGranddad(pointer_node uncle,
										pointer_node errorNode){
			if (errorNode != errorNode->previous->nextRight){
				_rightTurn(errorNode->previous, errorNode);
				_leftTurn(uncle->previous, errorNode);
				errorNode->color = BLACK;
			} else {
				_leftTurn(uncle->previous, errorNode->previous);
				errorNode->previous->color = BLACK;
			}
		}

	template <class _T, class _Compare, class _Allocator>
		void	_rb_tree<_T, _Compare, _Allocator>::
				___nodeLessGranddad(pointer_node uncle,
										pointer_node errorNode){
			if (errorNode != errorNode->previous->nextLeft){
				_leftTurn(errorNode->previous, errorNode);
				_rightTurn(uncle->previous, errorNode);
				errorNode->color = BLACK;
			} else {
				_rightTurn(uncle->previous, errorNode->previous);
				errorNode->previous->color = BLACK;
			}
		}

	template <class _T, class _Compare, class _Allocator>
		void	_rb_tree<_T, _Compare, _Allocator>::
				__blackUncle(pointer_node uncle,
								pointer_node addedNode){

			if (uncle->previous->nextLeft != addedNode->previous){
				___nodeMoreGranddad(uncle, addedNode);
			} else {
				___nodeLessGranddad(uncle, addedNode);
			}
			uncle->previous->color = RED;


		}

	template <class _T, class _Compare, class _Allocator>
			void	_rb_tree<_T, _Compare, _Allocator>::
					__redUncle(pointer_node uncle,
									pointer_node addedNode){
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
		typename _rb_tree<_T, _Compare, _Allocator>::pointer_node
			_rb_tree<_T, _Compare, _Allocator>::
			___findLeastRightChild(pointer_node currentNode){
				return ((currentNode->nextLeft->isItNil)
							? currentNode
							: ___findLeastRightChild(currentNode->nextLeft));
		}

	template <class _T, class _Compare, class _Allocator>
		void	_rb_tree<_T, _Compare, _Allocator>::
			__deleteNode(pointer_node deletedNode){
				_freeNode(deletedNode->nextRight);
				_freeNode(deletedNode->nextLeft);
				deletedNode->nextRight = NULL;
				deletedNode->nextLeft = NULL;
				deletedNode->color = BLACK;
				deletedNode->isItNil = true;
		}

	template <class _T, class _Compare, class _Allocator>
		void	_rb_tree<_T, _Compare, _Allocator>::
			___pointersSwap(pointer_node& to,
								pointer_node& from){
			pointer_node	tmp = to;

			to = from; from = tmp;
		}
	template <class _T, class _Compare, class _Allocator>
		void	_rb_tree<_T, _Compare, _Allocator>::
				____childrenParentSwap(pointer_node finded,
											pointer_node deleted,
											bool isNodeNeigbours){
			bool	deletedLessFinded
				= compare(deleted->value, finded->value);

			/*left children parents swap*/
			finded->nextLeft->previous = deleted;
			if (deletedLessFinded || !isNodeNeigbours){
				deleted->nextLeft->previous = finded;
			}
			/*right children parents swap*/
			finded->nextRight->previous = deleted;
			if (!deletedLessFinded || !isNodeNeigbours){
				deleted->nextRight->previous = finded;
			}
		}

	template <class _T, class _Compare, class _Allocator>
		void	_rb_tree<_T, _Compare, _Allocator>::
				____childrenSwap(pointer_node finded,
									pointer_node deleted,
									bool isNodeNeigbours){
			bool	deletedLessFinded
						= compare(deleted->value, finded->value);

			/*left children swap*/
			if (deletedLessFinded || !isNodeNeigbours){
				___pointersSwap(deleted->nextLeft, finded->nextLeft);
			} else {
				deleted->nextLeft = finded->nextLeft;
				finded->nextLeft = deleted;
			}
			/*right children swap*/
			if (!deletedLessFinded || !isNodeNeigbours){
				___pointersSwap(deleted->nextRight, finded->nextRight);
			} else {
				deleted->nextRight = finded->nextRight;
				finded->nextRight = deleted;
			}
		}

	template <class _T, class _Compare, class _Allocator>
		void	_rb_tree<_T, _Compare, _Allocator>::
				____parentChildrenSwap(pointer_node finded,
										pointer_node deleted,
										bool isNodeNeigbours){
			/*parents children swap*/
			if (deleted->previous){
				if (deleted != deleted->previous->nextRight)
						deleted->previous->nextLeft = finded;
				else { deleted->previous->nextRight = finded;}
			}
			if (!isNodeNeigbours){
				(finded != finded->previous->nextRight)
					? finded->previous->nextLeft = deleted
					: finded->previous->nextRight = deleted;
			}
		}

	template <class _T, class _Compare, class _Allocator>
		void	_rb_tree<_T, _Compare, _Allocator>::
				____parentsSwap(pointer_node finded,
									pointer_node deleted,
									bool isNodeNeigbours){
			/*parents swap*/
			if (isNodeNeigbours){
				finded->previous = deleted->previous;
				deleted->previous = finded;
			} else {
				___pointersSwap(deleted->previous, finded->previous); }
		}

	template <class _T, class _Compare, class _Allocator>
			void	_rb_tree<_T, _Compare, _Allocator>::
				____optionsSwap(pointer_node finded,
									pointer_node deleted,
									bool isNodeNeigbours){
		____childrenParentSwap(finded, deleted, isNodeNeigbours);
		____childrenSwap(finded, deleted, isNodeNeigbours);
		____parentChildrenSwap(finded, deleted, isNodeNeigbours);
		____parentsSwap(finded, deleted, isNodeNeigbours);
		if (!finded->previous) { node = &(*finded); }
	}

	template <class _T, class _Compare, class _Allocator>
		bool	_rb_tree<_T, _Compare, _Allocator>::
			____isNodeNeigboursSwap(pointer_node finded,
									pointer_node deleted){
			if ((!compare(deleted->nextRight->value, finded->value)
					&& !compare(finded->value, deleted->nextRight->value))
					|| (!compare(deleted->nextLeft->value, finded->value)
					&& !compare(finded->value, deleted->nextLeft->value)))
				return true;
			else { return false; }
		}

	template <class _T, class _Compare, class _Allocator>
		void	_rb_tree<_T, _Compare, _Allocator>::
			___nodesSwap(pointer_node finded,
							pointer_node deleted){
			nodeColor	tmpColor = deleted->color;

			deleted->color = finded->color;
			finded->color = tmpColor;

			____optionsSwap(finded, deleted,
								____isNodeNeigboursSwap(finded, deleted));
		}

	template <class _T, class _Compare, class _Allocator>
		void	_rb_tree<_T, _Compare, _Allocator>::
			___brotherParentChange(pointer_node doubleBlackNode,
										ft::pair<olderYangerBro,
										typename _rb_tree<_T, _Compare, _Allocator>
										::pointer_node> bro){
				if (bro.first == OLDER){
					_leftTurn(doubleBlackNode->previous, bro.second);
				} else {
					_rightTurn(doubleBlackNode->previous, bro.second);
				}
			}

	template <class _T, class _Compare, class _Allocator>
		ft::pair<olderYangerBro, typename _rb_tree<_T, _Compare, _Allocator>::pointer_node>
			_rb_tree<_T, _Compare, _Allocator>::
			___olderYangerBrother(pointer_node doubleBlackNode){
				typedef ft::pair<olderYangerBro,
								typename _rb_tree<_T, _Compare, _Allocator>
								::pointer_node>	__pair;

				if (doubleBlackNode->previous){
					if (doubleBlackNode->previous->nextRight != doubleBlackNode)
						{ return __pair(OLDER, doubleBlackNode->previous->nextRight); }
					return __pair(YANGER, doubleBlackNode->previous->nextLeft);
				}
				return __pair(NONE, NULL);
			}

	template <class _T, class _Compare, class _Allocator>
		void	_rb_tree<_T, _Compare, _Allocator>::
			___yangerBrotherBalancing(pointer_node doubleBlackNode,
										ft::pair<olderYangerBro,
										typename _rb_tree<_T, _Compare, _Allocator>
										::pointer_node> bro){
				doubleBlackNode->color = BLACK;
				bro.second->color = BLACK;
				if (bro.second->previous->color == RED){
					bro.second->nextLeft->color = RED;
					// bro.second->previous->color = RED; !maybe return this string!
				} else {
					bro.second->previous->color = BLACK;
					bro.second->nextLeft->color = BLACK;
				}
				_rightTurn(bro.second->previous, bro.second);
			}

	template <class _T, class _Compare, class _Allocator>
		void	_rb_tree<_T, _Compare, _Allocator>::
			___blackChildrenBalancing(pointer_node doubleBlackNode,
										ft::pair<olderYangerBro,
										typename _rb_tree<_T, _Compare, _Allocator>
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
		void	_rb_tree<_T, _Compare, _Allocator>::
			___redLeftChildBalancing(pointer_node doubleBlackNode,
										ft::pair<olderYangerBro,
										typename _rb_tree<_T, _Compare, _Allocator>
										::pointer_node> bro){
				// if (!doubleBlackNode->previous->previous
				// 		&& doubleBlackNode->isItNil){
				// 	___brotherParentChange(doubleBlackNode, bro);
				// 	bro.second->nextLeft->color = BLACK;
				// } else
				if (bro.first == YANGER){
					___yangerBrotherBalancing(doubleBlackNode, bro);
				} else {
					bro.second->color = RED;
					bro.second->nextLeft->color = BLACK;

					_rightTurn(bro.second, bro.second->nextLeft);
					// ___olderYangerBrother(doubleBlackNode);
					// if(bro.second->value.first == 38) { _print_node(bro.second); }
					___redRightChildBalancing(doubleBlackNode,
										___olderYangerBrother(doubleBlackNode));
				}
			}

	template <class _T, class _Compare, class _Allocator>
		void	_rb_tree<_T, _Compare, _Allocator>::
			___redRightChildBalancing(pointer_node doubleBlackNode,
										ft::pair<olderYangerBro,
										typename _rb_tree<_T, _Compare, _Allocator>
										::pointer_node> bro){
				// if (!doubleBlackNode->previous->previous
				// 		&& doubleBlackNode->isItNil){
				// 	bro.second->nextRight->color = BLACK;
				// 	_leftTurn(bro.second, bro.second->nextRight);
				// 	___brotherParentChange(doubleBlackNode,
				// 						___olderYangerBrother(doubleBlackNode));
				// } else
				if (bro.first == YANGER) {
					_leftTurn(bro.second, bro.second->nextRight);
					___yangerBrotherBalancing(doubleBlackNode,
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
		void	_rb_tree<_T, _Compare, _Allocator>::
			___redBrotherBalancing(pointer_node doubleBlackNode,
									ft::pair<olderYangerBro,
									typename _rb_tree<_T, _Compare, _Allocator>
									::pointer_node> bro){
				___brotherParentChange(doubleBlackNode, bro);
				bro.second->color = BLACK;
				doubleBlackNode->previous->color = RED;
				__blackBalancing(doubleBlackNode);
			}

	template <class _T, class _Compare, class _Allocator>
		void	_rb_tree<_T, _Compare, _Allocator>::
			___blackBrotherBalancing(pointer_node doubleBlackNode,
										ft::pair<olderYangerBro,
										typename _rb_tree<_T, _Compare, _Allocator>
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
		void	_rb_tree<_T, _Compare, _Allocator>::
			__blackBalancing(pointer_node doubleBlackNode){
				typedef ft::pair<olderYangerBro,
								typename _rb_tree<_T, _Compare, _Allocator>
								::pointer_node>	__pair;

				__pair	bro(___olderYangerBrother(doubleBlackNode));

				if (!doubleBlackNode->previous){
					doubleBlackNode->color = BLACK;
				} else if (bro.second->color == RED){
					___redBrotherBalancing(doubleBlackNode, bro);
				} else if (bro.second->color == BLACK){
					___blackBrotherBalancing(doubleBlackNode, bro);
				} else { return ; }

		}

	template <class _T, class _Compare, class _Allocator>
		void	_rb_tree<_T, _Compare, _Allocator>::
			__deletedWithTwoGhildren(pointer_node deletedNode){
				pointer_node	leastRightChild;

				leastRightChild = ___findLeastRightChild(deletedNode->nextRight);

				___nodesSwap(leastRightChild, deletedNode);
				_deleteOptions(deletedNode);
		}

	template <class _T, class _Compare, class _Allocator>
		void	_rb_tree<_T, _Compare, _Allocator>::
			__deletedWithOneChild(pointer_node deletedNode){

				if (deletedNode->nextRight->isItNil){
					deletedNode->nextLeft->color = deletedNode->color;
					_rightTurn(deletedNode, deletedNode->nextLeft);
					__deleteNode(deletedNode);
				} else {
					deletedNode->nextRight->color = deletedNode->color;
					_leftTurn(deletedNode, deletedNode->nextRight);
					__deleteNode(deletedNode);
				}
		}

	template <class _T, class _Compare, class _Allocator>
		void	_rb_tree<_T, _Compare, _Allocator>::
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
