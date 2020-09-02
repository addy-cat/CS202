/*
File: list_node

What is in this file? :
This file contains the implementation of the class list_node. List_node class is derived from the base class Tutor_topic
and is both a base class and a derived class. This class is responsible for managing the next reference
for the linear linked list. This class is also used to make a head and left and right references in the tree_node class,
where these data members are used to do operations on a linear linked list. This file also includes functions that allow
the String base class data members "subject" and "name" to be compared to one another so that they can be properly
entered into the linked list in the correct positions. These functions are used by the class tree_node in the functions
with the same name which act as wrapper functions. These functions in the tree_node class will return the result so that
the tree_manager class can use that result to determine where to add a node to the tree.

 */

//this class is derived from Tutor_topic and is both a base class and a derived class
public class list_node extends Tutor_topic {


    //the next pointer for the list of type list_node
    protected list_node next;

    //initialize next pointer in constructor
    public list_node() {
        super();
        next = null;
    }

    //set next to null in copy constructor
    public list_node(list_node a_node) {

        next = null;

    }

    //return the next pointer for traversal
    public list_node go_next() {

        return next;
    }

    //connect the next reference to a node
    public void connect_next(list_node connection) {

        next = connection;

    }

    //used for the tree_node classes add function to compare two subjects to see where to add to the tree
    public int compare_subjects(list_node to_compare) {

        //if the subjects are the same
        if (to_compare.subject.compareTo(subject) == 0) {
            return 0;
        //if the subject to compare if greater than subject
        } else if (to_compare.subject.compareTo(subject) > 0) {
            return 1;
        } else
            return -1;
    }


    //compare function that instead takes a string for adding, for the wrapper function of the same name in tree_node
    public int compare_subjects(String to_compare) {
         if(to_compare.compareTo(subject) == 0) {
             return 0;
         } else if (to_compare.compareTo(subject) > 0) {
             return 1;
         } else
             return -1;
    }



    //compare two string names of tutors
    public int compare_tutornames(String to_compare) {
        //if the names match
        if(to_compare.compareTo(name) == 0) {
            return 0;
            //if the name we are comparing is greater
        } else if (to_compare.compareTo(name) > 0) {
            return 1;
        } else
            //no match
            return -1;
    }

    //compare two names of type list_node
    public int compare_tutornames(list_node to_compare) {
        //if its a match
        if (name.compareTo(to_compare.name) == 0) {
            return 0;
            //if the name we are comparing is greater
        } else if (name.compareTo(to_compare.name) > 0) {
            return 1;
        } else
            //no match
            return -1;
    }




}
