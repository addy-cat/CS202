/*
Author name: Adriana Swantz
Date: 5/6/2020
Class number: CS202
Assignment 2

File: source.cpp

This program is a to-do list-esque system, where there are three activities included. These activities 
each belong to their own derived class from the base class Activity. This program uses aspects of
dynamic binding so certain functions are matched with their correct definitions
at run time. This is achieved using virtual functions. In this file, the base class
pointer points to the derived class object in order to properly call functions. Derived classes
include coffee shop, study, and working. This program is specific to me regarding these classes:
I personally go to coffee shops often to work on my homework and to hang out, I often go to the PSU
and PCC campus to study (the study class implies you are at a physical location), and I work at the CAT at
PSU. The functions for these classes are specific to these personal to-do list plans of mine.
The program has a very simple hierarchy, where the base class has three derived classes, and a node
class and a activity manager class that are seperate. This file more specifically uses several menus to allow
the user to interact with every aspect of the program. RTTI is used for functions unique to a class (3).
*/

#include "module.h"
#include <iostream>

//Function prototypes for the add and edit menu fucntions below main:
void add_activities_option(activity_manager& a_manager);
void edit_activities_option(activity*& a_activity);

//main function holding the most general menu for the options
int main() {

	//object of the activity manager class used to run its functions
	activity_manager a_manager;

	//for selecting an option from the switch statement below
	int option = 0;

	//for functions that need to take in a title from the user
	char* activity_title = new char[MAX_CHAR];

	//while the option isn't 5, the menu appears with
	//its options. If you select 5, main() stops
	//and program exits:
	while(option != 6) {
	cout << endl;

	//generic menu edit delete add display
	cout << " Select an activity " << endl;
	cout << "1) Display activities with high priority " << endl;
	cout << "2) Display all activities " << endl;
	cout << "3) Add an activity " << endl;
	cout << "4) Remove an activity " << endl;
	//use the find activity function to find an activity to mess with:
	cout << "5) Edit an activity " << endl;
	cout << "6) Quit " << endl;
	cout << endl;

	cin >> option;

	while(cin.fail()) {

		cin.clear();
		cin.ignore(100, '\n');
		cout << "Please enter a valid option 1-5. " << endl;
		cin >> option;
	}

	cin.clear();
	cin.ignore(100, '\n');
	
	switch (option) {
		
		case 1: 
			//if you select the option to display activities with
			//highest priority:
			a_manager.display_highest();
			break;
		case 2:

			//basic display function that disregards priority and displays all
			//activities and their data
			a_manager.display();
			break;
		case 3:

			 //if you select to add an activity then the function
                        //that holds the menu for this is called so you
                        //can select an activity to add it. (in order
                        //to avoid a nested switch statement or tricky if
                        //statements):
			add_activities_option(a_manager);

			break;
		case 4: 

			//for removing an activity. The remove function expects a title
			//so the user must enter one. It is then compared to an existing
			//title and removed if existing.
			cout << "Enter the title you would like removed: " << endl;
                        cin.get(activity_title, MAX_CHAR);
                        cin.clear();
                        cin.ignore(MAX_CHAR, '\n');

			//if you select to remove an activity, the user will
                        //enter a title and the remove activity function
                        //will use it to delete that title and its
                        //associated attributes:
                        a_manager.remove_activity(activity_title);
			break;
		case 5: {

			 //to find an activity we must make an activity pointer:
                        activity* temp = NULL;

                        //prompt for a title to find that title using the
                        //find_activity function which will find if that activity
			//exists:
                        cout << "Enter an activity title to edit: " << endl;

                        cin.get(activity_title, MAX_CHAR);
                        cin.clear();
                        cin.ignore(MAX_CHAR, '\n');

                        temp = a_manager.find_activity(activity_title);

                        //call the function that holds the options to
                        //change the attributes of an activity if it finds a match
			if (temp) {
                        	edit_activities_option(temp);
			} else 
			cout << "No activity to edit with that title." << endl;
		}
			break;
		case 6:
			  //quit the program
                        cout << "Quitting... " << endl;
                        break;
	
		default:
			cout << "Enter an option 1-4... " << endl;
	}
		
	//delete the dynamic memory associated with the activity_title char*	
	}

	//if the user entered a title then delete its memory
	if (activity_title) {
		delete [] activity_title;
	}

}

//function runs if the user selects to add an activity
void add_activities_option(activity_manager& a_manager) {

	//set and make the activity pointer
	activity* new_activity = NULL;

	//title for functions that expect a title
	char* activity_title = new char[MAX_CHAR];	

	//option for the menu selection
	int option = 0;

	cout << "Enter an activity type to add: " << endl;
	cout << "1) Coffee shop " << endl;
	cout << "2) Study " << endl;
	cout << "3) Work " << endl;
	cout << endl;

	cin >> option;

	while(cin.fail()) {
		cin.clear();
		cin.ignore(MAX_CHAR, '\n');
		cout << "Please enter a valid option: ";
		cin >> option;
	}
	
	cin.clear();
	cin.ignore(MAX_CHAR, '\n');

	switch (option) {

		case 1:
			//adds a coffee shop
			new_activity = new coffee_shop;
			break;

		case 2:
			//adds a study
			new_activity = new study;
			break;

		case 3:
			//adds a work
			new_activity = new CATwork;
			break;

		default:
			cout << "Enter an option 1-3... " << endl;


	}

	cout << "Enter a title for this new activity: " << endl;
        cin.get(activity_title, MAX_CHAR);
        cin.clear();
        cin.ignore(MAX_CHAR, '\n');

        new_activity->change_activity_title(activity_title);

//        cout << "Enter a priority for this new activity: " << endl;
        new_activity->change_priority();
	a_manager.add_activity(new_activity);
	delete [] activity_title;
}


//edit activities function that displays a menu for if the user wants to edit an activity.
//functions in this menu are the functions defined in the module.cpp for the derived classes:
void edit_activities_option(activity*& a_activity) {

	int option = 0;
	int RTTI_option = 0;
	
	cout << "Select an option: " << endl;
        cout << "1) Display all information: " << endl;
        cout << "2) Change description: " << endl;
        cout << "3) Change time/ date scheduled: " << endl;
        cout << "4) Change reservation spot: " << endl;
        cout << "5) Change duration: " << endl;
        cout << "6) Change if dependent or not: " << endl;
	cout << "7) Activity specific actions: " << endl;
        cout << endl;
	
	cin >> option;

	while(cin.fail()) {
                cin.clear();
                cin.ignore(MAX_CHAR, '\n');
                cout << "Please enter a valid option... ";
                cin >> option;
        }

        	cin.clear();
        	cin.ignore(MAX_CHAR, '\n');

	switch (option) {

		case 1: 
			//display the info for a activity
			a_activity->display();
			break;

		case 2:
			//change the description for an activity
			a_activity->change_desc();
			break;

		case 3:
			//change the time and date an activity is scheduled	
			a_activity->change_time_date_happening();
			break;

		case 4:
			//change the location in which an activity takes place
			a_activity->change_reservation_location();
			break;

		case 5:
			//change how long an activity takes
			a_activity->change_duration();
			break;

		case 6:
			//check whether or not the activity is independent
			a_activity->is_independent();
			break;

		case 7:	
			//Menu for if the user selects unique function for a class, in this
			//case the RTTI functions will be options
			cout << "Select a unique activity option: " << endl;
			cout << "1) Change deals/ coupons for a coffee shop: " << endl;
			cout << "2) Change room number reserved for studying: " << endl;
			cout << "3) Call out of work: " << endl;
			cout << endl;

			cin >> RTTI_option;
	
		        while(cin.fail()) {
                       		cin.clear();
                        	cin.ignore(100, '\n');
                        	cout << "Please enter valid option.";
                        	cin >> RTTI_option;
                        }

	                cin.clear();
       		        cin.ignore(100, '\n');

			//for RTTI (unique specific functions one per derived class):
			switch (RTTI_option) {
		
				//in this case the coffee shop classes change deals function will be called	
				case 1: {
					coffee_shop* temp = NULL;
					//RTTI:
					temp = dynamic_cast < coffee_shop* > (a_activity);

					//this checks if the activity belongs to coffee shop and if it does it runs the function
					if (temp) {
						temp->change_deals();
					} else
						//or else it doesnt belong to this class
						cout << "No coffee shop added." << endl;
				}
					break;
				case 2: {
					study* temp = NULL;

					//RTTI:
					temp = dynamic_cast < study* > (a_activity);
					//checks if the entered activity belongs to study class or not, if it does it runs the study function
					if (temp) {
						temp->change_room_number();
					} else 
						//or else this activity does not belong to the study class
						cout << "No study added." << endl;
				}
					break;
				case 3: {
					CATwork* temp = NULL;
					//RTTI:
					temp = dynamic_cast < CATwork* > (a_activity);
					//checks if what user entered activity belongs to the work class or not, if it does then run the work function
					if (temp) {
						temp->call_out();
					} else 
						//if what they entered does not belong in the work class 
						cout << "No work added." << endl;
				}
					break;
				default:
					cout << "Select 1-3...." << endl;
			}
	}
}
					

			
