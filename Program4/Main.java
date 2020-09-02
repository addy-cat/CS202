/*
Program 4
Student name: Adriana Swantz
Professor name: Karla Fant
CS202
Spring 2020
File: Main.java

What is this program about? :
This program simulates an online tutoring service, where tutors can post their services online. The functionality
resembles an online message board. Tutors will be prompted to choose a topic they feel they can tutor. Topics are
mathematics, chemistry, and computer science. Along with this, the specific subject of a topic will be prompted for,
and this subject is used to drive a lot of the program when it comes to the Red Black tree data structure that
holds the linear linked list of all the data associated with a tutor. Subjects are supposed to be very specific to
the topic that is chosen initially, for example, if a tutor chooses to tutor math, subjects could be "integrals", for
chemistry a subject could be "acids and bases", and for comp. sci. a subject could be "dynamic binding in C++". In this way,
the red black tree can store many different types of information in its nodes and not just iterations of "math"
"chemistry" and "comp sci". The structure of this program implies that the tutor will be using it and not a student.
As for data structures, a red black tree will be used, where each of its elements is a linear linked list. This LLL
includes all of the data associated with a tutor, such as name and subject. The R/B tree will be added to via a subject,
and will be retrieved from via a tutors name.

What is in this file? :
This file is the driver of the program. An initial menu is included for the user (a tutor) to select if they want to add
a tutor posting, to edit one that exists, and to display all current postings. If the user opts to add a tutor posting,
then a separate add function called "add_tutor" also located in this file will run that will actually create that tutor
instance. In the add function, the user will be able to select which topic they would like to tutor (chemistry, math,
or computer science), and an instance of that derived class is created. From there the functions that prompt for
data for that topic are then run automatically as all topics have the same data. As for the dynamically bound functions,
these functions are chosen correctly because of the use of a base class pointer. Once the user selects the topic they
want to tutor, the program will know which derived class needs to be pointed to.
 */

//for reading and writing to a textfile:
import java.io.*;

import java.util.InputMismatchException;
import java.util.Scanner;

public class Main {

    //throws exception for file io
    public static void main(String[] args) throws IOException {

        //for file io:
        BufferedReader in;
        in = new BufferedReader(new FileReader("in.txt"));

        //for user input:
        Scanner input = new Scanner(System.in);
        //Make an object of the tree_manager class to run its tree functions:
        tree_manager a_manager = new tree_manager();
        a_manager.read(in);
        //temp for edit case below
        String temp;
        //option int for menu selection
        int option = 0;

        //general menu
        while (option != 4) {
            System.out.println();

            System.out.println("Welcome to the tutoring job posting service!");
            System.out.println("Select an option from below:");

            System.out.println("1) Display all current tutor postings");
            System.out.println("2) Add a tutor posting");
            System.out.println("3) Edit a tutor posting");
            System.out.println("4) Quit");
            System.out.println();

            //check for user input error
            try {
                option = input.nextInt();
            } catch (InputMismatchException e) {
                option = 10;
            }

            //switch statement for cases
            switch (option) {
                case 1:
                    //in this case we will display the tree
                    a_manager.display();
                    break;
                case 2:
                    //call outside function to add a tutor
                    add_tutor(a_manager);
                    break;
                case 3: {

                    //in this case we will change the data members data in the linked list:

                    //make a list_node object so we can alter linked list
                    list_node to_edit;
                    System.out.println("Enter the tutors name to edit their posting: ");
                    input.nextLine();
                    //temp is for this user input to compare using the retrieve function
                    temp = input.nextLine();

                    //setting to_edit to whatever that match is
                    to_edit = a_manager.retrieve(temp);
                    //checking is the to_edit is null (has no match)
                    if (to_edit != null) {
                        //base classes change functions
                        to_edit.change_tutor_info();
                        //dynamically bound change functions for derived classes
                        to_edit.change_description();
                        to_edit.change_materials();
                    } else
                        //in this case, there was no match
                        System.out.println("No tutor is tutoring that subject..");
                }
                    break;
                case 4:
                    //in this case we quit
                    System.out.println("Quitting..");
                    PrintStream out;
                    out = new PrintStream(new FileOutputStream("in.txt"));
                    a_manager.write(out);
                    out.flush();
                    out.close();
                    break;
                default:
                    System.out.println("Enter a valid option 1-4");
            }
        }
    }

        //add function for if user selects to add a tutor above:
        static void add_tutor(tree_manager a_manager) {

            //for user input
            Scanner input = new Scanner(System.in);
            //base class reference for dynamic binding
            list_node new_tutor = null;
            //option for menu below
            int option = 0;

            //add menu for choosing a derived type to add
            System.out.println("Which topic are you tutoring? ");
            System.out.println("1) Mathematics");
            System.out.println("2) Chemistry");
            System.out.println("3) Computer Science");
            System.out.println();


            //check for user input error
            try {
                option = input.nextInt();
            } catch (InputMismatchException e) {
                option = 10;
            }


            //switch statement for cases
            switch(option) {
                case 1:
                    //in this case we make a new derived type Math using base class ref
                    new_tutor = new Math();
                    break;
                case 2:
                    //in this case we make a new derived type Chemistry using base class ref
                    new_tutor = new Chemistry();
                    break;
                case 3:
                    //in this case we make a new derived type CompSci using base class ref
                    new_tutor = new Computer_science();
                    break;
                default:
                    System.out.println("Select an option 1-3..");
            }

            //these change functions will run automatically for all derved types above:

            //this change function calls the base classes change function for common data members
            new_tutor.change_tutor_info();
            //this change function calls the dynamically bound description function to change derived class specific data member
            new_tutor.change_description();
            //this change function calls the dynamically bound materials function to change derived class specific data member
            new_tutor.change_materials();

            //adds a new tutor
            a_manager.add(new_tutor);

        }

    }
