#pragma once
#include "binary_tree.h"
//#include <iostream>
#include <string>
typedef struct BST
{
private:
	Binary_tree BT;
	Binary_tree::Node* n = BT.get_tree_root();
public:

	 int find(std::string const& name)
	{
		Binary_tree::Node* find = BT.find(name, n);
		if (find == nullptr)
		{
			return std::stoi("XXXXXX");
		}
		else
		{
			return find->id;
		}
	}
	 
	 std::string find(unsigned int const& id)
	 {
		 Binary_tree::Node* find = BT.find(id, n);
		 if (find == nullptr)
		 {
			  return "unsuccessful";
		 }
		 else
		 {
			  return find->name;
		 }
	 }
	 
	 std::string insert(int const& id, std::string const& name)
	 {
		 Binary_tree::Node* g = BT.add_new_node(n,id, name);
		 Binary_tree::Node* find = BT.find(id, g);
		 if (find == nullptr)
		 {
			 return "unsuccessful";
		 }
		 else
		 {
			 return "success";
		 }
	 }

}tree;