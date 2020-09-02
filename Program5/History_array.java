/*
File: History_array.java

What is in this file? :
This file contains the implementation of the array of linear linked lists class. This classes purpose is to
add a search/edit history for the program, allowing tutors to view their edit history, and allowing students to
view their search history. Functions include three add functions (one for each derived class topic type) that adds
that topic to the array based on their index position. Also included are three display functions for each derived
class, that when called in main, display just that topics recent history also based on index position in the table
(displays the last TWO searches of that topic). The lists in this data structure are the math list, chemistry list,
and computer science list. Lastly, this file contains a read and write function that saves and opens the data from
the linked lists into/ from a textfile. There are multiple textfiles (one for each array (2, student and tutor)).
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintStream;

public class History_array {

    //there are three linked lists in this data structure, so the table size is three:
    private int TABLE_SIZE = 3;

    //These are the max sizes of the three types of lists in the array:

    //this is the math type list
    private int MATH_SIZE;
    //this is the chemistry type list
    private int CHEM_SIZE;
    //this is the computer science type list
    private int CS_SIZE;

    //create the array of linked lists with the type list_node
    private list_node [] table;

    //class default constructor that initializes the list sizes and sets each index to null
    public History_array() {

        //the table is a array of linked lists
        table = new list_node[TABLE_SIZE];

        //each list's default size is zero:
        MATH_SIZE = 0;
        CHEM_SIZE = 0;
        CS_SIZE = 0;

        //every element of the array is set to null in the beginning
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = null;
        }
    }

    //class copy constructor because we will be making multiple arrays (two)
    public History_array(History_array a_history) {

        //set all to null initially then copy
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = null;
            table[i] = a_history.table[i];
        }
    }

    //this add function adds a math topic to the front of the math list (math's index is 0)
    public void add_math(list_node to_add) {
        //if the list is empty then we can just add directly to the beginning
        //of the array at table[0]:
        if(table[0] == null) {
            table[0] = to_add;
        } else {
            //if the list is not empty then we have to set what we are adding's
            //next to table[0] because table[0] has the first thing added
            to_add.connect_next(table[0]);
            table[0] = to_add;
        }
    }

    //this add function adds a chemistry topic to the front of the chemistry list (chemistry's index is 1)
    public void add_chemistry(list_node to_add) {
        //if the list is empty then we can just add directly to the beginning
        //of the array at table[1]:
        if(table[1] == null) {
            table[1] = to_add;
        } else {
            //if the list is not empty then we have to set what we are adding's
            //next to table[1] because table[1] has the first thing added
            to_add.connect_next(table[1]);
            table[1] = to_add;
        }
    }

    //this add function adds a CS topic to the front of the CS list (CS's index is 2)
    public void add_CS(list_node to_add) {
        //if the list is empty then we can just add directly to the beginning
        //of the array at table[2]:
        if(table[2] == null) {
            table[2] = to_add;
        } else {
            //if the list is not empty then we have to set what we are adding's
            //next to table[2] because table[2] has the first thing added
            to_add.connect_next(table[2]);
            table[2] = to_add;
        }
    }

    //Display the most recent math tutor history (the last two)
    public void display_math_history () {

        //if there is nothing in the zero index then there is no math history
        if (table[0] == null) {
            System.out.println("There is no math tutor search history.");
        } else {
            System.out.println("You have recently searched for: ");
            System.out.println();
            //display whatever is in head for starters
            table[0].display();
            System.out.println();
            //and if the next reference isnt null then also print the next math tutor info
            if (table[0].go_next() != null) {
                table[0].go_next().display();

            }
        }
    }
    //Display the most recent chem tutor history (the last two)
    public void display_chemistry_history () {

        //if there is nothing in the one index then there is no chem history
        if (table[1] == null) {
            System.out.println("There is no chemistry tutor search history.");
        } else {
            System.out.println("You have recently searched for: ");
            System.out.println();
            //display whatever is in head for starters
            table[1].display();
            System.out.println();
            //and if the next reference isnt null then also print the next chem tutor info
            if (table[1].go_next() != null) {
                table[1].go_next().display();

            }
        }
    }
    //Display the most recent CS tutor history (the last two)
    public void display_CS_history () {

        //if there is nothing in the one index then there is no CS history
        if (table[2] == null) {
            System.out.println("There is no computer science tutor search history.");
        } else {
            System.out.println("You have recently searched for: ");
            System.out.println();
            //display whatever is in head for starters
            table[2].display();
            System.out.println();
            //and if the next reference isnt null then also print the next CS tutor info
            if (table[2].go_next() != null) {
                table[2].go_next().display();

            }
        }
    }


    //public non recursive write function that calls the recursive write function for each of the three indeces in the table
    public void write(PrintStream to_write) {

        //math has the zero index, write it via the function below
        write(table[0], to_write);
        to_write.println("~~~~~~~~~~~~~~");
        //chemistry has the number one index, write it via the function below
        write(table[1], to_write);
        to_write.println("~~~~~~~~~~~~~~");
        //CS has the second index, write it via the function below
        write(table[2], to_write);
        to_write.println("~~~~~~~~~~~~~~");

    }

    //write out data to a text file using the head of the list
    private void write(list_node head, PrintStream to_write) {
        //if head is not empty then we must have something to write to a file:
        if (head != null) {
            //if the data we are adding to the file is an instance of the Math derived class:
            if (head instanceof Math) {
                //then we have an identifier in the textfile that shows the data belongs to a math class
                to_write.println("M");
                //if the data we are adding to the file is an instance of the Chemistry derived class:
            } else if (head instanceof Chemistry) {
                //then we have an identifier in the textfile that shows the data belongs to a chemistry class
                to_write.println("C");
                //if the data we are adding to the file is an instance of the CompSci derived class:
            } else if (head instanceof Computer_science) {
                //then we have an identifier in the textfile that shows the data belongs to the CS class
                to_write.println("CS");
            }

            //write whatever is in head to the file
            head.write(to_write);
            //then recurse to do this again
            write(head.go_next(), to_write);
        }
    }

    //read function for reading in data from the file
    public void read(BufferedReader to_read) throws IOException {

        String in;
        in = to_read.readLine();

        if (in != null) {
            while (in.equals("~~~~~~~~~~~~~~") != true) {
                //create a node that has the data to be read in it
                list_node to_add = null;

                if (in.equals("M")) {
                    to_add = new Math();
                } else if (in.equals("C")) {
                    to_add = new Chemistry();
                } else if (in.equals("CS")) {
                    to_add = new Computer_science();
                }

                if (to_add != null) {
                    to_add.read(to_read);
                    add_math(to_add);
                    //recurse
                    in = to_read.readLine();
                }
            }

            in = to_read.readLine();

            while (in.equals("~~~~~~~~~~~~~~") != true) {
                //create a node that has the data to be read in it
                list_node to_add = null;

                if (in.equals("M")) {
                    to_add = new Math();
                } else if (in.equals("C")) {
                    to_add = new Chemistry();
                } else if (in.equals("CS")) {
                    to_add = new Computer_science();
                }

                if (to_add != null) {
                    to_add.read(to_read);
                    add_chemistry(to_add);
                    //recurse
                    in = to_read.readLine();
                }
            }

            in = to_read.readLine();

            while (in.equals("~~~~~~~~~~~~~~") != true) {
                //create a node that has the data to be read in it
                list_node to_add = null;

                if (in.equals("M")) {
                    to_add = new Math();
                } else if (in.equals("C")) {
                    to_add = new Chemistry();
                } else if (in.equals("CS")) {
                    to_add = new Computer_science();
                }

                if (to_add != null) {
                    to_add.read(to_read);
                    add_CS(to_add);
                    //recurse
                    in = to_read.readLine();
                }
            }
        }
    }
}
