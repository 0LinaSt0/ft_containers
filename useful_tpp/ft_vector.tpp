/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.tpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:22:01 by marvin            #+#    #+#             */
/*   Updated: 2022/09/07 16:22:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft{
	template < class _T, class _Alloc>
	// Just change size of "capacitySize" variable
		void	vector<_T, _Alloc>::
				_capacityUpdate(typename vector<_T, _Alloc>::size_type amountCapacity){
			if (capacitySize == 0){
				capacitySize = amountCapacity;
			} else if (capacitySize < amountCapacity) {
				if ((capacitySize * 2) < amountCapacity){
					capacitySize = amountCapacity;
				} else {
					capacitySize *= 2;
				}
			}
		}

	template < class _T, class _Alloc>
	/* 	1) destruct needing element (DoIDeallocate - false)
		2) destruct and deallocate vec
			(DoIDeallocate - true, freeElems - how much deallocate)*/
		void	vector<_T, _Alloc>::
				_freeMemory(bool DoIDeallocate,
							typename vector<_T, _Alloc>::size_type freeElems){
		for (size_type i = 0; i < countElem; i++){
				vecAlloc.destroy(vec + i);
		}
		if (DoIDeallocate){
				vecAlloc.deallocate(vec, freeElems);
		}
	}

	template < class _T, class _Alloc >
	template < class InputIterator >
	/* Counts distance between two iterators and returns size of the distance */
		typename vector<_T, _Alloc>::size_type
			vector<_T, _Alloc>::
			_sizeItersDistance(InputIterator first, InputIterator last){
			size_type	distance = 0;

			while (first != last){
					distance++;
					first++;
				}
			return (distance);
		}

	template < class _T, class _Alloc >
	template < class InputIterator >
	/* Writes in 'container' value from begin_vector to 'posititon' iterators
		or from 'position' to end_vector. It depends on whichPartFl.
		'whichPartFl' flag could be:
			- 'b' if needs put first part of vector to containter
			- 'e' if needs put last part of vector to containter */
		void	vector<_T, _Alloc>::
				_writeValue(InputIterator &container, InputIterator position,
								char whichPartFl){
			if (whichPartFl == 'b') {
				for (InputIterator vecBeging(begin());
						vecBeging != position;
						vecBeging++, container++){
					(*container) = (*vecBeging);
				}
			} else if (whichPartFl == 'e') {
				for (InputIterator vecEnd(end());
						position != vecEnd;
						position++, container++){
					(*container) = (*position);
				}
			} else { }
		}
}
