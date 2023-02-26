/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:03:34 by hkalyonc          #+#    #+#             */
/*   Updated: 2023/02/16 09:07:35 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iterator_traits.hpp"

/*

	reverse_iterator synopsis

	template<typename Iterator>
	class reverse_iterator
	{
	protected:
		Iterator															current;
	public:
		typedef Iterator													iterator_type;
		typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
		typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
		typedef typename ft::iterator_traits<Iterator>::reference			reference;

		reverse_iterator(void);
		explicit reverse_iterator (iterator_type it);
		template<typename U>
		reverse_iterator(const reverse_iterator<U>& copy);
		~reverse_iterator(void);
		template<typename U>
		reverse_iterator&									operator=(const reverse_iterator<U>& rhs);

		iterator_type										base(void) const;

		reference											operator*(void) const;
		reverse_iterator									operator+(difference_type n) const;
		reverse_iterator&									operator++(void);
		reverse_iterator									operator++(int);
		reverse_iterator&									operator+=(difference_type n);
		reverse_iterator									operator-(difference_type n) const;
		reverse_iterator&									operator--(void);
		reverse_iterator									operator--(int);
		reverse_iterator&									operator-=(difference_type n);
		pointer												operator->(void) const;
		reference											operator[] (difference_type n) const;
	};

	template <typename T, typename U>
	bool													operator==(const reverse_iterator<T>& lhs, const reverse_iterator<U>& rhs);
	template <typename T, typename U>
	bool													operator!=(const reverse_iterator<T>& lhs, const reverse_iterator<U>& rhs);
	template <typename T, typename U>
	bool													operator<(const reverse_iterator<T>& lhs, const reverse_iterator<U>& rhs);
	template <typename T, typename U>
	bool													operator<=(const reverse_iterator<T>& lhs, const reverse_iterator<U>& rhs);
	template <typename T, typename U>
	bool													operator>(const reverse_iterator<T>& lhs, const reverse_iterator<U>& rhs);
	template <typename T, typename U>
	bool													operator>=(const reverse_iterator<T>& lhs, const reverse_iterator<U>& rhs);
	template <typename Iterator>
	reverse_iterator<Iterator>								operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it);
	template <typename Iterator>
	typename reverse_iterator<Iterator>::difference_type	operator-(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);

*/

namespace ft
{
	template<typename Iterator>
	class reverse_iterator
	{
	protected:
		Iterator															current;
	public:
		typedef Iterator													iterator_type;
		typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
		typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
		typedef typename ft::iterator_traits<Iterator>::reference			reference;

		reverse_iterator(void) : current(NULL)
		{
			return ;
		}

		explicit reverse_iterator (iterator_type it) : current(it)
		{
			return ;
		}

		template<typename U>
		reverse_iterator(const reverse_iterator<U>& copy) : current(copy.base())
		{
			return ;
		}

		~reverse_iterator(void)
		{
			return ;
		}

		iterator_type	base(void) const
		{
			return (this->current);
		}

		template<typename U>
		reverse_iterator&	operator=(const reverse_iterator<U>& rhs)
		{
			this->current = rhs.base();
			return (*this);
		}

		reference	operator*(void) const
		{
			iterator_type it = this->current;

			it--;
			return (*(it));
		}
		
		reverse_iterator	operator+(difference_type n) const
		{
			reverse_iterator	it(*this);

			it.current -= n;
			return (it);
		}

		reverse_iterator&	operator++(void)
		{
			this->current--;
			return (*this);
		}

		reverse_iterator	operator++(int)
		{
			reverse_iterator	it(*this);

			this->current--;
			return (it);
		}

		reverse_iterator&	operator+=(difference_type n)
		{
			this->current -= n;
			return (*this);
		}
		
		reverse_iterator	operator-(difference_type n) const
		{
			reverse_iterator	it(*this);

			it.current += n;
			return (it);
		}

		reverse_iterator&	operator--(void)
		{
			this->current++;
			return (*this);
		}

		reverse_iterator	operator--(int)
		{
			reverse_iterator	it(*this);

			this->current++;
			return (it);
		}

		reverse_iterator&	operator-=(difference_type n)
		{
			this->current += n;
			return (*this);
		}

		pointer	operator->(void) const
		{
			return (&(operator*()));
		}

		reference	operator[] (difference_type n) const
		{
			return (*(operator+(n)));
		}
	};

	template <typename T, typename U>
	bool	operator==(const reverse_iterator<T>& lhs, const reverse_iterator<U>& rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template <typename T, typename U>
	bool	operator!=(const reverse_iterator<T>& lhs, const reverse_iterator<U>& rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template <typename T, typename U>
	bool	operator<(const reverse_iterator<T>& lhs, const reverse_iterator<U>& rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template <typename T, typename U>
	bool	operator<=(const reverse_iterator<T>& lhs, const reverse_iterator<U>& rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template <typename T, typename U>
	bool	operator>(const reverse_iterator<T>& lhs, const reverse_iterator<U>& rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template <typename T, typename U>
	bool	operator>=(const reverse_iterator<T>& lhs, const reverse_iterator<U>& rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template <typename Iterator>
	reverse_iterator<Iterator>	operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it)
	{
		return (rev_it + n);
	}

	template <typename Iterator>
	typename reverse_iterator<Iterator>::difference_type	operator-(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (rhs.base() - lhs.base());
	}
}
