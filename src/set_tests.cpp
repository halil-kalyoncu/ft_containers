/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tests.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:19:22 by hkalyonc          #+#    #+#             */
/*   Updated: 2023/02/24 12:26:07 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tester/test_utils.hpp"

//less
#include <functional>

#define SETUP_ARRAYS()															\
	int	int_array[64] =	{66, 711, 448, 960, 979, 597,							\
						949, 272, 69, 111, 735, 981,							\
						449, 581, 517, 865, 899, 797,							\
						919, 167, 396, 983, 824, 977,							\
						816, 320, 395, 790, 519, 219,							\
						301, 238, 223, 873, 699, 922,							\
						289, 181, 173, 782, 382, 849,							\
						267, 764, 104, 709, 574, 417,							\
						889, 41, 27, 924, 907, 958,								\
						666, 861, 113, 713, 665, 127,							\
						112, 509, 51, 1};										\
	size_t int_size = 64;														\
	std::string str_array[32] =	{"42", "MU2F0", "N2HFL", "9WI09", "YO8O4",		\
								"QTPXM", "VTA1H", "JNMAY", "MB2T9", "04KXI",	\
								"7EJ3W", "UYV07", "348IJ", "C697N", "Hello",	\
								"KEIX5", "GAXZN", "5VE7G", "627WN", "ITT5Q",	\
								"XJU87", "1MCZE", "WEOUR", "8TV0Q", "WAIX7",	\
								"3KWWA", "6XGM6", "B4TYI", "HBAHB", "FJZXV",	\
								"RWHL8", "LAST"};								\
	size_t str_size = 32;														\
	(void) int_array;															\
	(void) int_size;															\
	(void) str_array;															\
	(void) str_size;

static void	ft_set_constructor(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	SETUP_ARRAYS();

	struct timeval	begin;
	struct timeval	end;

	ft_print_title("default constructor", output_stream, benchmark_stream);

	gettimeofday(&begin, NULL);
	NAMESPACE::set<int>	s1;
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_container(s1, output_stream);

	gettimeofday(&begin, NULL);
	NAMESPACE::set<int>	s2((std::less<int>()));
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_container(s2, output_stream);
	return ;
}

static void	ft_set_range_constructor(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	SETUP_ARRAYS();

	struct timeval	begin;
	struct timeval	end;

	ft_print_title("range constructor", output_stream, benchmark_stream);

	gettimeofday(&begin, NULL);
	NAMESPACE::set<int>			s1(int_array, int_array + int_size);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_container(s1, output_stream);

	gettimeofday(&begin, NULL);
	NAMESPACE::set<std::string>	s2(str_array, str_array + str_size);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_container(s2, output_stream);
	return ;
}

static void	ft_set_copy_constructor(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	SETUP_ARRAYS();

	struct timeval				begin;
	struct timeval				end;
	NAMESPACE::set<int>			s1(int_array, int_array + int_size);
	NAMESPACE::set<std::string>	s2(str_array, str_array + str_size);

	ft_print_title("copy constructor", output_stream, benchmark_stream);

	gettimeofday(&begin, NULL);
	NAMESPACE::set<int>			s1_copy(s1);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_container(s1, output_stream);
	ft_print_container(s1_copy, output_stream);

	gettimeofday(&begin, NULL);
	NAMESPACE::set<std::string>	s2_copy(s2);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_container(s2, output_stream);
	ft_print_container(s2_copy, output_stream);
	return ;
}

static void	ft_set_assignment(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	SETUP_ARRAYS();

	struct timeval		begin;
	struct timeval		end;
	NAMESPACE::set<int>	s1;
	NAMESPACE::set<int>	s2(int_array, int_array + int_size);
	NAMESPACE::set<int>	s3(int_array, int_array + 15);

	ft_print_title("assignment", output_stream, benchmark_stream);
	ft_print_container(s1, output_stream);
	ft_print_container(s2, output_stream);

	gettimeofday(&begin, NULL);
	s1 = s2;
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_container(s1, output_stream);
	ft_print_container(s2, output_stream);
	ft_print_container(s3, output_stream);

	gettimeofday(&begin, NULL);
	s2 = s3;
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_container(s1, output_stream);
	ft_print_container(s2, output_stream);
	ft_print_container(s3, output_stream);
	return ;
}

static void	ft_set_iterators(std::ofstream& output_stream)
{
	SETUP_ARRAYS();

	NAMESPACE::set<int>					s(int_array, int_array + int_size);
	NAMESPACE::set<int>::iterator		it = s.begin();
	NAMESPACE::set<int>::iterator		it2 = s.begin();
	NAMESPACE::set<int>::iterator		it_end = s.end();
	NAMESPACE::set<int>::const_iterator	cit = s.begin();
	NAMESPACE::set<int>::const_iterator	cit2 = s.begin();
	NAMESPACE::set<int>::const_iterator	cit_end = s.end();

	output_stream << "\niterators" << std::endl;
	output_stream << (it == it2) << (it != it_end) << (it2 == it_end);
	output_stream << (it == cit) << (it == cit2) << (it2 == cit) << (it2 == cit2);
	output_stream << (cit == cit2) << (cit != cit_end) << (cit2 != cit_end) << std::endl;
	output_stream << *it << " " << *cit2 << std::endl;

	it++;
	cit++;
	output_stream << (it == it2) << (it != it_end) << (it2 == it_end);
	output_stream << (it == cit) << (it == cit2) << (it2 == cit) << (it2 == cit2);
	output_stream << (cit == cit2) << (cit != cit_end) << (cit2 != cit_end) << std::endl;
	output_stream << *it << " " << *cit2 << std::endl;

	while (it != it_end) {
		output_stream << *it << " ";
		it++;
	}
	output_stream << std::endl;
	return ;
}

static void	ft_set_reverse_iterators(std::ofstream& output_stream)
{
	SETUP_ARRAYS();

	NAMESPACE::set<int>							s(int_array, int_array + int_size);
	NAMESPACE::set<int>::reverse_iterator		rit = s.rbegin();
	NAMESPACE::set<int>::reverse_iterator		rit2 = s.rbegin();
	NAMESPACE::set<int>::reverse_iterator		rit_end = s.rend();
	NAMESPACE::set<int>::const_reverse_iterator	crit = s.rbegin();
	NAMESPACE::set<int>::const_reverse_iterator	crit2 = s.rbegin();
	NAMESPACE::set<int>::const_reverse_iterator	crit_end = s.rend();

	output_stream << "\nreverse iterators" << std::endl;
	output_stream << (rit == rit2) << (rit != rit_end) << (rit2 == rit_end);
	output_stream << (rit == crit) << (rit == crit2) << (rit2 == crit) << (rit2 == crit2);
	output_stream << (crit == crit2) << (crit != crit_end) << (crit2 != crit_end) << std::endl;
	output_stream << *rit << " " << *crit << std::endl;

	rit++;
	crit++;
	output_stream << (rit == rit2) << (rit != rit_end) << (rit2 == rit_end);
	output_stream << (rit == crit) << (rit == crit2) << (rit2 == crit) << (rit2 == crit2);
	output_stream << (crit == crit2) << (crit != crit_end) << (crit2 != crit_end) << std::endl;
	output_stream << *rit << " " << *crit << std::endl;

	while (rit != rit_end) {
		output_stream << *rit << " ";
		rit++;
	}
	output_stream << std::endl;
	return ;
}

static void	ft_set_empty(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	SETUP_ARRAYS();

	struct timeval		begin;
	struct timeval		end;
	NAMESPACE::set<int>	m;
	bool				is_empty;

	ft_print_title("empty", output_stream, benchmark_stream);
	gettimeofday(&begin, NULL);
	is_empty = m.empty();
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "set is empty: " << is_empty << std::endl;

	m.insert(42);
	is_empty = m.empty();
	output_stream << "set is empty: " << is_empty << std::endl;

	m.erase(42);
	is_empty = m.empty();
	output_stream << "set is empty: " << is_empty << std::endl;
	return ;
}

static void	ft_set_size(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	SETUP_ARRAYS();

	struct timeval					begin;
	struct timeval					end;
	NAMESPACE::set<int>				s1;
	NAMESPACE::set<int>				s2(int_array, int_array + int_size);
	NAMESPACE::set<int>				s3(int_array, int_array + 42);
	NAMESPACE::set<int>::size_type	size;
	
	ft_print_title("size", output_stream, benchmark_stream);

	gettimeofday(&begin, NULL);
	size = s1.size();
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "s1 size: " << size << std::endl;

	gettimeofday(&begin, NULL);
	size = s2.size();
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "s2 size: " << size << std::endl;

	gettimeofday(&begin, NULL);
	size = s3.size();
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "s3 size: " << size << std::endl;

	for (int i = 0; i < 10; i++) {
		s2.erase(s2.begin());
	}
	size = s2.size();
	output_stream << "s2 size: " << size << std::endl;
	return ;
}

// static void	ft_set_max_size(std::ofstream& output_stream)
// {
// 	SETUP_ARRAYS();

// 	NAMESPACE::set<int>			int_s1(int_array, int_array + int_size);
// 	NAMESPACE::set<int>			int_s2;
// 	NAMESPACE::set<std::string>	str_s1(str_array, str_array + str_size);
// 	NAMESPACE::set<std::string>	str_s2;

// 	output_stream << "\nmax_size" << std::endl;
// 	output_stream << "max_size of set with int: " << int_s1.max_size() << " (" << int_s2.max_size() << ")" << std::endl;
// 	output_stream << "max_size of set with string: " << str_s1.max_size() << " (" << str_s2.max_size() << ")" << std::endl;
// 	return ;
// }

static void	ft_set_insert(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	SETUP_ARRAYS();

	struct timeval											begin;
	struct timeval											end;
	NAMESPACE::set<int>										m(int_array, int_array + 15);
	NAMESPACE::pair<NAMESPACE::set<int>::iterator, bool>	insert_pair;

	ft_print_title("insert", output_stream, benchmark_stream);
	gettimeofday(&begin, NULL);
	insert_pair = m.insert(42);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "inserted: " << insert_pair.second << std::endl;
	output_stream << *(insert_pair.first) << std::endl;

	gettimeofday(&begin, NULL);
	insert_pair = m.insert(-42);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "inserted: " << insert_pair.second << std::endl;
	output_stream << *(insert_pair.first) << std::endl;

	gettimeofday(&begin, NULL);
	insert_pair = m.insert(42);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "inserted: " << insert_pair.second << std::endl;
	output_stream << *(insert_pair.first) << std::endl;

	gettimeofday(&begin, NULL);
	insert_pair = m.insert(42);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "inserted: " << insert_pair.second << std::endl;
	output_stream << *(insert_pair.first) << std::endl;

	ft_print_container(m, output_stream);
	return ;
}

static void	ft_set_insert_range(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	SETUP_ARRAYS();

	struct timeval		begin;
	struct timeval		end;
	NAMESPACE::set<int>	m;

	ft_print_title("insert range", output_stream, benchmark_stream);
	ft_print_container(m, output_stream);

	gettimeofday(&begin, NULL);
	m.insert(int_array, int_array + 10);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_container(m, output_stream);

	gettimeofday(&begin, NULL);
	m.insert(int_array + 10, int_array + 30);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_container(m, output_stream);

	gettimeofday(&begin, NULL);
	m.insert(int_array, int_array + 15);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_container(m, output_stream);

	gettimeofday(&begin, NULL);
	m.insert(int_array + 25, int_array + 40);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_container(m, output_stream);

	gettimeofday(&begin, NULL);
	m.insert(int_array + 40, int_array + int_size);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_container(m, output_stream);
	return ;
}

static void	ft_set_erase(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	SETUP_ARRAYS()

	struct timeval					begin;
	struct timeval					end;
	NAMESPACE::set<int>				m(int_array, int_array + int_size);
	NAMESPACE::set<int>::iterator	it;

	ft_print_title("erase", output_stream, benchmark_stream);
	ft_print_container(m, output_stream);

	it = m.begin();
	gettimeofday(&begin, NULL);
	m.erase(it);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_container(m, output_stream);

	it = m.end();
	it--;
	gettimeofday(&begin, NULL);
	m.erase(it);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_container(m, output_stream);

	it = m.begin();
	for (int i = 0; i < 5; i++) {
		it++;
	}
	gettimeofday(&begin, NULL);
	m.erase(it);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_container(m, output_stream);

	it = m.end();
	for (int i = 0; i < 10; i++) {
		it--;
	}
	gettimeofday(&begin, NULL);
	m.erase(it);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_container(m, output_stream);

	it = m.begin();
	gettimeofday(&begin, NULL);
	while (it != m.end()) {
		m.erase(it);
		ft_print_container(m, output_stream);
		it = m.begin();
	}
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_container(m, output_stream);
	return ;
}

static void	ft_set_erase_key(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	SETUP_ARRAYS();

	struct timeval					begin;
	struct timeval					end;
	NAMESPACE::set<int>				m(int_array, int_array + int_size);
	NAMESPACE::set<int>::size_type	size_erase;

	ft_print_title("erase key", output_stream, benchmark_stream);

	gettimeofday(&begin, NULL);
	size_erase = m.erase(111);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "111 erased: " << size_erase << std::endl;
	ft_print_container(m, output_stream);

	gettimeofday(&begin, NULL);
	size_erase = m.erase(301);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "301 erased: " << size_erase << std::endl;
	ft_print_container(m, output_stream);

	gettimeofday(&begin, NULL);
	size_erase = m.erase(42);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "42 erased: " << size_erase << std::endl;
	ft_print_container(m, output_stream);

	gettimeofday(&begin, NULL);
	size_erase = m.erase(4242);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "4242 erased: " << size_erase << std::endl;
	ft_print_container(m, output_stream);

	gettimeofday(&begin, NULL);
	size_erase = m.erase(41);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "41 erased: " << size_erase << std::endl;
	ft_print_container(m, output_stream);

	gettimeofday(&begin, NULL);
	size_erase = m.erase(1);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "1 erased: " << size_erase << std::endl;
	ft_print_container(m, output_stream);
	return ;
}

static void	ft_set_erase_range(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	SETUP_ARRAYS();

	struct timeval					begin;
	struct timeval					end;
	NAMESPACE::set<int>				m(int_array, int_array + int_size);
	NAMESPACE::set<int>::iterator	it;
	NAMESPACE::set<int>::iterator	it_end;

	ft_print_title("erase_range", output_stream, benchmark_stream);

	it = m.begin();
	it_end = m.end();
	for (int i = 0; i < 20; i++) {
		it++;
		it_end--;
	}
	gettimeofday(&begin, NULL);
	m.erase(it, it_end);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_container(m, output_stream);

	it = m.begin();
	it_end = m.end();
	for (int i = 0; i < 5; i++) {
		it++;
		it_end--;
	}
	for (int i = 0; i < 3; i++) {
		it++;
	}
	gettimeofday(&begin, NULL);
	m.erase(it, it_end);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_container(m, output_stream);

	gettimeofday(&begin, NULL);
	m.erase(m.begin(), m.end());
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_container(m, output_stream);
	return ;
}

static void	ft_set_swap(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	SETUP_ARRAYS();

	struct timeval		begin;
	struct timeval		end;
	NAMESPACE::set<int>	s1(int_array, int_array + int_size);
	NAMESPACE::set<int>	s2;

	ft_print_title("swap", output_stream, benchmark_stream);
	ft_print_container(s1, output_stream);
	ft_print_container(s2, output_stream);

	gettimeofday(&begin, NULL);
	s1.swap(s2);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_container(s1, output_stream);
	ft_print_container(s2, output_stream);

	gettimeofday(&begin, NULL);
	std::swap(s1, s2);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_container(s1, output_stream);
	ft_print_container(s2, output_stream);

	s2.insert(42);
	gettimeofday(&begin, NULL);
	s2.swap(s1);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_container(s1, output_stream);
	ft_print_container(s2, output_stream);

	gettimeofday(&begin, NULL);
	std::swap(s1, s2);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_container(s1, output_stream);
	ft_print_container(s2, output_stream);

	s1.clear();
	gettimeofday(&begin, NULL);
	s2.swap(s1);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_container(s1, output_stream);
	ft_print_container(s2, output_stream);

	s1.clear();
	gettimeofday(&begin, NULL);
	std::swap(s1, s2);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_container(s1, output_stream);
	ft_print_container(s2, output_stream);

	gettimeofday(&begin, NULL);
	s2.swap(s1);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_container(s1, output_stream);
	ft_print_container(s2, output_stream);

	gettimeofday(&begin, NULL);
	std::swap(s1, s2);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_container(s1, output_stream);
	ft_print_container(s2, output_stream);
	return ;
}

static void	ft_set_clear(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	SETUP_ARRAYS();

	struct timeval		begin;
	struct timeval		end;
	NAMESPACE::set<int>	s(int_array, int_array + int_size);

	ft_print_title("clear", output_stream, benchmark_stream);

	gettimeofday(&begin, NULL);
	s.clear();
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_container(s, output_stream);

	gettimeofday(&begin, NULL);
	s.clear();
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_container(s, output_stream);
	return ;
}

static void	ft_set_find(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	SETUP_ARRAYS();
	struct timeval								begin;
	struct timeval								end;
	NAMESPACE::set<int>							int_s(int_array, int_array + int_size);
	NAMESPACE::set<int>::iterator				it;
	const NAMESPACE::set<std::string>			str_s(str_array, str_array + str_size);
	NAMESPACE::set<std::string>::const_iterator	cit;

	ft_print_title("find", output_stream, benchmark_stream);

	gettimeofday(&begin, NULL);
	it = int_s.find(111);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << *it << std::endl;

	gettimeofday(&begin, NULL);
	it = int_s.find(320);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << *it << std::endl;

	gettimeofday(&begin, NULL);
	it = int_s.find(42);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	if (it == int_s.end()) {
		output_stream << "couldn't find '42'" << std::endl;
	}

	gettimeofday(&begin, NULL);
	cit = str_s.find("Hello");
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << *cit << std::endl;

	gettimeofday(&begin, NULL);
	cit = str_s.find("42");
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << *cit << std::endl;

	gettimeofday(&begin, NULL);
	cit = str_s.find("non");
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	if (cit == str_s.end()) {
		output_stream << "couldn't find 'non'" << std::endl;
	}
	return ;
}

static void	ft_set_count(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	SETUP_ARRAYS();

	struct timeval					begin;
	struct timeval					end;
	NAMESPACE::set<int>				int_s(int_array, int_array + int_size);
	NAMESPACE::set<int>::size_type	count_size;

	ft_print_title("count", output_stream, benchmark_stream);

	gettimeofday(&begin, NULL);
	count_size = int_s.count(949);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "count(949): " << count_size << std::endl;

	gettimeofday(&begin, NULL);
	count_size = int_s.count(41);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "count(41): " << count_size << std::endl;

	gettimeofday(&begin, NULL);
	count_size = int_s.count(42);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "count(42): " << count_size << std::endl;

	gettimeofday(&begin, NULL);
	count_size = int_s.count(2);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "count(2): " << count_size << std::endl;
	return ;
}

static void	ft_set_lower_bound(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	SETUP_ARRAYS();

	struct timeval					begin;
	struct timeval					end;
	NAMESPACE::set<int>				s(int_array, int_array + int_size);
	NAMESPACE::set<int>::iterator	it;

	ft_print_title("lower_bound", output_stream, benchmark_stream);

	gettimeofday(&begin, NULL);
	it = s.lower_bound(1);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << *it << std::endl;

	gettimeofday(&begin, NULL);
	it = s.lower_bound(42);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << *it << std::endl;

	gettimeofday(&begin, NULL);
	it = s.lower_bound(1000);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	if (it == s.end()) {
		output_stream << "returned end_iterator" << std::endl;
	}
	return ;
}

static void	ft_set_upper_bound(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	SETUP_ARRAYS();

	struct timeval					begin;
	struct timeval					end;
	NAMESPACE::set<int>				s(int_array, int_array + int_size);
	NAMESPACE::set<int>::iterator	it;

	ft_print_title("upper_bound", output_stream, benchmark_stream);

	gettimeofday(&begin, NULL);
	it = s.upper_bound(1);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << *it << std::endl;

	gettimeofday(&begin, NULL);
	it = s.upper_bound(42);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << *it << std::endl;

	gettimeofday(&begin, NULL);
	it = s.upper_bound(1000);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	if (it == s.end()) {
		output_stream << "returned end_iterator" << std::endl;
	}
	return ;
}

static void	ft_set_equal_range(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	SETUP_ARRAYS();

	struct timeval																	begin;
	struct timeval																	end;
	NAMESPACE::set<int>																s(int_array, int_array + int_size);
	NAMESPACE::pair<NAMESPACE::set<int>::iterator, NAMESPACE::set<int>::iterator>	pair_equalrange;

	ft_print_title("equal_range", output_stream, benchmark_stream);

	gettimeofday(&begin, NULL);
	pair_equalrange = s.equal_range(1);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "lower_bound: " << *(pair_equalrange.first) << " ";
	output_stream << "; upper_bound: " << *(pair_equalrange.second) << std::endl;

	gettimeofday(&begin, NULL);
	pair_equalrange = s.equal_range(42);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "lower_bound: " << *(pair_equalrange.first) << " ";
	output_stream << "; upper_bound: " << *(pair_equalrange.second) << std::endl;

	gettimeofday(&begin, NULL);
	pair_equalrange = s.equal_range(983);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "lower_bound: " << *(pair_equalrange.first) << " ";
	output_stream << "; upper_bound: ";
	if (pair_equalrange.second == s.end()) {
		output_stream << "end iterator";
	}
	output_stream << std::endl;

	gettimeofday(&begin, NULL);
	pair_equalrange = s.equal_range(1000);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "lower_bound: ";
	if (pair_equalrange.first == s.end()) {
		output_stream << "end iterator";
	}
	output_stream << "; upper_bound: ";
	if (pair_equalrange.second == s.end()) {
		output_stream << "end iterator";
	}
	output_stream << std::endl;
	return ;
}

static void	ft_set_relational_operators(std::ofstream& output_stream)
{
	SETUP_ARRAYS();

	NAMESPACE::set<int>	s1;
	NAMESPACE::set<int>	s2(int_array, int_array + int_size);
	NAMESPACE::set<int>	s3(int_array, int_array + 10);

	output_stream << "\nrelational operators" << std::endl;

	output_stream << (s1 == s1) << (s2 == s2) << (s3 == s3) << (s1 == s2) << (s2 == s3) << (s1 == s3) << std::endl;
	output_stream << (s1 != s1) << (s2 != s2) << (s3 != s3) << (s1 != s2) << (s2 != s3) << (s1 != s3) << std::endl;
	output_stream << (s1 < s1) << (s2 < s2) << (s3 < s3) << (s1 < s2) << (s2 < s3) << (s1 < s3) << std::endl;
	output_stream << (s1 <= s1) << (s2 <= s2) << (s3 <= s3) << (s1 <= s2) << (s2 <= s3) << (s1 <= s3) << std::endl;
	output_stream << (s1 > s1) << (s2 > s2) << (s3 > s3) << (s1 > s2) << (s2 > s3) << (s1 > s3) << std::endl;
	output_stream << (s1 >= s1) << (s2 >= s2) << (s3 >= s3) << (s1 >= s2) << (s2 >= s3) << (s1 >= s3) << std::endl;
	return ;
}

void	ft_test_set(void)
{
	std::ofstream	output_stream;
	std::string		output_file = std::string("logs/output/") + STRING_NAMESPACE
										+ std::string("_set.log");
	std::ofstream	benchmark_stream;
	std::string		benchmark_file = std::string("logs/benchmark/") + STRING_NAMESPACE
										+ std::string("_set.log");

	output_stream.open(output_file.c_str());
	benchmark_stream.open(benchmark_file.c_str());
	if (output_stream.fail() == true) {
		std::cerr << "Failed to create outputfile for set" << std::endl;
		return ;
	}
	if (benchmark_stream.fail() == true) {
		std::cerr << "Failed to create benchmarkfile for set" << std::endl;
		output_stream.close();
		return ;
	}
	std::cout << "running SET tests" << std::endl;

	ft_print_title("SET", output_stream, benchmark_stream);
	ft_set_constructor(output_stream, benchmark_stream);
	ft_set_range_constructor(output_stream, benchmark_stream);
	ft_set_copy_constructor(output_stream, benchmark_stream);
	ft_set_assignment(output_stream, benchmark_stream);
	ft_set_iterators(output_stream);
	ft_set_reverse_iterators(output_stream);
	ft_set_empty(output_stream, benchmark_stream);
	ft_set_size(output_stream, benchmark_stream);
	//ft_set_max_size(output_stream);
	ft_set_insert(output_stream, benchmark_stream);
	ft_set_insert_range(output_stream, benchmark_stream);
	ft_set_erase(output_stream, benchmark_stream);
	ft_set_erase_key(output_stream, benchmark_stream);
	ft_set_erase_range(output_stream, benchmark_stream);
	ft_set_swap(output_stream, benchmark_stream);
	ft_set_clear(output_stream, benchmark_stream);
	ft_set_find(output_stream, benchmark_stream);
	ft_set_count(output_stream, benchmark_stream);
	ft_set_lower_bound(output_stream, benchmark_stream);
	ft_set_upper_bound(output_stream, benchmark_stream);
	ft_set_equal_range(output_stream, benchmark_stream);
	ft_set_relational_operators(output_stream);

	output_stream.close();
	benchmark_stream.close();
	std::cout << "finished SET tests" << std::endl;
	return ;
}