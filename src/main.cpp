#include <iostream>
#include "binary_tree.h"
#include "BST.h"
#include <random>
/* Note: 
	1. You will have to comment main() when unit testing your code because catch uses its own main().
	2. You will submit this main.cpp file and any header files you have on Gradescope. 
*/

int main()
{
	Binary_tree bst;
	tree t;
	for (int i = 0; i <10; i++)
	{
		std::cout << t.insert(i + rand()%10, "adam smith") << std::endl;
	}
	bst.traverse(t.get_tree_root());
	std::cout << t.get_height();
	return 0;
}

