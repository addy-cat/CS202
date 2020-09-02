/*
Author name: Adriana Swantz
Date: 5/14/2020
Class Number: CS202
Assignment 3

File: main.cpp

This program allows the user to manage three different types of materials/ 
activities relating to a remote experience. A user can manage their meetings,
their websites they visit, and the videos they watch. These materials are implied
to belong to one of three different types: recreation, work, or school. Supported
is add, remove, edit and find functionality for each type of material. The char* 
data is managed by a string class, so char*'s are avoided. Dynamic binding for the
description function in all three derived classes is used as well. The data structure
is a BST whos nodes are objects. Data is added to, removed, and found by searching
for the name of a meterial. The base class is remote_info, which has four derived
classes node, websites, videos, and meetings. The string class creates and manages
a char* str, and the BST manager class contains functions that allow the user to
manpulate the data in the BST. 
*/


#include "remote_info.h"
#include <iostream>

void add_remote_info_option(manager_BST& a_manager);
void edit_remote_info_option(remote_info*& a_info);

//main needs these args for the file io
int main(int argc, char** argv) {

	//make an object of the manager_BST class to use later on
	manager_BST a_manager;


	//if the use doesnt enter a file to open	
	if (argc != 2) {
		//then we need to tell them how to
		cout << "Usage: " << argv[0] << " <datafile>" << endl;
		return 0;
	}

	//this chare is the file name
	char* infile = argv[1];
	ifstream in(infile);
		while (in && !in.eof()) {
			a_manager.read(in);
		}

	
	//option for selecting an operation from the meno below
	int option = 0; 

	//make a temp string for when it comes to entering a string to remove
	//or search for
	my_string temp;

	//while the user doesnt choose case 5, display the menu
	//if they choose 5, then quit
	while (option != 5) {
	cout << endl;
	
	cout << "Select a remote material: " << endl;
	cout << "1) Display all remote information" << endl;
	cout << "2) Add a remote information" << endl;
	cout << "3) Remove a remote information" << endl;
	cout << "4) Edit a remote information" << endl;
	cout << "5) Quit" << endl;
	cout << endl;

	//take in the users choice	
	cin >> option;

	//check for user input error 
	while(cin.fail()) {

                cin.clear();
                cin.ignore(100, '\n');
                cout << "Please enter a valid option 1-5. " << endl;
                cin >> option;
        }

        cin.clear();
        cin.ignore(100, '\n');

	//switch statement and cases for the menu
	switch (option) {
	
		case 1:
			//display all information can easily be done
			//because << is overloaded
			cout << a_manager;
			break;
		case 2:
			//call the function that displays a menu of
			//possible things to add
			add_remote_info_option(a_manager);
			break;
		case 3:
			//prompt the user for something to remove from the BST
			//by asking for a title associated with an object
			cout << "Enter the title of the material you would like removed: " << endl;
			
			cin >> temp;
			cin.ignore(MAX_CHAR, '\n');

			//call the remove function on whatever they enter
			a_manager.remove_info(temp);
			break;	
		case 4: {
			remote_info* to_edit = NULL;
		
			//take in a name to search for	
			cout << "Enter a title to edit: " << endl;	
			cin >> temp;
			cin.ignore(MAX_CHAR, '\n');
			
			//send in the temp name the user just entered 	
			//into the retrieve function to search
			to_edit = a_manager.retrieve_info(temp);
	
			if (to_edit) {
				//if what they have entered is a valid
				//data to find, then they may edit it by
				//calling the edit function that offers a new
				//menu to choose what to edit:

				edit_remote_info_option(to_edit);
			} else
			//in the case that there is no name matching 
			//what the user has entered to locate and therefore edit
			cout << "There is no material to edit by that title." << endl;
		}
			break;
		case 5:
			//the while loop ends and the program quits in this case
			cout << "Quitting... " << endl;
			break;
		default:
			//default prompts for a valid option
			cout << "Enter an option 1-5... " << endl;
	}
	
   }

	ofstream out;
	out.open(argv[1]);
	//write whatever we did to the file
	a_manager.write(out);
	//close the file because we are done
	out.close();
	
	return 0;
}		

//function called when the user opts to add a new object to the BST
void add_remote_info_option(manager_BST& a_manager) {
	//base class pointer for dynamic binding
	node* new_info = NULL;	

	//option for the menu below
	int option = 0;

	cout << "Enter a remote material type to add: " << endl;
	cout << "1) Website" << endl;
	cout << "2) Video" << endl;
	cout << "3) Meetings" << endl;
	cout << endl;

	//take in the option the user chose	
	cin >> option;

	//check for user input error	
	while(cin.fail()) {
                cin.clear();
                cin.ignore(MAX_CHAR, '\n');
                cout << "Please enter a valid option: ";
                cin >> option;
        }

        cin.clear();
        cin.ignore(MAX_CHAR, '\n');

	//switch statement and cases depending on which type of 	
	//remote material the user would like to add
	switch (option) {

		//to add a new website, we need to make an object of the website class
		//using the base class pointer 	
		case 1:
			new_info = new websites;
			break;
		//to make a new video, we need to make an object of the videos class
		//using the base class pointer
		case 2:
			new_info = new videos;
			break;
		//to make a new meetings, we need to make an object of the meetings class
		//using the base class pointer
		case 3: 
			new_info = new meetings;
			break;
		default:
			cout << "Enter an option 1-3... " << endl;
	
	}

	//these things run regardless of which case the user selects
	//because they are not virtual but are instead just the base class functions
	//all types of a remote info have these
	new_info->change_name();	
	new_info->change_subject();
	new_info->change_priority();
	new_info->change_description();

	//call the add function on the new info using our operator overloaded +=
	a_manager += new_info;

}

//when the user opts to edit a material after having found it
//void edit_remote_info_option(remote_info*& a_info, manager_BST& a_manager) {
void edit_remote_info_option(remote_info*& a_info) {



	//option for the regular menu below
	int option = 0;
	//option for the RTTI menu
	int RTTI_option = 0;

	my_string temp;


	cout << "Select an option: " << endl;
	cout << "1) Change a description " << endl;
	cout << "2) Change a subject " << endl;
	cout << "3) Change a title/ name " << endl;
	cout << "4) Change a priority " << endl;
	cout << "5) Material specific actions" << endl;
	cout << endl;

	//take in an int option
	cin >> option;

	//check for user input error
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
			//change_description is virtual, so we use dynamic binding to access it
			//via the base class pointer a_info, so the right class function is ran.
			//Same goes for change subject, name and priority:
			a_info->change_description();
			break;
		case 2:
			a_info->change_subject();
			break;
		case 3:
			a_info->change_name();
			break;
		case 4:
			a_info->change_priority();
			break;
		case 5: 
			//Menu for RTTI function:
			cout << "Select a unique material option: " << endl;
			cout << "1) Change the duration of a video " << endl;
			cout << "2) Bookmark a website URL " << endl;
			//cout << "3) Add two videos together " << endl;
			cout << endl;

			//take in the option for the RTTI menu	
			cin >> RTTI_option;

			//check for user input error	
			while(cin.fail()) {
                                cin.clear();
                                cin.ignore(100, '\n');
                                cout << "Please enter valid option.";
                                cin >> RTTI_option;
                        }
				
			cin.clear();
			cin.ignore(100, '\n');
			
			switch (RTTI_option) {
				case 1: {
					//make a derived class pointer
					videos* temp = NULL;
		
					//we need to do downcasting on that derived classes pointer to access the function	
					//by changing its type into a base class pointer a_info, same goes for the websites
					//derived pointer below:
					temp = dynamic_cast < videos* > (a_info);

					//if the derived class pointer isnt NULL and exists
					if (temp) {
						//base class pointer to a function
						temp->change_duration();
					} else 
						cout << "You cant do this yet because you haven't added any videos." << endl;
					} 

					break;
				case 2: {
					//derived class pointer
					websites* temp = NULL;
				
					//derived class pointer for downcasting	
					temp = dynamic_cast < websites* > (a_info);
				
					//checking if there is a websites that has been added	
					if (temp) {
						 temp->bookmark();
					} else
						cout << "You cant do this yet because you haven't added any websites." << endl;
					}
					break;

				//this case 3 was meant for using my add operator in my videos class
				//however I could not get it to work. so i commented it out for now.
				//thinking back, it doesnt really make sense to add two videos together
				//so maybe it doesnt matter that this case doesnt work.
				/*
				case 3:
					{
					 remote_info* to_add = NULL;
					remote_info* to_add2 = NULL;

					cout << "What two videos would you like to add together?" << endl;
					  cout << "Enter a video title: " << endl;
       			                 cin >> temp;
                       			 cin.ignore(MAX_CHAR, '\n');

					to_add = a_manager.retrieve_info(temp);
					cout << "Enter another video title: " << endl;
					cin >> temp;
					cin.ignore(MAX_CHAR, '\n');
	
					to_add2 = a_manager.retrieve_info(temp);

					node* new_node = new videos(*to_add + *to_add2);
					a_manager.add_info(new_node);

					cout << "Videos added." << endl;
				}
				*/
					
				default:
					cout << "Select an option 1-2..." << endl;
			}
			break;
		default:
			cout << "Pick a valid option 1-5..." << endl;

	}

			
		
}
		

























































