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

// #include "../containers.hpp"

// namespace ft {
// 	template <class _T, class _Compare, class _Allocator>
// 		void	_tree<_T, _Compare, _Allocator>::_redDad(pointer_node addedNode){
// 			pointer_node	uncle = _findUncle(addedNode);

// 			if (!uncle){ }
// 			else if (!(uncle->previous)) { addedNode->previous->color = 'b'; }
// 			else if (uncle->color == 'r') { _redUncle(uncle, addedNode); }
// 			else if (uncle->color == 'b') { _blackUncle(uncle, addedNode); }
// 			else { return ;}
// 		}
// 	template <class _T, class _Compare, class _Allocator>
// 		void	_tree<_T, _Compare, _Allocator>::_blackUncle(pointer_node uncle, pointer_node addedNode){
// 			uncle->previous->color = 'r';
// 			addedNode->previous->color = 'b';

// 			if (addedNode->value.first > uncle->previous->value.first){
// 				_leftTurn(uncle->previous, addedNode->previous);
// 			} else {
// 				_rightTurn(uncle->previous, addedNode->previous);
// 			}
// 			_redDad(addedNode);
// 		}

// 	template <class _T, class _Compare, class _Allocator>
// 		void	_tree<_T, _Compare, _Allocator>::_redUncle(pointer_node uncle, pointer_node addedNode){
// 			/*dad*/addedNode->previous->color = 'b';
// 			/*uncle*/uncle->color = 'b';
// 			/*grandded*/uncle->previous->color = 'r';
// 			if (uncle->previous->previous
// 				&& uncle->previous->previous->color == 'r'){
// 				_redDed(uncle->previous);
// 			}
// 		}
// }
