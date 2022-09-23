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
	Binary_tree::Node* n = bst.get_tree_root();
	n=bst.insert(n, 0, "adam smith");
	n=bst.insert(n, 5, "adam smith");
	n=bst.insert(n, 6, "adam smith");
	n=bst.insert(n, 3, "adam smith");
	n=bst.insert(n, 7, "adam smith");
	n=bst.insert(n, 8, "adam smith");
	
	/*
	n=bst.add_new_node(n, 10, "adam smith");
	n=bst.add_new_node(n, 11, "adam smith");
	n=bst.add_new_node(n, 12, "adam smith");
	n=bst.add_new_node(n, 13, "adam smith");
	n=bst.add_new_node(n, 14, "adam smith");
	n=bst.add_new_node(n, 15, "adam smith");
	n=bst.add_new_node(n, 19, "adam smith");
	n=bst.add_new_node(n, 17, "adam smith");
	*/

	//bst.traverse(t.get_tree_root());
	//n = bst.check_balance(n);

	bst.traverse(n);
	return 0;
}

