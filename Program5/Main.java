/*
Program 5
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

Update for program 5:
This program now has a search/ edit history functionality as well. Via the use of an array of linked lists,
when you run the program as a student, you can view your recent tutor SEARCH history for a certain topic. If you
run the program as a tutor, you can view the recent EDIT history for a certain topic. Data is added into
the array of linked lists when: the student triggers the retrieve function via the search option, and when the tutor
triggers the retrieve function via their edit topic option. Basically a copy of the data they have retrieved is copied into
the array of linked list data structure "automatically" and the user does not have to specifically add these things to the history themselves.
 */

//for reading and writing to a textfile:
import java.io.*;

import java.util.InputMismatchException;
import java.util.Scanner;

//This is the first function to run that includes the most general menu
public class Main {

    //throws exception for file io
    public static void main(String[] args) throws IOException {

        //for user input
        Scanner input = new Scanner(System.in);

        //initial output describing the service
        System.out.println("Welcome to the online tutor posting service!");
        System.out.println("Here, you can sign up to tutor a subject, or you can view the current tutor listings as a student!");
        System.out.println();

        //for file io:
        BufferedReader in;
        in = new BufferedReader(new FileReader("in.txt"));

        //Make an object of the tree_manager class to run its tree functions:
        tree_manager a_manager = new tree_manager();
        //start recording whatever the user changes/ adds
        a_manager.read(in);

        //make a object of the history_array class (2):

        //This object is for the students search history:
        History_array student_history = new History_array();
        BufferedReader student_in;
        student_in = new BufferedReader(new FileReader("student_history.txt"));
        student_history.read(student_in);

        //This object is for the tutors edit history:
        History_array tutor_history = new History_array();
        BufferedReader tutor_in;
        tutor_in = new BufferedReader(new FileReader("tutor_history.txt"));
        tutor_history.read(tutor_in);

        //variable for the generic menu below
        int gen_option = 0;

        //general menu, first to run
        while (gen_option != 3) {

            System.out.println("Are you a student or a tutor?: ");

            System.out.println("1) I am a tutor");
            System.out.println("2) I am a student");
            System.out.println("3) Quit");
            System.out.println();

            //check for user input error
            try {
                gen_option = input.nextInt();
            } catch (InputMismatchException e) {
                gen_option = 10;
            }

            switch (gen_option) {
                case 1:
                    //in this case, the user is a tutor and the tutor specific function will run with the tutor menu
                    tutor_menu(tutor_history, a_manager);
                    break;
                case 2:
                    //in this case, the user is a student, and the student specific function will run with the student menu
                    student_menu(student_history, a_manager);
                    break;
                case 3:
                    System.out.println("Goodbye..");

                    //in this case we quit and write whatever has been changed/ added to the external textfile in.txt
                    PrintStream out;
                    out = new PrintStream(new FileOutputStream("in.txt"));
                    a_manager.write(out);
                    out.flush();
                    //close the file
                    out.close();

                    //in this case we quit and write whatever searched for to the external textfile student_history.txt
                    PrintStream out_student;
                    out_student = new PrintStream(new FileOutputStream("student_history.txt"));
                    student_history.write(out_student);
                    out_student.flush();
                    //close the file
                    out_student.close();

                    //in this case we quit and write whatever we edited to the external textfile tutor_history.txt
                    PrintStream out_tutor;
                    out_tutor = new PrintStream(new FileOutputStream("tutor_history.txt"));
                    tutor_history.write(out_tutor);
                    out_tutor.flush();
                    //close the file
                    out_tutor.close();

                    break;
                default:
                    //default if the user enters something invalid
                    System.out.println("Enter a valid option 1-3");
            }


        }
    }

    //this is the function that runs if the user has selected that they are a student
    static void student_menu(History_array a_history, tree_manager a_manager) {

        //for user input:
        Scanner input = new Scanner(System.in);

        //variable for the student menu below
        int stu_option = 0;

        //temp for searching for a subject for case 5
        String temp;

        //student menu
        while (stu_option != 7) {
            System.out.println();

            System.out.println("Welcome student!");
            System.out.println("Select an option from below:");
            System.out.println();
            System.out.println("1) View all current tutor postings");
            System.out.println("2) View all mathematics tutor postings");
            System.out.println("3) View all chemistry tutor postings");
            System.out.println("4) View all computer science tutor postings");
            //this next option will allow the student to search for a service based on subject of a topic
            System.out.println("5) Search for a specific tutor posting by subject");
            System.out.println("6) View the last two student search history for a topic");
            System.out.println("7) Return to previous menu");
            System.out.println();

            //check for user input error
            try {
                stu_option = input.nextInt();
            } catch (InputMismatchException e) {
                stu_option = 10;
            }

            switch (stu_option) {
                case 1:
                    //in this case, every tutor posting is displayed
                    a_manager.display();
                    break;
                case 2:
                    //in this case, only the tutor postings of the math subject are posted
                    a_manager.display_math();
                    break;
                case 3:
                    //in this case, only the tutor postings of the chemistry subject are posted
                    a_manager.display_chemistry();
                    break;
                case 4:
                    //in this case, only the CS tutor postings are displayed
                    a_manager.display_CS();
                    break;
                case 5: {
                    //in this case we will search for a subject and display its associated tutor data:

                    //make a list_node object so we can alter linked list
                    list_node to_search;
                    System.out.println("Enter a subject to search for: ");
                    input.nextLine();
                    //temp is for this user input to compare using the retrieve function
                    temp = input.nextLine();

                    //setting to_search to whatever that match is
                    to_search = a_manager.retrieve_subject(temp);
                    //checking if the to_search is null (has no match)
                    if (to_search != null) {
                        System.out.println();
                        System.out.println("That subject exists!");
                        System.out.println("Here is that subjects information: ");
                        System.out.println();
                        //correct classes display function
                        to_search.display();
                    } else {
                        //in this case, there was no match
                        System.out.println("No tutor is tutoring that subject..");
                        System.out.println("Nothing added to search history.");
                    }

                    //After the retrieve function is run, then what the user has just done is recorded and added to the history:

                    //here, we need to check to see if the subject they have entered is a math, chemistry, or CS topic.
                    //Using the instanceof keyword we will check for this. If it belongs to that topic, then what they
                    //have entered is paired with that subjects associated tutor data and is added to the search history

                    list_node new_node = null;

                    if (to_search instanceof Math) {
                        new_node = new Math((Math) to_search);
                        a_history.add_math(new_node);
                        System.out.println("Search added to history!");
                    } else if (to_search instanceof Chemistry) {
                        new_node = new Chemistry((Chemistry) to_search);
                        a_history.add_chemistry(new_node);
                        System.out.println("Search added to history!");
                    } else if (to_search instanceof Computer_science) {
                        new_node = new Computer_science((Computer_science) to_search);
                        a_history.add_CS(new_node);
                        System.out.println("Search added to history!");
                    }

                }
                break;
                case 6:
                    //in this case, we want to view the recent search history for a certain specific topic.
                    //The function "history_display" is run that contains a separate menu so the user can choose
                    //if they want to display the math, chemistry, or CS history.
                    history_display(a_history);
                    break;
                case 7:
                    //in this case, we want to return to the first menu run
                    System.out.println("Returning to previous menu...");
                    break;
                default:
                    //default for user input error
                    System.out.println("Enter a valid option 1-6");
            }

        }
    }


    static void tutor_menu(History_array a_history, tree_manager a_manager) {

            //for user input:
            Scanner input = new Scanner(System.in);

            //temp for edit case below
            String temp;

            //option int for menu selection
            int option = 0;

        //tutors menu
        while (option != 5) {
            System.out.println();

            System.out.println("Welcome tutor!");
            System.out.println("Select an option from below:");

            System.out.println("1) View all current tutor postings");
            System.out.println("2) Add a tutor posting");
            System.out.println("3) Edit a tutor posting");
            System.out.println("4) View the last two tutor edit history for a certain topic");
            System.out.println("5) Return to previous menu");
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
                    //in this case we will display the tree and all its entries
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
                    } else {
                        //in this case, there was no match
                        System.out.println("No tutor is tutoring that subject..");
                        System.out.println("Nothing added to search history.");
                    }

                    //After the retrieve function is run, then what the user has just done is recorded and added to the history:

                    //here, we need to check to see if the name they have entered is a math, chemistry, or CS topic.
                    //Using the instanceof keyword we will check for this. If it belongs to that topic, then what they
                    //have entered is paired with that names associated tutor data and is added to the edit history:
                    list_node new_node = null;

                    if (to_edit instanceof Math) {
                        new_node = new Math((Math) to_edit);
                        a_history.add_math(new_node);
                        System.out.println("Edit added to history!");
                    } else if (to_edit instanceof Chemistry) {
                        new_node = new Chemistry((Chemistry) to_edit);
                        a_history.add_chemistry(new_node);
                        System.out.println("Edit added to history!");
                    } else if (to_edit instanceof Computer_science) {
                        new_node = new Computer_science((Computer_science) to_edit);
                        a_history.add_CS(new_node);
                        System.out.println("Edit added to history!");
                    }
                }
                    break;
                case 4:
                    //in this case, we want to display the edit history for a certain topic. The function
                    //"history_display" is run so the user can select a certain topic that they want to view the
                    //edit history for:
                        history_display(a_history);
                    break;
                case 5:
                    //in this case we want to return to the menu first run
                    System.out.println("Returning to previous menu...");
                    break;
                default:
                    //default for checking for user input error
                    System.out.println("Enter a valid option 1-4");
            }
        }
    }

    //this function is run when either a tutor or a student opts to view the recent search/ edit history
    //for a certain topic. There are two a_history's: a student history and a tutor history. At this point,
    //the correct history type will be passed into this function based on which function ran from the
    // first menu of the program. This means that there are two arrays of linked lists possible to make in this program.
    static void history_display(History_array a_history) {

        //for user input
        Scanner input = new Scanner(System.in);

        //option for menu below
        int history_option = 0;

        //add menu for choosing a derived type to add
        System.out.println("Which topics recent history would you like to view? ");
        System.out.println("1) Mathematics");
        System.out.println("2) Chemistry");
        System.out.println("3) Computer Science");
        System.out.println();

        //check for user input error
        try {
            history_option = input.nextInt();
        } catch (InputMismatchException e) {
            history_option = 10;
        }

        switch(history_option) {
            case 1:
                //in this case, we want to view the recent 2 math histories
                a_history.display_math_history();
                break;
            case 2:
                //in this case we want to view the recent 2 chemistry histories
                a_history.display_chemistry_history();
                break;
            case 3:
                //in this case, we want to view the recent 2 CS histories
                a_history.display_CS_history();
                break;
            default:
                //default case for user input error
                System.out.println("Please select a valid option 1-3...");
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

            //these change functions will run automatically for all derived types above:

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
