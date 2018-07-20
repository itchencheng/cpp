/*
 ******************************************************************************
 *       Filename:    template.cpp
 *    Description:    cpp file
 *       
 *        Version:    1.0
 *        Created:    2018-07-20
 *         Author:    chencheng
 *
 *        History:    initial draft
 ******************************************************************************
 */

#include <iostream>
#include "List.h"


int main()
{
	List<char> list(19);

	std::cout << list.getMaxSize()       << std::endl;
	std::cout << list.getCurrentLength() << std::endl;

	std::cout << "Hello, world!" << std::endl;

	return 0;
}