/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tests.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:43:38 by hkalyonc          #+#    #+#             */
/*   Updated: 2023/02/24 12:25:54 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tester/test_utils.hpp"

static void	ft_stack_constructor(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	struct timeval	begin;
	struct timeval	end;

	ft_print_title("constructor", output_stream, benchmark_stream);

	gettimeofday(&begin, NULL);
	NAMESPACE::stack<int>	s;
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << s.size() << std::endl;
	return ;
}

static void	ft_stack_empty(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	struct timeval			begin;
	struct timeval			end;
	NAMESPACE::stack<int>	s;
	bool					is_empty;

	ft_print_title("empty", output_stream, benchmark_stream);

	gettimeofday(&begin, NULL);
	is_empty = s.empty();
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "is empty: " << is_empty << ", size: " << s.size() << std::endl;

	s.push(42);
	gettimeofday(&begin, NULL);
	is_empty = s.empty();
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "is empty: " << is_empty << ", size: " << s.size() << std::endl;

	s.pop();
	gettimeofday(&begin, NULL);
	is_empty = s.empty();
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "is empty: " << is_empty << ", size: " << s.size() << std::endl;
	return ;
}

static void	ft_stack_size(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	struct timeval						begin;
	struct timeval						end;
	NAMESPACE::stack<int>				s;
	NAMESPACE::stack<int>::size_type	s_size;

	ft_print_title("size", output_stream, benchmark_stream);

	gettimeofday(&begin, NULL);
	s_size = s.size();
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << s_size << std::endl;

	s.push(42);
	gettimeofday(&begin, NULL);
	s_size = s.size();
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << s_size<< std::endl;

	s.pop();
	gettimeofday(&begin, NULL);
	s_size = s.size();
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << s_size << std::endl;

	s.push(42);
	s.push(43);
	s.push(44);
	gettimeofday(&begin, NULL);
	s_size = s.size();
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << s_size<< std::endl;

	s.pop();
	gettimeofday(&begin, NULL);
	s_size = s.size();
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << s_size << std::endl;
	return ;
}

static void	ft_stack_top(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	struct timeval			begin;
	struct timeval			end;
	NAMESPACE::stack<int>	s;
	int						element;

	ft_print_title("top", output_stream, benchmark_stream);

	s.push(42);
	gettimeofday(&begin, NULL);
	element = s.top();
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "top: " << element << ", size: " << s.size() << std::endl;

	s.push(43);
	gettimeofday(&begin, NULL);
	element = s.top();
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "top: " << element << ", size: " << s.size() << std::endl;

	s.push(44);
	s.pop();
	gettimeofday(&begin, NULL);
	element = s.top();
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "top: " << element << ", size: " << s.size() << std::endl;
	return ;
}

static void	ft_stack_push(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	struct timeval			begin;
	struct timeval			end;
	NAMESPACE::stack<int>	s;

	ft_print_title("push", output_stream, benchmark_stream);

	gettimeofday(&begin, NULL);
	s.push(42);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "top: " << s.top() << ", size: " << s.size() << std::endl;

	gettimeofday(&begin, NULL);
	s.push(43);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "top: " << s.top() << ", size: " << s.size() << std::endl;

	gettimeofday(&begin, NULL);
	s.push(44);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "top: " << s.top() << ", size: " << s.size() << std::endl;

	gettimeofday(&begin, NULL);
	s.push(44);
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "top: " << s.top() << ", size: " << s.size() << std::endl;
	return ;
}

static void	ft_stack_pop(std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	struct timeval			begin;
	struct timeval			end;
	NAMESPACE::stack<int>	s;

	ft_print_title("push", output_stream, benchmark_stream);

	s.push(42);
	gettimeofday(&begin, NULL);
	s.pop();
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "size: " << s.size() << std::endl;

	s.push(42);
	s.push(43);
	s.push(44);
	gettimeofday(&begin, NULL);
	s.pop();
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "top: " << s.top() << ", size: " << s.size() << std::endl;

	gettimeofday(&begin, NULL);
	s.pop();
	gettimeofday(&end, NULL);
	ft_print_time(begin, end, benchmark_stream);
	output_stream << "top: " << s.top() << ", size: " << s.size() << std::endl;
	return ;
}

static void	ft_stack_relational_operators(std::ofstream& output_stream)
{
	NAMESPACE::stack<int>	s1;
	NAMESPACE::stack<int>	s2;
	NAMESPACE::stack<int>	s3;

	output_stream << "\nrelational operators" << std::endl;

	s2.push(42);
	s3.push(42);

	s2.push(43);
	s3.push(43);
	s3.push(43);

	s2.push(44);
	s3.push(44);

	output_stream << (s1 == s1) << (s2 == s2) << (s3 == s3) << (s1 == s2) << (s2 == s3) << (s1 == s3) << std::endl;
	output_stream << (s1 != s1) << (s2 != s2) << (s3 != s3) << (s1 != s2) << (s2 != s3) << (s1 != s3) << std::endl;
	output_stream << (s1 < s1) << (s2 < s2) << (s3 < s3) << (s1 < s2) << (s2 < s3) << (s1 < s3) << std::endl;
	output_stream << (s1 <= s1) << (s2 <= s2) << (s3 <= s3) << (s1 <= s2) << (s2 <= s3) << (s1 <= s3) << std::endl;
	output_stream << (s1 > s1) << (s2 > s2) << (s3 > s3) << (s1 > s2) << (s2 > s3) << (s1 > s3) << std::endl;
	output_stream << (s1 >= s1) << (s2 >= s2) << (s3 >= s3) << (s1 >= s2) << (s2 >= s3) << (s1 >= s3) << std::endl;
	return ;
}

void	ft_test_stack(void)
{
	std::ofstream	output_stream;
	std::string		output_file = std::string("logs/output/") + STRING_NAMESPACE
										+ std::string("_stack.log");
	std::ofstream	benchmark_stream;
	std::string		benchmark_file = std::string("logs/benchmark/") + STRING_NAMESPACE
										+ std::string("_stack.log");

	output_stream.open(output_file.c_str());
	benchmark_stream.open(benchmark_file.c_str());
	if (output_stream.fail() == true) {
		std::cerr << "Failed to create outputfile for stack" << std::endl;
		return ;
	}
	if (benchmark_stream.fail() == true) {
		std::cerr << "Failed to create benchmarkfile for stack" << std::endl;
		output_stream.close();
		return ;
	}
	std::cout << "running STACK tests" << std::endl;

	ft_print_title("STACK", output_stream, benchmark_stream);

	ft_stack_constructor(output_stream, benchmark_stream);
	ft_stack_empty(output_stream, benchmark_stream);
	ft_stack_size(output_stream, benchmark_stream);
	ft_stack_top(output_stream, benchmark_stream);
	ft_stack_push(output_stream, benchmark_stream);
	ft_stack_pop(output_stream, benchmark_stream);
	ft_stack_relational_operators(output_stream);

	output_stream.close();
	benchmark_stream.close();
	std::cout << "finished STACK tests" << std::endl;
	return ;
}
