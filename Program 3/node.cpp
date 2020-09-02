/*
File: node.cpp

This file contains the implementation of the node class. The node class is
derived from the base class remote_info. This file contains the functions
necessary to manage the left and right components of the BST. The nodes
created via this class are used by the BST manager class to create a BST.
Included in the node class are methods to move the root left and right, connect
the left and right pointers to new nodes, display the nodes via an 
overloaded ostream operator, and check for inequality, equality and assignment 
between nodes.

This file also contains the BST manager class. This class creates a binary
search tree, where its elements are objects. Ability to add, remove, find and
display elements of the BST are included. The algorithm for finding the node
to delete in the remove_info function uses a helper function that finds 
the inorder successor node, the minimum value on the right side of the tree,
in the case where the node to delete has two children.
*/


#include "remote_info.h"

//node constructor to set left and right nodes to NULL
node::node() {

	left = NULL;
	right = NULL;
}

//copy a node, use an IL so we can also copy the data in the base class
//for this function
node::node(const node& a_node): remote_info(a_node), left(0), right(0) {}

//If you want to create a new node from a pointer to a base class
node::node(remote_info* a_info):remote_info(*a_info), left(0), right(0) {}

//destructor to set left and right pointers to NULL
node::~node() {
	
	left = NULL;
	right = NULL;
}

//have the left pointer point to whatever it needs to point to later on	
void node::connect_left(node* connection) {
	
	left = connection;
}

//have the right pointer point to whatever it needs to point to later on    
void node::connect_right(node* connection) {
	
	right = connection;
}

//returns the left pointer
node*& node::go_left() {
	
	return left;
}

//returns the right pointer
node*& node::go_right() {

	return right;
}

//assignment operator for a node used in manager BST
node& node::operator = (const node& a_copy) {

	//if the node we are in is the node we are copying	
	if (this == &a_copy)
		return *this;

	//the node we are in equals the copy	
	this->remote_info::operator = (a_copy);
	return *this;
}

//check for inequality via an operator between nodes
bool node::operator != (const node& to_compare) {

	if (this->remote_info::operator != (to_compare)) {
		//return true if the nodes arent equal
		return true;
	}
	//else return false if the nodes are equal
	else
		return false;
}

//check for equality between two nodes via operator
bool node::operator == (const node& to_compare) {

	//if the two nodes are equal then return true
	if (this->remote_info::operator == (to_compare)) {
		return true;
	} else
		//if the two nodes are not equal then return false
		return false;

}
bool node::operator == (int to_compare) {

	if (this->remote_info::operator == (to_compare)) {
		return true;
	}
	else
		return false;
}

//display function for nodes, using an ostream operator instead
ostream& operator << (ostream& out, const node& to_display) {

	//get base class remote_info version of this operator so we can
	//output the data in the base class	

	to_display.display(out);	
	return out;	
}

//display function called by the ostream 
void node::display(ostream& out) const {

	remote_info::display(out);

}

void node::change_description() {}

//read function for a file
void node::read(istream& in) {
	remote_info::read(in);
}

//write function for a file
void node::write(ostream& out) {
	remote_info::write(out);
}
//----------------------------------------------------------------------------
//Functions for BST manager

//default constructor for the BST manager
manager_BST::manager_BST() {
	
	root = NULL;
}

//call the copy function for root in the copy constructor
manager_BST::manager_BST(const manager_BST& a_manager) {

	root = NULL;
	copy_tree(root, a_manager.root);
}

//assignment operator to set a BST to another
manager_BST& manager_BST::operator = (const manager_BST& src) {

	//check for self assignment
	if (this == &src) {
		return *this;
	}

	root = NULL;
	
	//call the copy tree function	
	copy_tree(root, src.root);

	return *this;
}

//copy nodes via a recursive copy function
void manager_BST::copy_tree(node*& dest, node* src) {

	//if there is something to copy from
	if (src) {

		//then dest is made a new node so we can add to it
		dest = new node(*src);
	
		//once source left is NULL, then the recursive call 	
		//will return and then the next line will run until it 
		//is NULL
		copy_tree(dest->go_left(), src->go_left());
		copy_tree(dest->go_right(), src->go_right());
	}
}

//destructor for the BST
manager_BST::~manager_BST() {

	//to recursively delete all nodes by calling the recursive delete 
	//function
	if (root) {
		delete_all(root);
	}
}

//recursive delete function to delete all nodes
void manager_BST::delete_all(node*& root) {

	//if there is something to delete
	if (root) {	
		//then call the delete function on both sides of the tree
		delete_all(root->go_right());
		delete_all(root->go_left());
	
		delete root;
		root = NULL;
	} 
}

//display function using an ostream operator for the tree
ostream& operator << (ostream& out, manager_BST& to_display) {

	//if there is nothing to display 
	if (!to_display.root) {	
		out << "Nothing to display. " << endl;
	} else

		//else call the recursive display function 
		to_display.display_tree(out, to_display.root);

	return out;
}

//to be called in main to add the object to the tree
manager_BST& manager_BST::operator += (node*& to_add) {

	add_info(root, to_add);	
	return *this;

}

//inorder BST display function 
void manager_BST::display_tree(ostream& out, node* root) {
	
	if (root != NULL) {
		//recursively display left side of tree
		display_tree(out, root->go_left());
		//display root of tree
		out << *root;
		out << endl;
		//display the right side of tree
		display_tree(out, root->go_right());

	}
}

//public retrieval function
remote_info* manager_BST::retrieve_info(const my_string& to_retrieve) {

	if (!root) {
		return 0;
	}

		return retrieve_info(root, to_retrieve);

}

//private recursive retrieval function
remote_info* manager_BST::retrieve_info(node*& root, const my_string& to_retrieve) {

	if (root) {

		if (*root > to_retrieve) {
			return retrieve_info(root->go_left(), to_retrieve);
		} else if (*root < to_retrieve) {
			return retrieve_info(root->go_right(), to_retrieve);
		} else {
		//} else if (*root == to_retrieve) {
			return root;
		}

	} else
		return NULL;

}

//This would have been the search for a material by an int priority
//But I dont think its necessary unless I read the project 3 pdf file wrong:


/*
//public to retrieve function that takes in an int to find a material
//based on priority
remote_info* manager_BST::retrieve_info(int priority_check) {


	if (!root) {
		return 0;
	}
		return retrieve_info(root, priority_check);

}

//private retrieve function that takes in an int to check
//for a material based on priority
remote_info* manage_BST::retrieve_info(node*& root, int priority_check) {

	if (root) {
		if (*root > priority_check) {
			return retrieve_info(root->go_left(), priority_check);
		} else if (*root < priority_check) {
			return retrieve_info(root->go_right(), priority_check);
		} else {
			return root;
		}
	} else
		return NULL;

}
*/

//return a node type
node*& manager_BST::min_of_right_tree(node*& root) {


	//to find the inorder successor we need to traverse the left of the tree
	if (root && root->go_left() != NULL) {
		return min_of_right_tree(root->go_left());
	} else 
	
		//return the leftmost node
		return root;

}

//public removal function to remove a node based on name 
void manager_BST::remove_info(const my_string& to_remove) {

	remove_info(root, to_remove);

}

//private recursive function to remove a node based on name
void manager_BST::remove_info(node*& root, const my_string& to_remove) {

	if (root) {

		if (*root < to_remove) {	
			remove_info(root->go_right(), to_remove);
		} else if (*root > to_remove) {
			remove_info(root->go_left(), to_remove);
		} else {
			//we are at a leaf then deletion is simple
			if (!root->go_right() && !root->go_left()) {
				delete root;
				cout << "Material removed successfully." << endl;
				root = NULL;
			}

			//node to be deleted has a right pointer
			else if (root->go_right() && !root->go_left()) {
			
				node* temp = root->go_right();	
				delete root;
				cout << "Material removed successfully." << endl;
				root = temp;
							
			//node to be deleted has a left pointer
			} else if (!root->go_right() && root->go_left()) {

				node* temp = root->go_left();
				delete root;
				cout << "Material removed successfully." << endl;
				root = temp;
		
			//in the complex case that the node we are deleting has both a right and left leaf	
			} else if (root->go_right() && root->go_left()) {

				//call the helper function that finds the inorder successor
				node* to_swap = min_of_right_tree(root->go_right());
				node* temp = to_swap;
				//swap the nodes
				*to_swap = *root;
				*root = *temp;
				remove_info(root->go_right(), to_remove);
			}

		}
	} else
		cout << "Nothing to delete with that title." << endl;
	
   }


//public add function for the BST
void manager_BST::add_info(node*& to_add) {
	
	add_info(root, to_add);

}

//private add function for the BST
void manager_BST::add_info(node*& root, node*& to_add) {

	//if there is a root then add below it:
	if (root) {
		if (*root < *to_add) {
			//if what we are adding is bigger than root
			add_info(root->go_right(), to_add);
		} else if (*root > *to_add) {
			//if what we are adding is smaller than root
			add_info(root->go_left(), to_add);
		} 
	} else 
		root = to_add;
}

//call the write function to write to a file
void manager_BST::write(ostream& out) {


	write(root, out);

}

//read function to read the data from the file
void manager_BST::read(istream& in) {

	my_string input;
	in >> input;
        in.ignore(100, '\n');

	node* to_add = NULL;

	if (input == "W") {
		//in this case we are reading a website
		to_add = new websites;
	}
	//in this case we are reading a video 
	else if (input == "V") {
		to_add = new videos;
	//in this case we are reading a meeting
	} else if (input == "M") {
		to_add = new meetings;
	}

	if (to_add) {
		to_add->read(in);
		add_info(to_add);
	}
}

//write data to a file from the BST
void manager_BST::write(node*& root, ostream& out) {

	if(root) {
		websites* to_save = NULL;
		to_save = dynamic_cast < websites* > (root);
		if (to_save) {
			//to designate a website being saved
			out << "W" << endl;
		} else {
			videos* to_save2 = NULL;
			to_save2 = dynamic_cast < videos* > (root);
			if (to_save2) {
				//to designate a video being saved
				out << "V" << endl;
			} else {
				meetings* to_save3 = NULL;
				to_save3 = dynamic_cast <meetings*> (root);
				if (to_save3) {
					//to designate a meeting being saved
					out << "M" << endl;
				}
			}
		}
		//call the write function on root
		root->write(out);
		//properly write the data to a file based on a BST
		write(root->go_left(), out);
		write(root->go_right(), out);
	}
	
}



