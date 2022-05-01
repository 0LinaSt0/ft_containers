/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vercot_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 21:44:46 by msalena           #+#    #+#             */
/*   Updated: 2022/05/01 07:35:19 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

namespace ft{
	template < class Tp >
	struct iterator_traits {
		typedef ptrdiff_t 						difference_type;
		typedef Tp								value_type;
		typedef Tp*								pointer;
		typedef Tp&								reference;
		typedef std::random_access_iterator_tag	iterator_category;
	};

	
}

#endif