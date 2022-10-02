#include <iostream>
#include "binary_tree.h"
//#include "BST.h"
#include <string>
#include <random>
/* Note: 
	1. You will have to comment main() when unit testing your code because catch uses its own main().
	2. You will submit this main.cpp file and any header files you have on Gradescope. 
*/

void command(Binary_tree&);
//make a command function
/*
* call the function once the program starts
* once a command is done, prompt for more input.
*/
//get a line to print out from the users input
//make one for file streams too


//bugs:
/*
* inputting "00001234" gives "1234"
* output file for testing is blank
*/


int main()
{
	Binary_tree bst;
	command(bst);
	return 0;
}

//look into using string.compare instead of ==

void command(Binary_tree& bst)
{
	std::string result;
	bool run = true;
	int numofcom = 0;
	std::cin >> numofcom;
	std::cin.ignore();
		while (numofcom > 0)
		{
				std::getline(std::cin, result);
				int space = result.find(' ');
				std::string command = result.substr(0, space);
				if (command == "insert")
				{
					//get the name and id by substr the character after the space up until
					//the end of the line
					std::string nameandid = result.substr(space + 1, result.size());
					space = nameandid.find(' ');
					//get the name by substr up until the first space
					std::string name = nameandid.substr(0, space);
					//get the id by substr the rest of the line
					std::string id = nameandid.substr(space, nameandid.size());
					//remove quotes
					if (name.find('"') != std::string::npos)
					{
						int quote = name.find('"');
						name = name.substr(quote + 1, name.size());
						quote = name.find('"');
						name = name.substr(0, quote);
					}
					bst.insert(std::stoi(id), name);

				}
				//remove id
				else if (command == "remove")
				{
					int id = stoi(result.substr(space + 1, result.size()));
					bst.remove(id);
				}
				else if (command == "search")
				{
					//check if number or name
					//get the id by substr the rest of the line
					std::string name = result.substr(space + 1, result.size());
					if (name.find('"') != std::string::npos)
					{
						int quote = name.find('"');
						name = name.substr(quote + 1, name.size());
						quote = name.find('"');
						name = name.substr(0, quote);
					}
					if (isdigit(name[0]))
					{
						bst.search(stoi(name));
					}
					else
					{
						bst.search(name);
					}
				}
				else if (command == "printInorder")
				{
					bst.print_inorder_helper();
				}
				else if (command == "printPreorder")
				{
					bst.print_preorder_helper();
				}
				else if (command == "printPostorder")
				{
					bst.print_postorder_helper();
				}
				else if (command == "printLevelCount")
				{
					bst.print_level_count();
				}
				else if (command == "removeInorder")
				{
					int N = stoi(result.substr(space + 1, result.size()));
					bst.remove_N(N);
				}
				else if (command == "traverse")
				{
					bst.traverse_whole_tree();
				}
				else
				{
					std::cout << "unsuccessful";
				}
				numofcom--;
			}
	
}
