/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:54:12 by hkalyonc          #+#    #+#             */
/*   Updated: 2023/02/24 12:25:26 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tester/test_utils.hpp"

//length_error, out_of_range
#include <stdexcept>
//swap
#include <algorithm>

#define SETUP_ARRAYS()															\
	int	int_array[64] =	{464, 767, 603, 886, 265, 339,							\
						456, 51, 73, 255, 304, 133,								\
						943, 969, 347, 477, 211, 539,							\
						604, 465, 137, 607, 648, 974,							\
						276, 1, 832, 868, 68, 837,								\
						445, 839, 784, 508, 87, 450,							\
						77, 731, 512, 542, 45, 236,								\
						345, 240, 951, 107, 371, 356,							\
						615, 695, 124, 247, 925, 447,							\
						386, 734, 294, 338, 532, 612,							\
						914, 495, 222, 852};									\
	size_t int_size = 64;														\
	std::string str_array[32] =	{"Y16U5", "PAONX", "CXAB8", "8EELO", "SWD86",	\
								"USRIY", "26VX5", "F6G1F", "1VWBJ", "BT5EM",	\
								"43H53", "KTBYV", "FVJUV", "ROBR5", "JQWX1",	\
								"TLGLV", "P1EPD", "WG15O", "H6412", "HXW45",	\
								"U9JOF", "IRDU3", "3WU5H", "0AXBJ", "VBFKL",	\
								"TSS5T", "ZVH9A", "4SUE3", "8C6XY", "CTK5Y",	\
								"3EPVP", "D7V17"};								\
	size_t str_size = 32;														\
	(void) int_array;															\
	(void) int_size;															\
	(void) str_array;															\
	(void) str_size;

static void	ft_vector_constructor(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	struct timeval	begin;
	struct timeval	end;

	ft_print_title("default constructor", output_stream, benchmark_stream);

	gettimeofday(&begin, NULL);
	NAMESPACE::vector<int>	v;
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_vector(v, output_stream);
	return ;
}

static void	ft_vector_fill_constructor(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	struct timeval	begin;
	struct timeval	end;

	ft_print_title("fill constructor", output_stream, benchmark_stream);

	gettimeofday(&begin, NULL);
	NAMESPACE::vector<int>	v1(15, 42);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_vector(v1, output_stream);

	gettimeofday(&begin, NULL);
	NAMESPACE::vector<int>	v2(0, 42);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_vector(v2, output_stream);

	gettimeofday(&begin, NULL);
	NAMESPACE::vector<std::string>	v3(15, "42");
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_vector(v3, output_stream);

	gettimeofday(&begin, NULL);
	NAMESPACE::vector<std::string>	v4(0, "42");
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_vector(v4, output_stream);
	return ;
}

static void	ft_vector_range_constructor(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	SETUP_ARRAYS();

	struct timeval	begin;
	struct timeval	end;

	ft_print_title("range constructor", output_stream, benchmark_stream);

	gettimeofday(&begin, NULL);
	NAMESPACE::vector<int>	v1(int_array, int_array + int_size);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_vector(v1, output_stream);

	gettimeofday(&begin, NULL);
	NAMESPACE::vector<std::string>	v2(str_array, str_array + str_size);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_vector(v2, output_stream);
	return ;
}

static void	ft_vector_copy_constructor(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	SETUP_ARRAYS();

	struct timeval					begin;
	struct timeval					end;
	NAMESPACE::vector<int>			v1(int_array, int_array + int_size);
	NAMESPACE::vector<std::string>	v2(str_array, str_array + str_size);

	ft_print_title("copy constructor", output_stream, benchmark_stream);

	gettimeofday(&begin, NULL);
	NAMESPACE::vector<int>	v1_copy(v1);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_vector(v1, output_stream);
	ft_print_vector(v1_copy, output_stream);

	gettimeofday(&begin, NULL);
	NAMESPACE::vector<std::string>	v2_copy(v2);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_vector(v2, output_stream);
	ft_print_vector(v2_copy, output_stream);
	return ;
}

static void	ft_vector_assignment(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	SETUP_ARRAYS();

	struct timeval			begin;
	struct timeval			end;
	NAMESPACE::vector<int>	v1;
	NAMESPACE::vector<int>	v2(int_array, int_array + int_size);
	NAMESPACE::vector<int>	v3(int_array, int_array + 15);
	NAMESPACE::vector<int>	v4(int_array, int_array + 20);

	ft_print_title("assignment", output_stream, benchmark_stream);
	ft_print_vector(v1, output_stream);
	ft_print_vector(v2, output_stream);

	gettimeofday(&begin, NULL);
	v1 = v2;
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_vector(v1, output_stream);
	ft_print_vector(v2, output_stream);
	ft_print_vector(v3, output_stream);

	gettimeofday(&begin, NULL);
	v2 = v3;
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_vector(v1, output_stream);
	ft_print_vector(v2, output_stream);
	ft_print_vector(v3, output_stream);

	gettimeofday(&begin, NULL);
	v3 = v4;
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_vector(v3, output_stream);
	ft_print_vector(v4, output_stream);

	gettimeofday(&begin, NULL);
	v4 = v1;
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_vector(v1, output_stream);
	ft_print_vector(v4, output_stream);
	return ;
}

static void	ft_vector_iterators(std::ofstream& output_stream)
{
	SETUP_ARRAYS();

	NAMESPACE::vector<int>					v(int_array, int_array + int_size);
	NAMESPACE::vector<int>::iterator		it = v.begin();
	NAMESPACE::vector<int>::iterator		it2 = v.begin();
	NAMESPACE::vector<int>::iterator		it_end = v.end();
	NAMESPACE::vector<int>::const_iterator	cit = v.begin();
	NAMESPACE::vector<int>::const_iterator	cit2 = v.begin();
	NAMESPACE::vector<int>::const_iterator	cit_end = v.end();

	output_stream << "\niterators" << std::endl;
	output_stream << (it == it2) << (it != it_end) << (it2 == it_end) << (it < it2) << (it <= it2) << (it > it2) << (it >= it2);
	output_stream << (it == it2 + 1) << (it != it_end - 1) << (it2 == it_end) << (it < it2 - 1) << (it <= it2 + 2) << (it > it2 - 1) << (it + 3 >= it2);
	output_stream << (it == cit) << (it == cit2) << (it2 == cit) << (it2 == cit2);
	output_stream << (cit == cit2) << (cit != cit_end) << (cit2 == cit_end) << (cit < cit2) << (cit <= cit2) << (cit > cit2) << (cit >= cit2);
	output_stream << (cit == cit2 + 1) << (cit != cit_end - 1) << (cit2 == cit_end) << (cit < cit2 - 1) << (cit <= cit2 + 2) << (cit > cit2 - 1) << (cit + 3 >= cit2);
	output_stream << *it << " " << *cit2 << std::endl;

	it++;
	cit += 2;
	output_stream << (it == it2) << (it != it_end) << (it2 == it_end) << (it < it2) << (it <= it2) << (it > it2) << (it >= it2);
	output_stream << (it == it2 + 1) << (it != it_end - 1) << (it2 == it_end) << (it < it2 - 1) << (it <= it2 + 2) << (it > it2 - 1) << (it + 3 >= it2);
	output_stream << (it == cit) << (it == cit2) << (it2 == cit) << (it2 == cit2);
	output_stream << (cit == cit2) << (cit != cit_end) << (cit2 == cit_end) << (cit < cit2) << (cit <= cit2) << (cit > cit2) << (cit >= cit2);
	output_stream << (cit == cit2 + 1) << (cit != cit_end - 1) << (cit2 == cit_end) << (cit < cit2 - 1) << (cit <= cit2 + 2) << (cit > cit2 - 1) << (cit + 3 >= cit2);
	output_stream << *it << " " << *cit2 << std::endl;

	ft_print_vector(v, output_stream);
	*it = 42;
	ft_print_vector(v, output_stream);

	while (it != it_end) {
		output_stream << *it << " ";
		it++;
	}
	output_stream << std::endl;
	return ;
}

static void	ft_vector_reverse_iterators(std::ofstream& output_stream)
{
	SETUP_ARRAYS();

	NAMESPACE::vector<int>							v(int_array, int_array + int_size);
	NAMESPACE::vector<int>::reverse_iterator		rit = v.rbegin();
	NAMESPACE::vector<int>::reverse_iterator		rit2 = v.rbegin();
	NAMESPACE::vector<int>::reverse_iterator		rit_end = v.rend();
	NAMESPACE::vector<int>::const_reverse_iterator	crit = v.rbegin();
	NAMESPACE::vector<int>::const_reverse_iterator	crit2 = v.rbegin();
	NAMESPACE::vector<int>::const_reverse_iterator	crit_end = v.rend();

	output_stream << "\nreverse iterators" << std::endl;
	output_stream << (rit == rit2) << (rit != rit_end) << (rit2 == rit_end) << (rit < rit2) << (rit <= rit2) << (rit > rit2) << (rit >= rit2);
	output_stream << (rit == rit2 + 1) << (rit != rit_end - 1) << (rit2 == rit_end) << (rit < rit2 - 1) << (rit <= rit2 + 2) << (rit > rit2 - 1) << (rit + 3 >= rit2);
	output_stream << (rit == crit) << (rit == crit2) << (rit2 == crit) << (rit2 == crit2);
	output_stream << (crit == crit2) << (crit != crit_end) << (crit2 == crit_end) << (crit < crit2) << (crit <= crit2) << (crit > crit2) << (crit >= crit2);
	output_stream << (crit == crit2 + 1) << (crit != crit_end - 1) << (crit2 == crit_end) << (crit < crit2 - 1) << (crit <= crit2 + 2) << (crit > crit2 - 1) << (crit + 3 >= crit2);
	output_stream << *rit << " " << *crit2 << std::endl;

	rit++;
	crit += 2;
	output_stream << (rit == rit2) << (rit != rit_end) << (rit2 == rit_end) << (rit < rit2) << (rit <= rit2) << (rit > rit2) << (rit >= rit2);
	output_stream << (rit == rit2 + 1) << (rit != rit_end - 1) << (rit2 == rit_end) << (rit < rit2 - 1) << (rit <= rit2 + 2) << (rit > rit2 - 1) << (rit + 3 >= rit2);
	output_stream << (rit == crit) << (rit == crit2) << (rit2 == crit) << (rit2 == crit2);
	output_stream << (crit == crit2) << (crit != crit_end) << (crit2 == crit_end) << (crit < crit2) << (crit <= crit2) << (crit > crit2) << (crit >= crit2);
	output_stream << (crit == crit2 + 1) << (crit != crit_end - 1) << (crit2 == crit_end) << (crit < crit2 - 1) << (crit <= crit2 + 2) << (crit > crit2 - 1) << (crit + 3 >= crit2);
	output_stream << *rit << " " << *crit2 << std::endl;

	ft_print_vector(v, output_stream);
	*rit = 42;
	ft_print_vector(v, output_stream);

	while (rit != rit_end) {
		output_stream << *rit << " ";
		rit++;
	}
	output_stream << std::endl;
	return ;
}

static void	ft_vector_size(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	SETUP_ARRAYS();

	struct timeval						begin;
	struct timeval						end;
	NAMESPACE::vector<int>				v1;
	NAMESPACE::vector<int>				v2(int_array, int_array + int_size);
	NAMESPACE::vector<int>				v3(int_array, int_array + 42);
	NAMESPACE::vector<int>::size_type	size;

	ft_print_title("size", output_stream, benchmark_stream);

	gettimeofday(&begin, NULL);
	size = v1.size();
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "v1 size: " << size << std::endl;

	gettimeofday(&begin, NULL);
	size = v2.size();
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "v2 size: " << size << std::endl;

	gettimeofday(&begin, NULL);
	size = v3.size();
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "v3 size: " << size << std::endl;

	for (int i = 0; i < 10; i++) {
		v2.erase(v2.begin());
	}
	size = v2.size();
	output_stream << "v2 size: " << size << std::endl;
	return ;
}

static void	ft_vector_max_size(std::ofstream& output_stream)
{
	SETUP_ARRAYS();

	NAMESPACE::vector<int>			int_v1(int_array, int_array + int_size);
	NAMESPACE::vector<int>			int_v2;
	NAMESPACE::vector<std::string>	str_v1(str_array, str_array + str_size);
	NAMESPACE::vector<std::string>	str_v2;

	output_stream << "\nmax_size" << std::endl;
	output_stream << "max_size of map with int and string: " << int_v1.max_size() << " (" << int_v2.max_size() << ")" << std::endl;
	output_stream << "max_size of map with string and string: " << str_v1.max_size() << " (" << str_v2.max_size() << ")" << std::endl;
	return ;
}

static void	ft_vector_resize(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	SETUP_ARRAYS();

	struct timeval			begin;
	struct timeval			end;
	NAMESPACE::vector<int>	v(int_array, int_array + 10);

	ft_print_title("resize", output_stream, benchmark_stream);

	gettimeofday(&begin, NULL);
	v.resize(42, 42);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_vector(v, output_stream);

	gettimeofday(&begin, NULL);
	v.resize(10, 1);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_vector(v, output_stream);

	gettimeofday(&begin, NULL);
	v.resize(42, 1);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_vector(v, output_stream);

	gettimeofday(&begin, NULL);
	v.resize(64, 0);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_vector(v, output_stream);

	try {
		v.resize(v.max_size() + 1);
	}
	catch (const std::length_error& le) {
		output_stream << le.what() << std::endl;
	}
	return ;
}

static void	ft_vector_capacity(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	SETUP_ARRAYS();

	struct timeval						begin;
	struct timeval						end;
	NAMESPACE::vector<int>				v1;
	NAMESPACE::vector<int>				v2(int_array, int_array + int_size);
	NAMESPACE::vector<int>::size_type	v_capacity;

	ft_print_title("capacity", output_stream, benchmark_stream);

	gettimeofday(&begin, NULL);
	v_capacity = v1.capacity();
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "capacity: " << v_capacity << std::endl;
	ft_print_vector(v1, output_stream);

	v1.push_back(42);
	gettimeofday(&begin, NULL);
	v_capacity = v1.capacity();
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "capacity: " << v_capacity << std::endl;
	ft_print_vector(v1, output_stream);

	v1.push_back(43);
	gettimeofday(&begin, NULL);
	v_capacity = v1.capacity();
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "capacity: " << v_capacity << std::endl;
	ft_print_vector(v1, output_stream);

	v1.push_back(44);
	gettimeofday(&begin, NULL);
	v_capacity = v1.capacity();
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "capacity: " << v_capacity << std::endl;
	ft_print_vector(v1, output_stream);

	v1.assign(2, 45);
	gettimeofday(&begin, NULL);
	v_capacity = v1.capacity();
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "capacity: " << v_capacity << std::endl;
	ft_print_vector(v1, output_stream);

	v1.assign(20, 45);
	gettimeofday(&begin, NULL);
	v_capacity = v1.capacity();
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "capacity: " << v_capacity << std::endl;
	ft_print_vector(v1, output_stream);

	v2.resize(42, 42);
	gettimeofday(&begin, NULL);
	v_capacity = v2.capacity();
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "capacity: " << v_capacity << std::endl;
	ft_print_vector(v2, output_stream);;
	return ;
}

static void	ft_vector_empty(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	SETUP_ARRAYS();

	struct timeval			begin;
	struct timeval			end;
	NAMESPACE::vector<int>	v1;
	NAMESPACE::vector<int>	v2(int_array, int_array + int_size);
	bool					is_empty;

	ft_print_title("empty", output_stream, benchmark_stream);

	ft_print_vector(v1, output_stream);
	gettimeofday(&begin, NULL);
	is_empty = v1.empty();
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "vector is empty: " << is_empty << std::endl;

	v1.push_back(42);
	ft_print_vector(v1, output_stream);
	gettimeofday(&begin, NULL);
	is_empty = v1.empty();
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "vector is empty: " << is_empty << std::endl;

	ft_print_vector(v2, output_stream);
	gettimeofday(&begin, NULL);
	is_empty = v2.empty();
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "vector is empty: " << is_empty << std::endl;

	v2.clear();
	ft_print_vector(v2, output_stream);
	gettimeofday(&begin, NULL);
	is_empty = v2.empty();
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "vector is empty: " << is_empty << std::endl;
	return ;
}

static void	ft_vector_reserve(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	SETUP_ARRAYS();

	struct timeval			begin;
	struct timeval			end;
	NAMESPACE::vector<int>	v;

	ft_print_title("reverve", output_stream, benchmark_stream);

	gettimeofday(&begin, NULL);
	v.reserve(42);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_vector(v, output_stream);

	gettimeofday(&begin, NULL);
	v.reserve(42);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_vector(v, output_stream);

	gettimeofday(&begin, NULL);
	v.reserve(0);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_vector(v, output_stream);

	gettimeofday(&begin, NULL);
	v.reserve(42);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_vector(v, output_stream);

	gettimeofday(&begin, NULL);
	v.reserve(64);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_vector(v, output_stream);
	return ;
}

static void	ft_vector_index_operator(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	SETUP_ARRAYS();

	struct timeval							begin;
	struct timeval							end;
	NAMESPACE::vector<int>					int_v(int_array, int_array + int_size);
	int										int_value;
	const NAMESPACE::vector<std::string>	str_v(str_array, str_array + str_size);

	ft_print_title("operator []", output_stream, benchmark_stream);

	gettimeofday(&begin, NULL);
	int_value = int_v[0];
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "v1[0]: " << int_value << std::endl;

	gettimeofday(&begin, NULL);
	int_value = int_v[42];
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "v1[42]: " << int_value << std::endl;

	gettimeofday(&begin, NULL);
	int_value = int_v[int_size - 1];
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "v1[63]: " << int_value << std::endl;

	gettimeofday(&begin, NULL);
	const std::string	str_value1 = str_v[0];
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "v2[0]: " << str_value1 << std::endl;

	gettimeofday(&begin, NULL);
	const std::string	str_value2 = str_v[str_size - 1];
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "v2[31]: " << str_value2 << std::endl;
	return ;
}

static void	ft_vector_at(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	SETUP_ARRAYS();

	struct timeval							begin;
	struct timeval							end;
	NAMESPACE::vector<int>					int_v(int_array, int_array + int_size);
	int										int_value;
	const NAMESPACE::vector<std::string>	str_v(str_array, str_array + str_size);

	ft_print_title("at", output_stream, benchmark_stream);

	gettimeofday(&begin, NULL);
	int_value = int_v.at(0);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "v1[0]: " << int_value << std::endl;

	gettimeofday(&begin, NULL);
	int_value = int_v.at(42);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "v1[42]: " << int_value << std::endl;

	gettimeofday(&begin, NULL);
	int_value = int_v.at(int_size - 1);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "v1[63]: " << int_value << std::endl;

	try {
		int_value = int_v.at(int_size);
		output_stream << "v1[64]: " << int_value << std::endl;
	}
	catch (const std::out_of_range& e) {
		output_stream << e.what() << std::endl;
	}

	gettimeofday(&begin, NULL);
	const std::string	str_value1 = str_v[0];
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "v2[0]: " << str_value1 << std::endl;

	gettimeofday(&begin, NULL);
	const std::string	str_value2 = str_v[0];
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "v2[31]: " << str_value2 << std::endl;

	try {
		const std::string	str_value3 = str_v[0];
		output_stream << "v1[64]: " << str_value3 << std::endl;
	}
	catch (const std::out_of_range& e) {
		output_stream << e.what() << std::endl;
	}
	return ;
}

static void	ft_vector_front(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	SETUP_ARRAYS();

	struct timeval	begin;
	struct timeval	end;
	NAMESPACE::vector<int>					int_v(int_array, int_array + int_size);
	int										int_value;
	const NAMESPACE::vector<std::string>	str_v(str_array, str_array + str_size);
	
	ft_print_title("front", output_stream, benchmark_stream);

	gettimeofday(&begin, NULL);
	int_value = int_v.front();
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "v1.front(): " << int_value << std::endl;

	if (&(int_v.front()) != &(int_v[0])) {
		output_stream << "front returns the wrong reference " << int_value << std::endl;
	}

	gettimeofday(&begin, NULL);
	const std::string	str_value = str_v.front();
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "v2.front(): " << str_value << std::endl;

	if (&(str_v.front()) != &(str_v[0])) {
		output_stream << "front returns the wrong reference " << int_value << std::endl;
	}
	return ;
}

static void	ft_vector_back(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	SETUP_ARRAYS();

	struct timeval	begin;
	struct timeval	end;
	NAMESPACE::vector<int>					int_v(int_array, int_array + int_size);
	int										int_value;
	const NAMESPACE::vector<std::string>	str_v(str_array, str_array + str_size);
	
	ft_print_title("back", output_stream, benchmark_stream);

	gettimeofday(&begin, NULL);
	int_value = int_v.back();
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "v1.back(): " << int_value << std::endl;

	if (&(int_v.front()) != &(int_v[0])) {
		output_stream << "back returns the wrong reference " << int_value << std::endl;
	}

	gettimeofday(&begin, NULL);
	const std::string	str_value = str_v.back();
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "v2.back(): " << str_value << std::endl;

	if (&(str_v.front()) != &(str_v[0])) {
		output_stream << "back returns the wrong reference " << int_value << std::endl;
	}
	return ;
}

static void	ft_vector_data(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	SETUP_ARRAYS();

	struct timeval									begin;
	struct timeval									end;
	NAMESPACE::vector<int>							int_v(int_array, int_array + int_size);
	NAMESPACE::vector<int>::iterator				int_it = int_v.begin();
	int*											int_ptr;
	const NAMESPACE::vector<std::string>			str_v(str_array, str_array + str_size);
	NAMESPACE::vector<std::string>::const_iterator	str_it = str_v.begin();
	const std::string*								str_ptr;
	size_t											i;

	ft_print_title("data", output_stream, benchmark_stream);

	gettimeofday(&begin, NULL);
	int_ptr = int_v.data();
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	i = 0;
	while (int_it != int_v.end()) {
		if (*int_it != int_ptr[i]) {
			output_stream << "data entries are not equal" << std::endl;
			break ;
		}
		int_it++;
		i++;
	}
	ft_print_vector(int_v, output_stream);
	int_ptr[0] = 42;
	ft_print_vector(int_v, output_stream);

	gettimeofday(&begin, NULL);
	str_ptr = str_v.data();
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	i = 0;
	while (str_it != str_v.end()) {
		if (*str_it != str_ptr[i]) {
			output_stream << "data entries are not equal" << std::endl;
			break ;
		}
		str_it++;
		i++;
	}
	return ;
}

static void	ft_vector_assign_range(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	SETUP_ARRAYS();

	struct timeval					begin;
	struct timeval					end;
	NAMESPACE::vector<int>			int_v;
	NAMESPACE::vector<std::string>	str_v;

	ft_print_title("assign range", output_stream, benchmark_stream);

	gettimeofday(&begin, NULL);
	int_v.assign(int_array, int_array + 10);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_vector(int_v, output_stream);

	gettimeofday(&begin, NULL);
	int_v.assign(int_array, int_array + int_size);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_vector(int_v, output_stream);

	gettimeofday(&begin, NULL);
	int_v.assign(int_array, int_array + 20);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_vector(int_v, output_stream);
	
	gettimeofday(&begin, NULL);
	int_v.assign(int_array, int_array);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_vector(int_v, output_stream);

	gettimeofday(&begin, NULL);
	str_v.assign(str_array, str_array + 10);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_vector(str_v, output_stream);

	gettimeofday(&begin, NULL);
	str_v.assign(str_array, str_array + str_size);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_vector(str_v, output_stream);

	gettimeofday(&begin, NULL);
	str_v.assign(str_array, str_array + 20);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_vector(str_v, output_stream);

	gettimeofday(&begin, NULL);
	str_v.assign(str_array, str_array);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_vector(str_v, output_stream);
	return ;
}

static void	ft_vector_assign(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	SETUP_ARRAYS();

	struct timeval					begin;
	struct timeval					end;
	NAMESPACE::vector<int>			int_v;
	NAMESPACE::vector<std::string>	str_v;

	ft_print_title("assign", output_stream, benchmark_stream);

	gettimeofday(&begin, NULL);
	int_v.assign(10, 10);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_vector(int_v, output_stream);

	gettimeofday(&begin, NULL);
	int_v.assign(64, 64);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_vector(int_v, output_stream);

	gettimeofday(&begin, NULL);
	int_v.assign(20, 20);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_vector(int_v, output_stream);
	
	gettimeofday(&begin, NULL);
	int_v.assign(0, 0);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_vector(int_v, output_stream);

	gettimeofday(&begin, NULL);
	str_v.assign(10, "ten");
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_vector(str_v, output_stream);

	gettimeofday(&begin, NULL);
	str_v.assign(32, "32");
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_vector(str_v, output_stream);

	gettimeofday(&begin, NULL);
	str_v.assign(20, "twenty");
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_vector(str_v, output_stream);

	gettimeofday(&begin, NULL);
	str_v.assign(0, "zero");
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_vector(str_v, output_stream);
	return ;
}

static void	ft_vector_push_back(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	SETUP_ARRAYS();

	struct timeval			begin;
	struct timeval			end;
	NAMESPACE::vector<int>	v;

	ft_print_title("push_back", output_stream, benchmark_stream);

	gettimeofday(&begin, NULL);
	v.push_back(42);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_vector(v, output_stream);

	for (int i = 1; i < 42; i++) {
		v.push_back(i);
	}
	ft_print_vector(v, output_stream);

	gettimeofday(&begin, NULL);
	v.push_back(42);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_vector(v, output_stream);
	return ;
}

static void	ft_vector_pop_back(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	SETUP_ARRAYS();

	struct timeval			begin;
	struct timeval			end;
	NAMESPACE::vector<int>	v(int_array, int_array + int_size);

	ft_print_title("pop_back", output_stream, benchmark_stream);

	gettimeofday(&begin, NULL);
	v.pop_back();
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_vector(v, output_stream);

	for (int i = 1; i < 42; i++) {
		v.pop_back();
	}
	ft_print_vector(v, output_stream);

	gettimeofday(&begin, NULL);
	v.pop_back();
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_vector(v, output_stream);
	return ;
}

static void	ft_vector_insert(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	SETUP_ARRAYS();

	struct timeval						begin;
	struct timeval						end;
	NAMESPACE::vector<int>				v;
	NAMESPACE::vector<int>::iterator	it;

	ft_print_title("insert", output_stream, benchmark_stream);

	gettimeofday(&begin, NULL);
	it = v.insert(v.end(), 42);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "inserted: " << *it;
	ft_print_vector(v, output_stream);

	gettimeofday(&begin, NULL);
	it = v.insert(v.begin(), 1);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "inserted: " << *it;
	ft_print_vector(v, output_stream);

	gettimeofday(&begin, NULL);
	it = v.insert(v.begin() + 1, 2);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "inserted: " << *it;
	ft_print_vector(v, output_stream);

	gettimeofday(&begin, NULL);
	it = v.insert(v.end() - 1, 41);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "inserted: " << *it;
	ft_print_vector(v, output_stream);

	gettimeofday(&begin, NULL);
	it = v.insert(v.begin() + 2, 3);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "inserted: " << *it;
	ft_print_vector(v, output_stream);

	gettimeofday(&begin, NULL);
	it = v.insert(v.end(), 43);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "inserted: " << *it;
	ft_print_vector(v, output_stream);
	return ;
}

static void	ft_vector_insert_fill(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	SETUP_ARRAYS();

	struct timeval			begin;
	struct timeval			end;
	NAMESPACE::vector<int>	v;

	ft_print_title("insert fill", output_stream, benchmark_stream);

	gettimeofday(&begin, NULL);
	v.insert(v.begin(), 1, 1);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_vector(v, output_stream);

	gettimeofday(&begin, NULL);
	v.insert(v.end(), 2, 42);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_vector(v, output_stream);

	gettimeofday(&begin, NULL);
	v.insert(v.begin() + 1, 2, 2);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_vector(v, output_stream);

	gettimeofday(&begin, NULL);
	v.insert(v.end() - 2, 5, 41);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_vector(v, output_stream);
	return ;
}

static void	ft_vector_insert_range(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	SETUP_ARRAYS();

	struct timeval			begin;
	struct timeval			end;
	NAMESPACE::vector<int>	v;

	ft_print_title("insert range", output_stream, benchmark_stream);

	gettimeofday(&begin, NULL);
	v.insert(v.begin(), v.begin(), v.end());
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_vector(v, output_stream);

	gettimeofday(&begin, NULL);
	v.insert(v.begin(), int_array, int_array);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_vector(v, output_stream);

	gettimeofday(&begin, NULL);
	v.insert(v.begin(), int_array, int_array + 10);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_vector(v, output_stream);

	gettimeofday(&begin, NULL);
	v.insert(v.begin(), int_array + 15, int_array + 20);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_vector(v, output_stream);

	gettimeofday(&begin, NULL);
	v.insert(v.begin(), int_array + 25, int_array + 42);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_vector(v, output_stream);
	return ;
}

static void	ft_vector_erase(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	SETUP_ARRAYS();

	struct timeval						begin;
	struct timeval						end;
	NAMESPACE::vector<int>				v(int_array, int_array + 10);
	NAMESPACE::vector<int>::iterator	it;

	ft_print_title("erase", output_stream, benchmark_stream);

	gettimeofday(&begin, NULL);
	it = v.erase(v.begin());
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "iterator now pointing at: " << *it << std::endl;
	ft_print_vector(v, output_stream);

	gettimeofday(&begin, NULL);
	it = v.erase(v.end() - 1);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	if (it == v.end()) {
		output_stream << "iterator now pointing at: end iterator" << std::endl;
	}
	ft_print_vector(v, output_stream);

	gettimeofday(&begin, NULL);
	it = v.erase(v.begin() + 3);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "iterator now pointing at: " << *it << std::endl;
	ft_print_vector(v, output_stream);

	gettimeofday(&begin, NULL);
	it = v.begin();
	while (it != v.end()) {
		v.erase(it);
		it = v.begin();
	}
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_vector(v, output_stream);
	return ;
}

static void	ft_vector_erase_range(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	SETUP_ARRAYS();

	struct timeval						begin;
	struct timeval						end;
	NAMESPACE::vector<int>				v(int_array, int_array + int_size);
	NAMESPACE::vector<int>::iterator	it;

	ft_print_title("erase range", output_stream, benchmark_stream);

	gettimeofday(&begin, NULL);
	it = v.erase(v.begin(), v.begin());
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	if (it == v.end()) {
		output_stream << "iterator now pointing at: end iterator" << std::endl;
	}
	else {
		output_stream << "iterator now pointing at: " << *it << std::endl;
	}
	ft_print_vector(v, output_stream);

	gettimeofday(&begin, NULL);
	it = v.erase(v.end(), v.end());
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	if (it == v.end()) {
		output_stream << "iterator now pointing at: end iterator" << std::endl;
	}
	else {
		output_stream << "iterator now pointing at: " << *it << std::endl;
	}
	ft_print_vector(v, output_stream);

	gettimeofday(&begin, NULL);
	v.erase(v.begin(), v.begin() + 5);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "iterator now pointing at: " << *it << std::endl;
	ft_print_vector(v, output_stream);

	gettimeofday(&begin, NULL);
	v.erase(v.begin() + 10, v.end() - 2);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "iterator now pointing at: " << *it << std::endl;
	ft_print_vector(v, output_stream);
	return ;
}

static void	ft_vector_swap(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	SETUP_ARRAYS();

	struct timeval			begin;
	struct timeval			end;
	NAMESPACE::vector<int>	v1(int_array, int_array + int_size);
	NAMESPACE::vector<int>	v2;

	ft_print_title("swap", output_stream, benchmark_stream);
	ft_print_vector(v1, output_stream);
	ft_print_vector(v2, output_stream);

	gettimeofday(&begin, NULL);
	v1.swap(v2);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_vector(v1, output_stream);
	ft_print_vector(v2, output_stream);

	gettimeofday(&begin, NULL);
	std::swap(v1, v2);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_vector(v1, output_stream);
	ft_print_vector(v2, output_stream);

	v2.push_back(42);
	gettimeofday(&begin, NULL);
	v2.swap(v1);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_vector(v1, output_stream);
	ft_print_vector(v2, output_stream);

	gettimeofday(&begin, NULL);
	std::swap(v1, v2);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_vector(v1, output_stream);
	ft_print_vector(v2, output_stream);

	v1.clear();
	gettimeofday(&begin, NULL);
	v2.swap(v1);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_vector(v1, output_stream);
	ft_print_vector(v2, output_stream);

	v1.clear();
	gettimeofday(&begin, NULL);
	std::swap(v1, v2);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_vector(v1, output_stream);
	ft_print_vector(v2, output_stream);

	gettimeofday(&begin, NULL);
	v2.swap(v1);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_vector(v1, output_stream);
	ft_print_vector(v2, output_stream);

	gettimeofday(&begin, NULL);
	std::swap(v1, v2);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_vector(v1, output_stream);
	ft_print_vector(v2, output_stream);
	return ;
}

static void	ft_vector_clear(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	SETUP_ARRAYS();

	struct timeval			begin;
	struct timeval			end;
	NAMESPACE::vector<int>	v(int_array, int_array + int_size);

	ft_print_title("clear", output_stream, benchmark_stream);

	gettimeofday(&begin, NULL);
	v.clear();
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_vector(v, output_stream);

	gettimeofday(&begin, NULL);
	v.clear();
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_vector(v, output_stream);
	return ;
}

static void	ft_vector_relational_operators(std::ofstream& output_stream)
{
	SETUP_ARRAYS();

	NAMESPACE::vector<int>	v1;
	NAMESPACE::vector<int>	v2(int_array, int_array + int_size);
	NAMESPACE::vector<int>	v3(int_array, int_array + 10);

	output_stream << "\nrelational operators" << std::endl;

	output_stream << (v1 == v1) << (v2 == v2) << (v3 == v3) << (v1 == v2) << (v2 == v3) << (v1 == v3) << std::endl;
	output_stream << (v1 != v1) << (v2 != v2) << (v3 != v3) << (v1 != v2) << (v2 != v3) << (v1 != v3) << std::endl;
	output_stream << (v1 < v1) << (v2 < v2) << (v3 < v3) << (v1 < v2) << (v2 < v3) << (v1 < v3) << std::endl;
	output_stream << (v1 <= v1) << (v2 <= v2) << (v3 <= v3) << (v1 <= v2) << (v2 <= v3) << (v1 <= v3) << std::endl;
	output_stream << (v1 > v1) << (v2 > v2) << (v3 > v3) << (v1 > v2) << (v2 > v3) << (v1 > v3) << std::endl;
	output_stream << (v1 >= v1) << (v2 >= v2) << (v3 >= v3) << (v1 >= v2) << (v2 >= v3) << (v1 >= v3) << std::endl;
	return ;
}

void	ft_test_vector(void)
{
	std::ofstream	output_stream;
	std::string		output_file = std::string("logs/output/") + STRING_NAMESPACE
										+ std::string("_vector.log");
	std::ofstream	benchmark_stream;
	std::string		benchmark_file = std::string("logs/benchmark/") + STRING_NAMESPACE
										+ std::string("_vector.log");

	output_stream.open(output_file.c_str());
	benchmark_stream.open(benchmark_file.c_str());
	if (output_stream.fail() == true) {
		std::cerr << "Failed to create outputfile for vector" << std::endl;
		return ;
	}
	if (benchmark_stream.fail() == true) {
		std::cerr << "Failed to create benchmarkfile for vector" << std::endl;
		output_stream.close();
		return ;
	}
	std::cout << "running VECTOR tests" << std::endl;

	ft_print_title("VECTOR", output_stream, benchmark_stream);
	ft_vector_constructor(output_stream, benchmark_stream);
	ft_vector_fill_constructor(output_stream, benchmark_stream);
	ft_vector_range_constructor(output_stream, benchmark_stream);
	ft_vector_copy_constructor(output_stream, benchmark_stream);
	ft_vector_assignment(output_stream, benchmark_stream);
	ft_vector_iterators(output_stream);
	ft_vector_reverse_iterators(output_stream);
	ft_vector_size(output_stream, benchmark_stream);
	ft_vector_max_size(output_stream);
	ft_vector_resize(output_stream, benchmark_stream);
	ft_vector_capacity(output_stream, benchmark_stream);
	ft_vector_empty(output_stream, benchmark_stream);
	ft_vector_reserve(output_stream, benchmark_stream);
	ft_vector_index_operator(output_stream, benchmark_stream);
	ft_vector_at(output_stream, benchmark_stream);
	ft_vector_front(output_stream, benchmark_stream);
	ft_vector_back(output_stream, benchmark_stream);
	ft_vector_data(output_stream, benchmark_stream);
	ft_vector_assign_range(output_stream, benchmark_stream);
	ft_vector_assign(output_stream, benchmark_stream);
	ft_vector_push_back(output_stream, benchmark_stream);
	ft_vector_pop_back(output_stream, benchmark_stream);
	ft_vector_insert(output_stream, benchmark_stream);
	ft_vector_insert_fill(output_stream, benchmark_stream);
	ft_vector_insert_range(output_stream, benchmark_stream);
	ft_vector_erase(output_stream, benchmark_stream);
	ft_vector_erase_range(output_stream, benchmark_stream);
	ft_vector_swap(output_stream, benchmark_stream);
	ft_vector_clear(output_stream, benchmark_stream);
	ft_vector_relational_operators(output_stream);

	output_stream.close();
	benchmark_stream.close();
	std::cout << "finished VECTOR tests" << std::endl;
	return ;
}
