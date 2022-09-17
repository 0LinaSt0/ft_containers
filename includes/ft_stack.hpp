/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:05:32 by marvin            #+#    #+#             */
/*   Updated: 2022/09/17 23:01:30 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include "ft_containers.hpp"
#include "ft_vector.hpp"

namespace ft{
	template <class _T, class Container = ft::vector<_T> >
	class stack{
		template <class tp, class Cntnr>
			friend bool	operator==(const stack<tp,Cntnr>& lhs, const stack<tp,Cntnr>& rhs);

		template <class tp, class Cntnr>
			friend bool	operator!=(const stack<tp,Cntnr>& lhs, const stack<tp,Cntnr>& rhs);

		template <class tp, class Cntnr>
			friend bool	operator<(const stack<tp,Cntnr>& lhs, const stack<tp,Cntnr>& rhs);

		template <class tp, class Cntnr>
			friend bool	operator<=(const stack<tp,Cntnr>& lhs, const stack<tp,Cntnr>& rhs);

		template <class tp, class Cntnr>
			friend bool	operator>(const stack<tp,Cntnr>& lhs, const stack<tp,Cntnr>& rhs);

		template <class tp, class Cntnr>
			friend bool	operator>=(const stack<tp,Cntnr>& lhs, const stack<tp,Cntnr>& rhs);

	public:
		typedef _T								value_type;
		typedef Container						container_type;
		typedef typename Container::size_type	size_type;
	protected:
		container_type	ctnr;
	public:
		explicit stack(const container_type& ctnr = container_type())
						: ctnr(ctnr){}
		stack(const stack& other){
			ctnr = other.ctnr;
		}
		~stack(void) { }

		stack& operator=( const stack& other ){
			ctnr = other.ctnr;
			return *this; 
		}

		bool	empty() const { return ctnr.empty(); }

		size_type	size() const { return ctnr.size(); }

		value_type&	top() { return ctnr.back(); }
		const value_type&	top() const { return ctnr.back(); }

		void	push (const value_type& val) { ctnr.push_back(val); }

		void	pop() { ctnr.pop_back(); }
	} ;

	template <class _T, class Container>
	bool	operator==(const stack<_T,Container>& lhs, const stack<_T,Container>& rhs)
		{ return lhs.ctnr == rhs.ctnr; }

	template <class _T, class Container>
	bool	operator!=(const stack<_T,Container>& lhs, const stack<_T,Container>& rhs)
		{ return lhs.ctnr != rhs.ctnr; }

	template <class _T, class Container>
	bool	operator<(const stack<_T,Container>& lhs, const stack<_T,Container>& rhs)
		{ return lhs.ctnr < rhs.ctnr; }

	template <class _T, class Container>
	bool	operator<=(const stack<_T,Container>& lhs, const stack<_T,Container>& rhs)
		{ return lhs.ctnr <= rhs.ctnr; }

	template <class _T, class Container>
	bool	operator>(const stack<_T,Container>& lhs, const stack<_T,Container>& rhs)
		{ return lhs.ctnr > rhs.ctnr; }

	template <class _T, class Container>
	bool	operator>=(const stack<_T,Container>& lhs, const stack<_T,Container>& rhs)
		{ return lhs.ctnr >= rhs.ctnr; }
}

#endif
