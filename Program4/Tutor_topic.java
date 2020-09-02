/*
File: Tutor_topic.java

What is in this file? :
This file contains the base classes implementation. The base class acts as a "hub" of the three different types of
tutoring topics. The topics (derived classes) include the topics mathematics, chemistry, and computer science.
This class includes the functionality that all 3 topics will use, including information such as a subject,
a tutors name and contact info, needed materials, descriptions, and the price of a tutoring session. The function
"change_tutor_info" is a single function that includes most of this functionality. This class also includes a display
function that displays the data members that all derived classes use except the dynamically bounded data specific to a
class.
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintStream;
import java.util.InputMismatchException;
import java.util.Scanner;

public abstract class Tutor_topic {

    //string data members for the tutor information
    protected String subject;
    protected String name;
    protected String contact;
    protected float price;

    //default constructor for price
    public Tutor_topic() {
        price = 0;
    }

    //copy constructor for data members
    public Tutor_topic(Tutor_topic a_topic) {
        subject = a_topic.subject;
        name = a_topic.name;
        contact = a_topic.contact;
        price = a_topic.price;
    }

    //these functions are defined here but not written, they are dynamically bound
    public int change_materials() {
        return 0;
    }
    public int change_description() {
        return 0;
    }


    //function to edit the data members associated with a tutor. Data members to edit include the tutors name
    //and contact information, the subject a tutor is tutoring, and a price for the tutoring service.
    public void change_tutor_info() {

        //string variable for determining if the user wants to change a certain data member or not
        String to_change = new String();
        //too allow for user input
        Scanner input = new Scanner(System.in);

        //Prompt for changing a subject. If the user selects yes then they may change it.
        System.out.println("Do you want to change a subject? Enter y/n: ");
        to_change = input.nextLine();
        if (to_change.equals("y")) {
            System.out.println("What subject are you tutoring? :");
            subject = input.nextLine();
            System.out.println("Subject set to: " + subject);
        } else {
            System.out.println("You selected 'n', no subject added.");
            subject = "no subject.";
        }

        //Prompt for changing a contact info for a tutor. If the user selects yes then they may change it.
        System.out.println("Do you want to change a tutors contact info? Enter y/n: ");
        to_change = input.nextLine();
        if (to_change.equals("y")) {
            System.out.println("What is your contact information? :");
            contact = input.nextLine();
            System.out.println("Contact set to: " + contact);
        }

        //Prompt for if user wants to change the tutors name. If yes then they may change it
        System.out.println("Do you want to change a tutors name? Enter y/n: ");
        to_change = input.nextLine();
        if (to_change.equals("y")) {
            System.out.println("What is your name? :");
            name = input.nextLine();
            System.out.println("Name set to: " + name);
        } else {
            System.out.println("You selected 'n', no name added.");
            name = "No name.";
        }

        //Prompt for if the user wants to change the price of a tutoring service. If yes then they may change it.
        System.out.println("Do you want to change the price for a service? Enter y/n: ");
        to_change = input.nextLine();
        if (to_change.equals("y")) {
            System.out.println("What is the rate of this session? :");
            try {
                price = input.nextFloat();
            } catch (InputMismatchException e) {
                System.out.println("Please only enter numbers for the price. Default price 0.00 added.");
            }

            System.out.println("Price set to: " + price);
        }

    }

    //display the subject, tutor name and contact info, and price of a session
    public void display() {

        if (name != null) {
            System.out.println("Tutors name is: " + name);
        } else
            System.out.println("No name set yet.");

        if (contact != null) {
            System.out.println("Tutors contact info: " + contact);
        } else
            System.out.println("No contact info yet.");

        if (subject != null) {
            System.out.println("Subject of the session: " + subject);
        } else
            System.out.println("No subject set yet");

        if (price != -1) {
            System.out.println("Price is: " + price);
        } else
            System.out.println("No price set yet.");

    }

    //this function is used in the class tree_manager for adding to the tree
    public int compare_subject(Tutor_topic to_compare) {

            if (to_compare.subject.compareTo(subject) == 0) {
                return 0;
            } else if (subject.compareTo(to_compare.subject) > 0) {
                return 1;
            } else  {
                return -1;
            }
    }

    //write function for outputting the data members of this class to a external text file
    public void write(PrintStream to_write) {
        to_write.println(subject);
        to_write.println(name);
        to_write.println(contact);
        to_write.println(price);
    }

    //read function for this class that reads its data members to a file
    public void read(BufferedReader to_read) throws IOException, NumberFormatException {
        //read the strings to the file
      subject = to_read.readLine();
      name = to_read.readLine();
      contact = to_read.readLine();
      //for the float price we need to check for valid input when reading in
      try {
          price = Float.parseFloat(to_read.readLine());
      } catch(NumberFormatException e) {
          System.out.println("Please enter a valid number");
      }

    }
}

