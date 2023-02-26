/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 08:43:28 by hkalyonc          #+#    #+#             */
/*   Updated: 2023/02/25 11:53:35 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

//ptrdiff_t
#include <cstddef>
//bidirectional_iterator_tag
#include <iterator>

/*

	bidirectional_iterator synopsis

	template <typename Iter, typename Value>
	class bidirectional_iterator
	{
	private:
		typedef Iter										_iterator_type;
		typedef Iter*										_iterator_ptr;
	public:
		typedef Value										value_type;
		typedef ptrdiff_t									difference_type;
		typedef value_type*									pointer;
		typedef value_type&									reference;
		typedef typename std::bidirectional_iterator_tag	iterator_category;
	
		explicit bidirectional_iterator(_iterator_ptr ptr = NULL);
		template<typename T>
		bidirectional_iterator(const ft::bidirectional_iterator<Iter, T>& copy);
		~bidirectional_iterator(void);
		template<typename T>
		ft::bidirectional_iterator<Iter, Value>&	operator=(const ft::bidirectional_iterator<Iter, T>& rhs);

		reference									operator*(void) const;
		pointer										operator->(void) const;
	
		ft::bidirectional_iterator<Iter, Value>&	operator++(void);
		ft::bidirectional_iterator<Iter, Value>		operator++(int);

		ft::bidirectional_iterator<Iter, Value>&	operator--(void);
		ft::bidirectional_iterator<Iter, Value>		operator--(int);
	
		_iterator_ptr								base(void) const;
	
	private:
		_iterator_ptr								_ptr;
	};

	template<typename Iter, typename T, typename U>
	bool	operator==(const ft::bidirectional_iterator<Iter, T>& lhs, const ft::bidirectional_iterator<Iter, U>& rhs);
	template<typename Iter, typename T, typename U>
	bool	operator!=(const ft::bidirectional_iterator<Iter, T>& lhs, const ft::bidirectional_iterator<Iter, U>& rhs);

*/

namespace ft
{

	template <typename Iter, typename Value>
	class bidirectional_iterator
	{
	private:
		typedef Iter										_iterator_type;
		typedef Iter*										_iterator_ptr;
	public:
		typedef Value										value_type;
		typedef ptrdiff_t									difference_type;
		typedef value_type*									pointer;
		typedef value_type&									reference;
		typedef typename std::bidirectional_iterator_tag	iterator_category;
	
		explicit bidirectional_iterator(_iterator_ptr ptr = NULL) : _ptr(ptr)
		{
			return;
		}
	
		template<typename T>
		bidirectional_iterator(const ft::bidirectional_iterator<Iter, T>& copy) :
			_ptr(copy.base())
		{
			return ;
		}
	
		~bidirectional_iterator(void)
		{
			return ;
		}
	
		template<typename T>
		ft::bidirectional_iterator<Iter, Value>&	operator=(
				const ft::bidirectional_iterator<Iter, T>& rhs)
		{
			this->_ptr = rhs.base();
			return (*this);
		}

		reference	operator*(void) const
		{
			return (this->_ptr->getValue());
		}
	
		pointer	operator->(void) const
		{
			return (this->_ptr->getValuePointer());
		}
	
		ft::bidirectional_iterator<Iter, Value>&	operator++(void)
		{
			this->_ptr = _iterator_type::nextNode(this->_ptr);
			return (*this);
		}

		ft::bidirectional_iterator<Iter, Value>	operator++(int)
		{
			ft::bidirectional_iterator<Iter, Value>	previous(*this);

			this->_ptr = _iterator_type::nextNode(this->_ptr);
			return (previous);
		}

		ft::bidirectional_iterator<Iter, Value>&	operator--(void)
		{
			this->_ptr = _iterator_type::previousNode(this->_ptr);
			return (*this);
		}

		ft::bidirectional_iterator<Iter, Value>	operator--(int)
		{
			ft::bidirectional_iterator<Iter, Value>	next(*this);

			this->_ptr = _iterator_type::previousNode(this->_ptr);
			return (next);
		}
	
		_iterator_ptr	base(void) const
		{
			return (this->_ptr);
		}
	
	private:
		_iterator_ptr	_ptr;
	};

	template<typename Iter, typename T, typename U>
	bool	operator==(const ft::bidirectional_iterator<Iter, T>& lhs,
		const ft::bidirectional_iterator<Iter, U>& rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template<typename Iter, typename T, typename U>
	bool	operator!=(const ft::bidirectional_iterator<Iter, T>& lhs,
		const ft::bidirectional_iterator<Iter, U>& rhs)
	{
		return (lhs.base() != rhs.base());
	}

}
