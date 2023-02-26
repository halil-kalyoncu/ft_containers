/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:05:23 by hkalyonc          #+#    #+#             */
/*   Updated: 2023/01/24 11:55:21 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{
	template<typename InputIterator1, typename InputIterator2>
	bool	equal(InputIterator1 first1, InputIterator1 last1,
		InputIterator2 first2)
	{
		while (first1 != last1) {
			if (!(*first1 == *first2)) {
				return (false);
			}
			first1++;
			first2++;
		}
		return (true);
	}

	template<typename InputIterator1, typename InputIterator2,
		typename BinaryPredicate>
	bool	equal(InputIterator1 first1, InputIterator1 last1,
		InputIterator2 first2, BinaryPredicate pred)
	{
		while (first1 != last1) {
			if (pred(*first1, *first2) == false) {
				return (false);
			}
			first1++;
			first2++;
		}
		return (true);
	}

}
