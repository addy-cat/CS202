#include "remote_info.h"

//Functions for the base class remote_info:


//remote_info default constructor for the int priority
//the strings in this base class are addressed in the string class
remote_info::remote_info():priority(0) {}

//remote_info copy constructor that calls the string classes assignment operator
remote_info::remote_info(const remote_info& to_copy) {

	//assignment operator calls the assignment operator in the string class
	name = to_copy.name;
	subject = to_copy.subject;

	//not using the string class operator because int can use the "="
	//and deep copy without issue
	priority = to_copy.priority;
}

//empty destructor because this class has no dynamic memory
remote_info::~remote_info() {}

//change the name associated with a remote resource
void remote_info::change_name() {

	cout << "Enter a new name for this remote resource: ";
	//calls the string classes istream operator to input a string name
	cin >> name;
	
	cin.ignore(100, '\n');

	cout << "Name changed!" << endl;
}

//change the subject of a remote resource
void remote_info::change_subject() {

	cout << "Enter the subject of this remote resource: ";
	//calls the string classes istream operator to input a string subject
	cin >> subject;
	cin.ignore(100, '\n');

	cout << "Subject changed!" << endl;
}

//change the priority associated with a resource
void remote_info::change_priority() {

	cout << "Enter a new priority for this resource: ";
	cin >> priority;

	//check fo user entering issues	
	 while(cin.fail() || (priority < 1 || priority > 10)) {
               cin.clear();
               cin.ignore(100, '\n');
               cout << "Please enter valid priority.";
               cin >> priority;
        }

               cin.clear();
               cin.ignore(100, '\n');

	cout << "Priority set!" << endl;
}

//ostream function to display data associated with a remote activity
//including name, subject and priority
ostream& operator << (ostream& out, const remote_info& to_display) {

	/*
	out << "Name: " << to_display.name << endl;
	out << "Subject: " << to_display.subject << endl;
	out << "Priority: " << to_display.priority << endl;
	*/
	
	to_display.display(out);
	return out;
}

//> operator for base class
bool remote_info::operator > (const remote_info& to_compare) {

	if (name > to_compare.name) {
		return true;
	} else {
		return false;	
	}

}

//< operator for base class
bool remote_info::operator < (const remote_info& to_compare) {

	if (name < to_compare.name) {
		return true;
	} else {
		return false;
	}

}

//<= operator for base class
bool remote_info::operator <= (const remote_info& to_compare) {

	if (name <= to_compare.name) {
		return true;
	} else
		return false;
}

//>= operator for base class
bool remote_info::operator >= (const remote_info& to_compare) {
		
	if (name >= to_compare.name) {
		return true;
	} else
		return false;
}

//== operator for base class
bool remote_info::operator == (const remote_info& to_compare) {	
	
	if (name == to_compare.name) {
		return true;
	} else
		return false;
}

//== operator for an int used in node.cpp
bool remote_info::operator == (int to_compare) {

	if (priority == to_compare) {
		return true;
	} else
		return false;
}

//!= operator for a base class
bool remote_info::operator != (const remote_info& to_compare) {

	if (name != to_compare.name) {
		return true;
	} else
		return false;
}

//= operator for a base class
remote_info& remote_info::operator = (const remote_info& to_copy) {
	
	//check for self assignment
	if (this == &to_copy) {
		return *this;
	}

	name = to_copy.name;
	priority = to_copy.priority;
	subject = to_copy.subject;	

	return *this;
}

//> operator for a string class
bool remote_info::operator > (const my_string& to_compare) {

        if (name > to_compare) {
                return true;
        } else {
                return false;
        }

}

//< operator for string
bool remote_info::operator < (const my_string& to_compare) {

        if (name < to_compare) {
                return true;
        } else {
                return false;
        }

}

//<= operator for string
bool remote_info::operator <= (const my_string& to_compare) {

        if (name <= to_compare) {
                return true;
        } else
                return false;
}

//>= operator for string class
bool remote_info::operator >= (const my_string& to_compare) {

        if (name >= to_compare) {
                return true;
        } else
                return false;
}

//== operator for string
bool remote_info::operator == (const my_string& to_compare) {

        if (name == to_compare) {
                return true;
        } else
                return false;
}

//!= operator for a string
bool remote_info::operator != (const my_string& to_compare) {

        if (name != to_compare) {
                return true;
        } else
                return false;
}

//read in the data members for the file
void remote_info::read(istream& in) {

	in >> name;
	in.ignore(100, '\n');
	in >> subject;
	in.ignore(100, '\n');
	in >> priority;
	in.ignore(100, '\n');
}

//write out the data members for the file
void remote_info::write(ostream& out) {

	out << name << endl;
	out << subject << endl;
	out << priority << endl;
}

//display function just for base class
void remote_info::display (ostream& out) const {

	out << "Name: " << name << endl;
        out << "Subject: " << subject << endl;
        out << "Priority: " << priority << endl;
	
	
}

//virtual function for derived classes
void remote_info::change_description() {}

//---------------------------------------------------------------------------
//Functions for videos class

//videos class default constructor for the time data
videos::videos():hour(0), min(0), sec(0) {}

//copy constructor for videos class, using an initialization list so
//the members in the base class can also be copied/ used for this class
videos::videos(const videos& to_copy):node(to_copy) {

	//assignment operator for copying this description string is enough
	//because it is overloaded:
	video_description = to_copy.video_description;
	
	//copy over the time elements to new ones
	hour = to_copy.hour;
	min = to_copy.min;
	sec = to_copy.sec;	

}

//change the description for a video
void videos::change_description() {

	cout << "What is this video about? " << endl;
	cout << "Description: " << endl;
	//calls the string classes istream operator to input a string description
        cin >> video_description;
        cin.ignore(100, '\n');

        cout << "Video description changed!" << endl;
}

//change the duration of a video
void videos::change_duration() {

	cout << "Enter a duration for this video: " << endl;
	cout << "Hours: ";
	cin >> hour;
	
	cout << "Minutes: ";
	cin >> min;

	cout << "Seconds: ";
	cin >> sec;

	cout << "Duration for this video set to " << hour << ":" << min << ":" << sec << endl;

}

//for displayal use the ostream operator
ostream& operator << (ostream& out, const videos& to_display) {

	//display the ostream function in base class somehow that displays
	//priority, name and subject:

	to_display.display(out);
	

	return out;
}

void videos::display(ostream& out) const {

	node::display(out);
	out << "Description: " << video_description << endl;
	out << "Duration: " << hour << ":" << min << ":" << sec << endl;

}

//assignment operator for the videos class to copy seconds, minutes, hours and 
//description
videos& videos::operator = (const videos& to_copy) {

	//check for self assignment
        if (this == &to_copy) {
                return *this;
        }

	this->node::operator = (to_copy);
	//copy data members
        video_description = to_copy.video_description;
	hour = to_copy.hour;
	min = to_copy.min;
	sec = to_copy.sec;

	return *this;
}

//operator + for adding the durations of two videos together
videos videos::operator + (const videos& to_copy) {

	//videos class object
	videos ret;

	//copy all existing hour/ min/ sec data and add it to new
	ret.hour = hour + to_copy.hour;
	ret.min = min + to_copy.min;
	ret.sec = sec + to_copy.sec;		
	return ret;
}

//read the data members for this class
void videos::read(istream& in) {


	node::read(in);

	in >> video_description;	
	in.ignore(100, '\n');
	in >> hour;
	in.ignore(100, '\n');
	in >> min;
	in.ignore(100, '\n');
	in >> sec;
	in.ignore(100, '\n');

}

//write the data members for this class to a file
void videos::write(ostream& out) {

	node::write(out);
	
	out << video_description << endl;
	out << hour << endl;
	out << min << endl;
	out << sec << endl;
}

//----------------------------------------------------------------------------------
//Functions for websites class:


//websites default constructor for the boolean bookmark value
websites::websites():bookmarked(0) {
}

//website copy constructor with initialization list so we can
//also copy the data in the base class remote_info
websites::websites(const websites& to_copy):node(to_copy) {

	//copy over the bookmarked value and the url value	
	bookmarked = to_copy.bookmarked;
	url = to_copy.url;
}
/*
void websites::insert(istream& in) {


	cout << "What is the URL of this website? " << endl;
        cout << "URL: " << endl;
        //calls the string classes istream operator to input a string description
        in >> url;
        in.ignore(100, '\n');

        cout << "Site URL changed!" << endl;

}
*/

void websites::change_description() {

	cout << "What is the URL of this website? " << endl;
        cout << "URL: " << endl;
        //calls the string classes istream operator to input a string description
        cin >> url;
        cin.ignore(100, '\n');

        cout << "Site URL changed!" << endl;
}
//bookmark a website
void websites::bookmark() {

	cout << "This site is now bookmarked." << endl;	
	bookmarked = true;
}
/*
istream& operator >> (istream &in, websites& to_input) {

	to_input.insert(in);
	return in;
}
*/

//ostream display function for displaying the data from the base class
//subject, name and priority, and also the data members for this class
//including bookmarked status and url	
ostream& operator << (ostream& out, const websites& to_display) {

	//output the data from base class
	to_display.node::display(out);
	to_display.display(out);

	return out;

}

//display the info for the base class and this class
void websites::display(ostream& out) const {

	node::display(out);	
	out << "URL: " << url << endl;
	if (bookmarked == true) {
		out << "This website is bookmarked. " << endl;
	} else
		out << "This website is not bookmarked. " << endl;
}


//website classes assignment operator to copy the bookmark status and url 
websites& websites::operator = (const websites& to_copy) {

	//check for self assignment
	if (this == &to_copy) {
		return* this;
	}

	this->node::operator = (to_copy);

	//copy the bookmarked and url data members using assignment operator	
	bookmarked = to_copy.bookmarked;
	url = to_copy.url;		

	return *this;
}

//read in the data from this classes data members
void websites::read(istream& in) {
	node::read(in);
	
	in >> url;	
	in.ignore(100, '\n');
	in >> bookmarked;
	in.ignore(100, '\n');

}

//write out the data for this classes data members
void websites::write(ostream& out) {

	node::write(out);
	
	out << url << endl;
	out << bookmarked << endl;
}

//-------------------------------------------------------------------------------
//Functions for meetings class
meetings::meetings() {}
//copy constructor for the meetings class
meetings::meetings(const meetings& to_copy):node(to_copy) {

	speaker = to_copy.speaker;
}

//change description for a meeting (speaker)
void meetings::change_description() {

	cout << "Who is the speaker/ organizer of this meeting?" << endl;
	cout << "Speaker: " << endl;

	cin >> speaker;
	cin.ignore(100, '\n');
	
	cout << "The speaker is: " << speaker << endl;	

}

//ostream display function for a meeting
ostream& operator << (ostream& out, const meetings& to_display) {

	//display a meetings title, subject and priority
        to_display.node::display(out);
        to_display.display(out);

        return out;

}

//display the base classes info and this classes speaker
void meetings::display(ostream& out) const {

	node::display(out);
        out << "Speaker: " << speaker << endl;
}


//meetings assignment operator function to copy the speaker string
meetings& meetings::operator = (const meetings& to_copy) {

	if (this == &to_copy) {
		return *this;
	}

	this->node::operator = (to_copy);

	speaker = to_copy.speaker;
	
	return *this;
}

//read this classes data members from a file
void meetings::read(istream& in) {
	node::read(in);
	in >> speaker;
        in.ignore(100, '\n');
}

//write this classes data members to a file
void meetings::write(ostream& out) {

	node::write(out);	
	
	out << speaker << endl;

}


