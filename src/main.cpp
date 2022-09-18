#include <iostream>
#include "binary_tree.h"
#include "BST.h"
#include <random>
/* Note: 
	1. You will have to comment main() when unit testing your code because catch uses its own main().
	2. You will submit this main.cpp file and any header files you have on Gradescope. 
*/
std::string string_generator();
int main()
{
	tree t;
	for (int i = 0; i < 1000; i++)
	{
		std::cout << t.insert(rand() % 999999, "adam smith") << std::endl;
	}
	return 0;
}

