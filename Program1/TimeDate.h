#include <iostream>
#ifndef TIMEDATE_H
#define TIMEDATE_H

//File: TimeDate.h

/*This class is a seperate class from the hierarchy of the other classes. This class is used by	classes Assignment and ScheduledEvents, to manage their duedate system and the schedules that events go live, respectively. Both classes will use TimeDate's change_time, change_date, and display_time_date functions. In the case of this class, class ScheduledEvents "has a" TimeDate, and class Assignment "has a" TimeDate.
*/

class TimeDate
{
	public:
		//TimeDate constructor to set integers in private section to
		//zero
		TimeDate();

		//function used by classes Assignments and ScheduledEvents to
		//change the time an assignment is due, and to schedule an
		//event
		void change_time(int new_second, int new_minute, int new_hour);		
		//function used by classes Assignments and ScheduledEvents to
                //change the date an assignment is due, and to schedule an
                //event
		void change_date(int new_day, int new_month, int new_year);

		//display a due date for Assignment, and display the date
		//and time of an event for ScheduledEvents
		void display_timedate();

		//used by the check_event function in ScheduledEvents class
		//to check if event date and time is the same as a date and time already
		//entered to display yes or no if the event has passed/ been completed
		bool compare_time_date(int minute, int hour, int day, int month, int year);

	private:
		//private data members used by above functions to 
		//set time and date.
		int second;
		int minute;
		int hour;
		int day;
		int month;
		int year;
};

#endif
