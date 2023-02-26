/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:37:12 by hkalyonc          #+#    #+#             */
/*   Updated: 2023/02/16 09:09:13 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

//ptrdiff_t
#include <cstddef>
//random_access_iterator_tag
#include <iterator>

namespace ft
{
	template <typename T>
	struct iterator_traits
	{
		typedef typename T::difference_type		difference_type;
		typedef typename T::value_type			value_type;
		typedef typename T::pointer				pointer;
		typedef typename T::reference			reference;
		typedef typename T::iterator_category	iterator_category;
	};

	template <typename T>
	struct iterator_traits<T*>
	{
		typedef ptrdiff_t						difference_type;
		typedef T								value_type;
		typedef value_type*						pointer;
		typedef value_type&						reference;
		typedef std::random_access_iterator_tag	iterator_category;
	};

}
