/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:24:55 by hkalyonc          #+#    #+#             */
/*   Updated: 2023/02/16 09:03:35 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{
	template <bool Cond, typename T = void>
	struct enable_if
	{
	};

	template <typename T>
	struct enable_if<true, T>
	{
		typedef T	type;
	};
}
