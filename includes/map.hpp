#ifndef MAP_HPP
#define MAP_HPP

#include "containers.hpp"

namespace ft{
	template < class _Key,										// map::key_type
		class _T,												// map::mapped_type
		class _Compare = std::less<_Key>,							// map::key_compare
		class _Alloc = std::allocator<ft::pair<const _Key,_T> >	// map::allocator_type
		> class map{
		public:
			typedef _Key										key_type;
			typedef	_T											mapped_type;
			typedef ft::pair<key_type, mapped_type>				value_type; // ???need const key but how if i want to do operator=???
			typedef _Compare									key_compare;
			typedef _Alloc										allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;

			class value_compare : public std::binary_function<value_type, value_type, bool>{
			public:
				friend class map<_Key, _T, _Compare, _Alloc>;
			protected:
				key_compare comp;

				value_compare (key_compare c) : comp(c) {}  // constructed with map's comparison object
			public:
				bool operator() (const value_type& x, const value_type& y) const
					{ return comp(x.first, y.first); }
			} ;
 		private:
			typedef _rb_tree<value_type, value_compare, allocator_type>	map_tree;
			typedef typename map_tree::pointer_node						ptr_node;

			map_tree		tree;
			allocator_type	mapAlloc;
			key_compare		mapCompare;
		public:
			typedef typename map_tree::size_type					size_type;
			typedef typename map_tree::iterator						iterator;
			typedef typename map_tree::const_iterator				const_iterator;
			typedef typename map_tree::reverse_iterator				reverse_iterator;
			typedef typename map_tree::const_reverse_iterator		const_reverse_iterator;

			explicit map (const key_compare& comp = key_compare(),
							const allocator_type& alloc = allocator_type())
				: tree(comp, alloc), mapAlloc(alloc), mapCompare(comp) {}
			template <class InputIterator>
				map (InputIterator first, InputIterator last,
						const key_compare& comp = key_compare(),
						const allocator_type& alloc = allocator_type())
					: tree(comp, alloc), mapAlloc(alloc), mapCompare(comp) {
					insert(first, last); }
			map (const map& x) : tree(x.tree) { operator=(x); }
			~map() { }

			map& operator= (const map& x){
				mapAlloc = x.mapAlloc;
				mapCompare = x.mapCompare;
				return *this;
			}

			mapped_type& operator[] (const key_type& k){
				ptr_node	desiredNode = tree.at(value_type(k, mapped_type()));

				return (!desiredNode) ? (*((insert(value_type(k, mapped_type()))).first)).second
										: desiredNode->value.second;
			}

			mapped_type& at (const key_type& k){
				ptr_node	desiredNode = tree.at(value_type(k, mapped_type()));

				if (!desiredNode)
					throw std::invalid_argument("libc++abi: terminating with uncaught exception of type std::out_of_range: map::at:  key not found");
				return desiredNode->value.second;
			}

			const mapped_type& at (const key_type& k) const{
				const ptr_node	desiredNode = tree.at(value_type(k, mapped_type()));

				if (!desiredNode)
					throw std::invalid_argument("libc++abi: terminating with uncaught exception of type std::out_of_range: map::at:  key not found");
				return (*desiredNode).second;
			}

			// Iterators: begin, end, rbegin, rend

			iterator begin(void) { return tree.begin(); }

			const_iterator begin(void) const { return tree.begin(); }

			iterator end(void) { return tree.end(); }

			const_iterator end(void) const { return tree.end(); }

			reverse_iterator rbegin(void) { return tree.rbegin(); }

			const_reverse_iterator rbegin(void) const { return tree.rbegin(); }

			reverse_iterator rend(void) { return tree.rend(); }

			const_reverse_iterator rend(void) const { return tree.rend(); }

			// Capacity: empty, size, max_size

			bool	empty(void) const { return tree.empty(); }

			size_type	size(void) const { return tree.size(); }

			size_type	max_size() const { return tree.max_size(); }

			// Modifiers: insert, erase, swap, clear

			pair<iterator,bool> insert (const value_type& val){
				return tree.insert(val); }

			iterator	insert(iterator position, const value_type& val){
				return tree.insert(position, val);
			}

			template <class InputIterator>
				void	insert(InputIterator first, InputIterator last){
					return tree.insert(first, last);
				}

			void	erase(iterator position) { return tree.erase(position); }

			size_type	erase(const key_type& k){
				return tree.erase(value_type(k, mapped_type()));
			}

			void	erase(iterator first, iterator last){
				return tree.erase(first, last);
			}

			void	swap (map& x){
				map	tmp(*this);

				*this = x;
				x = tmp;
			}

			void	clear(void) { tree.clear(); }

			// Observers: key_comp, value_comp

			key_compare	key_comp(void) const { return mapCompare; }

			value_compare	value_comp(void) const { return value_comp(mapCompare); }

			// Operators: find, count, lower_bound, upper_bound, equal_range

			iterator	find(const key_type& k) {
				return tree.find(value_type(k, mapped_type()));
			}

			const_iterator	find (const key_type& k) const{
				return (const_iterator)tree.find(value_type(k, mapped_type()));
			}

			size_type	count(const key_type& k) const{
				return tree.count(value_type(k, mapped_type()));
			}

			iterator	lower_bound(const key_type& k) {
				return tree.lower_bound(value_type(k, mapped_type()));
			}

			const_iterator	lower_bound(const key_type& k) const{
				return (const_iterator)tree.lower_bound(value_type(k, mapped_type()));
			}

			iterator	upper_bound(const key_type& k){
				return tree.upper_bound(value_type(k, mapped_type()));
			}

			const_iterator	upper_bound(const key_type& k) const{
				return (const_iterator)tree.upper_bound(value_type(k, mapped_type()));
			}

			pair<iterator,iterator>	equal_range(const key_type& k){
				return tree.equal_range(value_type(k, mapped_type()));
			}

			pair<const_iterator,const_iterator>	equal_range(const key_type& k) const{
				return (const_iterator)tree.equal_range(value_type(k, mapped_type()));
			}

			// Allocator

			allocator_type	get_allocator(void) const { return mapAlloc; }

		} ;

template < class map >
	void	printMapA(map& objct){
		std::cout << "Map_size:" << objct.size()
					<< "   ->   empty_fl:" << std::boolalpha << objct.empty()
					<< "   ->   max_size:" << objct.max_size()
					<< std::endl;
		for (typename map::iterator it(objct.begin());
					it != objct.end();
					it++){
			std::cout << ((*it).first) << "  ";
		}
		std::cout << std::endl;
	}


	template <class Key, class T, class Compare, class Alloc>
		bool operator== (const map<Key, T, Compare, Alloc>& lhs,
					const map<Key, T, Compare, Alloc>& rhs){
			if (lhs.empty() && rhs.empty()) return true;
			else if (lhs.empty() || rhs.empty()) return false;
			return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
		}

	template <class Key, class T, class Compare, class Alloc>
		bool operator!=(const map<Key, T, Compare, Alloc>& lhs,
					const map<Key, T, Compare, Alloc>& rhs){
			if (lhs.empty() && rhs.empty()) return false;
			else if (lhs.empty() || rhs.empty()) return true;
			return ft::equal(lhs.begin(), lhs.end(), rhs.begin()) ? 0 : 1;
		}

	template <class Key, class T, class Compare, class Alloc>
		bool operator< (const map<Key, T, Compare, Alloc>& lhs,
					const map<Key, T, Compare, Alloc>& rhs){
			if (lhs.empty() && rhs.empty()) return false;
			else if (lhs.empty() && !rhs.empty()) return true;
			else if (!lhs.empty() && rhs.empty()) return false;
			return ft::equal(lhs.begin(), lhs.end(), rhs.begin(),
								ft::_lessCheck<map, map>);
		}

	template <class Key, class T, class Compare, class Alloc>
		bool operator<=(const map<Key, T, Compare, Alloc>& lhs,
					const map<Key, T, Compare, Alloc>& rhs){
			if (lhs.empty() && rhs.empty()) return true;
			else if (lhs.empty() && !rhs.empty()) return true;
			else if (!lhs.empty() && rhs.empty()) return false;
			return ft::equal(lhs.begin(), lhs.end(), rhs.begin(),
								ft::_equalLessCheck<map, map>);
		}

	template <class Key, class T, class Compare, class Alloc>
		bool operator>(const map<Key, T, Compare, Alloc>& lhs,
					const map<Key, T, Compare, Alloc>& rhs){
			if (lhs.empty() && rhs.empty()) return false;
			else if (lhs.empty() && !rhs.empty()) return false;
			else if (!lhs.empty() && rhs.empty()) return true;
			return ft::equal(lhs.begin(), lhs.end(), rhs.begin(),
								ft::_moreCheck<map, map>);
		}

	template <class Key, class T, class Compare, class Alloc>
		bool operator>=(const map<Key, T, Compare, Alloc>& lhs,
					const map<Key, T, Compare, Alloc>& rhs){
			if (lhs.empty() && rhs.empty()) return true;
			else if (lhs.empty() && !rhs.empty()) return false;
			else if (!lhs.empty() && rhs.empty()) return true;
			return ft::equal(lhs.begin(), lhs.end(), rhs.begin(),
								ft::_equalMoreCheck<map, map>);
		}

	template <class Key, class T, class Compare, class Alloc>
		void swap( std::map<Key,T,Compare,Alloc>& lhs,
				std::map<Key,T,Compare,Alloc>& rhs ){
			lhs.swap(rhs);
		}
}

#endif
