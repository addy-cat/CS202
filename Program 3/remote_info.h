/*
File: remote_info.h

This file contains every class in the program. The base class remote_info
is in here, along with its four derived classes: websites, videos, meetings,
and node. There is also a string class that creates a char* string and 
manages it via various operator overload functions. There is also a 
manager class for the BST in this file, its class called BST_manager.
BST_manager uses the nodes created in the node class and includes add, 
remove, retrieve and display functions for the nodes. Data in inserted
into the BST by title of the material one is trying to add, alphabetically.
Every class has at least 2 operator overloaded functions, with the
base class and the string class having a full set of 
comparison operators, assignment operator, and ostream operator. 
*/

#include <cstring>
#include <iostream>
#include <fstream>
#ifndef REMOTE_INFO_H
#define REMOTE_INFO_H

using namespace std;

//const int FILE_SIZE = 100;
const int MAX_CHAR = 1000;

class my_string {

        public:
		//string class default constructor 
                my_string();
		//string class destructor for its dynamic memory
                ~my_string();
		//string class copy constructor for its dynamic memory
                my_string(const my_string& a_str);

		//string operator functions to create and manage a char* str
                friend ostream& operator << (ostream& out, const my_string& to_display);
	
                //*do not have this my_string& be const because we will change 		      //its value:*
		//for taking in a string
                friend istream& operator >> (istream& in, my_string& to_input);
		//for checking for inequality
                bool operator != (const my_string& to_compare);
		//checking for equality
                bool operator == (const my_string& to_compare);

		bool operator == (const char* to_compare);
		//checking if one string is less than or equal to another
                bool operator <= (const my_string& to_compare);
		//checking if one string is greater than or equal to another
                bool operator >= (const my_string& to_compare);
		//checking if one string is less than another
                bool operator < (const my_string& to_compare);
		//checking is one string is greater than another
                bool operator > (const my_string& to_compare);

		//assignment operator for setting one string equal to another	
                my_string& operator = (const my_string& a_str);

        private:

		//the char* string data member to be used in the above
		//functions to model the behavior of a string for the
		//derived classes of remote_info
                char* str;
};

//remote_info is the base class
class remote_info {


	public:
		//remote_info constructor
		remote_info();
		//remote_info's copy constructor
		remote_info(const remote_info& to_copy);
		//desctructor must be made virtual
		virtual ~remote_info();
		//function to change a subject
		void change_subject();
		//function to change a priority
		void change_priority();
		//function to change a name 
		void change_name();

		//virtual functions to be written in the derived classes:
	
		virtual void display(ostream& out) const;
		virtual void write(ostream& out);
		virtual void read(istream& in);

		//virtual description changing function not implemented
                //in this class but instead for its derived classes:
                virtual void change_description();

		//operator functions for use by node class:
	
		//display function to output data via ostream	
		friend ostream& operator << (ostream& out, const remote_info& to_display);

		//comparison operators to compare to the base class:

		//check for if base class data is larger than another
		bool operator > (const remote_info& to_compare);
		//if base class data is less than another
		bool operator < (const remote_info& to_compare);
		//base class data is less than or equal to another
		bool operator <= (const remote_info& to_compare);
		//base class data is greater than or equal to another
		bool operator >= (const remote_info& to_compare);
		//checking for equality
		bool operator == (const remote_info& to_compare);
		//checking for inequality
		bool operator == (int to_compare);
		bool operator != (const remote_info& to_compare);

		//comparison operators to compare to a string
		bool operator > (const my_string& to_compare);
		bool operator < (const my_string& to_compare);
		bool operator <= (const my_string& to_compare);
		bool operator >= (const my_string& to_compare);
		bool operator == (const my_string& to_compare);
		bool operator != (const my_string& to_compare);

		//assignment operator for setting data to another
		remote_info& operator = (const remote_info& to_copy);



	private:

		//for a subject of a material
		my_string subject;
		//for the title of a material
		my_string name;
		//for the priority of a material
		int priority;
		
};

class node: public remote_info {

        public:
		//defauly constructor for node
                node();
		//copy constructor for node
                node(const node& a_node);	
                node(remote_info* a_info);
		//virtual node desctructor
                virtual ~node();

		//to connect a node to left
                void connect_left(node* connection);
		//to connect a node to right
                void connect_right(node* connection);
		//traverse left in tree
                node*& go_left();
		//traverse right in tree
                node*& go_right();

		//assignment operator to set one node to another
                node& operator = (const node& a_copy);

		//check for inequality between nodes
                bool operator != (const node& to_compare);
		//check for equality between nodes
                bool operator == (const node& to_compare);
		bool operator == (int to_compare);
		//output the nodes
                friend ostream& operator << (ostream& out, const node& to_display);
		
	//	void write(ostream& out);

		//virtual change description function from base class
                virtual void change_description();
		virtual void display(ostream& out) const;

		virtual void write(ostream& out);
		virtual void read(istream& in);


        private:

		//traverse left in the tree
                node* left;
		//traverse right in the tree
                node* right;
};
	
class videos: public node {

	public:
		//video default constructor
		videos();
		//videos copy constructor
		videos(const videos& to_copy);
		//change the description of a video
		void change_description();
		//change the duration of a video
		void change_duration();
	
		//ostream operator for video data displayal	
		friend ostream& operator << (ostream& out, const videos& to_display);
		/*
		These comparison operators dont make sense here:

		bool operator > (const videos& to_compare);
		bool operator < (const videos& to_compare);
		bool operator >= (const videos& to_compare);
		bool operator <= (const videos& to_compare);
		bool operator == (const videos& to_compare);
		bool operator != (const videos& to_compare);
		*/

		//set one video to another
	        videos& operator = (const videos& to_copy);
		//add two videos together. might scrap this
		//idea because it doesnt make much sense.
		videos operator + (const videos& to_copy);
		void display(ostream& out) const;

		//for writing and reading this classes data to and from a file
		void write(ostream& out);
		void read(istream& in);
	
	
	private:

		//in this case the description is a video description
		my_string video_description;

		//time variables for changing the duration:
		int hour;
		int min;
		int sec;
};

class websites: public node {

	public:
		//website default constructor
		websites();
		//website copy constructor
		websites(const websites& to_copy);
		//change the URL of a video
		void change_description();
		//when this function is run, the video will be bookmarked.
		//might be commented out because it will take extra time to 
		//make it work in main
		void bookmark();
		//the ostream function calls this function to display data
		//belonging to this class
		void display(ostream& out) const;
	
		//output all data relating to a website	
		friend ostream& operator << (ostream& out, const websites& to_display);
		//take in data from user relating to a website
		friend istream& operator >> (istream& in, websites& to_input);
		//insert data used by istream function
		void insert(istream& in);
		/*
		//These comparison functions don't make sense here:
		bool operator > (const websites& to_compare);	
		bool operator < (const websites& to_compare);
		bool operator >= (const websites& to_compare);
		bool operator <= (const websites& to_compare);
		bool operator == (const websites& to_compare);
		bool operator != (const websites& to_compare);
		*/

		//set one website to another
		websites& operator = (const websites& to_copy);
		//for reading and writing this classes data to and from a file
		void read(istream& in);
		void write(ostream& out);
	
	private:
		//will change from false to true when bookmark function is run
		bool bookmarked;

		//in this case the description is a URL
		my_string url;
};


class meetings: public node {

	public:
		//meeting class constructor
		meetings();
		//meeting class copy constructor
		meetings(const meetings& to_copy);
		//change the speaker of a meeting
		void change_description();
	
		//ostream operator for displayal of meeting data	
		friend ostream& operator << (ostream& out, const meetings& to_display);	
		/*
		//These comparison operators don't really make sense here
		bool operator > (const meetings& to_compare);
		bool operator < (const meetings& to_compare);
		bool operator >= (const meetings& to_compare);
		bool operator <= (const meetings& to_compare);
		bool operator == (const meetings& to_compare);
		bool operator != (const meetings& to_compare);
		*/

		//set one meeting to another
		meetings& operator = (const meetings& to_copy);
		void display(ostream& out) const;
	
		//for writing and reading this classes data to and from a file	
		void read(istream& in);
		void write(ostream& out);

	private:

		//in this case, the description is a speaker
		my_string speaker;
};


class manager_BST {

	public: 
		//default constructor for the BST
		manager_BST();
		//copy constructor for the BST
		manager_BST(const manager_BST& a_manager);
		//set one element in the BST to another
		manager_BST& operator = (const manager_BST& src);
		manager_BST& operator += (node*& to_add);
		
		//manager destructor for root data that calls delete tree
		~manager_BST();

		//ostream function to display the BST
		friend ostream& operator << (ostream& out, manager_BST& to_display);
		//public retrieval function to find a specific element
		//of the BST via name
		remote_info* retrieve_info(const my_string& to_retrieve);
		remote_info* retrieve_info(int priority_check);
		//remove a specific element of the BST based on name
		void remove_info(const my_string& to_remove);
		//add a specific element to the BST based on name
		void add_info(node*& to_add);
	
		//for writing and reading this classes data to and from a file (a root)	
		void write(ostream& out);		
		void read(istream& in);


	private:
		//root pointer of the BST
		node* root;

		//private add function for the BST to add based on name
		void add_info(node*& root, node*& to_add);
		//private remove function for the BST to remove based on name
		void remove_info(node*& root, const my_string& to_remove);
		//helper function for removing in the case where the node to 	
		//remove has two children, in which we need to find the inorder
		//successor
		node*& min_of_right_tree(node*& root);
	
		//private helper function to find a certain element of the BST
		//so it may be edited in main	
		remote_info* retrieve_info(node*& root, const my_string& to_retrieve);
		remote_info* retrieve_info(node*& root, int priority_check);
		//display the tree, called by ostream
		void display_tree(ostream& out, node* root);
		//copy the nodes of the tree
		void copy_tree(node*& dest, node* src);
		//delete every element of the tree called by destructor
		void delete_all(node*& root);

		//write root to a file
		void write(node*& root, ostream& out);
		

};

#endif




