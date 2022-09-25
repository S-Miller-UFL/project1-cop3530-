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
std::string random_name();
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
	for (int i = 0; i < 10; i++)
	{
		//std::cout << (i + rand()) / 100 << std::endl;
		bst.main_insert((i), random_name());
	}
	/*
	std::cout << "preorder: " << std::endl;
	bst.print_preorder_helper();
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "inorder: " << std::endl;
	bst.print_inorder_helper();
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "postorder: " << std::endl;
	bst.print_postorder_helper();
	std::cout << std::endl;
	std::cout << std::endl;
	*/
	bst.traverse_whole_tree();
	return 0;
}
//for testing only, delete when submitting project
std::string random_name()
{
	std::vector<char> alphabet = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	std::string name = "";
	for (int i = 0; i < 5; i++)
	{
		name = name + alphabet.at(rand() %(alphabet.size()-1));
	}
	name = name + " ";
	for (int i = 0; i < 5; i++)
	{
		name = name + alphabet.at(rand() % (alphabet.size()-1));
	}
	return name;
}

