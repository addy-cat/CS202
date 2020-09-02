/*
File: node.cpp

This file contains the implementation of the node class functions and the
activity manager class functions.  Included for the node class is the display function
that directly prints the list, an add function that adds an activity and a remove
function that removes one. The node class also has various helper functions that
help the add, find and remove functions determine where the activity needs to be added or removed.
The activity manager add, remove and find functions use the similar functions in node
to run because the node class has the ability to actually add and remove data.
*/

#include "module.h"

//node functions:

//node default constructor setting next and previous pointers to NULL
//and the size of the list to zero, and creating the DLL of arrays
node::node() { 

	//set next and previous pointers to NULL 
	next = NULL;
	previous = NULL;

	//the size of the list starts at zero
	list_size = 0;

	//the list is an array of activities
	list = new activity* [MAX_ARRAY];

	//need to set every index of the array to NULL, this
	//function is below and is recursive
	null_list_helper_for_constructor(0);

}

//the copy constructor for the node class
node::node(const node* a_node) {

	//set next and previous pointers to NULL for copying
	next = NULL;
	previous = NULL;

	//list size is zero for copying
	list_size = 0;

	//call the recursive copy function below that copies from source 
	copy_activity(a_node->list, a_node->list_size, 0);

}

//copy function for an activity, where we are initiating the source
//list to contain an activity
void node::copy_activity(activity** source_list, int source_size, int i) {

	if (i < source_size) {
	//	list[i] = source_list[i];
		list[i] = new activity(*source_list[i]);
		copy_activity(source_list, source_size, i + 1);
	} else
		list_size = source_size;

}

//node class destructor to delete the dynamic memory of a list and 
//to delete the next and previous pointers
node::~node() {

	//delete whatever is next and whatever is previous
	next = NULL;
	previous = NULL;
	
	//the recursive delete list needs to be called to delete every element of the list
	//it expects an int
	delete_list(0);
	delete [] list;

}


void node::null_list_helper_for_constructor(int i) {

	//set all the array indices to NULL or else I get conditional jump relies on 	
	//uninitialized values error
	if (i < MAX_ARRAY) {
		list[i] = NULL;
		//increment i to go thru the whole array
		null_list_helper_for_constructor(i + 1);
	}

}

//used to compare the priority of an activity in
//the activity manager functions add activity to determine
//where to add an activity
int node::compare_priority(activity* a_activity) {

	return list[0]->compare_priority(a_activity);

}

//recursive delete function to delete a list called in destructor
void node::delete_list(int i) {

	//go thru the list and delete its elements one by one
	if (i < list_size) {
		
		delete_list(i+1);	
		delete list[i];
	}

	//else the list size takes in an int 0
	else {
		list_size = 0;
	}
}

//display function used to print each activity and all data
//associated with an activity to the console, by calling the
//recursive display function that takes in an int for its if 
//statement
void node::display() {
	
	if (list_size) {
		display(0);
	} else
		cout << "Nothing to display yet." << endl;

	//to help differentiate between seperate activity displays
	cout << "_________________________________" << endl;
}

//recurse thru the list by incrementing i to display every element of the list
void node::display(int i) {

	if (i < list_size) {
		list[i]->display();
		//recurse
		display(i + 1);
	}

}


//go next function to return the next pointer in the list
node *& node::go_next() {

	return next;

}

//go previous function to return the previous pointer in the list
node *& node::go_prev() {

	return previous;

}

//used to connect a next pointer to a node
void node::connect_next(node* connection) {

	next = connection;
}

//used to connect a previous pointer to a node
void node::connect_prev(node* connection) {

	previous = connection;
}

//node function used to add an activity to a list
void node::add_activity(activity*& a_activity) {

	//as long as there is data in the list:
	if (list_size != 0) {

		int status = add_activity_helper(a_activity, 0);		
	
		if (status == -1) {
			cout << "Too many activities with this priority." << endl;	
		} else {
		//if the size of the list based on the passed in value from
		//activity helper if not -1 (there is room to add) then add
		//a activity to the list	
			//shift i
			shift_i(status, list_size);
			list[status] = a_activity;
			list_size++;
		}
	
	} else {
	//else there is no room to add 
		list[0] = a_activity;
		list_size++;
	}
}

//find where we want to add an activity. Because titles must be sorted
//alphabetically we need to call the compare function from the activity
//class to compare the titles to see where to add.
int node::add_activity_helper(activity*& a_activity, int i) {

	//here i is zero so return that is the list is NULL
	if (list[i] == NULL) {
		return i;
	}

	//if i is less than the max for array size then all is good
	else if (i < MAX_ARRAY) {
//		int check = list[i]->compare_title(a_activity);
		 //status variable to compare the title to see where we need to add
		 int status = list[i]->compare_title(a_activity);

		//because status is <= 0 this is not the correct place to add
		//the activity because things need to be alphabetical and this
		//is too small
		if (status <= 0) {
			return add_activity_helper(a_activity, i + 1);
		}

		//else we can return i to add the activity
		else  {
			return i;
		}

	}

	else 
		//if there is no room to add
		return -1;
}

int node::add_activity_helper(const char* activity_title, int i) {

	//if (!list[i]) {

	if (i < MAX_ARRAY) {
		
		//incorrect place to add and not possible	
		if (!list[i]) {
			return -1;
		} 

		 int status = list[i]->compare_title(activity_title);

		//incorrect place to add, recurse
		if (status != 0) {
			return add_activity_helper(activity_title, i + 1);
		}
		//correct place to add
		else {
			return i;
		}
	} 

		return 0;
}

//shift every index from i to j up one index to help add
//or else you will get holes in your array
void node::shift_i(int i, int j) {

	if (j > i) {
		list[j] = list[j-1];
		shift_i(i, j-1);
	}

}

//shift index from i to list_size down one 
void node::shift_opposite_way(int i) {

	if (i < list_size) {
		list[i] = list[i+1];	
		shift_opposite_way(i + 1);
	}	

}

//delete an activity from the list by passing in the title of an 
//activity
bool node::remove_activity(const char* activity_title) {

	//if there is nothing in the list then we do not need to remove
	if (!list_size) {
		
		cout << "There are no titles. " << endl;
		return false;
	} else {

		//finds the index of the activity with passed in title
		int i = add_activity_helper(activity_title, 0);

		//if i equals negative 1 it was unsuccessful in finding the activity to remove
		if (i == -1) {
			cout << "No activities for this title exist." << endl;
			return false;
		} else {

			//else you can delete the index with that activity
			delete list[i];
			shift_opposite_way(i);	
			list_size--;
			//return true since something was removed
			return true;;
	}
    }

	//return false is nothing was removed
	return false;
}	

//issue here
bool node::find_activity(const char* activity_title, activity*& a_activity) {

	 int index = add_activity_helper(activity_title, 0);

	//go trru array and check each array and compare to title passed in
	//if its not the correct one go to next one. If it is, then return it

	if (index == -1) {
	
		//cout << "No activity found." << endl;	
		return false;
			
        } else {

		a_activity = list[index];
		return true;
	}

}


//---------------------------------------------------------------------

//activity manager functions


//activity manager constructor
activity_manager::activity_manager() {

	head = NULL;
	tail = NULL;

}

//activity manager destructor
activity_manager::~activity_manager() {

	//call the delete function to delete the head
	delete_list(head);
}


//recursive delete function to delete the head and everything after head
void activity_manager::delete_list(node*& head) {

	if (head) {
		delete_list(head->go_next());
		delete head;
	} else {

		//if there is no head then just set the head and tail to NULL
		head = NULL;
		tail = NULL;	
	}
}

//activity manager copy constructor to copy source head to head
activity_manager::activity_manager(const activity_manager& to_copy) {

	head = NULL;
	tail = NULL;
	copy_nodes(to_copy.head, head);

}

//copy constructor to copy from source head to dest head
void activity_manager::copy_nodes(node* source, node*& dest) {

	//if there is something to copy 
	if (source != NULL) {
		//make a new node to copy onto from
		node* temp = new node(*dest);
		dest->connect_next(temp);
		copy_nodes(source->go_next(), dest->go_next());
		//connect up next and previous nodes
		dest->go_next()->connect_prev(dest);
	} else 

		//if there is nothing to copy from
		tail = dest->go_prev();
}

//call the recursive remove activity function
void activity_manager::remove_activity(const char* activity_title) {

	remove_activity(head, activity_title);
}


//recursive remove activity function 
void activity_manager::remove_activity(node* head, const char* activity_title) {

	//if there is something to remove	
	if (head) {

		//if head has a title to remove then call node classes
		//remove activity that deletes the node
		if (head->remove_activity(activity_title)) {

			cout << "Activity was removed" << endl;	
		} else
	
			//traverse to find next to delete	
			remove_activity(head->go_next(), activity_title);
	} else 

		//if there is no head then the activity does not exist
		cout << "That activity doesn't exist" << endl;
			
}

//call the add activity function
void activity_manager::add_activity(activity*& a_activity) {

	add_activity(head, a_activity);
}


//activity manager add activity function to add an activity to the list
//and all an activities associated data
void activity_manager::add_activity(node*& head, activity*& a_activity) {

	//if head in not empty then we can add
	if (head != NULL) {

		//status will compare if the activity in heads priority
		//is bigger than or less than the activity we are trying to add
		//to determine where to add the activity
		int status = head->compare_priority(a_activity);
		if (status == -1) {

			//then we recurse because this is the wrong place to add
			add_activity(head->go_next(), a_activity);
		}

		//then a node already exists with the specified priority
		//so in this case just add it to what exists
		else if (status == 0) {
			head->add_activity(a_activity);
		}
	
		//if the priority is a valid and unique priority:	
		else {
			//we can add once the status is bigger than 1:

			//new node temp to use to add
			node* temp = new node;

			//temp is connected to the head pointer
			temp->connect_next(head);
			if (head->go_prev()) {

				//connect previous pointer
				temp->connect_prev(head->go_prev());
				//connect next pointer
				temp->go_prev()->connect_next(temp);
			}
			
			head->connect_prev(temp);
			temp->add_activity(a_activity);
			//the thing we added is now head
			head = temp;
		}	


	} else { 
		//if head is empty we need to make a new node for head
		head = new node;
		head->add_activity(a_activity);
	}

	//report success
	cout << "Activity added!" << endl;
}

//for displaying all activities disregarding priority level
void activity_manager::display() {

	if (!head) {
		//if the user has not yet entered an activity
		cout << "No activities added yet... " << endl;
	} else
		//if the user has entered an activity then display its title
		//along with all its data by calling recursive display function
		display(head);
}

//recursive display function 
void activity_manager::display(node* head) {

	//base case above guarantees at this point there will be something to
	//display:	
	if (head) {

		//display whatever is in head
		head->display();
		//then recurse to display the next data in head
		display(head->go_next());
	} 
}

//activity manager find activity function that calls the recursive
//find activity function
activity* activity_manager::find_activity(const char* activity_title) {

	//if there is nothing to find then return 0
	if (!head) {

		//return NULL;
		return 0;
	}

	//call the recursive find activity function below
	return find_activity(head, activity_title);


}

//by passing in the activity_title we can find the correct title the user enters
//this function is used for editing the activity via the change functions in the
//derived classes once we have found the correct activity to edit
activity* activity_manager::find_activity(node* head, const char* activity_title) {

	//if there is data in head then we know we can find something
	if (head) {

		//create an a_activity pointer and that pointer is put into
		//the status variable below to compare it to the activity_title
		activity* a_activity = NULL;

		bool status = head->find_activity(activity_title, a_activity);
	
		//checks if the activity is a match	
		if (status) {

			//if it is a match then return it to use it
			return a_activity;
		} 

		//recurse to find the match if it was not in head
		return find_activity(head->go_next(), activity_title);
	} else 	{

		//if there is no data in head then no activity exists
		return NULL;
	}

}

//to display the activity with the highest priority
void activity_manager::display_highest() {

	//so display whatever is in head because it will be highest
	if (head) {	
		head->display();
	} else

		cout << "There are no activities yet." << endl;
		
}

































		
