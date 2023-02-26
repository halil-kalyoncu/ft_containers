/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:31:52 by hkalyonc          #+#    #+#             */
/*   Updated: 2022/11/28 14:31:40 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{
	template<typename InputIterator1, typename InputIterator2>
	bool	lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
		InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1) {
			if (first2 == last2 || *first2 < *first1) {
				return (false);
			}
			if (*first1 < *first2) {
				return (true);
			}
			first1++;
			first2++;
		}
		return (first2 != last2);
	}

	template<typename InputIterator1, typename InputIterator2, typename Compare>
	bool	lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
		InputIterator2 first2, InputIterator2 last2, Compare comp)
	{
		while (first1 != last1) {
			if (first2 == last2 || comp(*first2, *first1) == true) {
				return (false);
			}
			if (comp(*first1, *first2) == true) {
				return (true);
			}
			first1++;
			first2++;
		}
		return (first2 != last2);
	}
}
