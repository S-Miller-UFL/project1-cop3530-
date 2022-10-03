#pragma once
#include <queue>
//got help from eric chen on 9/23/2022
//got help from liv on 9/26/2022
//got help from blake shaffer on 9/27/2022
//got help from richie on 10/3/2022

class Binary_tree
{
public:
	struct Node
	{
		int id;
		std::string name;
		int balance_factor;
		Node* left;
		Node* right;
		Node()
		{
			left = nullptr;
			right = nullptr;
			id = 0;
			name = "";
			balance_factor = 0;
		}
	};
	Binary_tree();
	~Binary_tree();
	//functions that help with inserting nodes
	void insert(unsigned int const&, std::string const&);
	//functions that help with removing nodes
	void remove(unsigned int const&);
	void remove_N(int const&);
	//functions that help with finding nodes
	void search(unsigned int const&);
	void search(std::string const&);
	//functions that help with printing
	void print_preorder_helper();
	void print_postorder_helper();
	void print_inorder_helper();
	void print_level_count();
	//traversers
	void traverse_whole_tree();
	std::vector<int> inorder();

private:
	//functions that help with inserting nodes
	Node* create_new_node(unsigned int const&, std::string const&);
	Node* priv_insert(Node*, unsigned int const&, std::string const&);
	//functions that help with removing nodes
	Node* priv_remove(Node*, unsigned int const&);
	//functions that help with printing
	void print_queue(std::queue< Binary_tree::Node*>);
	//functions that help with finding nodes
	Node* priv_search(unsigned int const&, Node*);
	std::queue<Node*> priv_search(std::queue<Binary_tree::Node*>, std::string const&, Node*);
	Node* find_parent(unsigned int const&, Node*);
	//getters
	int get_id(Node*);
	std::string get_name(Node*);
	Node* get_tree_root();
	int getheight(Node*);
	int check_balance(Node*);
	int get_balance_factor(Node*);
	std::queue< Binary_tree::Node*> get_preorder(Binary_tree::Node*, std::queue< Binary_tree::Node*>&);
	std::queue< Binary_tree::Node*> get_postorder(Binary_tree::Node*, std::queue< Binary_tree::Node*>&);
	std::queue< Binary_tree::Node*> get_inorder(Binary_tree::Node*, std::queue< Binary_tree::Node*>&);
	Node* get_ios(Node* root, int&);
	//traversers
	void traverse(Node*);
	//mutators
	Node* balance(Node*);
	Node* rotate_left(Node*);
	Node* rotate_right(Node*);
	void change_node_data(Node*, unsigned int const&);
	//variables
	int node_count;
	Node* tree_root;
};

Binary_tree::Binary_tree()
{
	this->tree_root = nullptr;
	this->node_count = 0;
}

Binary_tree::Node* Binary_tree::create_new_node(unsigned int const& id, std::string const& name)
{
	Binary_tree::Node* node = new Binary_tree::Node;
	node->id = id;
	node->name = name;
	if (this->node_count == 0)
	{
		this->tree_root = node;
	}
	this->node_count = node_count + 1;
	return node;
}


Binary_tree::Node* Binary_tree::priv_insert(Binary_tree::Node* root, unsigned int const& id, std::string const& name)
{
	if (root == nullptr)
	{
		root = create_new_node(id, name);
	}
	else if (id > root->id)
	{
		//std::cout << "going to the right of: " << root->id << std::endl;
		root->right = priv_insert(root->right,id,name);
	}
	else if (id < root->id)
	{
		//std::cout << "going to the left of: " << root->id << std::endl;
		root->left = priv_insert(root->left, id,name);
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

Binary_tree::Node* Binary_tree::priv_search(unsigned int const& id, Binary_tree::Node* node)
{
	//std::cout <<"currently at: " << node->id << std::endl;
	if (node == nullptr)
	{
		return node;
	}
	else if (node->id == id)
	{
		return node;
	}
	else if (node->id > id)
	{
		node = priv_search(id, node->left);
	}
	else if (node->id < id)
	{
		node = priv_search(id, node->right);
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
void Binary_tree::search(unsigned int const& id)
{
	if (priv_search(id, this->tree_root) == nullptr)
	{
		std::cout << "unsuccessful" << std::endl;
	}
	else
	{
		std::cout << get_name(priv_search(id, this->tree_root)) << std::endl;
	}
}
void Binary_tree::search(std::string const& name)
{
	std::queue<Binary_tree::Node*> q;
	q = priv_search(q, name, this->tree_root);
	if (q.empty())
	{
		std::cout << "unsuccessful" << std::endl;
	}
	else
	{
		while (!q.empty())
		{
			std::cout << get_id(q.front()) << std::endl;
			q.pop();
		}
	}
}
std::queue<Binary_tree::Node*> Binary_tree::priv_search(std::queue<Binary_tree::Node*> q,std::string const& name, Binary_tree::Node* node)
{
	if (node == nullptr)
	{
		return q;
	}
	if (node->name == name)
	{
		//im 99.9999999999999% sure this is preorder but you never know
		q.push(node);
		q = priv_search(q, name, node->left);
		q = priv_search(q, name, node->right);
	}
	if(node->name != name)
	{
		q = priv_search(q,name, node->left);
	}
	
	if (node->name != name)
	{
		q = priv_search(q,name, node->right);
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

//for debugging only. delete when submitting
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
	return N;
}
//based off of the code in the lecture slides (AVL trees)
Binary_tree::Node* Binary_tree::rotate_right(Node* root)
{
	Binary_tree::Node* N = nullptr;
	Binary_tree::Node* node = nullptr;
	node = root->left->right;
	N = root->left;
	root->left = node;
	N->right = root;
	return N;
}

void Binary_tree::remove(unsigned int const& id)
{
	this->tree_root = priv_remove(this->tree_root, id);
	if (priv_search(id,this->tree_root) != nullptr)
	{
		std::cout << "unsuccessful" << std::endl;
	}
	else
	{
		std::cout << "successful" << std::endl;
		this->node_count = this->node_count - 1;
	}
	//this->node_count = this->node_count - 1;
}


//pass in the node to be deleted
/*
*if the node to be deleted has no children
*	set the node equal to null ptr
* if the node to be deleted has only one child
*	set the node equal to the child
* if the node to be deleted has two children
*	find the inorder successor
*	set the node equal to the IOS
*/
//find the IOS
/*
* to find the IOS, we need to find the leftmost node of the right subtree
* to find the leftmost node, we need to find the node that is the most right-heavy
* this requires that our balances for each node be correct
*/
Binary_tree::Node* Binary_tree::priv_remove(Node* root, unsigned int const& id)
{
	//pass in tree root
	//return tree root but with node removed

	if (root == nullptr)
	{
		return root;
	}
	if (root->id == id)
	{
		if (root->left == nullptr && root->right == nullptr)
		{
			root = nullptr;
			delete root;
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
			std::queue<Binary_tree::Node*> q; // = get_inorder(root->right, q); this specific line is causing bad_alloc
			//fixed on 10/3/2022: the reason it was throwing bad alloc is because you were declaring q while also passing it into get_inorder.
			//you dont need to do that, as q gets passed in by reference.
			get_inorder(root->right, q);

			Binary_tree::Node* M = root; //get_ios(root->right, root->right->id);
			int temp = root->right->id;
			std::string tempn = root->right->name;
			//get the smallest value
			while (!q.empty())
			{
				if (q.front()->id <= temp)
				{
					temp = q.front()->id;
					M = q.front();
				}
				q.pop();
			}
			
			//get value of ios
			temp = M->id; //fix this
			tempn = M->name;
			//delete the ios by passing in the right subtree
			root->right = priv_remove(root->right, temp);
			//set the root
			root->id = temp;
			root->name = tempn;
		}
	}
	else if (root->id > id)
	{
		root->left = priv_remove(root->left,id);
	}
	else if (root->id < id)
	{
		root->right = priv_remove( root->right,id);
	}
	
	return root;
}

void Binary_tree::insert(unsigned int const& id, std::string const& name)
{
	this->tree_root = priv_insert(this->tree_root, id, name);
	if (priv_search(id, this->tree_root) == nullptr)
	{
		std::cout << "unsuccessful" << std::endl;
	}
	else
	{
		std::cout << "successful" << std::endl;
	}

}

void Binary_tree::print_preorder_helper()
{
	std::queue< Binary_tree::Node*> q;
	//get_preorder(this->tree_root, q);
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

void Binary_tree::print_level_count()
{
	std::cout << getheight(this->tree_root) << std::endl;
}
//our goal is a preorder
/*
* go to a node
* add the node to a queue
* go to left node rinse and repeat
* go to right node rinse and repeat
* return
*/
std::queue< Binary_tree::Node*> Binary_tree::get_preorder(Binary_tree::Node* root , std::queue< Binary_tree::Node*>& q)
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
std::queue< Binary_tree::Node*> Binary_tree::get_postorder(Binary_tree::Node* root, std::queue< Binary_tree::Node*>& q)
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
std::queue< Binary_tree::Node*> Binary_tree::get_inorder(Binary_tree::Node* root, std::queue< Binary_tree::Node*>& q)
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

Binary_tree::Node* Binary_tree::get_ios(Node* root, int& ios)
{
	Node* n = nullptr;
	Node* m = nullptr;
	if (root == nullptr)
	{
		return root;
	}
	if (ios > root->id)
	{
		ios = root->id;
		if (root->left != nullptr)
		{
			root = get_ios(root->left, ios);
		}
	}
	return root;
}


void Binary_tree::print_queue(std::queue<Binary_tree::Node*> q)
{
	std::string queue;
	while (!q.empty())
	{
		queue = queue + q.front()->name + ", ";
		q.pop();
	}
	queue = queue.substr(0, queue.size() - 2);
	std::cout << queue << std::endl;
}

//getting the entire tree but inorder traversal
//removing nth item from that inorder traversal
void Binary_tree::remove_N(int const& N)
{
	std::queue<Binary_tree::Node*> q;
	get_inorder(this->tree_root, q);
	for (int i = 0; i < N; i++)
	{
		q.pop();
	}
	remove(q.front()->id);
	while (!q.empty())
	{
		q.pop();
	}
	//this->node_count = node_count - 1;
}

//all we have to do for our destructor is get the queue of the inorder nodes and delete them sequentially
Binary_tree::~Binary_tree()
{
	std::queue<Binary_tree::Node*> q;
	get_inorder(this->tree_root, q);
	while (!q.empty())
	{
		delete(q.front());
		q.pop();
	}
}

std::vector<int> Binary_tree::inorder()
{
	std::queue<Binary_tree::Node*> q;
	get_postorder(this->tree_root, q);
	std::vector<int> v;
	while (!q.empty())
	{
		v.push_back( q.front()->id);
		q.pop();
	}
	return v;
}

