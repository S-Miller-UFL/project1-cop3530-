#include <iostream>
#include "binary_tree.h"
#include "BST.h"
#include <random>
/* Note: 
	1. You will have to comment main() when unit testing your code because catch uses its own main().
	2. You will submit this main.cpp file and any header files you have on Gradescope. 
*/

std::string random_name();
//get a line to print out from the users input
//make one for file streams too
int main()
{
	std::string result;
	std::cin >> result;
	std::cout << result << std::endl;
	//insert remove find etc
	//look into using string.compare instead of ==
	//get substring of result
	result.substr();
	//get the substring of result up until the first space character
	//if ()
	//{
		//check for appropriate parameters
		//insert nameid: name and then id seperated by space
		//
	//}
	/*
	* //use getline
	*use substring to see what command they wanna do, look at the data on the same line
	* based on commandand data, perform the command.
	* example: insert gatorid name
	* if "insert
	* call insert(gatorid, name)
	*
	 */
	
	Binary_tree bst;
	//use helper functions to help get the root
	for (int i = 0; i < 10; i++)
	{
		//std::cout << (i + rand()) / 100 << std::endl;
		bst.main_insert((i), random_name());
	}

	bst.traverse_whole_tree();
	bst.print_inorder_helper();
	bst.remove_N(3);
	bst.traverse_whole_tree();
	bst.print_level_count();
	
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

