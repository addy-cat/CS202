/*
File: activity.cpp

This file contains the implementation of the functions in the classes in activity.h. Implementation
for the base class activity, and its three derived classes coffee_shop, study and CATwork.
This file does not use a data structure and stores the data simply. Through dynamic binding this data
is stored in the data structure via class manager in node.h. Most functions contained
in the three derived classes are the exact same but have different data members are do different things.
One function in each derived class is not in the other classes (coffee_shop -> change_deals, study ->
room_number, CATwork->call out) in order to use RTTI in source.cpp.
*/


#include "module.h"
#include <cstring>


//Functions for class "activity"

//title default constructor to set ints to zero and char*'s to NULL
activity::activity() {
	
	activity_title = NULL;

	//these variables are used for durations of activities	
	duration_hour = 0;
	duration_min = 0;

	//these variables are used for the time/ date activities are scheduled to occur
	scheduled_day = 0;
	scheduled_month = 0;
	scheduled_hour = 0;
	scheduled_min = 0;

	//designate the priority of an activity
	priority = 0;

	//designate whether an activity is to be with another person or not
	dependence = false;
}

//copy constructor for the dynamic char array title
activity::activity(const activity& to_copy) {

	//to copy the title of an activity	
	if(to_copy.activity_title) {
		activity_title = new char[strlen(to_copy.activity_title) + 1];
		strcpy(activity_title, to_copy.activity_title);
	} else 
		activity_title = NULL;

	//copy over the int priority
	priority = to_copy.priority;

	//copy over the duration of an activity
	duration_hour = to_copy.duration_hour;
	duration_min = to_copy.duration_min;

	//copy over the dependence of an activity
	dependence = to_copy.dependence;

	//copy over the date/time an event is scheduled
	scheduled_day = to_copy.scheduled_day;
	scheduled_month = to_copy.scheduled_month;
	scheduled_hour = to_copy.scheduled_hour;
	scheduled_min = to_copy.scheduled_min;
	
}	

//title desctructor
activity::~activity() {

	//delete the memory of the char* activity title
	delete [] activity_title;
	activity_title = NULL;
}

//change the title for the three derived classes
void activity::change_activity_title(const char* activity_title) {

	//if a title exists already, delete it to replace it
	if(this->activity_title) {
		delete [] this->activity_title;
	}

	//change old title to new title
	this->activity_title = new char[strlen(activity_title) + 1];
	strcpy(this->activity_title, activity_title);
}

//change the duration of an activity in hours and minutes
void activity::change_duration() {

	//prompt for the duration in hours
	cout << "Enter a new duration: " << endl;
	cout << "Hours: " << endl;
	cin >> duration_hour;

	//prompt for the duration in minutes	
	cout << "Minutes: " << endl;
	cin >> duration_min;

	cout << "Duration set!" << endl;	
}

void activity::change_desc() {}
void activity::change_time_date_happening() {}
void activity::change_reservation_location() {}

//change the priority/ importance of an activity (will be used to
//display in list in order of priority)
void activity::change_priority() {

	int temp = 0;
	
	cout << "Set the priority of this activity from 1 to 10: " << endl;
	cin >> temp;

	  while(cin.fail()) {
               cin.clear();
               cin.ignore(100, '\n');
               cout << "Please enter valid option.";
               cin >> temp;
        }

               cin.clear();
               cin.ignore(100, '\n');


	//if what the user enters is not in the range of 1 to 10 then the input is not taken
	//I wanted there to be realistic priorities so it wouldnt be so big
	if (temp > 0 && temp < 11) {
		priority = temp;
		cout << "Priority set!" << endl;
	} else 
		cout << "Error, invalid entry" << endl;

}
	
//check if the activity is to be done with a friend or to be independent
bool activity::is_independent() {

	//running this functions changes the dependence status
	dependence = !dependence;

	//based on above status the status is output to the user
	if (dependence == false) {
		cout << "This activity is independent" << endl;
	} else 
		cout << "This activity to be done with a friend" << endl;

	return !dependence;
}


//display the title of the activity
void activity::display() {

	//if there is a title, then display it	
	if (activity_title) {
		cout << activity_title << endl;
	//if not, tell the user
	} else 
		cout << "There are no titles.. " << endl;
}

//display the priority of an activity
void activity::display_priority() {

	//if there is a priority to display, then display it	
	if (priority) {
		cout << priority << endl;
	} else 
		//if not, then tell the user
		cout << "No priority set." << endl;
}

//display the duration of an activity
void activity::display_duration() {

	//if there is a duration (would be in hours and minutes) then display it
	if (duration_hour && duration_min) {
		cout << duration_hour << ":" << duration_min << endl;
	} else
		//if not, tell the user
		cout << "No duration set." << endl;
}

//display the dependence of an activity
void activity::display_dependence() {

	//if the dependence value from the function "dependence" above is false, then the activity is independent
	 if (dependence == false) {
                cout << "This activity is independent" << endl;
        } else
		//or else it is dependent
                cout << "This activity to be done with a friend" << endl;
}

//this function is used by the node class in the function "add_activity_
//helper" where this functions return value is used to determine if
//the activity can be added or not
int activity::compare_title(activity* to_compare) {

	return strcmp(to_compare->activity_title, activity_title);
}


//to be used by node class to compare a title to see where to add
int activity::compare_title(const char* to_compare) {

	if (activity_title) {
		return strcmp(to_compare, activity_title);
	} else
		return 0;

}

//to determine priority of an activity to be used in node.cpp
int activity::compare_priority(activity* a_activity_to_compare) {
	
	if (priority == a_activity_to_compare->priority) {
		return 0;
	} else if(priority < a_activity_to_compare->priority) {
		return -1;
	} else 
		return 1;
}

//--------------------------------------------------------------------------

//Functions for class "coffee_shop"

//coffee_shop default constructor
coffee_shop::coffee_shop():address(0), order(0), deals(0) {

}

//coffee_shop desctructor
coffee_shop::~coffee_shop() {

	//deallocate the memory associated with the char*'s

	delete [] address;
	address = NULL;

	delete [] order;
	order = NULL;

	delete [] deals;
	deals = NULL;
}

//coffee_shop copy constructor using activity base class initialization 
//list
coffee_shop::coffee_shop(const coffee_shop& to_copy):activity(to_copy) {

	//copy over the address of a coffee shop
	if(to_copy.address) {
		address = new char[strlen(to_copy.address) + 1];
		strcpy(address, to_copy.address);
	} else
		address = NULL;

	//copy over the drink/ food order for the coffee shop
	if(to_copy.order) {
		order = new char[strlen(to_copy.order) + 1];
		strcpy(order, to_copy.order);
	} else
		order = NULL;

	//copy over the coupons/ deals of a coffee shop	
	if(to_copy.deals) {
		deals = new char[strlen(to_copy.deals) + 1];
		strcpy(deals, to_copy.deals);
	} else
		deals = NULL;

}

//change the description of a coffee shop visit. In this class, the 
//description is an order from the menu. Each class has a unique 
//type of description char*.
void coffee_shop::change_desc() {

	cout << "What are you going to order at the coffee shop? : " << endl;
	//if there is an order already, delete it
	if(order) {
		delete [] order;
	}

	//now we can add the new order to this coffee shop instance
	order = new char[MAX_CHAR + 1];
	cin.get(order, MAX_CHAR);
//	cin.ignore(MAX_CHAR, '\n');

}

//change the coupons/ savings associated with a coffee shop visit.
//This function is specific to this class.
void coffee_shop::change_deals() {

	 cout << "Enter a promotion or coupon: " << endl;

	//if there is already coupons, delete it
        if(deals) {
                delete [] deals;
        }

	//now we can add new coupon information
        deals = new char[MAX_CHAR + 1];
        cin.get(deals, MAX_CHAR);
//	cin.ignore(MAX_CHAR, '\n');
}

//Change the reservation location of the coffee shop. Each class
//has this function but each class uses it in a different way. For this
//class coffee shop, it is in the form of an address of the shop.
void coffee_shop::change_reservation_location() {


	 //if there is already an address, delete it
        cout << "Enter the address of the coffee shop: " << endl;
		
	        if (address) {
                delete [] address;
        }


	//now we can add a new address in this instance
	address = new char[MAX_CHAR + 1];
	cin.get(address, MAX_CHAR);
//	cin.ignore(MAX_CHAR, '\n');

}

//Change the time and date a visit is scheduled. 
//Uses data members that exist in the base class that all derived 
//classes can use for this same function. This function is similar
//in all derived classes.
void coffee_shop::change_time_date_happening() {
	
	cout << "Set the time and date of the coffee shop visit: " << endl;
	
	cout << "Month: ";
	cin >> scheduled_month;
	
	cout << "Day: ";
	cin >> scheduled_day;

	cout << "Hour: ";
	cin >> scheduled_hour;

	cout << "Minute: ";
	cin >> scheduled_min;

	cout << "Coffee shop visit scheduled!" << endl;
}

//display from the base class: title, priority, length of time activity takes, 
//and dependence. From this class specifically, display description, time/date to go,
//reservation address, and the current deals
void coffee_shop::display() {

	//for base class functions, use scope operator to access them:

	cout << "Coffee shop name: ";
	activity::display();	
	cout << endl;

	cout << "Priority: ";
	activity::display_priority();
	cout << endl;

	cout << "You'll spend this much time here: ";
	activity::display_duration();
	cout << endl;

	cout << "Dependence: ";
	activity::display_dependence();
	cout << endl;

        //now for functions specific to this coffee_shop class:

	if (deals) {
		cout << "Current deals/ savings: " << deals << endl;
	} else 
		cout << "You haven't added any deals." << endl;

	if (address) {
		cout << "Location of shop: " << address << endl;
	} else
		cout << "You haven't added an address." << endl;
	if (order) {
		cout << "Your order: " << order << endl;
	} else 
		cout << "No orders." << endl;
	
	if(scheduled_day || scheduled_month || scheduled_hour || scheduled_min) {
	cout << "Scheduled visit: " << scheduled_day << "/" << scheduled_month << " at " << scheduled_hour << ":" << scheduled_min << endl;
	} else 
		cout << "No scheduled visit." << endl;
	
}

//-----------------------------------------------------------------------------------------

//Functions for study class:


//study class default constructor to set int to zero and char*'s to NULL
study::study(): room_number(0), building(0), topic(0)  {

}

//study class copy constructor
study::study(const study& to_copy):activity(to_copy) {

	//copy over building char*
	 if(to_copy.building) {
                building = new char[strlen(to_copy.building) + 1];
                strcpy(building, to_copy.building);
        } else
                building = NULL;

	//copy over topic char*
        if(to_copy.topic) {
                topic = new char[strlen(to_copy.topic) + 1];
                strcpy(topic, to_copy.topic);
        } else
                topic = NULL;

	//copy over int room number
	room_number = to_copy.room_number;

}

//study class desctructor
study::~study() {

	//deallocate memory for the building char*
	delete [] building;
        building = NULL;

	//deallocate memory for the topic char*
	delete [] topic;
	topic = NULL;
}


//change the topic to study.The description for this class is in the form
//of a topic to study.
void study::change_desc() {

	cout << "What are you going to study at the campus? : " << endl;

	//if there is already a topic to study then delete it
        if(topic) {
                delete [] topic;
        }

	//now we can add a new topic
        topic = new char[MAX_CHAR + 1];
        cin.get(topic, MAX_CHAR);

}

//change the room number to study in. This function is specific to this
//class. 
void study::change_room_number() {

	cout << "What room number are you studying in? : " << endl;

	cin >> room_number;

	//checking for user input error
	while(cin.fail()) {
               cin.clear();
               cin.ignore(100, '\n');
               cout << "Please enter valid option.";
               cin >> room_number;
        }

               cin.clear();
               cin.ignore(100, '\n');
}

//change where the study location is. All classes have this function, but
//in the case of this class study, the location comes in the form of
//a building in which the reservation location to study in is. This class
//study along with this function implies that you are going to a 
//physical location to study such
//as the PSU library or the engineering building for tutoring.
void study::change_reservation_location() {

	cout << "Enter the building in which the reservation is: " << endl;
        if (building) {
		//if a building already exists delete it
                delete [] building;
        }

	//now we can make a new building char*
        building = new char[MAX_CHAR + 1];
        cin.get(building, MAX_CHAR);
}

//change the date and time the study session is scheduled to happen
void study::change_time_date_happening() {

        cout << "Set the time and date of the study session " << endl;

        cout << "Month: ";
        cin >> scheduled_month;

        cout << "Day: ";
        cin >> scheduled_day;

        cout << "Hour: ";
        cin >> scheduled_hour;

        cout << "Minute: ";
        cin >> scheduled_min;

}

//display from the base class: title, priority, length of time activity takes,
//and dependence. From this class specifically, display description (topic)
//, time/date to go, reservation building, and the room number
void study::display() {

        //for base class functions, use scope operator to access them properly:

        cout << "Study title: ";
        activity::display();
        cout << endl;

        cout << "Priority: ";
        activity::display_priority();
        cout << endl;

        cout << "You'll spend this much time here: ";
        activity::display_duration();
        cout << endl;

        cout << "Dependence: ";
        activity::display_dependence();
        cout << endl;

        //now for functions specific to this study class:

        if (building) {
                cout << "Building to study in: " << building << endl;
        } else
                cout << "You haven't added a building." << endl;
	
	if (room_number) {
		cout << "Room number to study in: " << room_number << endl;
	} else 
		cout << "No room numbers." << endl;

        if (topic) {
                cout << "Study topic: " << topic << endl;
        } else
                cout << "No topics." << endl;

	if(scheduled_day || scheduled_month || scheduled_hour || scheduled_min) {
        	cout << "Scheduled visit: " << scheduled_day << "/" << scheduled_month << " at " << scheduled_hour << ":" << scheduled_min << endl;
        } else
            	cout << "No scheduled visit." << endl;

}
                      
//----------------------------------------------------------------------------
//Functions for work class

//default constructor for work class
CATwork::CATwork(): called_out(0), room_title(0), tasks(0) {

}	

//copy constructor for work class
CATwork::CATwork(const CATwork& to_copy):activity(to_copy) {

	//copy over a task
        if(to_copy.tasks) {
                tasks = new char[strlen(to_copy.tasks) + 1];
                strcpy(tasks, to_copy.tasks);
        } else
                tasks = NULL;

	//copy over a room title
        if(to_copy.room_title) {
                room_title = new char[strlen(to_copy.room_title) + 1];
                strcpy(room_title, to_copy.room_title);
        } else
                room_title = NULL;

	//copy over the status of called out
	called_out = to_copy.called_out;
}

//work destructor
CATwork::~CATwork() {

	//deallocate the momory associated with char*'s tasks and room_title
	delete [] room_title;
	room_title = NULL;

	delete [] tasks;
	tasks = NULL;

}

//change description of work. The description in this class is in the form
//of a task to do at work.
void CATwork::change_desc() {

	cout << "What tasks will you do at work? : " << endl;

	//if there is a task already, delete it
        if(tasks) {
                delete [] tasks;
        }

	//now we can make a new task
        tasks = new char[MAX_CHAR + 1];
        cin.get(tasks, MAX_CHAR);
	
}

//change the room name youre working in. The reservation location
//for this class comes in the form of a room title. In the CAT at PSU,
//room titles have silly names that aren't numbers so this is a char*.
//Meetings for work are able to be used or "reserved" like in real life.
void CATwork::change_reservation_location() {

	//prompt for a room name. If there exists a room title delete it.
	cout << "Enter the room name to reserve for meeting " << endl;
        if (room_title) {
                delete [] room_title;
        }

	//we can now make a new room title
        room_title = new char[MAX_CHAR + 1];
        cin.get(room_title, MAX_CHAR);

}

//change the time/date work is scheduled
void CATwork::change_time_date_happening() {

        cout << "Set the time and date of your shift: " << endl;

        cout << "Month: ";
        cin >> scheduled_month;

        cout << "Day: ";
        cin >> scheduled_day;

        cout << "Hour: ";
        cin >> scheduled_hour;

        cout << "Minute: ";
        cin >> scheduled_min;

	cout << "Shift time/date set." << endl;

}

//call out of work by triggering boolean value. This function is unique
//to this class.
void CATwork::call_out() {

	cout << "Calling out..." << endl;
	called_out = true;

}

//display work data including work title, priority, duration and depdence
//from the base class, and then if called out, room title reserved, and
//tasks and scheduled time/date from this class.
void CATwork::display() {

	//for base class functions, use scope operator to access them:

        cout << "Work title: ";
        activity::display();
        cout << endl;

        cout << "Priority: ";
        activity::display_priority();
        cout << endl;

        cout << "You'll spend this much time here: ";
        activity::display_duration();
        cout << endl;

        cout << "Dependence: ";
        activity::display_dependence();
        cout << endl;

        //now for functions specific to this work class:

	if (called_out == true) {
		cout << "Called out" << endl;
	} else
		cout << "Not called out" << endl;

        if (room_title) {
                cout << "Room to reserve: " << room_title << endl;
        } else
                cout << "No room reserved." << endl;

        if (tasks) {
                cout << "Work task: " << tasks << endl;
        } else
                cout << "No tasks." << endl;

        if(scheduled_day || scheduled_month || scheduled_hour || scheduled_min) {
                cout << "Scheduled shift: " << scheduled_day << "/" << scheduled_month << " at " << scheduled_hour << ":" << scheduled_min << endl;
        } else
                cout << "No scheduled shift." << endl;

}

