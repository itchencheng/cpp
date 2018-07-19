/*
 * pointer test program 
 */


#include <iostream>

#define SIZE 10

/* pointer alloc */
int allocMemory(int ** ptr)
{
	(*ptr) = new int [SIZE];

	return 0;
}


/* pointer free */
int freeMemory(int ** ptr)
{
	delete [] (*ptr);

	return 0;
}


/* process */
int process(int * ptr)
{
	for (int i = 0; i < SIZE; i++) {
		ptr[i] = i;
	}

	return 0;
}



int main()
{
	int * ptr = nullptr;

	allocMemory(&ptr);

	process(ptr);

	for (int i = 0; i < SIZE; i++) {
		std::cout << i << std::endl;
	}

	freeMemory(&ptr);

	return 0;
}