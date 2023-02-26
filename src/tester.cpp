/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 08:42:12 by hkalyonc          #+#    #+#             */
/*   Updated: 2023/02/24 12:14:28 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tester/test_utils.hpp"

//remove
#include <map>
#include <vector>

void	ft_print_time(struct timeval& begin, struct timeval& end,
	std::ofstream& benchmark_stream)
{
	long			seconds;
	long			microseconds;
	long			total_time;

	seconds = end.tv_sec - begin.tv_sec;
	microseconds = end.tv_usec - begin.tv_usec;
	//microseconds
	total_time = seconds * 1000000 + microseconds;
	//milliseconds
	// total_time = seconds * 1000. + microseconds / 1000.;
	benchmark_stream << "Time measured:\t" << total_time << " μs" << std::endl;
	return ;
}

void	ft_print_title(const std::string& title, std::ofstream& output_stream,
	std::ofstream& benchmark_stream)
{
	output_stream << std::endl << title << std::endl;
	benchmark_stream << std::endl << title << std::endl;
	return ;
}

int	main(void)
{
	ft_test_stack();
	ft_test_vector();
	ft_test_map();
	ft_test_set();
	return (0);
}
