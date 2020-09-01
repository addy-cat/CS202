#include <cstring>
#include "module.h"

//File: module.cpp

/*
This is the file that contains the bulk of most of the code for the derived classes of the Module base class. This file contains the functions
for class Module, and two of three of its derived classes: ScheduledEvents and LectureVideos. The reason only two of Module's child classes are in here along with
Module is because Module's third derived class, Assignment, works with an Assignment_manager class that managers an array of linked lists, so this class
is with classes that it relates to moreso. The types of functions that this file includes are non-data structure functions, that are very simple and manage 
instances of videos and scheduled events. This file also contains the copy constructors, default constructors, and destructors for Module, ScheduledEvents,
and LectureVideos. Base class Module contains functions display_title() and change_title() that all three of its derived classes use,
along with a compare_title() function that Assignment_manager uses for changing Assignment data.
*/

//Module class functions:

//Module class default constructor setting only protected data member a_title to NULL
Module::Module() {

	a_title = NULL;
}

//copy constructor for Module class that copies a title 
Module::Module(const Module& to_copy) {

	//make sure there is a title to copy so the pointer isn't NULL, to avoid 
	//dereferencing a NULL pointer
	if(to_copy.a_title) {
		a_title = new char[strlen(to_copy.a_title) + 1];
		strcpy(a_title, to_copy.a_title);
	} else
		a_title = NULL;
}

//Module destructor to deallocate char* a_title
Module::~Module() {

	//delete array []
	delete [] a_title;
	a_title = NULL;
}

//change title for three child classes
//will be called in main
void Module::change_title(const char* new_title) {

	//need to delete title if one is there already to avoid memory leak	
	if(a_title) {
		delete [] a_title;
	}

	//change old title to new title
	a_title = new char[strlen(new_title) + 1];
	strcpy(a_title, new_title);

}

//compare the title that already exists to the to_compare title
//(this function is used by class Assignment_manager in node.cpp to compare
//a title of an assignment entered by the user to the actual
//title of an assignment to see if the title exists in the ARR of LLL)
//This returns true if the titles match and false if not
bool Module::compare_title(const char* to_compare) {

	if(strcmp(to_compare, a_title) == 0) {
		return true;
	} else 
		return false;
	
}

//display title for three child classes
//this function will be called by the three child classes to display their titles
//void Module::display_title() {
void Module::display(){

	//check if there are titles for a module	
	if (a_title) {
	cout << a_title << endl;
	} else 
		cout << "There are no titles. " << endl;

}

//--------------------------------------------------------------------------------------

//LectureVideo class functions:

//default constructor for LectureVideo data members, setting all to default values
LectureVideo::LectureVideo() {

	sec = 0;
	min = 0;
	hour = 0;
	height = 0;
	width = 0;
	speed = 1.00;
	subtitles = false;
	is_viewed = false;
}

//display all lecture video information (title/length/resolution/speed/is viewed)
void LectureVideo::display() {

	//call this classes base class, module, display function that prints the title
	//because module holds the ability to do so for all derived classes
	cout << "Video Title: ";
	//need to specify this display function is from Module base class
	Module::display();
	cout << endl;

	//then display the duration of the video in hour:min:sec 
	
	cout << "Length of video: " << hour << ":" << min << ":" << hour << endl;

	//display the resolution of the video via int by int
	
	cout << "Video resolution: " << width << " x " << height << endl;

	//display the speed of the video
	
	cout << "Video playback speed: " << speed << endl;

	//display if video has been viewed
	
	if (is_viewed  == true) {
		cout << "Video has been viewed" << endl;
	} else 
		cout << "Video has not been viewed" << endl;

	//display if subtitles have been toggled on

	if (subtitles) {
		cout << "Subtitles are on. " << endl;
	}
	else 
		cout << "Subtitles are off. " << endl;

}

//change the duration of a video
void LectureVideo::change_duration() {

	//prompt user for a length of a video in hours, minutes, seconds
	cout << "Enter a duration: " << endl;
	cout << "Hours: ";
	cin >> hour;

	cout << "Minutes: ";
	cin >> min;

	cout << "Seconds: ";
	cin >> sec;

	//print what they have set
	cout << "Duration set to " << hour << ":" << min << ":" << sec << endl;

}


//edit the resolution of the video
void LectureVideo::change_resolution(){

	//the option int for the switch statement below
        int option = 0;

	//select a resolution:
	//I figured a switch statement would be best because this resolution format 
	//can be tricky for a user to enter because there are integers and an "x"
	//and it seemed more realistic this way
        cout << "Select a resolution from below: " << endl;
        cout << "1. 640x480" << endl;
        cout << "2. 960x720" << endl;
        cout << "3. 1024x768" << endl;
        cout << "4. 1280x960" << endl;
        cout << "5. 1600x1200" << endl;
        cout << "6. 2048x1536" << endl;

        cin >> option;

	//cases depending on option to set width and height
        switch(option) {
                case 1:
			width = 640;
			height = 480;
                        cout << "Resolution set to 640x480" << endl;
                        break;
                case 2:
			width = 960;
			height = 720;
			cout << "Resolution set to 960x720" << endl;
                        break;
                case 3:
                        width = 1024;
			height = 768;
                        cout << "Resolution set to 1024x768" << endl;
                        break;
                case 4:
			width = 1280;
			height = 960;
			cout << "Resolution set to 1280x960" << endl;
                        break;
                case 5:
			width = 1600;
			height = 1200;
			cout << "Resolution set to 1600x1200" << endl;
                        break;
                case 6:
			width = 2048;
			height = 1536;
			cout << "Resolution set to 2048x1536" << endl;
                        break;
        }

}


//this function toggles the video subtitles on or off based on boolean value
//in main() it will ask user if they want subtitles on or off
int LectureVideo::toggle_subtitles() {

	//subtitles is basically inversed when this function is called
	subtitles = !subtitles;

	//check if subtitles are toggled or not
	if (subtitles == false) {
		cout << "The subtitles are off" << endl;
	} else
		cout << "The subtitles are on" << endl;
}

//function will run after user requests to watch a video, will set isViewed to be true,
//otherwise it starts off false
int LectureVideo::watch_video() {

	cout << "Watching video... ... ... \n";
	cout << "Video has been watched" << endl;
	is_viewed = true;
}


//change the playback speed of a video
void LectureVideo::change_speed() {

	int option = 0;

	//select a speed
	//switch statement more realistic here rather than having user enter speed themselves
	cout << "Select a playback speed from below: " << endl;
	cout << "1. 0.50" << endl;
	cout << "2. 0.75" << endl;
	cout << "3. 1.00" << endl;
	cout << "4. 1.25" << endl;
	cout << "5. 1.50" << endl;
	cout << "6. 2.00" << endl;

	cin >> option;

	//cases depending on which speed was selected setting speed to option
	switch(option) {
		case 1:
			speed = 0.50;
			cout << "Playback speed set to 0.5" << endl;
			break;
		case 2:
			speed = 0.75;
			cout << "Playback speed set to 0.75" << endl;
			break;
		case 3:
			speed = 1.00;
			cout << "Playback speed set to 1.00" << endl;
			break;
		case 4:
			speed = 1.25;
			cout << "Playback speed set to 1.25" << endl;
			break;
		case 5:
			speed = 1.50;
			cout << "Playback speed set to 1.50" << endl;
			break;
		case 6:
			speed = 2.00;
			cout << "Playback speed set to 2.00" << endl;
			break;
	}
}
	


//------------------------------------------------------------------------------------

//Scheduled events classes:

//ScheduledEvents constructor
ScheduledEvents::ScheduledEvents() {

	//set char* description to NULL and priority int to zero
	description = NULL;
	priority = 0;

	//set the change_time and change_date data members arguments to zero
	//because they expect integers
	live.change_time(0, 0, 0);
	live.change_date(0, 0, 0);

}

//ScheduledEvents copy constructor 
//With initialization list from Module's copy constructor so this copy constructor can 
//also copy over the data members in Module class and not just this class
ScheduledEvents::ScheduledEvents(const ScheduledEvents& to_copy):Module(to_copy) {

	//check if there is a description already to copy, if
	//there is, copy it
	if(to_copy.description) {
                description = new char[strlen(to_copy.description) + 1];
                strcpy(description, to_copy.description);
        } else
	//if there is nothing to copy the description should have nothing
                description = NULL;

	//int priority copy
	priority = to_copy.priority;

	//live object copy
	live = to_copy.live;
}

//ScheduledEvents destructor for char* description
ScheduledEvents::~ScheduledEvents() {

        //delete array []
        delete [] description;
        description = NULL;

}

//call TimeDate class object to display the time and date the event is scheduled for
void ScheduledEvents::display() {

	//call module base class title function
	cout << "Event Title: ";

	//need to specify this display function is from the Module base class or else 
	//the program will barf
	Module::display();
        cout << endl;

	//call TimeDate classes object live here, to display the
	//time and date this event occurs
	cout << "Event happens at: ";
	live.display_timedate();
	cout << endl;

	//display int priority
	cout << "This events priority is " << priority << endl;
}


//change the description of an event
void ScheduledEvents::change_description() {

	cout << "Enter a description for event: ";
	//if there is a previous description, delete its character array
	if (description) {
		delete [] description;
	} 

	//now we can for sure set a new description using a new array
	description = new char[MAX_CHAR+1];
	cin.get(description, MAX_CHAR);
	
}

//change time and date of an event using the TimeDate object live
//This function is used to set the date and time and event happens, or goes "live"
void ScheduledEvents::change_time_date() {

	//local variables for the time and date
	int second = 0;
    	int minute = 0;	    
	int hour = 0;

	int day = 0;
	int month = 0;
	int year = 0;

	cout << "Enter the time/ date of the event: " << endl;
	cout << "Hour: ";
	cin >> hour;
	cout << "Minute: ";
	cin >> minute;
	cout << "Second: ";
	cin >> second;

	//pass the second, minute and hour user entires to the 
	//change_time function in TimeDate class using live object
	live.change_time(second, minute, hour);

	cout << "Year: ";
	cin >> year;
	cout << "Month: ";
	cin >> month;
	cout << "Day: ";
	cin >> day;

	//pass the day, month and year user entries to change_date function
	//in TimeDate class using live object
	live.change_date(day, month, year);

}

//change the priority of an event
void ScheduledEvents::change_priority() {

	int temp = 0;

	cout << "Set the priority of the event using an integer value from 1 to 10: ";
	cin >> temp;

	//if the priority a user enters is not in the bounds of the
	//rating system from 1 to 10, output an error.
	if (temp > 0 && temp < 11) {
		priority = temp;
	} else 
		cout << "Error, invalid entry";

}


//check if the time and date cooresponds to an event already existing to
//see if the event is passed or completed
bool ScheduledEvents::check_event() {

        //local variables for the time and date
        int minute = 0;
        int hour = 0;

        int day = 0;
        int month = 0;
        int year = 0;

	cout << "Check due date by entering these values: " << endl;
        cout << "Enter the minute: ";
        cin >> minute;
	cout << "Enter current hour: ";
	cin >> hour;
	cout << "Enter current day: ";
	cin >> day;
	cout << "Enter current month: ";
	cin >> month;
	cout << "Enter current year: ";
	cin >> year;

        //pass the minute, hour, day, month and year user entires to the
        //compare_time_date function in TimeDate class using live object
        if (live.compare_time_date(minute, hour, day, month, year)) {
			cout << "The date and time for this event has passed." << endl;
	} else 
			cout << "The date and time for this event has not passed." << endl;
}

	



















