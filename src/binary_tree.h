#pragma once
#include <queue>
//got help from eric chen on 9/23/2022
/*
* insert NAME ID
* remove ID
* search ID
* search NAME
* printInorder
* printPreorder
* printPostorder	
* printLevelCount
* removeInorder N
*/
class Binary_tree
{
public:
	struct Node
	{
		unsigned int id = 0;
		std::string name = "";
		int balance_factor = 0;
		Node* left = nullptr;
		Node* right = nullptr;
	};
	Node* create_new_node(unsigned int const&, std::string const&);
	Node* insert(Node*,unsigned int const&, std::string const&);
	int get_id(Node*);
	std::string get_name(Node*);
	Node* find(unsigned int const&, Node*);
	void find_helper(unsigned int const&);
	void find_helper(std::string const&);
	void change_node_data(Node*, unsigned int const&);
	std::queue<Node*> find(std::queue<Binary_tree::Node*>,std::string const&, Node*);
	Node* get_tree_root();
	int getheight(Node*);
	void traverse(Node*);
	//Binary_tree::Node* check_balance(Node*);
	int get_balance_factor(Node*);
	Node* rotate_left(Node*);
	Node* rotate_right(Node*);
	int count();
	std::queue<Binary_tree::Node*> count_helper(Node*, std::queue<Binary_tree::Node*>);
	void remove_node(unsigned int const&);
	Node* remove(Node*, bool);
	void main_insert(unsigned int const&, std::string const&);
	void print_preorder_helper();
	void print_postorder_helper();
	void print_inorder_helper();
	std::queue< Binary_tree::Node*> get_preorder(Binary_tree::Node* , std::queue< Binary_tree::Node*> );
	std::queue< Binary_tree::Node*> get_postorder(Binary_tree::Node* , std::queue< Binary_tree::Node*> );
	std::queue< Binary_tree::Node*> get_inorder(Binary_tree::Node* , std::queue< Binary_tree::Node*> );
	void print_queue(std::queue< Binary_tree::Node*>);


private:
	int node_count = 0;
	//create a constructor for tree_root
	Node* tree_root = nullptr;
	static int _level;
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
	//node = check_balance(node);
	this->node_count = node_count + 1;
	return node;
}


Binary_tree::Node* Binary_tree::insert(Binary_tree::Node* root, unsigned int const& id, std::string const& name)
{
	if (root != nullptr)
	{
		//std::cout << "at node: " << root->id << std::endl;
	}
	if (root == nullptr)
	{
		root = create_new_node(id, name);
	}
	//temporary
	if (root->id == id)
	{
		//std::cout << "duplicate detected: " << root->id << " already exists!" << std::endl;
	}
	else if (id > root->id)
	{
		//std::cout << "going to the right of: " << root->id << std::endl;
		root->right = insert(root->right,id,name);
	}
	else if (id < root->id)
	{
		//std::cout << "going to the left of: " << root->id << std::endl;
		root->left = insert(root->left, id,name);
	}
	root->balance_factor = getheight(root->left) - getheight(root->right);
	/*
	* if tree is right heavy //balance_factor == -2
	*	if trees right subtree is left heavy //balance_factor == +1
	*		perform right left rotation
	*	else
	*		perform left rotation
	* else if tree is left heavy //balance_factor == +2
	*	if trees left subtree is right heavy //balance_factor == -1
	*		perform left right rotation
	*	else
	*		perform right rotation
	* 
	*/
	//based off code from lecture slides (avl trees)
	
	if (root->balance_factor == -2)
	{
		if (root->right->balance_factor == 1)
		{
			//std::cout << "performing right left rotation: " << std::endl;
			root->right = rotate_right(root->right);
			root = rotate_left(root);
		}
		else
		{
			//std::cout << "performing left rotation: " << std::endl;
			root = rotate_left(root);
		}
	}
	else if (root->balance_factor == 2)
	{
		if (root->left->balance_factor == -1)
		{
			//std::cout << "performing left right rotation: " << std::endl;
			root->left = rotate_left(root->left);
			root = rotate_right(root);
		}
		else
		{
			//std::cout << "performing right rotation: " << std::endl;
			root = rotate_right(root);
		}
	}
	
	root->balance_factor = getheight(root->left) - getheight(root->right);

	//root = check_balance(root);
	//std::cout << "added " << root->id << std::endl;
	//need to perform rotation correction here
	//root->balance_factor = getheight(root->left) - getheight(root->right);
	return root;
}


int Binary_tree::get_id(Binary_tree::Node* target)
{
	return target->id;
}

std::string Binary_tree::get_name(Node* root)
{
	return root->name;
}

Binary_tree::Node* Binary_tree::find(unsigned int const& id, Binary_tree::Node* node)
{
	//std::cout <<"currently at: " << node->id << std::endl;
	if (node == nullptr)
	{
		return node;
	}
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
	return node;
}
void Binary_tree::find_helper(unsigned int const& id)
{
	std::cout << get_name(find(id, this->tree_root)) << std::endl;
}
void Binary_tree::find_helper(std::string const& name)
{
	std::queue<Binary_tree::Node*> q;
	q = find(q, name, this->tree_root);
	while (!q.empty())
	{
		std::cout << get_id(q.front()) << std::endl;
		q.pop();
	}
}
std::queue<Binary_tree::Node*> Binary_tree::find(std::queue<Binary_tree::Node*> q,std::string const& name, Binary_tree::Node* node)
{
	if (node == nullptr)
	{
		return q;
	}
	if (node->name == name)
	{
		//im 99.9999999999999% sure this is preorder but you never know
		q.push(node);
		q = find(q, name, node->left);
		q = find(q, name, node->right);
	}
	if(node->name != name)
	{
		q = find(q,name, node->left);
		//q = find(q, name, node->right);
	}
	
	if (node->name != name)
	{
		q = find(q,name, node->right);
	}
	
	return q;
}

Binary_tree::Node* Binary_tree::get_tree_root()
{
	return this->tree_root;
}


void Binary_tree::change_node_data(Binary_tree::Node* target, unsigned int const& data)
{
	target->id = data;
}

int Binary_tree::getheight(Binary_tree::Node* node)
{
	int count = 0;
	if (node == nullptr)
	{
		return count;
	}
	else
	{
		count = std::max(getheight(node->left),getheight(node->right))+1;
	}
	return count;
}

void Binary_tree::traverse(Node* n)
{
	if (n == nullptr)
	{
		return;
	}
	else
	{
		std::cout << "at node: " << n->id << std::endl;
		std::cout << "left of " << n->id << ": ";
		traverse(n->left);
		std::cout << std::endl;
		std::cout << "right of " << n->id << ": ";
		traverse(n->right);
		std::cout << std::endl;
	}
}

//well leave this here for now, will probably delete later.
/*
Binary_tree::Node* Binary_tree::check_balance(Node* tree_root)
{
	int left = 0;
	int right = 0;
	left = getheight(tree_root->left);
	right = getheight(tree_root->right);
	//std::cout << "balance factor: " << left - right << std::endl;
	if (tree_root->balance_factor > 1 || tree_root->balance_factor < -1)
	{
		std::cout << tree_root->id << " is unbalanced!" << std::endl;
		//tree_root = rotate(tree_root, tree_root->balance_factor);
		//return false;
	}
	else
	{
		std::cout << tree_root->id << " is balanced!" << std::endl;
		//return true;
	}
	return tree_root;
}
*/

int Binary_tree::get_balance_factor(Node* root)
{
	return root->balance_factor;
}

//based off of the code in the lecture slides (AVL trees)
Binary_tree::Node* Binary_tree::rotate_left(Node* root)
{
	Binary_tree::Node* N = nullptr;
	Binary_tree::Node* node = nullptr;
	node = root->right->left;
	N = root->right;
	root->right = node;
	N->left = root;
	return N;
}
//based off of the code in the lecture slides (AVL trees)
Binary_tree::Node* Binary_tree::rotate_right(Node* root)
{
	Binary_tree::Node* N = nullptr;
	Binary_tree::Node* node = new Binary_tree::Node;
	node = root->left->right;
	N = root->left;
	root->left = node;
	N->right = root;
	return N;
}
//only here for debugging
int Binary_tree::count()
{
	std::queue<Binary_tree::Node*> q = count_helper(this->tree_root, q);
	return q.size();
}

std::queue<Binary_tree::Node*> Binary_tree::count_helper(Node* root, std::queue<Binary_tree::Node*> q)
{
	if (root == nullptr)
	{
		return q;
	}
	else
	{
		q.push(root);
		q = count_helper(root->left, q);
		q = count_helper(root->right, q);
	}
	return q;
}

void Binary_tree::remove_node(unsigned int const& id)
{

}

//pass in the node BEFORE the one to be deleted
//left = which side is it on
Binary_tree::Node* Binary_tree::remove(Node* root, bool left)
{
	//if the node to be deleted is the left node
	if (left)
	{
		root->left = root->left->left;
	}
	if (!left)
	{
		root->right = root->right->left;
	}
	
	return root;
}

void Binary_tree::main_insert(unsigned int const& id, std::string const& name)
{
	this->tree_root = insert(this->tree_root, id, name);

}

void Binary_tree::print_preorder_helper()
{
	std::queue< Binary_tree::Node*> q;
	print_queue(get_preorder(this->tree_root,q));
}

void Binary_tree::print_postorder_helper()
{
	std::queue< Binary_tree::Node*> q;
	print_queue(get_postorder(this->tree_root, q));
}

void Binary_tree::print_inorder_helper()
{
	std::queue< Binary_tree::Node*> q;
	print_queue(get_inorder(this->tree_root, q));
}
//our goal is a preorder
/*
* go to a node
* add the node to a queue
* go to left node rinse and repeat
* go to right node rinse and repeat
* return
*/
std::queue< Binary_tree::Node*> Binary_tree::get_preorder(Binary_tree::Node* root , std::queue< Binary_tree::Node*> q)
{
	if (root == nullptr)
	{
		return q;
	}
	else
	{
		q.push(root);
		q = get_preorder(root->left, q);
		q = get_preorder(root->right, q);
	}
	return q;
}
//our goal is a postorder
/*
* go to a node
* go to the left node rinse and repeat
* go to the right node rinse and repeat
* add the node to the queue
* return
*/
std::queue< Binary_tree::Node*> Binary_tree::get_postorder(Binary_tree::Node* root, std::queue< Binary_tree::Node*> q)
{
	if (root == nullptr)
	{
		return q;
	}
	else
	{
		q = get_postorder(root->left, q);
		q = get_postorder(root->right, q);
		q.push(root);
	}
	return q;
}

//our goal is an inorder
/*
* go to a node
* go to the left node rinse and repeat
* add the node to the queue
* go to the right node rinse and repeat
* return
*/
std::queue< Binary_tree::Node*> Binary_tree::get_inorder(Binary_tree::Node* root, std::queue< Binary_tree::Node*> q)
{
	if (root == nullptr)
	{
		return q;
	}
	else
	{
		q = get_inorder(root->left, q);
		q.push(root);
		q = get_inorder(root->right, q);
	}
	return q;
}

void Binary_tree::print_queue(std::queue<Binary_tree::Node*> q)
{
	while (!q.empty())
	{
		std::cout << q.front()->name << " ,";
		q.pop();
	}
}
