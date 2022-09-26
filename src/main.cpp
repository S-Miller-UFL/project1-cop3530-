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

	//use helper functions to help get the root
	for (int i = 0; i < 10; i++)
	{
		//std::cout << (i + rand()) / 100 << std::endl;
		bst.main_insert((i), random_name());
	}
	bst.traverse_whole_tree();
	bst.remove_node(0);
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

