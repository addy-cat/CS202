/*
File: Math.java

What is in this file? :
This file includes the implementation of the derived class Math. Included in this file is the functions specific to the
Math topic: the type of calculator the student must need for a math subject, and the prerequisite math knowledge
they must have to learn a subject. The functions are dynamically bound but have unique data members in this file.
This function is derived from "Tutor_topic.java" which acts as a hub. Functions included are a display function
that directly displays the description and needed materials for this class along with calling the base classes
general display function. In this class Math, a description is prerequisite math knowledge, and a material is a
calculator type.
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Scanner;

public class Math extends list_node {

    //string data members for the math class
    protected String calculator_type;
    protected String prereqs;

    //constructor calls the base classes constructor
    public Math() {
        super();
    }

    //copy constructor for the two strings
    public Math(Math a_math) {
        super(a_math);
        calculator_type = a_math.calculator_type;
        prereqs = a_math.prereqs;
    }

    //display function that calls the indirect base classes display and also the local math data members
    public void display() {

        //call the base classes display function to display base class data members
        super.display();

        //these are the two data members for this math class:
        if (calculator_type != null) {
            System.out.println("Calculator needed is: " + calculator_type);
        } else
            System.out.println("No calculator type set yet.");

        if (prereqs != null) {
            System.out.println("Prerequisites needed are: " + prereqs);
        } else
            System.out.println("No prerequisites set yet.");

    }

    //change the materials for this math class that's data member is a calculator string
    public int change_materials() {

        Scanner input = new Scanner(System.in);
        System.out.println("What is the required calculator for this subject?:");
        calculator_type = input.nextLine();

        if (calculator_type != null) {
            System.out.println("Calculator set to: " + calculator_type);
            return 0;
        } else
            //in main remember to handle this case
            return -1;
    }

    //change the description for this class thats data member is a prerequisite String
    public int change_description() {

        Scanner input = new Scanner(System.in);
        System.out.println("What prior knowledge should this person know to learn this subject?:");
        prereqs = input.nextLine();

        if (prereqs != null) {
            System.out.println("Prerequisites set to: " + prereqs);
            return 0;
        } else
            //in main remember to handle this case
            return -1;
    }

    //write function for this classes data members calculator type and prerequisites
    public void write (PrintStream to_write) {
        //need to also call the base classes data members for this class so that is also written to the file
        super.write(to_write);
        //this classes data members:
        to_write.println(calculator_type);
        to_write.println(prereqs);
    }

    //read function for this class to read its data members to a textfile
    public void read(BufferedReader to_read) throws IOException, NumberFormatException {

        //need to also read in the data members from the base class for this class
        super.read(to_read);
        //read in this classes 2 data members
        calculator_type = to_read.readLine();
        prereqs = to_read.readLine();

    }

}
