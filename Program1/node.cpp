#include <iostream>
#include "node.h"
using namespace std;

//File: node.cpp

/*
This file contains a lot of information regarding both the third derived class from Module, Assignment, and the data structure. It
also contains the functions for the class Assignment_manager, and the functions for the Node class. The Assignment_manager class
assists the Assignment class is adding the Assignment classes data to an array of linked lists. The Assignment_manager
is the class that actually does the heavy lifting for the data structure, such as adding Assignment information like titles and descriptions, and changing and 
displaying information in the array of linked lists. The functions for Assignment (not Assignment_manager), however, are very simple
much like the functions in Module.cpp. Node class also has its functions here, such as a function for incrementing node* next and connecting nodes.
*/

//Assignment class functions:

//Assignment default constructor
Assignment::Assignment() {
	
	//description char* set to NULL
	description = NULL;

	//grade integer set to zero
	grade = 0;
		
	//TimeDate object duedate has its function change_time and change_date
	//functions initialize their arguments to zero
	duedate.change_date(0, 0, 0);
	duedate.change_time(0, 0, 0);
}

 
//Assignment copy constructor
Assignment::Assignment(const Assignment& to_copy):Module(to_copy) {
//make sure there is a assignment to copy so the pointer isn't NULL, to avoid
//dereferencing a NULL pointer

        if(to_copy.description) {
                description = new char[strlen(to_copy.description) + 1];
                strcpy(description, to_copy.description);
        } else
		//if there is nothing to copy
                description = NULL;

	//copy grade int
	grade = to_copy.grade;

	//copy duedate
	duedate = to_copy.duedate;
}


//Assignment desctructor for dynamic memory
Assignment::~Assignment() {

	//delete correctly for character array description
	delete [] description;

	//remember to set to NULL
	description = NULL;
}

//change the time and date an assignment is due using the TimeDate object duedate
void Assignment::change_time_date() {

	//initialize local time variables to zero
	int second = 0;
	int minute = 0;
	int hour = 0;

	//initialize local date variables to zero
	int day = 0;
	int month = 0;
	int year = 0;

	//promt user for the time, then store these values
	//into the local variables
	cout << "Enter the due time/ date: ";
	cout << endl;
	cout << "Hour: ";
        cin >> hour;
        cout << "Minute: ";
        cin >> minute;
        cout << "Second: ";
        cin >> second;

        //pass the second, minute and hour user entires to the
        //change_time function in TimeDate class using duedate object
        duedate.change_time(second, minute, hour);


	//prompt user for the date, then store these values into
	//the local date variables
        cout << "Year: ";
        cin >> year;
        cout << "Month: ";
        cin >> month;
        cout << "Day: ";
        cin >> day;

        //pass the day, month and year user entries to change_date function
        //in TimeDate class using duedate object
        duedate.change_date(day, month, year);


}

//change the grade and the description for an assignment
void Assignment::change_grade_desc() {

	//make sure cin is clear
	//(function caused lots of issues... without this cin check the 
	//function fails to ask the user for a description the second times its run)
	if(cin) {
		cin.clear();
		cin.ignore(MAX_CHAR, '\n');
	}

	cout << "Enter an assignment description:";

	//check if there is already a description, and if there is,
	//be sure to delete what is in there
	if(description) {
		delete [] description;
	}

	//designate description to be a character array
	description = new char[MAX_CHAR];
	cin.get(description, MAX_CHAR);
	cin.ignore(MAX_CHAR, '\n');

	//include a check for cin failing or the program blows up for some reason
	//(this function caused a lot of issues)
	cout << "Enter a grade: (numerical values only)";
	cin >> grade;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Please enter a numerical grade." << endl;
		cin >> grade;
	}
		
	cin.clear();
	cin.ignore(100, '\n');

}



//display an assignments title, grade, due date, and description
void Assignment::display() {

	//display the title of an assignment from the Module class 
	cout << "Assignment Title: ";
	Module::display();
	cout << endl;

	//display the due date and time of an assignment using an object
	//of the TimeDate class called duedate. This function is in the TimeDate
	//class. 
	cout << "Is due: ";
	duedate.display_timedate();
	cout << endl;

	//display an integer grade
	cout << "Grade: ";
	cout << grade;
	cout << endl;	

	//Display the description of an assignment
	cout << "Description is: ";
	cout << endl;
	//check if there is a description and if there isn't make sure to
	//say so. Need to have an if statement checking if there is a 
	//description of else the program hangs when this function outputs
	//description.
	if (description) {
	
		cout << description;
		cout << endl;
	} else
		cout << "No description. "<< endl;

}


//-----------------------------------------------------------------------------------------
//Node class functions:

//initialize next pointer to NULL
Node::Node() {

	next = NULL;
}

//copy constructor for a node with initialization list
//because class Node has a parent, Assignment. We need to cause the
//base class constructor with arguments to be invoked.
Node::Node(const Assignment& to_copy):Assignment(to_copy){

	next = NULL;	
	
}

//destructor for the next pointer in Node
Node::~Node() {

	next = NULL;

}

//Function that returns the next value of the list instead of using a next pointer
Node *& Node::go_next() {

	return next;

}

//connect nodes
void Node::connect_next(Node* connection) {

	//in case there is already something in next
	if (next) {
		delete next;
	} 

	next = connection;
}

//-----------------------------------------------------------------------------------------
//Assignment_manager class functions

//make an ARR of LLL, constructor
Assignment_manager::Assignment_manager() {

	//Node** table set to NULL in this constructor
	table = NULL;

	//table is an array of 3 head pointers
	table = new Node*[TABLE_SIZE];

	//for every array is NULL
	for(int i = 0; i < TABLE_SIZE; i++) {
		
		table[i] = NULL;
	}
}

//copy constructor for Assignment_manager that copies the elements in table
Assignment_manager::Assignment_manager(const Assignment_manager& source) {

	for (int i = 0; i < TABLE_SIZE; i++) {
		table[i] = NULL;
		table[i] = source.table[i];
	}

}

//node copy constructor calls this function to traverse the lists
void Assignment_manager::copy(Node*& newhead, Node* oldhead) {

	if(oldhead) {
		newhead->connect_next(oldhead->go_next());
		copy(newhead->go_next(), oldhead->go_next());
	}

}

//function to change the information by searching for a title for LABS
bool Assignment_manager::change_lab(char* searched_title) {

	//make a Node to pass the output from search_title into
	Node* temp = search_title(table[0], searched_title);

	//if there is no title matching searched_title:
	if (temp == NULL) {
		cout << "That lab does not exist... :( " << endl;
		return false;
	} else {
		
		temp->change_grade_desc();
		temp->change_time_date();
		return true;
	}

}

//function to change the information by searching for a title for BOOKWORK
bool Assignment_manager::change_bookwork(char* searched_title) {

        //make a Node to pass the output from search_title into
        Node* temp = search_title(table[1], searched_title);

        //if there is no title matching searched_title:
        if (temp == NULL) {
                cout << "That bookwork does not exist... :( " << endl;
                return false;
        } else {

                temp->change_grade_desc();
                temp->change_time_date();
                return true;
        }

}

//function to change the information by searching for a title for EXAMS
bool Assignment_manager::change_exam(char* searched_title) {

        //make a Node to pass the output from search_title into
        Node* temp = search_title(table[2], searched_title);

        //if there is no title matching searched_title:
        if (temp == NULL) {
                cout << "That exam does not exist... :( " << endl;
                return false;
        } else {

                temp->change_grade_desc();
                temp->change_time_date();
                return true;
        }

}

//return the Assignment we want to change
Node*& Assignment_manager::search_title(Node*& head, char* searched_title) {

	//if title is not in the list	
	if(head == NULL) {
		return head;
	}	

	//call compare title	
	if(head->compare_title(searched_title)) {
		return head;
	} else 
		return search_title(head->go_next(), searched_title);

}



//desctructor
Assignment_manager::~Assignment_manager() {

	//delete all three linked lists in array

	for(int i = 0; i < TABLE_SIZE; i++) {
			
		delete_all(table[i]);
	}
	delete [] table;
	table = NULL;
}

//delete recursively for a arbitrary list from table
void Assignment_manager::delete_all(Node*& head) {

	if (head) {
		delete_all(head->go_next());
		delete head;
		head = NULL;
	}

}

//add a lab assignment non recursive function:
bool Assignment_manager::add_lab_assign(const Assignment& a_assignment){

	//if table for labs is NULL, add assignment
	if(table[0] == NULL) {
		table[0] = new Node(a_assignment);
		return true;
	} else {
		Node* newnode = new Node(a_assignment);
		//recursive call on the correct assignment (first list)
		Node* temp = add_assignment(table[0]);
		temp->connect_next(newnode);
	}

}

//add a bookwork assignment non recursive function:
bool Assignment_manager::add_bookwork_assign(const Assignment& a_assignment){

	//if table for bookwork is NULL, add assignment
        if(table[1] == NULL) {
                table[1] = new Node(a_assignment);
                return true;
        } else {
                Node* newnode = new Node(a_assignment);
		//recursive call on the correct assignment (second list)
                Node* temp = add_assignment(table[1]);
                temp->connect_next(newnode);
        }

}

//add take home exam assignment non recursive function:
bool Assignment_manager::add_take_home_exam(const Assignment& a_assignment){

	//if table for exams is NULL, add assignment
        if(table[2] == NULL) {
                table[2] = new Node(a_assignment);
                return true;
        } else {
                Node* newnode = new Node(a_assignment);
		//recursive call on the correct assignment (third list)
                Node* temp = add_assignment(table[2]);
                temp->connect_next(newnode);
        }

}


//add an arbitrary assignment recursive function (all 3 add assignment functions
//will call this same recursive function)
Node*& Assignment_manager::add_assignment(Node*& head) {

	if (head->go_next()) {
		return add_assignment(head->go_next());
	}

	return head;
}


//this function is the non recursive wrapper function for the
//display labs function below
void Assignment_manager::display_labs() {

	//if there are no labs to display then tell user
	if (table[0] == NULL) {
		cout << "There are no labs to display!" << endl;
	} else 
		//if there are labs in 0 index of table then call display
		display(table[0]);
}


//this function is the non recursive wrapper function for the
//display bookwork function below
void Assignment_manager::display_bookwork() {

	//if there are no bookworks to display then tell user
	if (table[1] == NULL) {
		cout << "There are no bookworks to display!" << endl;
	} else 
		//if there are labs in the first index of table then call display
        	display(table[1]);
}


//this function is the non recursive wrapper function for the
//display take home exams function below
void Assignment_manager::display_take_home_exam() {

	//if there are no exams to display then tell user
	if (table[2] == NULL) {
		cout << "There are no exams to display!" << endl;
	} else
		//if there are labs in the 2nd index of table then call display
        	display(table[2]);
}


//displays the data for an assignment lab recursively, gets this data from
//the display function for Assignment class called display()
void Assignment_manager::display(Node* head) {

	//if the head has a next to next	
	if(head->go_next()) {
		display(head->go_next());
	}
	
	head->display();	
}




		
	
