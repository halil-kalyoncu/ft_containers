/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:31:08 by hkalyonc          #+#    #+#             */
/*   Updated: 2023/02/25 11:39:36 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

//enable_if
#include "enable_if.hpp"
//lexicographical_compare
#include "lexicographical_compare.hpp"
//is_integral
#include "is_integral.hpp"
//iterator_traits
#include "iterator_traits.hpp"
//random_access_iterator
#include "random_access_iterator.hpp"
//reverse_iterator
#include "reverse_iterator.hpp"
//equal
#include "equal.hpp"

//allocator
#include <memory>
//out_of_range, length_error, bad_alloc
#include <exception>
//input_iterator_tag, forward_iterator_tag, distance
#include <iterator>

/*

	vector synopsis

	template <typename T, typename Alloc = std::allocator<T> >
	class vector
	{
	public:
		typedef T														value_type;
		typedef Alloc													allocator_type;
		typedef typename allocator_type::reference						reference;
		typedef typename allocator_type::const_reference				const_reference;
		typedef typename allocator_type::pointer						pointer;
		typedef typename allocator_type::const_pointer					const_pointer;
		typedef ft::random_access_iterator<pointer>						iterator;
		typedef ft::random_access_iterator<const_pointer>				const_iterator;
		typedef ft::reverse_iterator<iterator>							reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;
		typedef typename iterator_traits<iterator>::difference_type		difference_type;
		typedef typename allocator_type::size_type						size_type;

		explicit vector(const allocator_type& alloc = allocator_type());
		explicit vector(size_type n, const value_type& val = value_type(),
			const allocator_type& alloc = allocator_type());
		template<typename InputIterator>
		vector(InputIterator first, InputIterator last,
			const allocator_type& alloc = allocator_type());
		vector(const ft::vector<T, allocator_type>& copy);
		~vector(void);
		ft::vector<T, allocator_type>&	operator=(const ft::vector<T, allocator_type>& rhs);

		iterator				begin(void);
		const_iterator			begin(void);
		iterator				end(void);
		const_iterator			end(void) const;
		reverse_iterator		rbegin(void);
		const_reverse_iterator	rbegin(void) const;
		reverse_iterator		rend(void);
		const_reverse_iterator	rend(void) const;

		size_type				size(void) const;
		size_type				max_size(void) const;
		void					resize(size_type n, value_type val = value_type());
		size_type				capacity(void) const;
		bool					empty(void) const;
		void					reserve(size_type n);

		reference				operator[](size_type n);
		const_reference			operator[](size_type n) const;
		reference				at(size_type n);
		const_reference			at(size_type n) const;
		reference				front(void);
		const_reference			front(void) const;
		reference				back(void);
		const_reference			back(void) const;
		value_type*				data(void);
		const value_type*		data(void) const;

		template<typename InputIterator>
		void					assign(InputIterator first, InputIterator last);
		void					assign(size_type n, const value_type& val);
		void					push_back(const value_type& val);
		void					pop_back(void);
		iterator				insert(iterator position, const value_type& val);
		void					insert(iterator position, size_t n, const value_type& val);
		void					insert(iterator position, InputIterator first, InputIterator last);
		iterator				erase(iterator position);
		iterator				erase(iterator first, iterator last);
		void					swap(ft::vector<T, allocator_type>& x);
		void					clear(void);

		allocator_type			get_allocator() const;

	private:
		pointer					_ptr;
		size_type				_size;
		size_type				_capacity;
		allocator_type			_alloc;

		size_t					_calcNewCapacity(size_type elements) const;
		void					_realloc(size_type new_size);
		void					_reallocFill(size_type new_size, size_type index_position, size_type fill_size, const value_type& val);
		template<typename InputIterator>
		void					_reallocFill(size_type new_size, size_type index_position, InputIterator first, InputIterator last, size_type range_iterator)
		void					_constructElements(pointer ptr, size_t n, const value_type& val);
		void					_destroyElements(pointer ptr, size_t n);
		template<typename InputIterator>
		void					_copyElements(InputIterator first, InputIterator last, pointer destination);
		template<typename InputIterator>
		void					_insertElements(InputIterator first, InputIterator last, pointer ptr_pos)
		template<typename InputIterator>
		void					_copyElementsReallocFill(InputIterator first, InputIterator last, pointer destination)
		void					_moveElements(pointer source, size_t n, pointer destination);
		void					_moveElementsBackwards(pointer source_last, size_t n, pointer destination_last);
		template<typename InputIterator>
		void					_assignRange(InputIterator first, InputIterator last, std::forward_iterator_tag)
		template<typename InputIterator>
		void					_assignRange(InputIterator first, InputIterator last, std::input_iterator_tag)
		template<typename InputIterator>
		void					_insertRange(iterator position, InputIterator first, InputIterator last, std::forward_iterator_tag)
		template<typename InputIterator>
		void					_insertRange(iterator position, InputIterator first, InputIterator last, std::input_iterator_tag)
		size_t					_calc_index(iterator it) const;
	};

	template<typename T, typename Alloc>
	bool						operator==(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs);
	template<typename T, typename Alloc>
	bool						operator!=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs);
	template<typename T, typename Alloc>
	bool						operator<(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs);
	template<typename T, typename Alloc>
	bool						operator<=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs);
	template<typename T, typename Alloc>
	bool						operator>(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs);
	template<typename T, typename Alloc>
	bool						operator>=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs);

	template<typename T, typename Alloc>
	void						swap(ft::vector<T, Alloc>& x, ft::vector<T, Alloc>& y);

*/

namespace ft
{
	template <typename T, typename Alloc = std::allocator<T> >
	class vector
	{
	public:
		typedef T														value_type;
		typedef Alloc													allocator_type;
		typedef typename allocator_type::reference						reference;
		typedef typename allocator_type::const_reference				const_reference;
		typedef typename allocator_type::pointer						pointer;
		typedef typename allocator_type::const_pointer					const_pointer;
		typedef ft::random_access_iterator<pointer>						iterator;
		typedef ft::random_access_iterator<const_pointer>				const_iterator;
		typedef ft::reverse_iterator<iterator>							reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;
		typedef typename iterator_traits<iterator>::difference_type		difference_type;
		typedef typename allocator_type::size_type						size_type;

		explicit vector(const allocator_type& alloc = allocator_type()) :
			_ptr(NULL), _size(0), _capacity(0), _alloc(alloc)
		{
			this->_ptr = this->_alloc.allocate(this->_capacity);
			return ;
		}

		explicit vector(size_type n, const value_type& val = value_type(),
			const allocator_type& alloc = allocator_type()) : _ptr(NULL),
			_size(n), _capacity(n), _alloc(alloc)
		{
			this->_ptr = this->_alloc.allocate(this->_capacity);
			this->_constructElements(this->_ptr, n, val);
			return ;
		}

		template<typename InputIterator>
		vector(InputIterator first, InputIterator last,
			const allocator_type& alloc = allocator_type(),
			typename ft::enable_if<!(ft::is_integral<InputIterator>::value), void *>::type = NULL) :
				_ptr(NULL), _size(0), _capacity(0),
				_alloc(alloc)
		{
			this->_ptr = this->_alloc.allocate(this->_capacity);
			this->assign(first, last);
			return ;
		}

		vector(const ft::vector<T, allocator_type>& copy) : _ptr(NULL),
			_size(copy._size), _capacity(copy._capacity),
			_alloc(allocator_type())
		{
			this->_ptr = this->_alloc.allocate(this->_capacity);
			this->_copyElements(copy.begin(), copy.end(), this->_ptr);
			return ;
		}

		~vector(void)
		{
			this->_destroyElements(this->_ptr, this->_size);
			this->_alloc.deallocate(this->_ptr, this->_capacity);
			return ;
		}

		ft::vector<T, allocator_type>&	operator=(const ft::vector<T, allocator_type>& rhs)
		{
			if (this != &rhs) {
				this->_destroyElements(this->_ptr, this->_size);
				this->_size = 0;
				this->assign(rhs.begin(), rhs.end());
			}
			return (*this);
		}

		iterator	begin(void)
		{
			return (iterator(this->_ptr));
		}
		
		const_iterator	begin(void) const
		{
			return (const_iterator(this->_ptr));
		}

		iterator	end(void)
		{
			return (iterator(this->_ptr + this->_size));
		}

		const_iterator	end(void) const
		{
			return (const_iterator(this->_ptr + this->_size));
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

		size_type	size(void) const
		{
			return (this->_size);
		}

		size_type	max_size(void) const
		{
			return (this->_alloc.max_size());
		}

		void	resize(size_type n, value_type val = value_type())
		{
			if (n > this->max_size()) {
				throw std::length_error("vector");
			}
			if (this->_size == n) {
				return ;
			}
			if (this->_size > n) {
				this->_destroyElements(this->_ptr + n, this->_size - n);
			}
			else {
				if (n > this->_capacity) {
					this->_realloc(this->_calcNewCapacity(n));
				}
				this->_constructElements(this->end().base(), n - this->_size, val);
			}
			this->_size = n;
			return ;
		}

		size_type	capacity(void) const
		{
			return (this->_capacity);
		}

		bool	empty(void) const
		{
			return (this->_size == 0);
		}

		void	reserve(size_type n)
		{
			if (n > this->max_size()) {
				throw std::length_error("vector");
			}
			if (n <= this->_capacity) {
				return ;
			}
			this->_realloc(n);
			return ;
		}

		reference	operator[](size_type n)
		{
			return(*(this->_ptr + n));
		}

		const_reference	operator[](size_type n) const
		{
			return(*(this->_ptr + n));
		}

		reference	at(size_type n)
		{
			if (n >= this->_size) {
				throw std::out_of_range("vector");
			}
			return (operator[](n));
		}

		const_reference	at(size_type n) const
		{
			if (n >= this->_size) {
				throw std::out_of_range("vector");
			}
			return (operator[](n));
		}

		reference	front(void)
		{
			return (*(this->begin()));
		}

		const_reference	front(void) const
		{
			return (*(this->begin()));
		}

		reference	back(void)
		{
			return (*(this->end() - 1));
		}

		const_reference	back(void) const
		{
			return (*(this->end() - 1));
		}

		value_type*	data(void)
		{
			return (this->_ptr);
		}

		const value_type*	data(void) const
		{
			return (this->_ptr);
		}

		template<typename InputIterator>
		void	assign(InputIterator first, InputIterator last,
			typename ft::enable_if<!(ft::is_integral<InputIterator>::value), void *>::type = NULL)
		{
			this->clear();
			this->_assignRange(first, last,
				typename ft::iterator_traits<InputIterator>::iterator_category());
			return ;
		}

		void	assign(size_type n, const value_type& val)
		{
			this->clear();
			if (n > this->_capacity) {
				this->_realloc(n);
			}
			this->_constructElements(this->_ptr, n, val);
			this->_size = n;
			return ;
		}

		void	push_back(const value_type& val)
		{
			if (this->_size >= this->_capacity) {
				this->_realloc(this->_calcNewCapacity(this->_size + 1));
			}
			this->_alloc.construct(this->end().base(), val);
			this->_size++;
			return ;
		}

		void	pop_back(void)
		{
			//original has undefined behavior
			if (this->empty() == true) {
				return ;
			}
			this->_alloc.destroy(this->_ptr + (this->_size - 1));
			this->_size--;
			return ;
		}

		iterator	insert(iterator position, const value_type& val)
		{
			size_type	index_position = this->_calc_index(position);

			this->insert(position, 1, val);
			return (this->begin() + index_position);
		}

		void	insert(iterator position, size_t n, const value_type& val)
		{
			size_type	new_size = this->_size + n;
			size_type	index_position = this->_calc_index(position);

			if (n == 0) {
				return ;
			}
			if (new_size > this->_capacity) {
				this->_reallocFill(new_size, index_position, n, val);
			}
			else {
				this->_constructElements(this->end().base(), n, val);
				if (position != this->end()) {
					this->_moveElementsBackwards(this->end().base() - 1,
						this->_size - index_position,
						this->end().base() + n - 1);
					this->_destroyElements(position.base(), n);
					this->_constructElements(position.base(), n, val);
				}
			}
			this->_size = new_size;
			return ;
		}

		template<typename InputIterator>
		void	insert(iterator position, InputIterator first, InputIterator last,
			typename ft::enable_if<!(ft::is_integral<InputIterator>::value), void *>::type = NULL)
		{
			this->_insertRange(position, first, last,
				typename iterator_traits<InputIterator>::iterator_category());
			return ;
		}

		iterator erase(iterator position)
		{
			size_type	index_position = this->_calc_index(position);
			pointer		ptr = this->_ptr + index_position;
			size_type	i = index_position;

			if (position == this->end()) {
				return (position);
			}
			while (i < (this->_size - 1)) {
				this->_alloc.destroy(ptr);
				this->_alloc.construct(ptr, *(ptr + 1));
				ptr++;
				i++;
			}
			this->_alloc.destroy(ptr);
			this->_size--;
			return (position);
		}

		iterator	erase(iterator first, iterator last)
		{
			size_type	range = static_cast<size_type>(last - first);

			if (range == 0) {
				return (first);
			}
			this->_moveElements(last.base(), this->_size - range, first.base());
			this->_destroyElements(this->end().base() - range, range);
			this->_size -= range;
			return (first);
		}

		void	swap(ft::vector<T, allocator_type>& x)
		{
			pointer	ptr_tmp;
			size_t	size_tmp;
			size_t	capacity_tmp;

			ptr_tmp = x._ptr;
			x._ptr = this->_ptr;
			this->_ptr = ptr_tmp;
			size_tmp = x._size;
			x._size = this->_size;
			this->_size = size_tmp;
			capacity_tmp = x._capacity;
			x._capacity = this->_capacity;
			this->_capacity = capacity_tmp;
			return ;
		}

		void	clear(void)
		{
			this->_destroyElements(this->_ptr, this->_size);
			this->_size = 0;
			return ;
		}

		allocator_type	get_allocator() const
		{
			return (this->_alloc);
		}

	private:
		pointer			_ptr;
		size_type		_size;
		size_type		_capacity;
		allocator_type	_alloc;

		size_t	_calcNewCapacity(size_type elements) const
		{
			if (2 * this->_capacity > elements) {
				return (2 * this->_capacity);
			}
			return (elements);
		}

		void	_realloc(size_type new_size)
		{
			pointer	realloc;

			if (new_size < this->_size) {
				this->resize(new_size);
				return ;
			}
			realloc = this->_alloc.allocate(new_size);
			this->_copyElements(this->begin(), this->end(), realloc);

			this->_destroyElements(this->_ptr, this->_size);
			this->_alloc.deallocate(this->_ptr, this->_capacity);
			this->_ptr = realloc;
			this->_capacity = new_size;
			return ;
		}

		void	_reallocFill(size_type new_size, size_type index_position,
			size_type fill_size, const value_type& val)
		{
			size_type	new_capacity = this->_calcNewCapacity(new_size);
			pointer		realloc;

			realloc = this->_alloc.allocate(new_capacity);
			this->_copyElements(this->begin(), this->begin() + index_position,
				realloc);
			this->_constructElements(realloc + index_position, fill_size, val);
			this->_copyElements(this->begin() + index_position,
				this->end(), realloc + index_position + fill_size);

			this->_destroyElements(this->_ptr, this->_size);
			this->_alloc.deallocate(this->_ptr, this->_capacity);
			this->_ptr = realloc;
			this->_capacity = new_capacity;
			return ;
		}

		template<typename InputIterator>
		void	_reallocFill(size_type new_size, size_type index_position,
			InputIterator first, InputIterator last, size_type range_iterator)
		{
			size_type	new_capacity = this->_calcNewCapacity(new_size);
			pointer		realloc;

			realloc = this->_alloc.allocate(new_capacity);
			this->_copyElements(this->begin(), this->begin() + index_position,
				realloc);
			try {
				this->_copyElementsReallocFill(first, last, realloc + index_position);
			}
			catch (std::bad_alloc& ba) {
				this->_destroyElements(realloc, index_position);
				this->_alloc.deallocate(realloc, new_capacity);
				throw ba;
			}
			this->_copyElements(this->begin() + index_position,
				this->end(), realloc + index_position + range_iterator);
			
			this->_destroyElements(this->_ptr, this->_size);
			this->_alloc.deallocate(this->_ptr, this->_capacity);
			this->_ptr = realloc;
			this->_capacity = new_capacity;
			this->_size = new_size;
			return ;
		}

		void	_constructElements(pointer ptr, size_t n, const value_type& val)
		{
			size_t	i = 0;

			while (i < n) {
				this->_alloc.construct(ptr, val);
				ptr++;
				i++;
			}
			return ;
		}

		void	_destroyElements(pointer ptr, size_t n)
		{
			size_t	i = 0;

			while (i < n) {
				this->_alloc.destroy(ptr);
				ptr++;
				i++;
			}
			return ;
		}

		template<typename InputIterator>
		void	_copyElements(InputIterator first, InputIterator last,
			pointer destination)
		{
			while (first != last) {
				this->_alloc.construct(destination, *first);
				first++;
				destination++;
			}
			return ;
		}

		// difference to _copyElements: while inserting elements, increment the
		// size attribute.
		// If construct throws, the destructor has the correct size,
		// doesn't result in leaks
		template<typename InputIterator>
		void	_insertElements(InputIterator first, InputIterator last,
			pointer ptr_pos)
		{
			while (first != last) {
				this->_alloc.construct(ptr_pos, *first);
				first++;
				ptr_pos++;
				this->_size++;
			}
			return ;
		}

		template<typename InputIterator>
		void	_copyElementsReallocFill(InputIterator first, InputIterator last,
			pointer destination)
		{
			pointer	origin = destination;
			size_t	i = 0;

			while (first != last) {
				try {
					this->_alloc.construct(destination, *first);
				}
				catch (...) {
					this->_destroyElements(origin, i);
					throw std::bad_alloc();
				}
				first++;
				destination++;
				i++;
			}
			return ;
		}

		void	_moveElements(pointer source, size_t n, pointer destination)
		{
			size_t	i = 0;
	
			while (i < n) {
				this->_alloc.destroy(destination);
				this->_alloc.construct(destination, *source);
				source++;
				destination++;
				i++;
			}
			return ;
		}

		void	_moveElementsBackwards(pointer source_last, size_t n,
			pointer destination_last)
		{
			size_t	i = 0;

			while (i < n) {
				this->_alloc.destroy(destination_last);
				this->_alloc.construct(destination_last, *source_last);
				source_last--;
				destination_last--;
				i++;
			}
			return ;
		}

		template<typename InputIterator>
		void	_assignRange(InputIterator first, InputIterator last,
			std::forward_iterator_tag)
		{
			size_type	new_size = static_cast<size_type>(std::distance(first, last));

			if (new_size > this->max_size()) {
				throw std::length_error("vector");
			}
			if (new_size > this->_capacity) {
				this->_realloc(new_size);
			}
			this->_copyElements(first, last, this->_ptr);
			this->_size = new_size;
			return ;
		}

		template<typename InputIterator>
		void	_assignRange(InputIterator first, InputIterator last,
			std::input_iterator_tag)
		{
			while (first != last) {
				this->push_back(*first);
				first++;
			}
			return ;
		}

		template<typename InputIterator>
		void	_insertRange(iterator position, InputIterator first,
			InputIterator last, std::forward_iterator_tag)
		{
			size_type	range_insert = static_cast<size_type>(std::distance(first, last));
			size_type	new_size = this->_size + range_insert;
			pointer		append;

			if (range_insert == 0) {
				return ;
			}
			if (new_size > this->max_size()) {
				throw std::length_error("vector");
			}
			if (new_size > this->_capacity) {
				this->_reallocFill(new_size, this->_calc_index(position),
					first, last, range_insert);
			}
			else {
				if (position == this->end()) {
					this->_insertElements(first, last, this->end().base());
				}
				else {
					append = this->_alloc.allocate(range_insert);
					this->_copyElements(position, this->end(), append);
					this->_destroyElements(position.base(), this->end() - position);
					this->_insertElements(first, last, position.base());
					this->_copyElements(append, append + range_insert,
						position.base() + range_insert);
					this->_destroyElements(append, range_insert);
					this->_alloc.deallocate(append, range_insert);
				}
			}
			return ;
		}

		template<typename InputIterator>
		void	_insertRange(iterator position, InputIterator first,
			InputIterator last, std::input_iterator_tag)
		{
			size_t		index_position = this->_calc_index(position);
			size_t		size_before_insert = this->_size;
			size_t		elements_inserted = 0;
			pointer		append;
			size_t		size_append = size_before_insert - index_position;

			while (first != last) {
				this->push_back(*first);
				first++;
				elements_inserted++;
			}
			if (size_append == 0) {
				return ;
			}
			position = this->begin() + index_position;
			append = this->_alloc.allocate(size_append);
			this->_copyElements(position, this->begin() + size_before_insert,
				append);
			this->_moveElements(this->_ptr + size_before_insert,
				elements_inserted, position.base());
			this->_moveElements(append, size_append, position.base() + elements_inserted);
			this->_destroyElements(append, size_append);
			this->_alloc.deallocate(append, size_append);
			return ;
		}

		size_t	_calc_index(iterator it) const
		{
			return (static_cast<size_type>(it - this->begin()));
		}

	};

	//just for terminator tester, shouldn't be here in my opinion
	template<typename T, typename Alloc>
	void	swap(ft::vector<T, Alloc>& x, ft::vector<T, Alloc>& y)
	{
		x.swap(y);
		return ;
	}

	template<typename T, typename Alloc>
	bool	operator==(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
	{
		if (lhs.size() != rhs.size()) {
			return (false);
		}
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}
	
	template<typename T, typename Alloc>
	bool	operator!=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
	{
		return (!(lhs == rhs));
	}
	
	template<typename T, typename Alloc>
	bool	operator<(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(),
			rhs.end()));
	}
	
	template<typename T, typename Alloc>
	bool	operator<=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
	{
		return (!(rhs < lhs));
	}
	
	template<typename T, typename Alloc>
	bool	operator>(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
	{
		return (rhs < lhs);
	}
	
	template<typename T, typename Alloc>
	bool	operator>=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
	{
		return (!(lhs < rhs));
	}

}

namespace std
{
	template<typename T, typename Alloc>
	void	swap(ft::vector<T, Alloc>& x, ft::vector<T, Alloc>& y)
	{
		x.swap(y);
		return ;
	}
}
