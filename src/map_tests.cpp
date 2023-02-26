/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tests.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:08:58 by hkalyonc          #+#    #+#             */
/*   Updated: 2023/02/24 12:26:19 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tester/test_utils.hpp"

//less
#include <functional>
//out_of_range
#include <stdexcept>
//swap
#include <algorithm>

#define SETUP_ARRAYS()															\
	NAMESPACE::pair<int, std::string> intstr_array[64];							\
	init_intstr(intstr_array, 64);												\
	size_t intstr_size = 64;													\
	NAMESPACE::pair<std::string, std::string> strstr_array[32];					\
	init_strstr(strstr_array, 32);												\
	size_t strstr_size = 32;													\
	(void) intstr_array;														\
	(void) intstr_size;															\
	(void) strstr_array;														\
	(void) strstr_size;

static void	init_intstr(NAMESPACE::pair<int, std::string>* arr, size_t size)
{
	int			int_array[64] =	{66, 711, 448, 960, 979, 597,
								949, 272, 69, 111, 735, 981,
								449, 581, 517, 865, 899, 797,
								919, 167, 396, 983, 824, 977,
								816, 320, 395, 790, 519, 219,
								301, 238, 223, 873, 699, 922,
								289, 181, 173, 782, 382, 849,
								267, 764, 104, 709, 574, 417,
								889, 41, 27, 924, 907, 958,
								666, 861, 113, 713, 665, 127,
								112, 509, 51, 1};
	std::string	str_array[64] =	{"SPKvujubcg", "yKMty75Jp7", "tvfkLNbW0Z", "5DMPaPYioL", "GDNa8YqNfG", "BNv56jmeIN",
								"wJ4m3gNLhU", "T2CNPZpYY1", "51xGt6kDFK", "w6qBjjCJeb", "sNxvTi14O5", "fTpKnOE6fS",
								"OOcswU0HFl", "hLMyJpyA6i", "UdipAy9i1r", "BZJ04BjChp", "iGP47dW4pb", "DHISEtGhCO",
								"Yq3XKPDbvv", "fast7QJ5P9", "hLFiLfFpDi", "X0JL2lUUMM", "zY8aU063ON", "XGln55Enb8",
								"M5ZgLVzmd7", "ffCleX6CqX", "5MJaHOD9I6", "GXdBxTO7tV", "enFU30TSjr", "EZbYcMptxK",
								"BrDoqfEXdM", "TzNDcMQcO3", "bpQyCbFxWP", "KSZyCO0QF0", "9g56ENvWUe", "2Ms5fdetOl",
								"vBFa7PDfjl", "8kMWsO5V6F", "ptDcMcl43A", "FfwBYdsl8U", "VH7czPxl0K", "OeYbgwCbSz",
								"jsvz95Ga2W", "bayaI42CHo", "00wvj3ejm2", "Zil1rkPrbx", "znCTw1idfe", "WJRhbgXvsS",
								"peIlwj7sSf", "KwqHXJ5KiS", "kJzWk6z6YW", "J1OKmuXNQE", "SrAcT9URSF", "XIF9ZH0XJR",
								"G92vYSkH59", "JyBSQdIzL6", "LzRgEZQAUj", "6FY6O0ivvK", "MYMovDZPRw", "MyDC4AiXMa",
								"kqNG1mPSDf", "j7UzhbmbpA", "TRMB978ES5", "bvk1sfPJUo"};

	for (size_t i = 0; i < size; i++) {
		arr[i] = NAMESPACE::make_pair(int_array[i], str_array[i]);
	}
	return ;
}

static void	init_strstr(NAMESPACE::pair<std::string, std::string>* arr, size_t size)
{
	std::string	str_array1[32] =	{"42", "MU2F0", "N2HFL", "9WI09", "YO8O4", "QTPXM",
									"VTA1H", "JNMAY", "MB2T9", "04KXI", "7EJ3W", "UYV07",
									"348IJ", "C697N", "Hello", "KEIX5", "GAXZN", "5VE7G",
									"627WN", "ITT5Q", "XJU87", "1MCZE", "WEOUR", "8TV0Q",
									"WAIX7","3KWWA", "6XGM6", "B4TYI", "HBAHB", "FJZXV",
									"RWHL8", "LAST"};
	std::string	str_array2[32] =	{"42Heilbronn", "QEAZP", "E6WVV", "YHROG", "YNALW", "8NXES",
									"E3VMO", "JG1Z7", "E8TK1", "Y2VBT", "U3VHN", "8UOWZ",
									"6AVPJ", "A8JJD", "World", "0M706", "DV9WM", "DSX8G",
									"OTA55", "S3905", "QJEPJ", "ZM61J", "ZKADL", "O9B2Q",
									"5Y9PG", "4R2Z2", "MJPE0", "EFAB0", "JGS34", "GAVAQ",
									"BEL73", "ELEMENT"};

	for (size_t i = 0; i < size; i++) {
		arr[i] = NAMESPACE::make_pair(str_array1[i], str_array2[i]);
	}
	return ;
}

static void	ft_map_constructor(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	struct timeval	begin;
	struct timeval	end;

	ft_print_title("default constructor", output_stream, benchmark_stream);
	gettimeofday(&begin, NULL);
	NAMESPACE::map<int, std::string>	m1;
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_container(m1, output_stream);

	gettimeofday(&begin, NULL);
	NAMESPACE::map<int, std::string>	m2((std::less<int>()));
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_container(m2, output_stream);
	return ;
}

static void	ft_map_range_constructor(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	SETUP_ARRAYS();

	struct timeval	begin;
	struct timeval	end;

	ft_print_title("range constructor", output_stream, benchmark_stream);
	gettimeofday(&begin, NULL);
	NAMESPACE::map<int, std::string>			m1(intstr_array, intstr_array + intstr_size);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_container(m1, output_stream);

	gettimeofday(&begin, NULL);
	NAMESPACE::map<std::string, std::string>	m2(strstr_array, strstr_array + strstr_size);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_container(m2, output_stream);
	return ;
}

static void	ft_map_copy_constructor(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	SETUP_ARRAYS();

	struct timeval								begin;
	struct timeval								end;
	NAMESPACE::map<int, std::string>			m1(intstr_array, intstr_array + intstr_size);
	NAMESPACE::map<std::string, std::string>	m2(strstr_array, strstr_array + strstr_size);

	ft_print_title("copy constructor", output_stream, benchmark_stream);
	gettimeofday(&begin, NULL);
	NAMESPACE::map<int, std::string>			m1_copy(m1);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_container(m1, output_stream);
	ft_print_container(m1_copy, output_stream);

	gettimeofday(&begin, NULL);
	NAMESPACE::map<std::string, std::string>	m2_copy(m2);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_container(m2, output_stream);
	ft_print_container(m2_copy, output_stream);
	return ;
}

static void	ft_map_assignment(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	SETUP_ARRAYS();

	struct timeval						begin;
	struct timeval						end;
	NAMESPACE::map<int, std::string>	m1;
	NAMESPACE::map<int, std::string>	m2(intstr_array, intstr_array + intstr_size);
	NAMESPACE::map<int, std::string>	m3(intstr_array, intstr_array + 15);

	ft_print_title("assignment", output_stream, benchmark_stream);
	ft_print_container(m1, output_stream);
	ft_print_container(m2, output_stream);

	gettimeofday(&begin, NULL);
	m1 = m2;
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_container(m1, output_stream);
	ft_print_container(m2, output_stream);
	ft_print_container(m3, output_stream);

	gettimeofday(&begin, NULL);
	m2 = m3;
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_container(m1, output_stream);
	ft_print_container(m2, output_stream);
	ft_print_container(m3, output_stream);
	return ;
}

static void	ft_map_iterators(std::ofstream& output_stream)
{
	SETUP_ARRAYS();

	NAMESPACE::map<int, std::string>					m(intstr_array, intstr_array + intstr_size);
	NAMESPACE::map<int, std::string>::iterator			it = m.begin();
	NAMESPACE::map<int, std::string>::iterator			it2 = m.begin();
	NAMESPACE::map<int, std::string>::iterator			it_end = m.end();
	NAMESPACE::map<int, std::string>::const_iterator	cit = m.begin();
	NAMESPACE::map<int, std::string>::const_iterator	cit2 = m.begin();
	NAMESPACE::map<int, std::string>::const_iterator	cit_end = m.end();

	output_stream << "\niterators" << std::endl;
	output_stream << (it == it2) << (it != it_end) << (it2 == it_end);
	output_stream << (it == cit) << (it == cit2) << (it2 == cit) << (it2 == cit2);
	output_stream << (cit == cit2) << (cit != cit_end) << (cit2 != cit_end) << std::endl;
	output_stream << it->first << " " << cit2->first << std::endl;

	it++;
	cit++;
	output_stream << (it == it2) << (it != it_end) << (it2 == it_end);
	output_stream << (it == cit) << (it == cit2) << (it2 == cit) << (it2 == cit2);
	output_stream << (cit == cit2) << (cit != cit_end) << (cit2 != cit_end) << std::endl;
	output_stream << it->first << " " << cit2->first << std::endl;

	while (it != it_end) {
		output_stream << it->first << " ";
		it++;
	}
	output_stream << std::endl;
	return ;
}

static void	ft_map_reverse_iterators(std::ofstream& output_stream)
{
	SETUP_ARRAYS();

	NAMESPACE::map<int, std::string>							m(intstr_array, intstr_array + intstr_size);
	NAMESPACE::map<int, std::string>::reverse_iterator			rit = m.rbegin();
	NAMESPACE::map<int, std::string>::reverse_iterator			rit2 = m.rbegin();
	NAMESPACE::map<int, std::string>::reverse_iterator			rit_end = m.rend();
	NAMESPACE::map<int, std::string>::const_reverse_iterator	crit = m.rbegin();
	NAMESPACE::map<int, std::string>::const_reverse_iterator	crit2 = m.rbegin();
	NAMESPACE::map<int, std::string>::const_reverse_iterator	crit_end = m.rend();

	output_stream << "\nreverse iterators" << std::endl;
	output_stream << (rit == rit2) << (rit != rit_end) << (rit2 == rit_end);
	output_stream << (rit == crit) << (rit == crit2) << (rit2 == crit) << (rit2 == crit2);
	output_stream << (crit == crit2) << (crit != crit_end) << (crit2 != crit_end) << std::endl;
	output_stream << rit->first << " " << crit->first << std::endl;

	rit++;
	crit++;
	output_stream << (rit == rit2) << (rit != rit_end) << (rit2 == rit_end);
	output_stream << (rit == crit) << (rit == crit2) << (rit2 == crit) << (rit2 == crit2);
	output_stream << (crit == crit2) << (crit != crit_end) << (crit2 != crit_end) << std::endl;
	output_stream << rit->first << " " << crit->first << std::endl;

	while (rit != rit_end) {
		output_stream << rit->first << " ";
		rit++;
	}
	output_stream << std::endl;
	return ;
}

static void	ft_map_empty(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	SETUP_ARRAYS();

	struct timeval						begin;
	struct timeval						end;
	NAMESPACE::map<int, std::string>	m;
	bool								is_empty;

	ft_print_title("empty", output_stream, benchmark_stream);
	gettimeofday(&begin, NULL);
	is_empty = m.empty();
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "map is empty: " << is_empty << std::endl;

	m.insert(NAMESPACE::make_pair<int, std::string>(42, "42"));
	is_empty = m.empty();
	output_stream << "map is empty: " << is_empty << std::endl;

	m.erase(42);
	is_empty = m.empty();
	output_stream << "map is empty: " << is_empty << std::endl;
	return ;
}

static void	ft_map_size(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	SETUP_ARRAYS();

	struct timeval								begin;
	struct timeval								end;
	NAMESPACE::map<int, std::string>			m1;
	NAMESPACE::map<int, std::string>			m2(intstr_array, intstr_array + intstr_size);
	NAMESPACE::map<int, std::string>			m3(intstr_array, intstr_array + 42);
	NAMESPACE::map<int, std::string>::size_type	size;
	
	ft_print_title("size", output_stream, benchmark_stream);

	gettimeofday(&begin, NULL);
	size = m1.size();
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "m1 size: " << size << std::endl;

	gettimeofday(&begin, NULL);
	size = m2.size();
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "m2 size: " << size << std::endl;

	gettimeofday(&begin, NULL);
	size = m3.size();
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "m3 size: " << size << std::endl;

	for (int i = 0; i < 10; i++) {
		m2.erase(m2.begin());
	}
	size = m2.size();
	output_stream << "m2 size: " << size << std::endl;
	return ;
}

// static void	ft_map_max_size(std::ofstream& output_stream)
// {
// 	SETUP_ARRAYS();

// 	NAMESPACE::map<int, std::string>			int_m1(intstr_array, intstr_array + intstr_size);
// 	NAMESPACE::map<int, std::string>			int_m2;
// 	NAMESPACE::map<std::string, std::string>	str_m1(strstr_array, strstr_array + strstr_size);
// 	NAMESPACE::map<std::string, std::string>	str_m2;

// 	output_stream << "\nmax_size" << std::endl;
// 	output_stream << "max_size of map with int and string: " << int_m1.max_size() << " (" << int_m2.max_size() << ")" << std::endl;
// 	output_stream << "max_size of map with string and string: " << str_m1.max_size() << " (" << str_m2.max_size() << ")" << std::endl;
// 	return ;
// }

static void	ft_map_index_operator(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	SETUP_ARRAYS();

	struct timeval								begin;
	struct timeval								end;
	NAMESPACE::map<std::string, std::string>	m(strstr_array, strstr_array + strstr_size);
	std::string									value;

	ft_print_title("operator []", output_stream, benchmark_stream);
	gettimeofday(&begin, NULL);
	value = m["Hello"];
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "m('Hello'): " << value << std::endl;

	gettimeofday(&begin, NULL);
	value = m["42"];
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "m('42'): " << value << std::endl;

	gettimeofday(&begin, NULL);
	value = m["LAST"];
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "m('LAST'): " << value << std::endl;

	m["LAST"] = "just changed";
	output_stream << "m('LAST'): " << m["LAST"] << std::endl;
	return ;
}

static void	ft_map_at(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	SETUP_ARRAYS();

	struct timeval								begin;
	struct timeval								end;
	NAMESPACE::map<std::string, std::string>	m(strstr_array, strstr_array + strstr_size);
	std::string									value;

	ft_print_title("at", output_stream, benchmark_stream);
	gettimeofday(&begin, NULL);
	value = m.at("Hello");
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "at('Hello'): " << value << std::endl;

	gettimeofday(&begin, NULL);
	value = m.at("42");
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "at('42'): " << value << std::endl;

	gettimeofday(&begin, NULL);
	value = m.at("LAST");
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "at('LAST'): " << value << std::endl;

	try {
		value = m.at("non");
		output_stream << "at('non'): " << value << std::endl;
	}
	catch (const std::out_of_range& e) {
		output_stream << e.what() << std::endl;
	}
	return ;
}

static void	ft_map_insert(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	SETUP_ARRAYS();

	struct timeval														begin;
	struct timeval														end;
	NAMESPACE::map<int, std::string>									m(intstr_array, intstr_array + 15);
	NAMESPACE::pair<NAMESPACE::map<int, std::string>::iterator, bool>	insert_pair;

	ft_print_title("insert", output_stream, benchmark_stream);
	gettimeofday(&begin, NULL);
	insert_pair = m.insert(NAMESPACE::make_pair<int, std::string>(42, "42"));
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "inserted: " << insert_pair.second << std::endl;
	output_stream << insert_pair.first->first << ", " << insert_pair.first->second << std::endl;

	gettimeofday(&begin, NULL);
	insert_pair = m.insert(NAMESPACE::make_pair<int, std::string>(-42, "-42"));
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "inserted: " << insert_pair.second << std::endl;
	output_stream << insert_pair.first->first << ", " << insert_pair.first->second << std::endl;

	gettimeofday(&begin, NULL);
	insert_pair = m.insert(NAMESPACE::make_pair<int, std::string>(42, "42"));
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "inserted: " << insert_pair.second << std::endl;
	output_stream << insert_pair.first->first << ", " << insert_pair.first->second << std::endl;

	gettimeofday(&begin, NULL);
	insert_pair = m.insert(NAMESPACE::make_pair<int, std::string>(42, "Heilbronn"));
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "inserted: " << insert_pair.second << std::endl;
	output_stream << insert_pair.first->first << ", " << insert_pair.first->second << std::endl;

	ft_print_container(m, output_stream);
	return ;
}

static void	ft_map_insert_range(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	SETUP_ARRAYS();

	struct timeval						begin;
	struct timeval						end;
	NAMESPACE::map<int, std::string>	m;

	ft_print_title("insert range", output_stream, benchmark_stream);
	ft_print_container(m, output_stream);

	gettimeofday(&begin, NULL);
	m.insert(intstr_array, intstr_array + 10);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_container(m, output_stream);

	gettimeofday(&begin, NULL);
	m.insert(intstr_array + 10, intstr_array + 30);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_container(m, output_stream);

	gettimeofday(&begin, NULL);
	m.insert(intstr_array, intstr_array + 15);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_container(m, output_stream);

	gettimeofday(&begin, NULL);
	m.insert(intstr_array + 25, intstr_array + 40);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_container(m, output_stream);

	gettimeofday(&begin, NULL);
	m.insert(intstr_array + 40, intstr_array + intstr_size);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_container(m, output_stream);
	return ;
}

static void	ft_map_erase(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	SETUP_ARRAYS()

	struct timeval								begin;
	struct timeval								end;
	NAMESPACE::map<int, std::string>			m(intstr_array, intstr_array + intstr_size);
	NAMESPACE::map<int, std::string>::iterator	it;

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

static void	ft_map_erase_key(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	SETUP_ARRAYS();

	struct timeval								begin;
	struct timeval								end;
	NAMESPACE::map<int, std::string>			m(intstr_array, intstr_array + intstr_size);
	NAMESPACE::map<int, std::string>::size_type	size_erase;

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

static void	ft_map_erase_range(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	SETUP_ARRAYS();

	struct timeval								begin;
	struct timeval								end;
	NAMESPACE::map<int, std::string>			m(intstr_array, intstr_array + intstr_size);
	NAMESPACE::map<int, std::string>::iterator	it;
	NAMESPACE::map<int, std::string>::iterator	it_end;

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

static void	ft_map_swap(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	SETUP_ARRAYS();

	struct timeval						begin;
	struct timeval						end;
	NAMESPACE::map<int, std::string>	m1(intstr_array, intstr_array + intstr_size);
	NAMESPACE::map<int, std::string>	m2;

	ft_print_title("swap", output_stream, benchmark_stream);
	ft_print_container(m1, output_stream);
	ft_print_container(m2, output_stream);

	gettimeofday(&begin, NULL);
	m1.swap(m2);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_container(m1, output_stream);
	ft_print_container(m2, output_stream);

	gettimeofday(&begin, NULL);
	std::swap(m1, m2);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_container(m1, output_stream);
	ft_print_container(m2, output_stream);

	m2.insert(NAMESPACE::make_pair<int, std::string>(42, "42"));
	gettimeofday(&begin, NULL);
	m2.swap(m1);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_container(m1, output_stream);
	ft_print_container(m2, output_stream);

	gettimeofday(&begin, NULL);
	std::swap(m1, m2);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_container(m1, output_stream);
	ft_print_container(m2, output_stream);

	m1.clear();
	gettimeofday(&begin, NULL);
	m2.swap(m1);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_container(m1, output_stream);
	ft_print_container(m2, output_stream);

	m1.clear();
	gettimeofday(&begin, NULL);
	std::swap(m1, m2);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_container(m1, output_stream);
	ft_print_container(m2, output_stream);

	gettimeofday(&begin, NULL);
	m2.swap(m1);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_container(m1, output_stream);
	ft_print_container(m2, output_stream);

	gettimeofday(&begin, NULL);
	std::swap(m1, m2);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_container(m1, output_stream);
	ft_print_container(m2, output_stream);
	return ;
}

static void	ft_map_clear(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	SETUP_ARRAYS();

	struct timeval						begin;
	struct timeval						end;
	NAMESPACE::map<int, std::string>	m(intstr_array, intstr_array + intstr_size);

	ft_print_title("clear", output_stream, benchmark_stream);

	gettimeofday(&begin, NULL);
	m.clear();
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_container(m, output_stream);

	gettimeofday(&begin, NULL);
	m.clear();
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	ft_print_container(m, output_stream);
	return ;
}

static void	ft_map_find(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	SETUP_ARRAYS();
	struct timeval												begin;
	struct timeval												end;
	NAMESPACE::map<int, std::string>							int_m(intstr_array, intstr_array + intstr_size);
	NAMESPACE::map<int, std::string>::iterator					it;
	const NAMESPACE::map<std::string, std::string>				str_m(strstr_array, strstr_array + strstr_size);
	NAMESPACE::map<std::string, std::string>::const_iterator	cit;

	ft_print_title("find", output_stream, benchmark_stream);

	gettimeofday(&begin, NULL);
	it = int_m.find(111);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << it->first << ", " << it->second << std::endl;

	gettimeofday(&begin, NULL);
	it = int_m.find(320);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << it->first << ", " << it->second << std::endl;

	gettimeofday(&begin, NULL);
	it = int_m.find(42);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	if (it == int_m.end()) {
		output_stream << "couldn't find '42'" << std::endl;
	}

	gettimeofday(&begin, NULL);
	cit = str_m.find("Hello");
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << cit->first << ", " << cit->second << std::endl;

	gettimeofday(&begin, NULL);
	cit = str_m.find("42");
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << cit->first << ", " << cit->second << std::endl;

	gettimeofday(&begin, NULL);
	cit = str_m.find("non");
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	if (cit == str_m.end()) {
		output_stream << "couldn't find 'non'" << std::endl;
	}
	return ;
}

static void	ft_map_count(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	SETUP_ARRAYS();

	struct timeval								begin;
	struct timeval								end;
	NAMESPACE::map<int, std::string>			int_m(intstr_array, intstr_array + intstr_size);
	NAMESPACE::map<int, std::string>::size_type	count_size;

	ft_print_title("count", output_stream, benchmark_stream);

	gettimeofday(&begin, NULL);
	count_size = int_m.count(949);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "count(949): " << count_size << std::endl;

	gettimeofday(&begin, NULL);
	count_size = int_m.count(41);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "count(41): " << count_size << std::endl;

	gettimeofday(&begin, NULL);
	count_size = int_m.count(42);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "count(42): " << count_size << std::endl;

	gettimeofday(&begin, NULL);
	count_size = int_m.count(2);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "count(2): " << count_size << std::endl;
	return ;
}

static void	ft_map_lower_bound(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	SETUP_ARRAYS();

	struct timeval								begin;
	struct timeval								end;
	NAMESPACE::map<int, std::string>			m(intstr_array, intstr_array + intstr_size);
	NAMESPACE::map<int, std::string>::iterator	it;

	ft_print_title("lower_bound", output_stream, benchmark_stream);

	gettimeofday(&begin, NULL);
	it = m.lower_bound(1);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << it->first << ", " << it->second << std::endl;

	gettimeofday(&begin, NULL);
	it = m.lower_bound(42);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << it->first << ", " << it->second << std::endl;

	gettimeofday(&begin, NULL);
	it = m.lower_bound(1000);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	if (it == m.end()) {
		output_stream << "returned end_iterator" << std::endl;
	}
	return ;
}

static void	ft_map_upper_bound(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	SETUP_ARRAYS();

	struct timeval								begin;
	struct timeval								end;
	NAMESPACE::map<int, std::string>			m(intstr_array, intstr_array + intstr_size);
	NAMESPACE::map<int, std::string>::iterator	it;

	ft_print_title("upper_bound", output_stream, benchmark_stream);

	gettimeofday(&begin, NULL);
	it = m.upper_bound(1);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << it->first << ", " << it->second << std::endl;

	gettimeofday(&begin, NULL);
	it = m.upper_bound(42);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << it->first << ", " << it->second << std::endl;

	gettimeofday(&begin, NULL);
	it = m.upper_bound(1000);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	if (it == m.end()) {
		output_stream << "returned end_iterator" << std::endl;
	}
	return ;
}

static void	ft_map_equal_range(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	SETUP_ARRAYS();

	struct timeval																							begin;
	struct timeval																							end;
	NAMESPACE::map<int, std::string>																		m(intstr_array, intstr_array + intstr_size);
	NAMESPACE::pair<NAMESPACE::map<int, std::string>::iterator, NAMESPACE::map<int, std::string>::iterator>	pair_equalrange;

	ft_print_title("equal_range", output_stream, benchmark_stream);

	gettimeofday(&begin, NULL);
	pair_equalrange = m.equal_range(1);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "lower_bound: " << pair_equalrange.first->first << " " << pair_equalrange.first->second;
	output_stream << "; upper_bound: " << pair_equalrange.second->first << " " << pair_equalrange.second->second << std::endl;

	gettimeofday(&begin, NULL);
	pair_equalrange = m.equal_range(42);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "lower_bound: " << pair_equalrange.first->first << " " << pair_equalrange.first->second;
	output_stream << "; upper_bound: " << pair_equalrange.second->first << " " << pair_equalrange.second->second << std::endl;

	gettimeofday(&begin, NULL);
	pair_equalrange = m.equal_range(983);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "lower_bound: " << pair_equalrange.first->first << " " << pair_equalrange.first->second;
	output_stream << "; upper_bound: ";
	if (pair_equalrange.second == m.end()) {
		output_stream << "end iterator";
	}
	output_stream << std::endl;

	gettimeofday(&begin, NULL);
	pair_equalrange = m.equal_range(1000);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "lower_bound: ";
	if (pair_equalrange.first == m.end()) {
		output_stream << "end iterator";
	}
	output_stream << "; upper_bound: ";
	if (pair_equalrange.second == m.end()) {
		output_stream << "end iterator";
	}
	output_stream << std::endl;
	return ;
}

static void	ft_map_relational_operators(std::ofstream& output_stream)
{
	SETUP_ARRAYS();

	NAMESPACE::map<int, std::string>	m1;
	NAMESPACE::map<int, std::string>	m2(intstr_array, intstr_array + intstr_size);
	NAMESPACE::map<int, std::string>	m3(intstr_array, intstr_array + 10);

	output_stream << "\nrelational operators" << std::endl;

	output_stream << (m1 == m1) << (m2 == m2) << (m3 == m3) << (m1 == m2) << (m2 == m3) << (m1 == m3) << std::endl;
	output_stream << (m1 != m1) << (m2 != m2) << (m3 != m3) << (m1 != m2) << (m2 != m3) << (m1 != m3) << std::endl;
	output_stream << (m1 < m1) << (m2 < m2) << (m3 < m3) << (m1 < m2) << (m2 < m3) << (m1 < m3) << std::endl;
	output_stream << (m1 <= m1) << (m2 <= m2) << (m3 <= m3) << (m1 <= m2) << (m2 <= m3) << (m1 <= m3) << std::endl;
	output_stream << (m1 > m1) << (m2 > m2) << (m3 > m3) << (m1 > m2) << (m2 > m3) << (m1 > m3) << std::endl;
	output_stream << (m1 >= m1) << (m2 >= m2) << (m3 >= m3) << (m1 >= m2) << (m2 >= m3) << (m1 >= m3) << std::endl;
	return ;
}

void	ft_test_map(void)
{
	std::ofstream	output_stream;
	std::string		output_file = std::string("logs/output/") + STRING_NAMESPACE
										+ std::string("_map.log");
	std::ofstream	benchmark_stream;
	std::string		benchmark_file = std::string("logs/benchmark/") + STRING_NAMESPACE
										+ std::string("_map.log");

	output_stream.open(output_file.c_str());
	benchmark_stream.open(benchmark_file.c_str());
	if (output_stream.fail() == true) {
		std::cerr << "Failed to create outputfile for map" << std::endl;
		return ;
	}
	if (benchmark_stream.fail() == true) {
		std::cerr << "Failed to create benchmarkfile for map" << std::endl;
		output_stream.close();
		return ;
	}
	std::cout << "running MAP tests" << std::endl;

	ft_print_title("MAP", output_stream, benchmark_stream);
	ft_map_constructor(output_stream, benchmark_stream);
	ft_map_range_constructor(output_stream, benchmark_stream);
	ft_map_copy_constructor(output_stream, benchmark_stream);
	ft_map_assignment(output_stream, benchmark_stream);
	ft_map_iterators(output_stream);
	ft_map_reverse_iterators(output_stream);
	ft_map_empty(output_stream, benchmark_stream);
	ft_map_size(output_stream, benchmark_stream);
	//ft_map_max_size(output_stream);
	ft_map_index_operator(output_stream, benchmark_stream);
	ft_map_at(output_stream, benchmark_stream);
	ft_map_insert(output_stream, benchmark_stream);
	ft_map_insert_range(output_stream, benchmark_stream);
	ft_map_erase(output_stream, benchmark_stream);
	ft_map_erase_key(output_stream, benchmark_stream);
	ft_map_erase_range(output_stream, benchmark_stream);
	ft_map_swap(output_stream, benchmark_stream);
	ft_map_clear(output_stream, benchmark_stream);
	ft_map_find(output_stream, benchmark_stream);
	ft_map_count(output_stream, benchmark_stream);
	ft_map_lower_bound(output_stream, benchmark_stream);
	ft_map_upper_bound(output_stream, benchmark_stream);
	ft_map_equal_range(output_stream, benchmark_stream);
	ft_map_relational_operators(output_stream);

	output_stream.close();
	benchmark_stream.close();
	std::cout << "finished MAP tests" << std::endl;
	return ;
}
