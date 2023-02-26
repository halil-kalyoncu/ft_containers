/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:01:01 by hkalyonc          #+#    #+#             */
/*   Updated: 2023/02/21 15:48:04 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "pair.hpp"
#include "RedBlackTree.hpp"
#include "bidirectional_iterator.hpp"
#include "reverse_iterator.hpp"
#include "equal.hpp"
#include "lexicographical_compare.hpp"
#include "iterator_traits.hpp"

//allocator
#include <memory>
//less, binary_function
#include <functional>
//out_of_range
#include <stdexcept>

/*

	map	synopsis

template<typename Key, typename T, typename Compare = std::less<Key>, typename Alloc = std::allocator<ft::pair<const Key, T> > >
	class map
	{
	public:
		typedef Key																				key_type;
		typedef T																				mapped_type;
		typedef typename ft::pair<const Key, mapped_type>										value_type;
		typedef Compare																			key_compare;
		typedef Alloc																			allocator_type;
		typedef typename allocator_type::reference												reference;
		typedef typename allocator_type::const_reference										const_reference;
		typedef typename allocator_type::pointer												pointer;
		typedef typename allocator_type::const_pointer											const_pointer;
		typedef ft::bidirectional_iterator<ft::RbtNode<value_type, Alloc>, value_type>			iterator;
		typedef ft::bidirectional_iterator<ft::RbtNode<value_type, Alloc>, const value_type>	const_iterator;
		typedef typename ft::reverse_iterator<iterator>											reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator>									const_reverse_iterator;
		typedef typename iterator_traits<iterator>::difference_type								difference_type;
		typedef typename allocator_type::size_type												size_type;

		class value_compare : public std::binary_function<value_type, value_type, bool>
		{
			friend class		map;
		public:
			typedef bool		result_type;
			typedef value_type	first_argument_type;
			typedef value_type	second_argument_type;

			value_compare(const ft::map<Key, T, Compare, Alloc>::value_compare& copy);
			~value_compare(void);

			ft::map<Key, T, Compare, Alloc>::value_compare&	operator=(const ft::map<Key, T, Compare, Alloc>::value_compare& rhs);

			bool				operator()(const value_type& x, const value_type& y) const;

		protected:
			Compare				comp;

			value_compare(Compare c);

		private:
			value_compare(void);
		};

		explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
		template<typename InputIterator>
		map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
		map(const map& copy);
		~map(void);
		ft::map<Key, T, Compare, Alloc>&		operator=(const ft::map<Key, T, Compare, Alloc>& rhs);

		iterator								begin(void);
		const_iterator							begin(void) const;
		iterator								end(void);
		const_iterator							end(void) const;
		reverse_iterator						rbegin(void);
		const_reverse_iterator					rbegin(void) const;
		reverse_iterator						rend(void);
		const_reverse_iterator					rend(void) const;

		bool									empty(void) const;
		size_type								size(void) const;
		size_type								max_size(void) const;

		mapped_type&							operator[](const key_type& k);
		mapped_type&							at(const key_type& k);
		const mapped_type&						at(const key_type& k) const;

		ft::pair<iterator, bool>				insert(const value_type& val);

		iterator								insert(iterator position, const value_type& val);
		template <typename InputIterator>
		void									insert(InputIterator first, InputIterator last);
		size_type								erase(const key_type& k);
		void									erase(iterator position);
		void									erase(iterator first, iterator last);
		void									swap(ft::map<Key, T, Compare, Alloc>& x);
		void									clear(void);

		key_compare								key_comp(void) const;
		value_compare							value_comp(void) const;

		iterator								find(const key_type& k);
		const_iterator							find(const key_type& k) const;
		size_type								count(const key_type& k) const;
		iterator								lower_bound(const key_type& k);
		const_iterator							lower_bound(const key_type& k) const;
		iterator								upper_bound(const key_type& k);
		const_iterator							upper_bound(const key_type& k) const;
		ft::pair<const_iterator,const_iterator>	equal_range(const key_type& k) const;
		ft::pair<iterator,iterator>				equal_range(const key_type& k);

		allocator_type							get_allocator(void) const;

	private:
		typedef ft::RedBlackTree<value_type, ft::map<Key, T, Compare, Alloc>::value_compare,
			Alloc>								_treeType;

		_treeType*								_tree;
		size_type								_size;
		allocator_type							_alloc;
	};

	template<typename Key, typename T, typename Compare, typename Alloc>
	bool										operator==(const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs);
	template<typename Key, typename T, typename Compare, typename Alloc>
	bool										operator!=(const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs);
	template<typename Key, typename T, typename Compare, typename Alloc>
	bool										operator<(const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs);
	template<typename Key, typename T, typename Compare, typename Alloc>
	bool										operator<=(const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs);
	template<typename Key, typename T, typename Compare, typename Alloc>
	bool										operator>(const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs);
	template<typename Key, typename T, typename Compare, typename Alloc>
	bool										operator>=(const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs);

	template<typename Key, typename T, typename Compare, typename Alloc>
	void										swap(ft::map<Key,T,Compare,Alloc>& lhs, ft::map<Key,T,Compare,Alloc>& rhs);

*/

namespace ft
{
	template<typename Key, typename T, typename Compare = std::less<Key>,
		typename Alloc = std::allocator<ft::pair<const Key, T> > >
	class map
	{
	public:
		typedef Key																				key_type;
		typedef T																				mapped_type;
		typedef typename ft::pair<const Key, mapped_type>										value_type;
		typedef Compare																			key_compare;
		typedef Alloc																			allocator_type;
		typedef typename allocator_type::reference												reference;
		typedef typename allocator_type::const_reference										const_reference;
		typedef typename allocator_type::pointer												pointer;
		typedef typename allocator_type::const_pointer											const_pointer;
		typedef ft::bidirectional_iterator<ft::RbtNode<value_type, Alloc>, value_type>			iterator;
		typedef ft::bidirectional_iterator<ft::RbtNode<value_type, Alloc>, const value_type>	const_iterator;
		typedef typename ft::reverse_iterator<iterator>											reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator>									const_reverse_iterator;
		typedef typename iterator_traits<iterator>::difference_type								difference_type;
		typedef typename allocator_type::size_type												size_type;

		class value_compare : public std::binary_function<value_type, value_type, bool>
		{
			friend class	map;
		public:
			typedef bool		result_type;
			typedef value_type	first_argument_type;
			typedef value_type	second_argument_type;

			value_compare(const ft::map<Key, T, Compare, Alloc>::value_compare& copy) :
				comp(copy.comp)
			{
				return ;
			}

			~value_compare(void)
			{
				return ;
			}

			ft::map<Key, T, Compare, Alloc>::value_compare&	operator=(
				const ft::map<Key, T, Compare, Alloc>::value_compare& rhs)
			{
				if (this != &rhs) {
					this->comp = rhs.comp;
				}
				return (*this);
			}

			bool	operator()(const value_type& x, const value_type& y) const
			{
				return (this->comp(x.first, y.first));
			}

		protected:
			Compare	comp;

			value_compare(Compare c) : comp(c)
			{
				return ;
			}

		private:
			value_compare(void) : comp(Compare())
			{
				return ;
			}
		};

		explicit map(const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()) :
				_tree(new _treeType(ft::map<Key, T, Compare, Alloc>::value_compare(comp))),
				_size(0), _alloc(alloc)
		{
			return ;
		}

		template<typename InputIterator>
		map(InputIterator first, InputIterator last,
			const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()) :
				_tree(new _treeType(ft::map<Key, T, Compare, Alloc>::value_compare(comp))),
				_size(0), _alloc(alloc)
		{
			while (first != last) {
				this->_tree->insertNode(*first);
				this->_size++;
				first++;
			}
			return ;
		}

		map(const map& copy) : _tree(new _treeType(*(copy._tree))),
			_size(copy._size), _alloc(copy._alloc)
		{
			return ;
		}

		~map(void)
		{
			delete this->_tree;
			return ;
		}

		ft::map<Key, T, Compare, Alloc>&	operator=(const ft::map<Key, T, Compare, Alloc>& rhs)
		{
			if (this != &rhs) {
				delete this->_tree;
				this->_tree = new _treeType(*(rhs._tree));
				this->_size = rhs._size;
			}
			return (*this);
		}

		iterator	begin(void)
		{
			return (iterator(this->_tree->getFirstNode()));
		}

		const_iterator	begin(void) const
		{
			return (const_iterator(this->_tree->getFirstNode()));
		}

		iterator	end(void)
		{
			return (iterator(this->_tree->getEnd()));
		}

		const_iterator	end(void) const
		{
			return (const_iterator(this->_tree->getEnd()));
		}

		reverse_iterator	rbegin(void)
		{
			return (reverse_iterator(this->end()));
		}

		const_reverse_iterator	rbegin(void) const
		{
			return (const_reverse_iterator(this->end()));
		}

		reverse_iterator	rend(void)
		{
			return (reverse_iterator(this->begin()));
		}

		const_reverse_iterator	rend(void) const
		{
			return (const_reverse_iterator(this->begin()));
		}

		bool	empty(void) const
		{
			return (this->_size == 0);
		}

		size_type	size(void) const
		{
			return (this->_size);
		}

		size_type	max_size(void) const
		{
			return (this->_alloc.max_size());
		}

		mapped_type&	operator[](const key_type& k)
		{
			ft::pair<const key_type, mapped_type>	object = ft::make_pair<const key_type, mapped_type>(k, mapped_type());
			ft::pair<iterator, bool>				insert_result = this->insert(object);

			return ((*insert_result.first).second);
		}

		mapped_type&	at(const key_type& k)
		{
			iterator	it = this->find(k);

			if (it == this->end()) {
				throw std::out_of_range("map::at:  key not found");
			}
			return (it->second);
		}

		const mapped_type&	at(const key_type& k) const
		{
			iterator	it = this->find(k);

			if (it == this->end()) {
				throw std::out_of_range("map::at:  key not found");
			}
			return (it->second);
		}

		ft::pair<iterator, bool>	insert(const value_type& val)
		{
			ft::pair<iterator, bool>	result;
			iterator					it = this->find(val.first);

			if (it != this->end()) {
				result.first = it;
				result.second = false;
			}
			else {
				result.first = iterator(this->_tree->insertNode(val));
				result.second = true;
				this->_size++;
			}
			return (result);
		}

		iterator	insert(iterator position, const value_type& val)
		{
			ft::pair<iterator, bool>	insert_pair = this->insert(val);

			return (insert_pair.first);
			(void) position;
		}
		
		template <typename InputIterator>
		void	insert(InputIterator first, InputIterator last)
		{
			while (first != last) {
				this->insert(*first);
				first++;
			}
		}

		size_type	erase(const key_type& k)
		{
			value_type	node = ft::make_pair<const key_type, mapped_type>(k, mapped_type());

			if (this->_tree->deleteNode(node) == false) {
				return (0);
			}
			this->_size--;
			return (1);
		}

		void	erase(iterator position)
		{
			this->erase(position->first);
			return ;
		}

		void	erase(iterator first, iterator last)
		{
			key_type	current_key;

			while (first != last) {
				current_key = first->first;
				erase(current_key);
				first = this->upper_bound(current_key);
			}
			return ;
		}

		void	swap(ft::map<Key, T, Compare, Alloc>& x)
		{
			_treeType*	tmp_tree_ptr = this->_tree;
			size_type	tmp_size = this->_size;

			this->_tree = x._tree;
			this->_size = x._size;
			x._tree = tmp_tree_ptr;
			x._size = tmp_size;
			return ;
		}

		void	clear(void)
		{
			while (this->_size != 0) {
				this->erase(this->begin());
			}
			return ;
		}

		key_compare	key_comp(void) const
		{
			return (key_compare());
		}
		
		value_compare	value_comp(void) const
		{
			return (value_compare());
		}

		iterator	find(const key_type& k)
		{
			value_type							node = ft::make_pair<const key_type, mapped_type>(k, mapped_type());
			typename _treeType::node_pointer	ptr_k = _tree->findNode(node);

			return (iterator(ptr_k));
		}

		const_iterator	find(const key_type& k) const
		{
			value_type							node = ft::make_pair<const key_type, mapped_type>(k, mapped_type());
			typename _treeType::node_pointer	ptr_k = _tree->findNode(node);

			return (const_iterator(ptr_k));
		}

		size_type	count(const key_type& k) const
		{
			const_iterator	it = this->find(k);

			if (it == this->end()) {
				return (0);
			}
			return (1);
		}

		iterator	lower_bound(const key_type& k)
		{
			value_type							node = ft::make_pair<const key_type, mapped_type>(k, mapped_type());
			typename _treeType::node_pointer	ptr_k = _tree->findLowerBound(node);

			return (iterator(ptr_k));
		}

		const_iterator	lower_bound(const key_type& k) const
		{
			value_type							node = ft::make_pair<const key_type, mapped_type>(k, mapped_type());
			typename _treeType::node_pointer	ptr_k = _tree->findLowerBound(node);

			return (const_iterator(ptr_k));
		}

		iterator	upper_bound(const key_type& k)
		{
			value_type							node = ft::make_pair<const key_type, mapped_type>(k, mapped_type());
			typename _treeType::node_pointer	ptr_k = _tree->findUpperBound(node);

			return (iterator(ptr_k));
		}

		const_iterator	upper_bound(const key_type& k) const
		{
			value_type							node = ft::make_pair<const key_type, mapped_type>(k, mapped_type());
			typename _treeType::node_pointer	ptr_k = _tree->findUpperBound(node);

			return (const_iterator(ptr_k));
		}

		ft::pair<const_iterator,const_iterator>	equal_range(const key_type& k) const
		{
			pair<const_iterator, const_iterator>	pair_equal_range;
			
			pair_equal_range = ft::make_pair<const_iterator, const_iterator>(
				this->lower_bound(k), this->upper_bound(k));
			return (pair_equal_range);
		}

		ft::pair<iterator,iterator>	equal_range(const key_type& k)
		{
			pair<iterator, iterator>	pair_equal_range;
			
			pair_equal_range = ft::make_pair<iterator, iterator>(
				this->lower_bound(k), this->upper_bound(k));
			return (pair_equal_range);
		}

		allocator_type	get_allocator(void) const
		{
			return (this->_alloc);
		}

	private:
		typedef ft::RedBlackTree<value_type, ft::map<Key, T, Compare, Alloc>::value_compare, Alloc>	_treeType;

		_treeType*		_tree;
		size_type		_size;
		allocator_type	_alloc;
	};

	//just for terminator tester, shouldn't be here in my opinion
	template<typename Key, typename T, typename Compare, typename Alloc>
	void	swap(ft::map<Key,T,Compare,Alloc>& lhs, ft::map<Key,T,Compare,Alloc>& rhs)
	{
		lhs.swap(rhs);
		return ;
	}

	template<typename Key, typename T, typename Compare, typename Alloc>
	bool	operator==(const ft::map<Key,T,Compare,Alloc>& lhs,
		const ft::map<Key,T,Compare,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size()) {
			return (false);
		}
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template<typename Key, typename T, typename Compare, typename Alloc>
	bool	operator!=(const ft::map<Key,T,Compare,Alloc>& lhs,
		const ft::map<Key,T,Compare,Alloc>& rhs)
	{
		return (!(lhs == rhs));
	}

	template<typename Key, typename T, typename Compare, typename Alloc>
	bool	operator<(const ft::map<Key,T,Compare,Alloc>& lhs,
		const ft::map<Key,T,Compare,Alloc>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(),
			rhs.begin(), rhs.end()));
	}

	template<typename Key, typename T, typename Compare, typename Alloc>
	bool	operator<=(const ft::map<Key,T,Compare,Alloc>& lhs,
		const ft::map<Key,T,Compare,Alloc>& rhs)
	{
		return (!(rhs < lhs));
	}

	template<typename Key, typename T, typename Compare, typename Alloc>
	bool	operator>(const ft::map<Key,T,Compare,Alloc>& lhs,
		const ft::map<Key,T,Compare,Alloc>& rhs)
	{
		return (rhs < lhs);
	}

	template<typename Key, typename T, typename Compare, typename Alloc>
	bool	operator>=(const ft::map<Key,T,Compare,Alloc>& lhs,
		const ft::map<Key,T,Compare,Alloc>& rhs)
	{
		return (!(lhs < rhs));
	}

}

namespace std
{
	template<typename Key, typename T, typename Compare, typename Alloc>
	void	swap(ft::map<Key,T,Compare,Alloc>& lhs, ft::map<Key,T,Compare,Alloc>& rhs)
	{
		lhs.swap(rhs);
		return ;
	}
}
