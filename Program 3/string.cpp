/*
File: string.cpp

This file contains the implementation of the string class located in 
remote_info.h. The string class creates a char* str and uses it to 
produce various operations on that str. In this way, the string class can be
called when we need to find a certain string for removal or retrieval.
The string class is used by all derived classes of the base class when a
char* is expected. The string class makes it simpler to do things like
copy dynamic memory, add dynamic memory, or take in/ output strings from the 
user to the console. The string class also overloads all comparison 
functions that are called by the base class remote_info and its derived
classes, along with the BST manager when it comes to finding where to add/
remove/ retrieve a material. This class simplifies code because since all of
the derived classes use a char*, the code to write the functions for a char* are
only written once. The code in the derived classes looks less bulky this way.
The comparison operators, since they are using char* data, are comparing
alphabetically.
*/


#include <iostream>
#include "remote_info.h"


//set the char str to NULL
my_string::my_string():str(0) {}

//for the dynamic str, delete it
my_string::~my_string() {

	if (str) 
		delete [] str;
}

//copy constructor for the char* str that copies a string
my_string::my_string(const my_string& a_str) {

	if (a_str.str) {
		str = new char[strlen(a_str.str) + 1];
		strcpy(str, a_str.str);
	} else
		str = NULL;
}

//checking for inequality between two strings
bool my_string::operator != (const my_string& to_compare) {
	
	if (strcmp(str, to_compare.str) != 0) {
		return true;
	} else
		return false;
	
}

bool my_string::operator == (const char* to_compare) {

	if (strcmp(str, to_compare) == 0) {
		return true;
	} else
		return false;

}

//checking for equality between two strings
bool my_string::operator == (const my_string& to_compare) {
	
	if (strcmp(str, to_compare.str) == 0) {
		return true;
	} else
		return false;
}

//checking if one string is less than another string
bool my_string::operator < (const my_string& to_compare) {

	if (strcmp(str, to_compare.str) < 0) {
		return true;	
	} else
		return false;
}

//checking is one string is greater than another string
bool my_string::operator > (const my_string& to_compare) {

	if (strcmp(str, to_compare.str) > 0) {
		return true;
	} else
		return false;
}

//checking if one string is less than or equal to another
bool my_string::operator <= (const my_string& to_compare) {
	
	if (str > to_compare.str) {
		return false;
	} else
		return true;
}

//checking if one string is greater than or equal to another
bool my_string::operator >= (const my_string& to_compare) {
	
	if (str < to_compare.str) {
		return false;
	} else
		return true;
}

//assignment operator to set one string equal to another in case
//we need such a thing
my_string& my_string::operator = (const my_string& a_str) {

	//checking for self assignment between the current string
	//and a passed in string. In this case we can just return 
	//the string in the current object.
	if (this == &a_str) {
		return *this;
	}

	//in this case make a new string
	if (a_str.str) {
		str = new char[strlen(a_str.str) + 1];
		strcpy(str, a_str.str);
	} else
		str = NULL;

	//regardless return the *this string
	return *this;
	
}

//overloading the cout operator so outputting is simpler
ostream& operator << (ostream& out, const my_string& to_display) {

	out << to_display.str;
	return out;
}

//overloading the input operator so inputting is simpler
istream& operator >> (istream& in, my_string& to_input) {

	char temp[100]; //make a temp variable 
	in.get(temp, 100, '\n');

	if (to_input.str) {
		delete [] to_input.str;
	}

	to_input.str = new char[strlen(temp) + 1]; 
	strcpy(to_input.str, temp); //the string to be inputted is temp
	return in; //return what we inputted
}









		























