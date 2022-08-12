#ifndef MAP_HPP
#define MAP_HPP

#include "containers.hpp"

namespace ft{
	template < class Key,										// map::key_type
		class T,												// map::mapped_type
		class Compare = std::less<Key>,							// map::key_compare
		class Alloc = std::allocator<ft::pair<const Key,T> >	// map::allocator_type
		> class map{
		public:
			typedef Key											key_type;
			typedef	T											mapped_type;
			typedef ft::pair<const key_type, mapped_type>		value_type;
			typedef Compare										key_compare;
			//WAT IS THIS -> typedef ...		value_compare;
			typedef Alloc										allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
 		private:
			_rb_tree<		tree;
			allocator_type	treeAlloc;
			key_compare		treeCompare;
		public:
			explicit map (const key_compare& comp = key_compare(),
							const allocator_type& alloc = allocator_type())
					: treeCompare(comp), treeAlloc(alloc) {}
			template <class InputIterator>
				map (InputIterator first, InputIterator last,
						const key_compare& comp = key_compare(),
						const allocator_type& alloc = allocator_type())
					: treeCompare(comp), treeAlloc(alloc) {

				}
			map (const map& x);
			~map();

			map& operator= (const map& x);
		} ;
}

#endif
