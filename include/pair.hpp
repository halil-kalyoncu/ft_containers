/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:58:29 by hkalyonc          #+#    #+#             */
/*   Updated: 2023/02/22 08:59:32 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{
	template<typename T1, typename T2>
	class pair
	{
	public:
		typedef T1	first_type;
		typedef T2	second_type;

		T1			first;
		T2			second;

		pair(void) : first(first_type()), second(second_type())
		{
			return ;
		}

		pair(const T1& a, const T2& b): first(a), second(b)
		{
			return ;
		}

		template<typename U, typename V>
		pair(const pair<U, V>& copy): first(copy.first), second(copy.second)
		{
			return ;
		}

		~pair(void)
		{
			return;
		}

		pair<T1, T2>&	operator=(const pair<T1, T2>& rhs)
		{
			if (this != &rhs) {
				this->first = rhs.first;
				this->second = rhs.second;
			}
			return (*this);
		}
	};

	template<typename T1, typename T2>
	bool	operator==(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

	template<typename T1, typename T2>
	bool	operator!=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return (!(lhs == rhs));
	}

	template<typename T1, typename T2>
	bool	operator<(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return (lhs.first < rhs.first || (!(rhs.first < lhs.first)
			&& lhs.second < rhs.second));
	}

	template<typename T1, typename T2>
	bool	operator<=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return (!(rhs < lhs));
	}

	template<typename T1, typename T2>
	bool	operator>(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return (rhs < lhs);
	}

	template<typename T1, typename T2>
	bool	operator>=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return (!(lhs < rhs));
	}

	template<typename T1, typename T2>
	pair<T1, T2>	make_pair(T1 x, T2 y)
	{
		return (pair<T1, T2>(x, y));
	}

}
