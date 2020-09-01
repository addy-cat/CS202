#include "TimeDate.h" 
using namespace std;

//File: TimeDate.cpp
/*
This file brings a time/date aspect to classes ScheduledEvents and Assignments.
These classes both have a "has a" relationships with TimeDate. TimeDate allows
Assignments to have a due date and ScheduledEvents to have a live/ happening date.
The functions in this file allow for changing the duedate/ live time/date, 
displaying the time/ date an assignment is due/ the date/time an event is
scheduled, and comparing the time/date to a user entered time/date to check if
the time/date has passed.
*/


//TimeDate default constructor setting data member time/ date stuff  to 0
TimeDate::TimeDate() {

	second = 0;
	minute = 0;
	hour = 0;
	day = 0;
	month = 0;
	year = 0;
}

//function called by ScheduledEvents class functions display and 
//change_time_date, where these functions display when an event happens and
//the ability to change a schedule via an object called live. 
//This function specifically will change a time. This function will
// also be called by the Assignment class to change the time an assignment
//is due. 
void TimeDate::change_time(int new_second, int new_minute, int new_hour) {

	//set the variables other functions will use will be set to new verions
        //of those variables so they my be updated
	second = new_second;
	minute = new_minute;
	hour = new_hour;

}


//function called by ScheduledEvents class functions display and
//change_time_date, where these functions display when an event happens and
//the ability to change a schedule via an object called live.
//This function specifically will change a date. This function will
// also be called by the Assignment class to change the date an assignment
//is due. 
void TimeDate::change_date(int new_day, int new_month, int new_year) {

	//set the variables other functions will use will be set to new verions
	//of those variables so they my be updated
	day = new_day;
	month = new_month;
	year = new_year;

}

//function called by ScheduledEvents function display() and Assignment function
//display(), this function displays the time/date an event happens, and displays the time/ date an assignment is due. The data members is
void TimeDate::display_timedate() {

	cout << "Time " << hour << " : " << minute << " : " << second  << endl;
	cout << "Date: " << day << " / " << month << " / " << year << endl; 

}

//Function used by ScheduledEvent to check whether or not an event has passed/
//is completed. Compares the current value in these member functions to the
//data members.
bool TimeDate::compare_time_date(int minute, int hour, int day, int month, int year) {

	//compares the current data in data members to the variables.
	//Will return false whenever a time/ date element is greater than
	//it should be, therefore its designated as already happened.
	//This cluster of if statements will return true if the data member
	//values are not greater than they should be, and therefore will not
	//be passed.

	if(this->year > year ) {
		return false;
	} else if(this->month > month) {
		return false;
	} else if(this->day > day) {
		return false;
	} else if(this->hour > hour) {
		return false; 
	} else if(this->minute > minute) {
		return false; 
	} else
		return true;
}



