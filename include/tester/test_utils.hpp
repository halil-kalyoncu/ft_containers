/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 09:23:33 by hkalyonc          #+#    #+#             */
/*   Updated: 2023/02/24 11:15:38 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define NAMESPACE std
#define STRING_NAMESPACE "std"
#ifdef STD
	#include <map>
	#include <stack>
	#include <vector>
	#include <set>
#else
	#undef NAMESPACE
	#define NAMESPACE ft
	#undef STRING_NAMESPACE
	#define STRING_NAMESPACE "ft"
	#include "../map.hpp"
	#include "../stack.hpp"
	#include "../vector.hpp"
	#include "../set.hpp"
	#include "../pair.hpp"
#endif

//cerr
#include <iostream>
//ofstream
#include <fstream>
#include <stdio.h>
#include <sys/time.h>

void	ft_print_time(struct timeval& begin, struct timeval& end,
	std::ofstream& benchmark_stream);

void	ft_print_title(const std::string& title, std::ofstream& output_stream,
	std::ofstream& benchmark_stream);

template<typename T1, typename T2>
std::ostream&	operator<<(std::ostream& oStream, const NAMESPACE::pair<T1, T2>& rhs)
{
	oStream << "["<< rhs.first << "," << rhs.second << "]";
	return (oStream);
}

template<typename T>
void	ft_print_container(const T& container, std::ofstream& ofStream)
{
	typename T::const_iterator	cit = container.begin();

	ofStream << "size: " << container.size() << ", content: [";
	while (cit != container.end()) {
		ofStream << *cit << " ";
		cit++;
	}
	ofStream << "]" << std::endl;
	return ;
}

template<typename Vector>
void	ft_print_vector(const Vector& container, std::ofstream& ofStream)
{
	typename Vector::const_iterator	cit = container.begin();

	ofStream << "size: " << container.size() << ", capacity: " << container.capacity();
	ofStream << ", content: [";
	while (cit != container.end()) {
		ofStream << *cit << " ";
		cit++;
	}
	ofStream << "]" << std::endl;
	return ;
}

void	ft_test_stack(void);
void	ft_test_vector(void);
void	ft_test_map(void);
void	ft_test_set(void);