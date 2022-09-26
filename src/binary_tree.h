#pragma once
#include <queue>
//got help from eric chen on 9/23/2022
//got help from liv on 9/26/2022
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
	Node* find_parent(unsigned int const& ,Node*);
	void find_helper(unsigned int const&);
	void find_helper(std::string const&);
	void change_node_data(Node*, unsigned int const&);
	std::queue<Node*> find(std::queue<Binary_tree::Node*>,std::string const&, Node*);
	Node* get_tree_root();
	int getheight(Node*);
	void traverse(Node*);
	void traverse_whole_tree();
	int check_balance(Node*);
	int get_balance_factor(Node*);
	Node* balance(Node*);
	Node* rotate_left(Node*);
	Node* rotate_right(Node*);
	int count();
	std::queue<Binary_tree::Node*> count_helper(Node*, std::queue<Binary_tree::Node*>);
	void remove_node(unsigned int const&);
	Node* remove(Node*, unsigned int const&);
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
	if (root == nullptr)
	{
		root = create_new_node(id, name);
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
	root->balance_factor = check_balance(root);
	root = balance(root);
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
Binary_tree::Node* Binary_tree::find_parent(unsigned int const& id, Node* parent)
{
	if (parent == nullptr)
	{
		return parent;
	}
	if (parent->left->id == id)
	{
		return parent;
	}
	if (parent->right->id == id)
	{
		return parent;
	}
	if (parent->id > id)
	{
		parent = find_parent(id, parent->left);
	}
	if (parent->id < id)
	{
		parent = find_parent(id, parent->right);
	}
	return parent;
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

void Binary_tree::traverse_whole_tree()
{
	traverse(this->tree_root);
}

//well leave this here for now, will probably delete later.

int Binary_tree::check_balance(Node* tree_root)
{
	return getheight(tree_root->left) - getheight(tree_root->right);
}


int Binary_tree::get_balance_factor(Node* root)
{
	return root->balance_factor;
}

Binary_tree::Node* Binary_tree::balance(Node* root)
{
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
		root->left->balance_factor = check_balance(root->left);
		root->right->balance_factor = check_balance(root->right);
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
		root->left->balance_factor = check_balance(root->left);
		root->right->balance_factor = check_balance(root->right);
	}
	root->balance_factor = check_balance(root);
	return root;
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
	//N->balance_factor = check_balance(N);
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
	//N->balance_factor = check_balance(N);
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
	//Binary_tree::Node* N = find(id, this->tree_root);
	this->tree_root = remove(this->tree_root, id);
	this->node_count = this->node_count - 1;
}


//method 1:
//pass in the PARENT of the node to be deleted
/*
* if the root has no grandchildren
*	set root's child equal to nullptr (or alternatively, delete it)
* if the root has one grandchild
*	point the root
* 
*/
//method 2:
//pass in the node to be deleted
/*
*if the node to be deleted has no children
*	set the node equal to null ptr
* if the node to be deleted has only one child
*	set the node equal to the child
* if the node to be deleted has two children
*	find the inorder successor
*	set the node equal to the IOS
*	
*/
//find the IOS
/*
* to find the IOS, we need to find the leftmost node of the right subtree
* to find the leftmost node, we need to find the node that is the most right-heavy
* this requires that our balances for each node be correct
*/
Binary_tree::Node* Binary_tree::remove(Node* root, unsigned int const& id)
{
	//pass in tree root
	//return tree root but with node removed
	/*
	* cant get find involved, wont return tree root.
	* this function will have to find the tree root
	* traverse the tree
	* if the node is found, remove it
	* return tree root;
	*/
	if (root == nullptr)
	{
		return root;
	}
	//removing leaf node works fine
	//removing node with two children
	//removing node with one child
	if (root->id == id)
	{
		if (root->left == nullptr && root->right == nullptr)
		{
			root = nullptr;
		}
		else if (root->left == nullptr && root->right != nullptr)
		{
			//set node equal to right node
			root = root->right;
		}
		else if (root->left != nullptr && root->right == nullptr)
		{
			//set node equal to left node
			root = root->left;
		}
		else if (root->left != nullptr && root->right != nullptr)
		{
			//do some complicated shit here involving in order successor
			/*
			* go into the right subtree and get the node with the smallest value(M)
			* make a temp node and set the temp node value equal to M's value(temp)
			* set smallest value node equal to its right node
			* delete M
			* set roots value equal to temp
			*/
			std::queue<Binary_tree::Node*> q = get_inorder(root,q);
			Binary_tree::Node* M = nullptr;
			int temp = root->right->id;
			while (!q.empty())
			{
				if (q.front()->id < temp)
				{
					temp = q.front()->id;
					M = q.front();
				}
				q.pop();
			}
			
		}
	}
	else if (root->id > id)
	{
		root->left = remove(root->left,id);
	}
	else if (root->id < id)
	{
		root->right = remove( root->right,id);
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
