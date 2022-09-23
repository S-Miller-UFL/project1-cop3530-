#include <iostream>
#include "binary_tree.h"
#include "BST.h"
#include <random>
/* Note: 
	1. You will have to comment main() when unit testing your code because catch uses its own main().
	2. You will submit this main.cpp file and any header files you have on Gradescope. 
*/
//i have no idea if this binary tree actually works and arranges properly
/*
* in addition, i need to see if theres a way i can visualize it
*/
int main()
{
	Binary_tree bst;
	tree t;
	Binary_tree::Node* n = nullptr;
	//use getline
	/*
	* use substring to see what command they wanna do, look at the data on the same line
	* based on command and data, perform the command.
	* example: insert gatorid name
	* if "insert
	*	call insert(gatorid,name)
	*/
	/*
	n=bst.insert(n, 0, "adam smith");
	n=bst.insert(n, 5, "adam smith");
	n=bst.insert(n, 6, "adam smith");
	n=bst.insert(n, 3, "adam smith");
	n=bst.insert(n, 7, "adam smith");
	n=bst.insert(n, 8, "adam smith");
	
	
	n=bst.insert(n, 10, "adam smith");
	n=bst.insert(n, 11, "adam smith");
	n=bst.insert(n, 12, "adam smith");
	n=bst.insert(n, 13, "adam smith");
	n=bst.insert(n, 14, "adam smith");
	n=bst.insert(n, 15, "adam smith");
	n=bst.insert(n, 19, "adam smith");
	n=bst.insert(n, 17, "adam smith");
	*/
	//use helper functions to help get the root
	for (int i = 0; i < 5000; i++)
	{
		bst.main_insert(i, "adam smith");
	}
	n = bst.get_tree_root();
	//bst.traverse(t.get_tree_root());
	//n = bst.check_balance(n);
	//n = bst.get_tree_root();
	bst.traverse(n);
	std::cout << "number of nodes: " << bst.count() << std::endl;
	return 0;
}

