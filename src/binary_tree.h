#pragma once

class Binary_tree
{
public:
	struct Node
	{
		unsigned int id = 0;
		std::string name = "";
		Node* root = nullptr;
		Node* left = nullptr;
		Node* right = nullptr;
	};
	Node* create_new_node(unsigned int const&, std::string const&);
	Node* add_new_node(Node*,unsigned int const&, std::string const&);
	int get_node_data(Node*);
	Node* find(unsigned int const&, Node*);
	void change_node_data(Node*, unsigned int const&);
	Node* find(std::string const&, Node*);
	Node* get_tree_root();

private:
	int node_count = 0;
	Node* tree_root = nullptr;
};

Binary_tree::Node* Binary_tree::create_new_node(unsigned int const& id, std::string const& name)
{
	Binary_tree::Node* node = new Binary_tree::Node;
	node->id = id;
	node->name = name;
	if (this->node_count == 0)
	{
		this->tree_root = node;
	}
	return node;
}

Binary_tree::Node* Binary_tree::add_new_node(Binary_tree::Node* root, unsigned int const& id, std::string const& name)
{
	if (root == nullptr)
	{
		root = create_new_node(id, name);
	}
	else if (id > root->id)
	{
		root->right = add_new_node(root->right,id,name);
	}
	else if (id < root->id)
	{
		root->left = add_new_node(root->left, id,name);
	}
	this->node_count = node_count + 1;
	return root;
}

/*
void Binary_tree::Node::add_new_node_void(Binary_tree::Node* root,unsigned int const& data)
{
	if (root == nullptr)
	{
		root = create_new_node(data);
	}
	else if (data > root->id)
	{
		root->right = add_new_node(root->right, data);
	}
	else if (data < root->id)
	{
		root->left = add_new_node(root->left, data);
	}
}
*/
int Binary_tree::get_node_data(Binary_tree::Node* target)
{
	return target->id;
}

Binary_tree::Node* Binary_tree::find(unsigned int const& id, Binary_tree::Node* node)
{
	std::cout <<"currently at: " << node->id << std::endl;
	if (node->id == id)
	{
		return node;
	}
	if (node->id > id)
	{
		node = find(id, node->left);
	}
	if (node->id < id)
	{
		node = find(id, node->right);
	}
	if (node == nullptr)
	{
		return nullptr;
	}
	return node;
}
Binary_tree::Node* Binary_tree::find(std::string const& name, Binary_tree::Node* node)
{
	Binary_tree::Node* target = nullptr;
	if (node == nullptr)
	{
		return nullptr;
	}
	if (node->name == name)
	{
		return node;
	}
	if(node->name != name)
	{
		target = find(name, node->left);
		target = find(name, node->right);
	}
	return target;
}

Binary_tree::Node* Binary_tree::get_tree_root()
{
	return this->tree_root;
}


void Binary_tree::change_node_data(Binary_tree::Node* target, unsigned int const& data)
{
	target->id = data;
}

