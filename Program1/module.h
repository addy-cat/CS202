#include <iostream>
#include <cstring>
#include "TimeDate.h"
#include "node.h"

#ifndef MODULE_H
#define MODULE_H

using namespace std;

//File: Module.h

/*
This file is the most robust .h file in the program, as it holds the classes for two of its three derived classes. The two classes it holds are ScheduledEvents, and LectureVideos. Class Module is the parent to both of these classes, so ScheduledEvents and LectureVideos have an "is a" relationship with the Module class. Module also had a third derived class, Assignment, however because of Assignment's association with the data structure, Assignment class is not in this file but it instead with node class.
Modules main function is the commonality of the three child classes when it comes to titles of videos, assignments, and scheduled events. These three classes do not have much else in common other than their titles. Module holds the ability to both display the titles and change the titles of its derived classes data members using an "a_title" char array.
*/

//for max lengths of char*'s
const int MAX_CHAR = 1000;

class Module
{
	public: 
		//default constructor, destructor, and copy constructor because 
		//class Module has dynamic memory (char* a_title)
		Module();

		//Destructor to delete a_title char memory
		~Module();

	        //replaces a_title with new_title, used by derived classes
		//for functions relating to changing title data	
		Module(const char* new_title);

		//copies a title
		Module(const Module& to_copy);

		//derived classes will use these functions put here
		//because common elements are in Module class:

		//change the title for the three derived classes
		void change_title(const char* new_title);

		//compare the passed in title to a_title, return true if
		//they are the same and false if they are different
		bool compare_title(const char* to_compare);

		//display the title for the three derived classes
		void display();

	protected:
		//protected data member a_title that will be used by the display
		//and change title functions above
		char* a_title;
};

//A LectureVideo "is a" Module plus more
//The LectureVideo class will have functionality relating to videos.
//This class is derived from the Module class through public derivation.
//LectureVideos uses the Modules functions to change the title and display
//the title for a video. 
class LectureVideo: public Module
{
	
	public:

		//default constructor initializing integer values
		LectureVideo();

		//this display function will display the length of a video (not title)
		//but will also call the module base classes display title function
		void display();

		//edit the resolution of the lecture video
		void change_resolution();

		//change the playback speed of a video
		void change_speed();

		//see if video has been viewed
		int watch_video();

		//toggle_subtitles will turn the subtitles on or off
		int toggle_subtitles();

		//change the length of the video
		void change_duration();
		

	private:

		//data members for functions above

		//variables for video duration
		int sec;
		int min;
		int hour;

		//variable for playback speed
		float speed;

		//bool values for toggling subtitles or toggling
		//whether or not a video has been viewed
		bool subtitles;
		bool is_viewed;

		//variables for the height and width of a video for
		//resolution
		int height;
		int width;

};

//ScheduledEvents class is a class derived from Module that deals with
//events. A ScheduledEvent "is a" Module plus more. The functions in
//Module display_title and change title are used by this class. 
//This class also has functionality with the TimeDate class in TimeDate.h, 
//where each event has a time that it goes "live", or occurs. TimeDate will
//help the function change_time_date in this class carry out its operations.
class ScheduledEvents: public Module
{

	public:
		//constructor/ copy constructor
		ScheduledEvents();
		ScheduledEvents(const ScheduledEvents& to_copy);

		//destructor for char* description
		~ScheduledEvents();

		//display dates/times from TimeDate class and titles of events
		void display();

		//change the description of a scheduled event
		void change_description();

		//change the date an event is scheduled to go live/ happen using 
		//the live object to access TimeDate class
		void change_time_date();

		//change the priority/ importance (1-5) that an event has, example
		//an assignments due date or a test date
		void change_priority();

		//used to check if an event has been completed/ passed or not
		//based on a time/ date from the TimeDate class
		bool check_event();	



	private:
	
		//object of the TimeDate class in TimeDate.h that has functions that
		//interact with the change, check and display event function above.	
		TimeDate live;

		//data members used by change_priority/ description
		//and display functions above, where priority is the int value
		//of importance an event has, and description is a description of an event
		int priority;
		char* description;
};

#endif
