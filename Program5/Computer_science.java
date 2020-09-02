/*
File: Computer_science.java

What is in this file? :
This file includes the implementation of the derived class Computer_science. Included in this file is the functions specific to the
CS topic: the type of software the student must need for a CS subject, and the prerequisite programming language
they must know to learn a subject. The functions are dynamically bound but have unique data members in this file.
This function is derived from "Tutor_topic.java" which acts as a hub. Functions included are a display function
that directly displays the description and needed materials for this class along with calling the base classes
general display function. In this class Computer_science, a description is prerequisite programming language knowledge,
and a material is a software type.
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Scanner;

public class Computer_science extends list_node {

    //data members software and language for the materials and description functions
    protected String software;
    protected String language;

    //constructor calls the base classes constructor
    public Computer_science() {
        super();
    }

    //the copy constructor for this class copies its two string data members
    public Computer_science(Computer_science a_computer) {
        super(a_computer);
        software = a_computer.software;
        language = a_computer.language;
    }

    //display function for this class calls the display function of its indirect base class tutor_topic and also
    //displays its own two data members
    public void display() {

        //call the indirect base classes display function to display base class data members
        super.display();

        //display this classes own two data members software and language
        if (software != null) {
            System.out.println("Software needed is: " + software);
        } else
            System.out.println("No software type set yet.");

        if (language != null) {
            System.out.println("Programming language needed is: " + language);
        } else
            System.out.println("No programming language(s) set yet.");

    }

    //change the materials for this class CS which is in the form of a required software
    public int change_materials() {

        Scanner input = new Scanner(System.in);
        System.out.println("What is the required software for this subject?:");
        software = input.nextLine();

        if (software != null) {
            System.out.println("Software needed: " + software);
            return 0;
        } else
            //in main remember to handle this case
            return -1;
    }

    //change the description for this class which is in the form of a programming language
    public int change_description() {

        Scanner input = new Scanner(System.in);
        System.out.println("What programming language(s) should this person know to learn this subject? :");
        language = input.nextLine();

        if (language != null) {
            System.out.println("Programming language set to: " + language);
            return 0;
        } else
            //in main remember to handle this case
            return -1;
    }

    //write function for the CS class that writes data to a file
    public void write (PrintStream to_write) {
        //first we need to also write the data for this class that exists in the base class
        super.write(to_write);
        //then we can add to the textfile the two data members unique to this class
        to_write.println(software);
        to_write.println(language);
    }

    //read function for this class to read its data members to a textfile
    public void read(BufferedReader to_read) throws IOException, NumberFormatException {

        //need to also read in the data members from the base class for this class
        super.read(to_read);
        //read in this classes 2 data members
        software = to_read.readLine();
        language = to_read.readLine();

    }

}
