/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:05:32 by marvin            #+#    #+#             */
/*   Updated: 2022/07/18 14:05:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include "containers.hpp"

namespace ft{
	template <class T, class Container = std::deque<T> >
	class stack{
	public:
		typedef T								value_type;
		typedef Container						container_type;
		typedef typename Container::size_type	size_type;
	protected:
		container_type	ctnr;
	public:
		explicit stack(const container_type& ctnr = container_type())
						: ctnr(ctnr){}
		~stack();

		bool	empty() const { return ctnr.empty(); }

		size_type	size() const { return ctnr.size(); }

		value_type&	top() { return ctnr.back(); }
		const value_type&	top() const { return ctnr.back(); }

		void	push (const value_type& val) { ctnr.push_back(val); }

		void	pop() { ctnr.pop_back(); }
	} ;

	template <class T, class Container>
	bool	operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
		{ return lhs.ctnr == rhs.ctnr; }

	template <class T, class Container>
	bool	operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
		{ return lhs.ctnr != rhs.ctnr; }

	template <class T, class Container>
	bool	operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
		{ return lhs.ctnr < rhs.ctnr; }

	template <class T, class Container>
	bool	operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
		{ return lhs.ctnr <= rhs.ctnr; }

	template <class T, class Container>
	bool	operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
		{ return lhs.ctnr > rhs.ctnr; }

	template <class T, class Container>
	bool	operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
		{ return lhs.ctnr >= rhs.ctnr; }
}

#endif
