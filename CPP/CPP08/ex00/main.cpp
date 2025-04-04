/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:46:41 by hehuang           #+#    #+#             */
/*   Updated: 2025/03/24 17:42:06 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec = {1, 2, 3, 4, 5, 3, 7};
    int N = 4;
	try
	{
		std::vector<int>::iterator result = easyfind(vec, N);
		std::cout << "Found " << N << " at position: " << std::distance(vec.begin(), result) << std::endl;
    } 
	catch (std::exception &e)
	{
		std::cout << e.what() << N << " not found in the container." << std::endl;
    }

    return 0;
}
