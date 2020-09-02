/*
File: Chemistry.java

What is in this file? :
This file includes the implementation of the derived class Chemistry. Included in this file is the functions specific to the
Chemistry topic: the type of supplied the student must need for the chemistry subject, and the precautions
they must take to learn a subject. The functions are dynamically bound but have unique data members in this file.
This function is derived from "Tutor_topic.java" which acts as a hub. Functions included are a display function
that directly displays the description and needed materials for this class along with calling the base classes
general display function. In this class Chemistry, a description is precautions, and a material is necessary laboratory
supplies for a subject.
 */


import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Scanner;

public class Chemistry extends list_node {

    //string data members for this class for the functions description and materials
    protected String supplies;
    protected String precautions;

    //chemistry class constructor that calls the base classes constructor
    public Chemistry() {
        super();
    }

    //the copy constructor for this class copies the supplies and precautions data members
    public Chemistry(Chemistry a_chem) {
        super(a_chem);
        supplies = a_chem.supplies;
        precautions = a_chem.precautions;
    }

    //display the data members from the base class and also this class
    public void display() {

        //call the indirect base classes display function to display base class data members
        super.display();

        //then display also the data members specific to this class
        if (supplies != null) {
            System.out.println("Supplies needed are: " + supplies);
        } else
            System.out.println("No supplies set yet.");

        if (precautions != null) {
            System.out.println("Precautions needed are: " + precautions);
        } else
            System.out.println("No precautions set yet.");

    }

    //change the materials for this class which comes in the form of supplies
    public int change_materials() {

        Scanner input = new Scanner(System.in);
        System.out.println("What is the required supplies the student must have for this subject?:");
        supplies = input.nextLine();

        if (supplies != null) {
            System.out.println("Supplies set to: " + supplies);
            return 0;
        } else
            //in main remember to handle this case
            return -1;
    }

    //change the description for this class which comes in the form of a precaution
    public int change_description() {

        Scanner input = new Scanner(System.in);
        System.out.println("Chemistry can be dangerous, ");
        System.out.println("are there any precautions for this subject?:");
        precautions = input.nextLine();

        if (precautions != null) {
            System.out.println("Precautions set to: " + precautions);
            return 0;
        } else
            //in main remember to handle this case
            return -1;
    }

    //write function that writes data to a textfile
    public void write (PrintStream to_write) {
        //need to first write the base classes data members for this class to the file
        super.write(to_write);
        //then also write this classes unique two data members to the textfile
        to_write.println(supplies);
        to_write.println(precautions);
    }

    //read function for this class to read its data members to a textfile
    public void read(BufferedReader to_read) throws IOException, NumberFormatException {

        //need to also read in the data members from the base class for this class
        super.read(to_read);
        //read in this classes 2 data members
        supplies = to_read.readLine();
        precautions = to_read.readLine();


    }

}