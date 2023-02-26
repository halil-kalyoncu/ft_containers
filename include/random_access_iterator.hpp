/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:16:00 by hkalyonc          #+#    #+#             */
/*   Updated: 2023/02/25 11:50:57 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

//iterator_traits
#include "iterator_traits.hpp"

//ptrdiff_t
#include <cstddef>
//random_access_iterator_tag
#include <iterator>

/*

	random_access_iterator synopsis
	
	template<typename T>
	class random_access_iterator
	{
	public:
		typedef T																iterator_type;

		typedef typename ft::iterator_traits<iterator_type>::value_type			value_type;
		typedef typename ft::iterator_traits<iterator_type>::pointer			pointer;
		typedef typename ft::iterator_traits<iterator_type>::reference			reference;
		typedef typename ft::iterator_traits<iterator_type>::difference_type	difference_type;
		typedef typename ft::iterator_traits<iterator_type>::iterator_category	iterator_category;

		explicit random_access_iterator(pointer ptr = NULL);
		template<typename Iter>
		random_access_iterator(const ft::random_access_iterator<Iter>& copy);
		~random_access_iterator(void);
		template<typename Iter>
		ft::random_access_iterator<T>&	operator=(const ft::random_access_iterator<Iter>& rhs);
	
		reference						operator*(void) const;
		pointer							operator->(void) const;

		ft::random_access_iterator<T>&	operator++(void);
		ft::random_access_iterator<T>	operator++(int);

		ft::random_access_iterator<T>&	operator--(void);
		ft::random_access_iterator<T>	operator--(int);

		ft::random_access_iterator<T>	operator+(difference_type n);
		ft::random_access_iterator<T>	operator-(difference_type n);
		ft::random_access_iterator<T>&	operator+=(difference_type n);
		ft::random_access_iterator<T>&	operator-=(difference_type n);

		reference						operator[](difference_type n) const;

		pointer							base(void) const;

	private:
		iterator_type	_ptr;
	};
	
	template<typename T, typename U>
	bool													operator==(const ft::random_access_iterator<T>& lhs, const ft::random_access_iterator<U>& rhs);
	template<typename T, typename U>
	bool													operator!=(const ft::random_access_iterator<T>& lhs, const ft::random_access_iterator<U>& rhs);

	template<typename T, typename U>
	typename ft::random_access_iterator<T>::difference_type	operator+(const ft::random_access_iterator<T>& lhs, const ft::random_access_iterator<U>& rhs);
	template<typename T, typename U>
	typename ft::random_access_iterator<T>::difference_type	operator-(const ft::random_access_iterator<T>& lhs, const ft::random_access_iterator<U>& rhs);
	template<typename T>
	ft::random_access_iterator<T> 							operator+(typename ft::random_access_iterator<T>::difference_type n, ft::random_access_iterator<T>& rhs);

	template<typename T, typename U>
	bool													operator<(const ft::random_access_iterator<T>& lhs, const ft::random_access_iterator<U>& rhs);
	template<typename T, typename U>
	bool													operator>(const ft::random_access_iterator<T>& lhs, const ft::random_access_iterator<U>& rhs);
	template<typename T, typename U>
	bool													operator<=(const ft::random_access_iterator<T>& lhs, const ft::random_access_iterator<U>& rhs);
	template<typename T, typename U>
	bool													operator>=(const ft::random_access_iterator<T>& lhs, const ft::random_access_iterator<U>& rhs);

*/

namespace ft
{

	template<typename T>
	class random_access_iterator
	{
	public:
		typedef T																iterator_type;

		typedef typename ft::iterator_traits<iterator_type>::value_type			value_type;
		typedef typename ft::iterator_traits<iterator_type>::pointer			pointer;
		typedef typename ft::iterator_traits<iterator_type>::reference			reference;
		typedef typename ft::iterator_traits<iterator_type>::difference_type	difference_type;
		typedef typename ft::iterator_traits<iterator_type>::iterator_category	iterator_category;

		explicit random_access_iterator(pointer ptr = NULL) : _ptr(ptr)
		{
			return ;
		}
	
		template<typename Iter>
		random_access_iterator(const ft::random_access_iterator<Iter>& copy) :
			_ptr(copy.base())
		{
			return ;
		}
	
		~random_access_iterator(void)
		{
			return ;
		}
	
		template<typename Iter>
		ft::random_access_iterator<T>&	operator=(const ft::random_access_iterator<Iter>& rhs)
		{
			this->_ptr = rhs.base();
			return (*this);
		}
	
		reference	operator*(void) const
		{
			return (*(this->_ptr));
		}

		pointer	operator->(void) const
		{
			return (this->_ptr);
		}

		ft::random_access_iterator<T>&	operator++(void)
		{
			this->_ptr++;
			return (*this);
		}

		ft::random_access_iterator<T>	operator++(int)
		{
			ft::random_access_iterator<T>	previous(*this);

			this->_ptr++;
			return (previous);
		}

		ft::random_access_iterator<T>&	operator--(void)
		{
			this->_ptr--;
			return (*this);
		}

		ft::random_access_iterator<T>	operator--(int)
		{
			ft::random_access_iterator<T>	next(*this);

			this->_ptr--;
			return (next);
		}

		ft::random_access_iterator<T>	operator+(difference_type n)
		{
			ft::random_access_iterator<T>	res(*this);

			res._ptr += n;
			return (res);
		}

		ft::random_access_iterator<T>	operator-(difference_type n)
		{
			ft::random_access_iterator<T>	res(*this);

			res._ptr -= n;
			return (res);
		}

		ft::random_access_iterator<T>&	operator+=(difference_type n)
		{
			this->_ptr += n;
			return (*this);
		}

		ft::random_access_iterator<T>&	operator-=(difference_type n)
		{
			this->_ptr -= n;
			return (*this);
		}

		reference	operator[](difference_type n) const
		{
			return ((this->_ptr)[n]);
		}

		pointer	base(void) const
		{
			return (this->_ptr);
		}

	private:
		iterator_type	_ptr;
	};
	
	template<typename T, typename U>
	bool	operator==(const ft::random_access_iterator<T>& lhs,
		const ft::random_access_iterator<U>& rhs)
	{
		return (lhs.base() == rhs.base());
	}
	
	template<typename T, typename U>
	bool	operator!=(const ft::random_access_iterator<T>& lhs,
		const ft::random_access_iterator<U>& rhs)
	{
		return (lhs.base() != rhs.base());
	}
	
	template<typename T, typename U>
	typename ft::random_access_iterator<T>::difference_type	operator+(
		const ft::random_access_iterator<T>& lhs,
		const ft::random_access_iterator<U>& rhs)
	{
		return (lhs.base() + rhs.base());
	}

	template<typename T, typename U>
	typename ft::random_access_iterator<T>::difference_type	operator-(
		const ft::random_access_iterator<T>& lhs,
		const ft::random_access_iterator<U>& rhs)
	{
		return (lhs.base() - rhs.base());
	}

	template<typename T>
	ft::random_access_iterator<T> operator+(
		typename ft::random_access_iterator<T>::difference_type n,
		ft::random_access_iterator<T>& rhs)
	{
		ft::random_access_iterator<T>	res(rhs);
		
		res += n;
		return (res);
	}
	
	template<typename T, typename U>
	bool	operator<(const ft::random_access_iterator<T>& lhs,
		const ft::random_access_iterator<U>& rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template<typename T, typename U>
	bool	operator>(const ft::random_access_iterator<T>& lhs,
		const ft::random_access_iterator<U>& rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template<typename T, typename U>
	bool	operator<=(const ft::random_access_iterator<T>& lhs,
		const ft::random_access_iterator<U>& rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template<typename T, typename U>
	bool	operator>=(const ft::random_access_iterator<T>& lhs,
		const ft::random_access_iterator<U>& rhs)
	{
		return (lhs.base() >= rhs.base());
	}

}
