/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:30:58 by hkalyonc          #+#    #+#             */
/*   Updated: 2023/02/24 10:48:23 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "vector.hpp"

/*

	stack synopsis

	template<typename T, typename Container = ft::vector<T> >
	class stack
	{
	public:
		typedef T								value_type;
		typedef Container						container_type;
		typedef typename Container::size_type	size_type;
		typedef value_type&						reference;
		typedef const value_type&				const_reference;
	
		explicit stack(const container_type& cntr = container_type());
		stack(const stack<T, container_type>& copy);
		~stack(void);
		stack<T, container_type>&	operator=(const stack<T, container_type>& rhs);

		bool						empty(void) const;
		size_type					size(void) const;
		value_type&					top(void);
		const value_type&			top(void) const;
		void						push(const value_type& val);
		void						pop(void);

	protected:
		container_type				c;

	private:
		template<typename TO, typename CO>
		friend bool					operator==(const stack<TO, CO>& lhs, const stack<TO, CO>& rhs);
		template<typename TO, typename CO>
		friend bool					operator!=(const stack<TO, CO>& lhs, const stack<TO, CO>& rhs);
		template<typename TO, typename CO>
		friend bool					operator<(const stack<TO, CO>& lhs, const stack<TO, CO>& rhs);
		template<typename TO, typename CO>
		friend bool					operator<=(const stack<TO, CO>& lhs, const stack<TO, CO>& rhs);
		template<typename TO, typename CO>
		friend bool					operator>(const stack<TO, CO>& lhs, const stack<TO, CO>& rhs);
		template<typename TO, typename CO>
		friend bool					operator>=(const stack<TO, CO>& lhs, const stack<TO, CO>& rhs);
	};

	template<typename T, typename Container>
	bool							operator==(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs);
	template<typename T, typename Container>
	bool							operator!=(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs);
	template<typename T, typename Container>
	bool							operator<(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs);
	template<typename T, typename Container>
	bool							operator<=(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs);
	template<typename T, typename Container>
	bool							operator>(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs);
	template<typename T, typename Container>
	bool							operator>=(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs);

*/

namespace ft
{
	template<typename T, typename Container = ft::vector<T> >
	class stack
	{
	public:
		typedef T								value_type;
		typedef Container						container_type;
		typedef typename Container::size_type	size_type;
		typedef value_type&						reference;
		typedef const value_type&				const_reference;
	
		explicit stack(const container_type& cntr = container_type()) : c(cntr)
		{
			return ;
		}

		//original has no copy constructor
		stack(const stack<T, container_type>& copy) : c(copy.c)
		{
			return ;
		}
	
		~stack(void)
		{
			return ;
		}

		//original has no assignment overload
		stack<T, container_type>&	operator=(const stack<T, container_type>& rhs)
		{
			if (this != &rhs) {
				this->c.clear();
				this->c = rhs.c;
			}
			return (*this);
		}
	
		bool	empty(void) const
		{
			return (this->c.size() == 0);
		}
	
		size_type	size(void) const
		{
			return (this->c.size());
		}
	
		value_type&	top(void)
		{
			return (this->c.back());
		}
	
		const value_type&	top(void) const
		{
			return (this->c.back());
		}
	
		void	push(const value_type& val)
		{
			this->c.push_back(val);
			return ;
		}
	
		void	pop(void)
		{
			//original has undefined behavior
			if (this->empty() == true) {
				return ;
			}
			this->c.pop_back();
			return ;
		}

	protected:
		container_type	c;

	private:
		template<typename TO, typename CO>
		friend bool	operator==(const stack<TO, CO>& lhs, const stack<TO, CO>& rhs);
		template<typename TO, typename CO>
		friend bool	operator!=(const stack<TO, CO>& lhs, const stack<TO, CO>& rhs);
		template<typename TO, typename CO>
		friend bool	operator<(const stack<TO, CO>& lhs, const stack<TO, CO>& rhs);
		template<typename TO, typename CO>
		friend bool	operator<=(const stack<TO, CO>& lhs, const stack<TO, CO>& rhs);
		template<typename TO, typename CO>
		friend bool	operator>(const stack<TO, CO>& lhs, const stack<TO, CO>& rhs);
		template<typename TO, typename CO>
		friend bool	operator>=(const stack<TO, CO>& lhs, const stack<TO, CO>& rhs);
	};

	template<typename T, typename Container>
	bool	operator==(const ft::stack<T, Container>& lhs,
						const ft::stack<T, Container>& rhs)
	{
		return (lhs.c == rhs.c);
	}
	
	template<typename T, typename Container>
	bool	operator!=(const ft::stack<T, Container>& lhs,
						const ft::stack<T, Container>& rhs)
	{
		return (lhs.c != rhs.c);
	}
	
	template<typename T, typename Container>
	bool	operator<(const ft::stack<T, Container>& lhs,
						const ft::stack<T, Container>& rhs)
	{
		return (lhs.c < rhs.c);
	}
	
	template<typename T, typename Container>
	bool	operator<=(const ft::stack<T, Container>& lhs,
						const ft::stack<T, Container>& rhs)
	{
		return (lhs.c <= rhs.c);
	}
	
	template<typename T, typename Container>
	bool	operator>(const ft::stack<T, Container>& lhs,
						const ft::stack<T, Container>& rhs)
	{
		return (lhs.c > rhs.c);
	}
	
	template<typename T, typename Container>
	bool	operator>=(const ft::stack<T, Container>& lhs,
						const ft::stack<T, Container>& rhs)
	{
		return (lhs.c >= rhs.c);
	}
}