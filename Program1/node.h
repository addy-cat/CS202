#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <cstring>
#include "module.h"
#include "TimeDate.h"

//File: node.h

/*
This file is the node.h file that contains the Assignment class, the node class,
and the Assignment_manager class. The Assignment class is one of the three derived
classes derived from the Module class. The reason it is in here instead of the Module.
h file is because Assignment works with the node and assignment_manager classes for the
data structure. Assignment "is a" Module plus more, while Node "is an" Assignment plus
more because Node is derived from Assignment. Assignment_manager class is a seperate
class that has a "has a" relationship with the Node class. The Assignment_manager class
is needed because it manages the array of head pointers for the assignments in the
assignment class. This class works with the node class to build the data structure and
manages the assignment class. The node class includes the private next pointer in order
to work with the Assignment_manager class to create and manage the data structure.
*/

//set the size of the table to three (for labs, bookwork, and exams)
const int TABLE_SIZE = 3;

//Assignment "is a" module and node is derived from it
//The Assignment class holds the data for the LLL
class Assignment: public Module {
        public:
                //constructor
		Assignment();

		//copy constructor
                Assignment(const Assignment& to_copy);

		//desctructor
		~Assignment();

		//these functions are here because they don't need a LLL to run
		//because they dont deal with a single assignment
		//and the Assignment class doesnt know theres a LLL:

		//display descriptiom, title, grade and due date of an assignment
		void display();

		//change the grade and description of an assignment
		void change_grade_desc();

		//using TimeDate class to change the due date of an assignment
		//using the duedate object below
		void change_time_date();

		
	protected:
		//char array for description
		char* description;
		//int value for an assignment grade
		int grade;

		//object of TimeDate class
		TimeDate duedate;

};

//A node "is a" Assignment plus the pointers to manage the next pointer for the LLL
class Node: public Assignment
{
	public: 
		//constructor
		Node();

		//node desctructor
		~Node();
		
		//Node copy constructor because this class has pointers
		//A node is an assignment
		Node(const Assignment& to_copy);
	
		//node function returns an object of the node class	
		Node *& go_next();

		//connect the next pointer
		void connect_next(Node* connection);	
	

	protected:
		//next pointer for the LLL's
		Node* next;
};

//This class manages the assignments with a array of LLL
class Assignment_manager
{
	
	public:
		//constructor
		Assignment_manager();
		//desctructor
		~Assignment_manager();
		//copy constructor
		Assignment_manager(const Assignment_manager& source);
	
		//these functions are here and not in Assignment class because
		//they use the LLL to run:

		//find an assignment by comparing user entered title and actual title in LLL
		Assignment& find_assignment(const char* compare);
	
		//add a lab assignment to the list using its table index of 0	
		bool add_lab_assign(const Assignment& a_assignment);

		//add a bookwork assignment to the list using table index 1
		bool add_bookwork_assign(const Assignment& a_assignment);

		//add an exam assignment to the list using index 2
		bool add_take_home_exam(const Assignment& a_assignment);

		//display the various aspects of a book assignment
		//by calling the display function
		void display_bookwork();

		//display the various aspects of a lab using display function
		void display_labs();

		//display various aspects of an exam using display function
		void display_take_home_exam();

		//these functions used in main:

		//change the lab data based on searched title
		bool change_lab(char* seached_title);

		//change the bookwork data based on a searched title
		bool change_bookwork(char* searched_title);

		//change the exam data based on a searched title
		bool change_exam(char* searched_title);


	protected:

		//create an array of linked lists
		Node** table; 

		//add assignment and passing in head
		Node*& add_assignment(Node*& head);

		//delete function called by destructor to clear memory
		void delete_all(Node*& head);

		//copy the new head to old head pointer
		void copy(Node*& newhead, Node* oldhead);

		//called by the public display functions for assignment
		//types to display various aspects of an assignment
		void display(Node* head);

		//search for a title of an assignment to see if it
		//exists in the list. this assignment is passed to the
		//above public change functions.
		Node*& search_title(Node*& head, char* searched_title);
};


#endif
