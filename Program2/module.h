/*

File: activity.h

This file includes the prototypes for the functions inside of classes. The base class "activity"
is the base class to its three derived classes coffee_shop, CATwork, and study. The classes node and
activity manager are seperate from the hierarchy. The node class contains a double linked list of arrays
and the functionality necessary to add, remove and search for an activity. The activity manager class
carries out these operations. Base class activity contains not only several functions used by all its
derived classes, but also virtual functions declared inside the derived classes for dynamic binding.
*/

#include <iostream>
#include <cstring>

#ifndef ACTIVITY_H
#define ACTIVITY_H

using namespace std;

//for max size of array
const int MAX_ARRAY = 2000;

//for max size of char*'s such as title
const int MAX_CHAR = 1000;

//Activity base class
class activity {

	public:

		//Default constructor
		activity();

		//Virtual desctructor
		virtual ~activity();
		
		//copy constructor for dynamic memory
		activity(const activity& to_copy);
	
		//Not dynamically bound because these functions are managed
		//by the base class:
	
		//Title or name
		void change_activity_title(const char* activity_title);

		//Priority level
		void change_priority();
		
		//compare title functions used in the node classes add activity helper functions
		//to compare a passed in title to one already exsting
		int compare_title(activity* to_compare);
		int compare_title(const char* to_compare);

		//compare priority used by node classes add activity class to determine the
		//correct spot to add an activity
		int compare_priority(activity* a_activity_to_compare);

		//display priority
		void display_priority();

		//display duration
		void display_duration();

		//display dependence
		void display_dependence();

		//change the length of time an activity takes
		void change_duration();

		//If activity is independent or not
		bool is_independent();

		//virtual because derived classes will have display, change_desc,
		//change_time_date and change_reservation as well
		virtual void display();
		virtual void change_desc(); 
		virtual void change_time_date_happening();
		virtual void change_reservation_location();

	protected:

		//variables for the change time an activity takes
		int duration_hour;
		int duration_min;

	
		//variables for changing the date/ time an activity takes place
                int scheduled_day;
                int scheduled_month;
		int scheduled_hour;
		int scheduled_min;

		
		//to change the name of activity
		char* activity_title;

		//change priority of activity
		int priority;

		//check if dependent or not
		bool dependence;


};

//Class coffee_shop is derived from activity class
//and "is a" activity plus more
class coffee_shop: public activity 
{
	public:
		//constructor
		coffee_shop();
		//destructor
		~coffee_shop();
		
		//coffee_shop constructor
		coffee_shop(const coffee_shop& to_copy);
		
		//dynamically bound functions:
			
		//Input info about coffee shop
		void change_desc();

		//display description, time/ date to go
                //, reservation location (address), and the current deals,
                //(and from BASE class, the title, priority, length of time
                //it takes, and if the activity is independent or not)
		virtual void display();

		//function UNIQUE to this class for RTTI:
		//function to change any promotions or deals going on at the shop
		void change_deals();

		//set a date and a time to go to the shop
		void change_time_date_happening();

		//reserve a spot at the shop by specifying a physical address
		void change_reservation_location();


	private:
	
		//for change_reservation_location to specify address
		char* address;

		//for changing the description of a coffee shop
		char* order;

		//for changing the deals and saving going on for the shop
		char* deals;

};

//class study that is derived from activity. Study "is a" activity plus more
class study: public activity
{

	public:

		//study class constructor
		study();

		//study copy constructor
		study(const study& to_copy);

		//study destructor
		~study();		
	
		//dynamically bound functions:

                //Input info about studying
                void change_desc();

		//display description, time/ date to go
                //, reservation location (building), and the room number to study,
                //(and from BASE class, the title, priority, length of time
                //it takes, and if the activity is independent or not)
                void display();

		//function UNIQUE to this class for RTTI:
                //function to change the room number of a study room at the uni
                void change_room_number();

		//reserve a spot at the university library 
                void change_reservation_location();

	        //set a date and a time to go to the library
                void change_time_date_happening();

	private:	

		//for changing the location to study by specifying building
		char* building;

		 //for changing the description of study session
                char* topic;

		//data member room_number for the room one wants to study in
		//at the uni
		int room_number;

};

//class for going to work
class CATwork: public activity 
{

	public:
		
		//work default constructor
		CATwork();

		//work copy constructor
		CATwork(const CATwork& to_copy);

		//work desctructor
		~CATwork();

       	        //dynamically bound functions:

                //Input info about working
                void change_desc();

                //display description, time/ date to go
		//, reservation location (room title), and if you have called out, 
		//(and from BASE class, the title, priority, length of time
		//it takes, and if the activity is independent or not)
                void display();

                //function UNIQUE to this class for RTTI:
		//call out of work 
                void call_out();

		//reserve a room to have a meeting in
                void change_reservation_location();

                //set a date and a time to go to the library
                void change_time_date_happening();


	private:

		//check if you have called out of work or not
		bool called_out;
	
		//for changing the location of the meeting
                char* room_title;

                //for changing the description of your job
                char* tasks;
		
}; 

//Node class holds data for activities
class node
{

	public: 
		//node constructor
		node();
		//node destructor
		~node();
		//node copy constructor
		node(const node* a_node);
		//to return the next pointer
		node*& go_next();
		//to return the previous pointer
		node*& go_prev();
		//to connect up next nodes
		void connect_next(node* connection);
		//to connect up previous nodes
		void connect_prev(node* connection);
		//to copy an activity
		void copy_activity(activity** source_list, int source_size, int i);
		//to delete the list, called in the destructor
		void delete_list(int i);
                //add an activity to the list
                void add_activity(activity*& a_activity);

		//two helper functions to help determine where to add an activity
		int add_activity_helper(activity*& a_activity, int i);
		int add_activity_helper(const char* activity_title, int i);

		//to compare priority to determine where to add
		int compare_priority(activity* a_activity);
                //removal of an activity
                bool remove_activity(const char* activity_title);

		//to set all the indices of the list to null
		void null_list_helper_for_constructor(int i);
                //display
                void display();
		void display(int i);
                //retrieval of an activity to aid in editing it later in main using the functions
		//declared in the three derived classes
                bool find_activity(const char* activity_title, activity*& a_activity);

		//to shift the index left to aid in adding an activity
		void shift_i(int i, int j);
		//to shift the index right to aid in removing an activity
		void shift_opposite_way(int i);

	protected:

		//to keep track of the size of the list	
		int list_size;

		//declaring next and previous pointers:
		//to be used in next = connection
		node* next;
		//to be used in previous = connection
		node* previous;

		//designating activity as a table
		activity** list;

};


//Activity_manager is off by itself and has a "has a" relationships Node	
//Manages the activities available
class activity_manager
{
	public:
	
		//manager constructor
		activity_manager();
		//manager destructor
		~activity_manager();
	
		//copy constructor	
		activity_manager(const activity_manager& to_copy);

		//copy the nodes for manager
		void copy_nodes(node* source, node*& dest);
		//add an activity 
		void add_activity(activity*& a_activity);
		//remove an activity
		void remove_activity(const char* activity_title);
		//delete the list recursively, to be called in destructor
		void delete_list(node*& head);
		//display the activities and all the activities data
		void display();
		//display what is in head, or the highest priority activity
		void display_highest();
		//retrieval of an activity 
		activity* find_activity(const char* activity_title);

	private:
		//create a head and a tail for the list
		node* head;
		node* tail;
		//private recursive functions used by above public functions
		activity* find_activity(node* head, const char* activity_title);
		//recursive functions for displaying, removing and adding
		//an activity
		void display(node* head);
		void remove_activity(node* head, const char* activity_title);
		void add_activity(node*& head, activity*& a_activity);
};



#endif























