/*
Author name: Adriana Swantz
Date: 4/16/2020
Class number: CS202
Assignment 1

File: main.cpp

This program includes seven classes, in which 5 of these classes have OOP relationships with eachother. Class "Module" is the base class at the very top of the hierarchy, containing similar functions that its three derived classes will use: ability to change titles of videos/ events/ assignments, and ability to display the titles of these data members. Derived from Module are three child classes, LectureVideos, Assignments, and ScheduledEvents. These three classes each have their own functions that are specific for their own class, and each of these classes have their own job and purpose: they bring assignment, event, and video functionality to the program. Derived from the assignment class is a Node class that includes the pointers to manage the next pointer for a array of linked lists. There are seperate classes assignment manager and TimeDate, that manage the assignments in the LLL and manage the time/ date functionalities respectively. The program as a whole resembles something like Canvas or D2L.
*/

#include "module.h"
#include "TimeDate.h"
#include <cstring>
#include "node.h"
#include <iostream>
using namespace std;

//function prototypes for menu functions below main:
//functions include the menu selection functionalities for each
//derived class 
//void assignment_option(Assignment &a_assignment);
void assignment_manager_option(Assignment_manager &a_assignment_man);
void scheduled_events_option(ScheduledEvents &a_event);
void lecture_videos_option(LectureVideo &a_video);

//main is a basic, general menu to interact
//with the modules. These modules will have their own
//switch statement menus in their own functions in this file
//that will be called depending on what the user selects here.

int main() {

	//class objects for instances of videos 
	//used to stand for a specific video that the user can choose to
	//interact with
	LectureVideo a_video;
	LectureVideo a_video2;
	LectureVideo a_video3;

	//class objects for instances of events
        //used to stand for a specific event that the user can choose to
        //interact with
	ScheduledEvents a_event;
	ScheduledEvents a_event2;
	ScheduledEvents a_event3;

	//assignment manager object
	Assignment_manager a_assignment_man;

	//int choices for switch statement for selecting which module 
	//the user would like to interact with: 
	int option = 0; //option for general module selection switch statement
	int video_num = 0; //option if user selects video
	int assignment_num = 0; //option for if user selects assignment
	int event_num = 0; //option for if user selects event

	//general selection menu for selecting a Module from the three derived classes
	while(option != 4) {	
	cout << endl;
	cout << "Select a Module: " << endl;
	cout << endl;
	cout << "1. Assignments " << endl;
	cout << "2. Lecture Videos " << endl;
	cout << "3. Scheduled Events " << endl;
	cout << "4. Quit " << endl;
	cout << endl;

	cin >> option;

	//for if user enters invalid option
	while(cin.fail()) {
                                cin.clear();
                                cin.ignore(100, '\n');
                                cout << "Please enter valid option.";
                                cin >> option;
                        }

                        cin.clear();
                        cin.ignore(100, '\n');
	
	switch (option) 
	{
		case 1:
			//if user selects assignment_manager Module, they will choose 	
			//an assignment they would like to interact with. The 
			//number and instances of assignments are hard coded in this
			//file and cannot be created during run time.
			cout << "Loading Assignments Module... " << endl;
			cout << endl;
			assignment_manager_option(a_assignment_man);
			
			break;
		case 2:

			//for if user selects lecture videos Module,	
			//select which instance of video they would like to alter/ interact with.
			cout << "Loading Lecture Videos Module... " << endl;
			cout << endl;
			cout << "Select a video: " << endl;
			cout << endl;
			cout << "1. Video 1\n";
			cout << "2. Video 2\n";
			cout << "3. Video 3\n";
			cin >> video_num;

			//if user enters invalid information
			while(cin.fail()) {
                                cin.clear();
                                cin.ignore(100, '\n');
                                cout << "Please enter valid option.";
                                cin >> video_num;
                        }

                        cin.clear();
                        cin.ignore(100, '\n');

			//the three instances of the LectureVideo class are options to be
			//interacted with. Depending on which one the user selects they will be 	
			//able to edit one instance of a video. 
			if (video_num == 1) {
				lecture_videos_option(a_video);
			} else if (video_num == 2) {
				lecture_videos_option(a_video2);
			} else if (video_num == 3) {
				lecture_videos_option(a_video3);
			}

			break;
		case 3:
			//for if user selects the ScheduledEvents module from main
			//menu, can select a specific instance of an event from 1-3
			cout << "Loading Scheduled Events Module... " << endl;
			cout << endl;
			cout << "Select an event: " << endl;
			cout << endl;
                        cout << "1. Event 1\n";
                        cout << "2. Event 2\n";
                        cout << "3. Event 3\n";
                        cin >> event_num;

			//for meaningless user input
			while(cin.fail()) {
                                cin.clear();
                                cin.ignore(100, '\n');
                                cout << "Please enter valid option.";
                                cin >> event_num;
                        }

                        cin.clear();
                        cin.ignore(100, '\n');
			
			//objects of the ScheduledEvent class will be addressed
			//so user can edit/ interact with a single instance of an event 1-3
                        if (event_num == 1) {
                                scheduled_events_option(a_event);
                        } else if (event_num == 2) {
                                scheduled_events_option(a_event2);
                        } else if (event_num == 3) {
                                scheduled_events_option(a_event3);
                        }

			break;
		case 4:
			cout << "Quitting.. " << endl;
			break; 
				
		default:
			cout << "Enter 1-3... " << endl;
	}
   	}
}


//This function is called if the user selects the lecture video module above.
//Here the user can select one of 7 utilities the LectureVideo class includes,
//including the display title and change title functionalities offered from its base class, Module.
void lecture_videos_option(LectureVideo& a_video) {

	//char array used for taking in a new name of a title of a video from the user
	char* title = new char[200];

	//option for selecting an option from the menu below
	int option = 0;

	//lecture video selection menu	
	cout << "Select lecture video option: " << endl;
	cout << endl;
	cout << "1. Display all video information " << endl;
	cout << "2. Change the duration of a video " << endl;
	cout << "3. Change the resolution of a video " << endl;
	cout << "4. Toggle subtitles for a video " << endl;
	cout << "5. Watch a video " << endl;
	cout << "6. Change the playback speed for a video " << endl;
	cout << "7. Change the title of a video " << endl;
	cout << endl;

	//for invalid user input
	cin >> option;
	while(cin.fail()) {
                          cin.clear();
                          cin.ignore(100, '\n');
                          cout << "Please enter valid option.";
                          cin >> option;
                        }

                        cin.clear();
                        cin.ignore(100, '\n');

	
	switch (option) 
	{
		case 1:
			//display various data that a video includes, such as title, resolution, duration, speed,
			//whether subtitles are on, and whether or not a video has been watched
			a_video.display();
			break;
		case 2:
			//edit the duration of a video
			a_video.change_duration();
			break;
		case 3:
			//edit the resolution of a video
			a_video.change_resolution();
			break;
		case 4:
			//toggle the subtitles of a video
			a_video.toggle_subtitles();
			break;
		case 5:
			//toggle if video has been watched or not
			a_video.watch_video();
			break;
		case 6:
			//edit the playback speed of a video
			a_video.change_speed();
			break;
		case 7:
			//change_title function from base class uses this,
			//take in a new title name from the user and pass it into the
			//change title function within base class Module, allowing 
			//the Video class access to it
			cout << "Enter title: " << endl;
	                cin.get(title, 200);
			cin.clear();
			cin.ignore(100, '\n');

			a_video.change_title(title);
			break;
		default:
			//default for invalid input
			cout << "Enter an option 1-7... " << endl;
	}			

	//delete memory associated with the title memory allocated previously
	delete [] title;
}

//If user selects the scheduled events option from original switch statement menu.
//Here, the user can select one of 6 functionalities offered by the ScheduledEvents class.
//Included is ability to edit the title of an event and display a title, where these
//two functions are available from this classes base class, Module.
void scheduled_events_option(ScheduledEvents& a_event) {

	//char array for entering a new title for an event	
	char* title = new char [200];

	//option for selecting off of menu below
	int option = 0;

	//Menu holding options for interacting with scheduled event instances	
	cout << "Select Event option: " << endl;
	cout << endl;
	cout << "1. Display all event information " << endl;
        cout << "2. Change the description of an event " << endl;
        cout << "3. Change the time/ date an event is scheduled " << endl;
        cout << "4. Change the priority of an event " << endl;
        cout << "5. Check is event has passed/ been completed  " << endl;
        cout << "6. Change the title of an event " << endl;
	cout << endl;

        cin >> option;
	
	//for invalid user input
	while(cin.fail()) {
                                cin.clear();
                                cin.ignore(100, '\n');
                                cout << "Please enter valid option.";
                                cin >> option;
                        }

                        cin.clear();
                        cin.ignore(100, '\n');


        switch (option)
        {
                case 1:
			//display various data associated with an event, such as description, 
			//time and date an event is scheduled for, priority of event, and whether or not
			//an event has passed. Title also displayed.
                        a_event.display();
                        break;
                case 2:
			//change the description of an event
                        a_event.change_description();
                        break;
                case 3:	
			//change the time and date of when an event goes live, or happens
                        a_event.change_time_date();
                        break;
                case 4:
			//change the priority/ importance of an event
                        a_event.change_priority();
                        break;
                case 5:
			//check whether an event has passed/ been completed
                        a_event.check_event();
                        break;
                case 6:
                        //change_title function from base class
                        cout << "Enter title: " << endl;
                        cin.get(title, 200);
                        cin.clear();
                        cin.ignore(100, '\n');

	
                        a_event.change_title(title);
                        break;
                default:
                        cout << "Enter an option 1-6... " << endl;
        }

	//delete memory associated with the title memory allocated previously
        delete [] title;
}

	
//If user selects the assignment option, functions available to edit/ interact with
//an instance of an assignment via assignment_manager. Functionality with changing title and displaying title
//come from base class, Module.
void assignment_manager_option(Assignment_manager& a_assignment_man) {

	//char array used to change the title of an assignment
        char* title = new char [200];
	//option to select which type of assignment user wants (lab/ book homework/ exam)
	int assignment_type = 0;
	//option to select a functionality from menu below:
	//option for lab functions
        int option_lab = 0;
	//option for bookwork functions
	int option_bookwork = 0;
	//option for exam functions
	int option_exam = 0;
	//for checking if the title has been changed successfully or not
	bool success = false;

	cout << "Select an Assignment type: " << endl;
	cout << "1. Lab" << endl;
	cout << "2. Book Homework" << endl;
	cout << "3. Take-home Exams" << endl;
	cout << endl;
	
	cin >> assignment_type;
	 //for error checking in input
        while(cin.fail()) {
                                cin.clear();
                                cin.ignore(100, '\n');
                                cout << "Please enter valid Assignment type (1-3).";
                                cin >> assignment_type;
                        }

                        cin.clear();
                        cin.ignore(100, '\n');

	if (assignment_type == 1) {

	//if user selects option one, the menu for lab appears	
        cout << "Select Laboratory option: " << endl;
	cout << endl;
        cout << "1. Add lab" << endl;
        cout << "2. Display all labs " << endl; 
        cout << "3. Change lab information " << endl;
	cout << endl;

        cin >> option_lab;
	//for error checking in input
	while(cin.fail()) {
                                cin.clear();
                                cin.ignore(100, '\n');
                                cout << "Please enter valid option.";
                                cin >> option_lab;
                        }

                        cin.clear();
                        cin.ignore(100, '\n');

	//switch statement for lab
        switch (option_lab)
        {
                case 1:
		{
			//New instance of Assignment to add to assignment manager
			Assignment new_assignment;
			//prompt user for title to add to the list
			cout << "Enter a lab title: " << endl;	
			cin.get(title, 200);
                        cin.clear();
                        cin.ignore(100, '\n');

			//this function comes from Module:
			new_assignment.change_title(title);
			//these functions are in Assignment_manager class:
			new_assignment.change_time_date();
			new_assignment.change_grade_desc();
			
			cout << "Lab added.. " << endl;
	
			//call add lab function on new_assignment	
			a_assignment_man.add_lab_assign(new_assignment);

		}
                        break;
                case 2:
			//call the display labs function from class Assignment_manager to display the labs
			a_assignment_man.display_labs();
                        break;
                case 3:
			//change the information for a lab
			cout << "Enter the title of the lab you wish to edit: " << endl;
			cin.get(title, MAX_CHAR);
			cin.ignore(MAX_CHAR, '\n');

			//bool success equal to the bool returned value of change_lab 
			success = a_assignment_man.change_lab(title);
			if (success) {
				cout << "Lab information changed! " << endl;
			}

                        break;
		//default error checking option
                default:
                        cout << "Enter an option 1-3... " << endl;
        }

   }

	//if user selects to interact with book homework
	if (assignment_type == 2) {

        cout << "Select Book Homework option: " << endl;
        cout << endl;
        cout << "1. Add Book Homework" << endl;
        cout << "2. Display all bookwork" << endl;
        cout << "3. Change bookwork information " << endl;
        cout << endl;

        cin >> option_bookwork;
        //for error checking in input
        while(cin.fail()) {
                                cin.clear();
                                cin.ignore(100, '\n');
                                cout << "Please enter valid option.";
                                cin >> option_bookwork;
                        }

                        cin.clear();
                        cin.ignore(100, '\n');

	//switch statement for book homework
        switch (option_bookwork)
        {
                case 1:
                {
                        //New instance of Assignment to add to assignment manager
                        Assignment new_assignment;
                        cout << "Enter a bookwork title: " << endl;
                        cin.get(title, 200);
                        cin.clear();
                        cin.ignore(100, '\n');

			//this function comes from Module class:
                        new_assignment.change_title(title);
			//these functions come from Assignment_manager class to
			//change the time/date an assignment is due and to change grade
                        new_assignment.change_time_date();
                        new_assignment.change_grade_desc();
			
                        cout << "Bookwork added.. " << endl;

			//call add book homework function on new_assignment
                        a_assignment_man.add_bookwork_assign(new_assignment);

                }
                        break;
                case 2:
			//display the book homework information from list
                        a_assignment_man.display_bookwork();
                        break;
                case 3:
			//search for a title of a book to see if it exists in the list to edit its books data:
                        cout << "Enter the title of the book homework you wish to edit: " << endl;
                        cin.get(title, MAX_CHAR);
                        cin.ignore(MAX_CHAR, '\n');

                        //bool success equal to the bool returned value of change_bookwork
                        success = a_assignment_man.change_bookwork(title);
                        if (success) {
                                cout << "Book homework information changed! " << endl;
			   }

                        break;
                //default error checking option
                default:
                        cout << "Enter an option 1-3... " << endl;
        }

   }

	//if user selects to interact with an exam
	 if (assignment_type == 3) {

        cout << "Select take-home exam option: " << endl;
        cout << endl;
        cout << "1. Add Take-home Exam" << endl;
        cout << "2. Display all Exams" << endl;
        cout << "3. Change take-home exam information " << endl;
        cout << endl;

        cin >> option_exam;
        //for error checking in input
        while(cin.fail()) {
                                cin.clear();
                                cin.ignore(100, '\n');
                                cout << "Please enter valid option.";
                                cin >> option_exam;
                        }

                        cin.clear();
                        cin.ignore(100, '\n');

	//switch statement for exam menu cases
        switch (option_exam)
        {
                case 1:
                {
                        //New instance of Assignment to add to assignment manager
                        Assignment new_assignment;
			//prompt user for a title for the exam
                        cout << "Enter an exam title: " << endl;
                        cin.get(title, 200);
                        cin.clear();
                        cin.ignore(100, '\n');

			//this function comes from Module class
                        new_assignment.change_title(title);
			//these functions come from Assignment_manager class
			//to add the time/ date and grade/ description to the list
                        new_assignment.change_time_date();
                        new_assignment.change_grade_desc();
		
			
                        cout << "Exam added.. " << endl;

			//call the add take home exam on new_assignment
                        a_assignment_man.add_take_home_exam(new_assignment);

                }
                        break;
                case 2:
			//display the take home exam information
                        a_assignment_man.display_take_home_exam();
                        break;
                case 3:
			//enter a title to compare to a preexisting title in the list
			//to see if it exists
                        cout << "Enter the title of the exam you wish to edit: " << endl;
                        cin.get(title, MAX_CHAR);
                        cin.ignore(MAX_CHAR, '\n');

                        //bool success equal to the bool returned value of change_exam
                        success = a_assignment_man.change_exam(title);
                        if (success) {
                                cout << "Exam information changed! " << endl;
                           }

                        break;
                //default error checking option
                default:
                        cout << "Enter an option 1-3... " << endl;
        }

   	//delete memory associated with the title memory allocated previously
        delete [] title;
	
   }
}




