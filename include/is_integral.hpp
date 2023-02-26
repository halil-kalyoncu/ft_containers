/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 09:17:04 by hkalyonc          #+#    #+#             */
/*   Updated: 2023/02/24 09:15:53 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{
	template<typename T, T v>
	struct integral_constant
	{
		typedef T						value_type;
		typedef integral_constant<T, v>	type;

		static const T					value = v;

		operator T() const
		{
			return (this->value);
		}
	};

	struct false_type : public integral_constant<bool, false> {};
	struct true_type : public integral_constant<bool, true> {};

	template<typename T>
	class is_integral : public false_type {};

	template<>
	class is_integral<bool> : public true_type {};

	template<>
	class is_integral<char> : public true_type {};

	template<>
	class is_integral<wchar_t> : public true_type {};

	template<>
	class is_integral<signed char> : public true_type {};

	template<>
	class is_integral<short int> : public true_type {};

	template<>
	class is_integral<int> : public true_type {};

	template<>
	class is_integral<long int> : public true_type {};

	template<>
	class is_integral<long long int> : public true_type {};

	template<>
	class is_integral<unsigned char> : public true_type {};

	template<>
	class is_integral<unsigned short int> : public true_type {};

	template<>
	class is_integral<unsigned int> : public true_type {};

	template<>
	class is_integral<unsigned long int> : public true_type {};

	template<>
	class is_integral<unsigned long long int> : public true_type {};

	template<>
	class is_integral<const bool> : public true_type {};

	template<>
	class is_integral<const char> : public true_type {};

	template<>
	class is_integral<const wchar_t> : public true_type {};

	template<>
	class is_integral<const signed char> : public true_type {};

	template<>
	class is_integral<const short int> : public true_type {};

	template<>
	class is_integral<const int> : public true_type {};

	template<>
	class is_integral<const long int> : public true_type {};

	template<>
	class is_integral<const long long int> : public true_type {};

	template<>
	class is_integral<const unsigned char> : public true_type {};

	template<>
	class is_integral<const unsigned short int> : public true_type {};

	template<>
	class is_integral<const unsigned int> : public true_type {};

	template<>
	class is_integral<const unsigned long int> : public true_type {};

	template<>
	class is_integral<const unsigned long long int> : public true_type {};

	template<>
	class is_integral<volatile bool> : public true_type {};

	template<>
	class is_integral<volatile char> : public true_type {};

	template<>
	class is_integral<volatile wchar_t> : public true_type {};

	template<>
	class is_integral<volatile signed char> : public true_type {};

	template<>
	class is_integral<volatile short int> : public true_type {};

	template<>
	class is_integral<volatile int> : public true_type {};

	template<>
	class is_integral<volatile long int> : public true_type {};

	template<>
	class is_integral<volatile long long int> : public true_type {};

	template<>
	class is_integral<volatile unsigned char> : public true_type {};

	template<>
	class is_integral<volatile unsigned short int> : public true_type {};

	template<>
	class is_integral<volatile unsigned int> : public true_type {};

	template<>
	class is_integral<volatile unsigned long int> : public true_type {};

	template<>
	class is_integral<volatile unsigned long long int> : public true_type {};

	template<>
	class is_integral<const volatile bool> : public true_type {};

	template<>
	class is_integral<const volatile char> : public true_type {};

	template<>
	class is_integral<const volatile wchar_t> : public true_type {};

	template<>
	class is_integral<const volatile signed char> : public true_type {};

	template<>
	class is_integral<const volatile short int> : public true_type {};

	template<>
	class is_integral<const volatile int> : public true_type {};

	template<>
	class is_integral<const volatile long int> : public true_type {};

	template<>
	class is_integral<const volatile long long int> : public true_type {};

	template<>
	class is_integral<const volatile unsigned char> : public true_type {};

	template<>
	class is_integral<const volatile unsigned short int> : public true_type {};

	template<>
	class is_integral<const volatile unsigned int> : public true_type {};

	template<>
	class is_integral<const volatile unsigned long int> : public true_type {};

	template<>
	class is_integral<const volatile unsigned long long int> : public true_type {};
}
