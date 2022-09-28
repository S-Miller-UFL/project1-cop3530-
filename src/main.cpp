#include <iostream>
#include "binary_tree.h"
#include "BST.h"
#include <string>
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
	Binary_tree bst;
	std::string result;
	std::getline(std::cin,result);
	std::cout << result << std::endl;
	//insert remove find etc
	//look into using string.compare instead of ==
	//get substring of result
	//result.substr();
	//get the substring of result up until the first space character
	int space = result.find(' ');
	std::string command = result.substr(0, space);
	std::string nameandid = result.substr(space+1, result.size());
	space = nameandid.find(' ');
	std::string name = nameandid.substr(0, space);
	std::string id = nameandid.substr(space, nameandid.size());
	//name = name.substr(1, name.size()-2); //remove the quotes
	//i feel like they will try to test for this method of removal, lets
	//search the string to see if there actually ARE any quotes in it just to be safe.
	if (name.find('"') != std::string::npos)
	{
		int quote = name.find('"');
		name = name.substr(quote + 1, name.size());
		quote = name.find('"');
		name = name.substr(0, quote);
	}
	if (command == "insert")
	{
		//check for appropriate parameters
		//insert nameid: name and then id seperated by space
		std::cout << " 'insert' entered!" << std::endl;
		std::cout << "name: " << name << std::endl;
		std::cout << "id:" << id << std::endl;
		bst.main_insert(std::stoi(id),name);
	}
	/*
	* //use getline
	* use substring to see what command they wanna do, look at the data on the same line
	* based on commandand data, perform the command.
	* example: insert gatorid name
	* if "insert
	* call insert(gatorid, name)
	*
	 */
	
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

