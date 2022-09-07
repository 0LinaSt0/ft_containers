/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb_tree_insert.tpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:59:14 by marvin            #+#    #+#             */
/*   Updated: 2022/09/07 16:59:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft {

	/*returns:
		1. NULL - if newNode is root
		2. newNode - if grandded is root
		3. uncle - all other */
	template <class _T, class _Compare, class _Allocator>
		typename rb_tree<_T, _Compare, _Allocator>::pointer_node
			rb_tree<_T, _Compare, _Allocator>::
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
		void	rb_tree<_T, _Compare, _Allocator>::
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
		void	rb_tree<_T, _Compare, _Allocator>::
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
		void	rb_tree<_T, _Compare, _Allocator>::
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
		void	rb_tree<_T, _Compare, _Allocator>::
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
			void	rb_tree<_T, _Compare, _Allocator>::
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
}
