/*
File: tree_node

What is in this file? :
This file contains the implementation of the class tree_node. The functions in this file manage the parent, left and right
references, and also the head reference. Functions in this file manage a linear linked list. Functions include a display, add,
and retrieve. The remove function is never used. FUnctions also include connection functions for the right, left and
parent references, and functions that return the left and right references. There are also color data members for the
red black tree used in the class tree_manager. There are also wrapper functions that use the returned value from the same
titles functions in the list_node class that are then used in the tree_manager class when it comes to determining where
to add an element to the red black tree.
 */

//for write function
import java.io.PrintStream;

public class tree_node {

    //red black tree data members left, right, and parent
   private tree_node left;
   private tree_node right;
   private tree_node parent;

   //head node of type list_node for linked list functions
   private list_node head;
   //enum name Color object for red black tree colors
   private Color color;

    //tree_node class constructor for initializing the parent, left and right references for the tree
    public tree_node() {
        left = null;
        right = null;
        parent = null;
        //color object is red
        color = Color.Red;
    }

    //copy constructor for the members of the tree when we make another
    public tree_node(list_node to_copy) {
        head = to_copy;
        left = null;
        right = null;
        parent = null;
        color = Color.Red;
    }

    //set the color to red
    public void set_color(Color color) {
        this.color = color;
    }

    //return the color
    public Color get_color() {
        return color;
    }

    //copy constructor for the tree_node data members, setting the left, right and parent to null
    public tree_node(tree_node a_node) {

        left = null;
        right = null;
        parent = null;
    }

    //return the left reference
    public tree_node go_left() {
        return left;
    }

    //return the right reference
    public tree_node go_right() {
        return right;
    }

    //return the parent rference
    public tree_node go_parent() {
        return parent;
    }

    //connect the right reference to a node
    public void connect_right(tree_node connection) {
        right = connection;
    }

    //connect the left reference to a node
    public void connect_left(tree_node connection) {
        left = connection;
    }

    //connect the parent refernce to a node
    public void connect_parent(tree_node connection) {
        parent = connection;
    }

    //display the linked list public function that calls the recursive function
    public void display() {

        if (head != null)
            display(head);
        else
            System.out.println("Nothing to display yet.");

        System.out.println("----------------------------------------------");
    }

    //private recursive display function that recursively displays the head
    private void display(list_node head) {

        if (head != null) {
            //display the info in head
            head.display();
            //then recurse
            display(head.go_next());
        }
    }

    //display the linked list public function that calls the recursive function
    public void display_math() {

        if (head != null)
            display_math(head);
        else
            System.out.println("No math topics to display yet.");

    }

    //private recursive display function that recursively displays the head for math topics
    private void display_math(list_node head) {

        if (head != null) {
            if (head instanceof Math) {
                //display the info in head
                head.display();
                System.out.println("----------------------------------------------");
            }
            //then recurse
            display_math(head.go_next());
        }
    }

    //display the linked list public function that calls the recursive function
    public void display_chemistry() {

        if (head != null)
            display_chemistry(head);
        else
            System.out.println("No chemistry topics to display yet.");

    }

    //private recursive display function that recursively displays the head for chemistry topics
    private void display_chemistry(list_node head) {

        if (head != null) {
            if (head instanceof Chemistry) {
                //display the info in head
                head.display();
                System.out.println("----------------------------------------------");
            }
            //then recurse
            display_chemistry(head.go_next());
        }
    }

    //display the linked list public function that calls the recursive function
    public void display_CS() {

        if (head != null)
            display_CS(head);
        else
            System.out.println("No computer science topics to display yet.");

    }

    //private recursive display function that recursively displays the head for CS topics
    private void display_CS(list_node head) {

        if (head != null) {
            if (head instanceof Computer_science) {
                //display the info in head
                head.display();
                System.out.println("----------------------------------------------");
            }
            //then recurse
            display_CS(head.go_next());
        }
    }

    //add a head to the linear linked list
    public void add_tutor(list_node to_add) {

        if (head != null) {
            //if there is nothing then call the recursive function below which handles this case
            add_tutor(head, to_add);
        } else
            //if there is something then it is to be added
            head = to_add;
    }

    //private recursive add function
    private void add_tutor(list_node head, list_node to_add) {

        //if there is noting in head then:
        if (head != null) {
            //if what is to be added is not a match, then recurse
            if (head.compare_tutornames(to_add) > 0) {
                add_tutor(head.go_next(), to_add);
            } else {
                //else it is a match then what is to be added is head
                to_add.connect_next(head.go_next());
                head.connect_next(to_add);
            }
        } else
            //if there is nothing in the list then the first thing in the list will be to_add
            head = to_add;
    }

    //Remove function created but not used because it isnt a requirement
    /*
    public boolean remove_tutor(list_node to_add) {

        if (head == null) {
            System.out.println("There are no subjects yet.");
            return false;
        } else {
            //if the subject we are trying to delete is after the compare_subjects subject
            if (head.compare_subjects(to_add) > 0) {
                //set the head to null to invoke garbage collection
                head = null;
                head = head.go_next();

            } else if (head.compare_subjects(to_add) == 0) {
                head = null;
                head = head.go_next();

            } else {
                System.out.println("No topics for this subject exist.");
                return false;
            }

        }
        return true;
    }

*/
     //retrieve function for the list
    public list_node retrieve(String name) {
        //if there is nothing in head then there is nothing to retrieve
        if (head == null) {
            return null;
        } else
            //else call the recursive find function
              return retrieve(head, name);
    }

    //private recursive find function
    private list_node retrieve(list_node head, String to_retrieve) {

        //if there is something to be found, then call the compare_tutornames from list_node that helps find a match
        if (head != null) {
            //if we have found a match
            if (head.compare_tutornames(to_retrieve) == 0) {
                return head;
            } else
                //if we have not found a match then recurse
                 return retrieve(head.go_next(), to_retrieve);
        } else {
            //if head is empty then return null
            return null;
        }
    }

    //retrieve function for program 5's requirement to be able to have a user search for a service
    public list_node retrieve_subject(String subject) {
        //if there is nothing in head then there is nothing to retrieve
        if (head == null) {
            return null;
        } else
            //else call the recursive find function
            return retrieve_subject(head, subject);
    }

    //private recursive find function
    private list_node retrieve_subject(list_node head, String to_retrieve) {

        //if there is something to be found, then call the compare_subjects from list_node that helps find a match
        if (head != null) {
            //if we have found a match
            if (head.compare_subjects(to_retrieve) == 0) {
                return head;
            } else
                //if we have not found a match then recurse
                return retrieve_subject(head.go_next(), to_retrieve);
        } else {
            //if head is empty then return null
            return null;
        }
    }

    //wrapper function for tree_manager classes add tree function
    public int compare_subjects(list_node to_compare) {
        return head.compare_subjects(to_compare.subject);
    }

    //for adding in tree manager, compare subjects
    public int compare_subjects(tree_node to_compare) {
        return head.compare_subjects(to_compare.head);
    }


    //compare two tutornames with type tree_node
    public int compare_tutornames(tree_node to_compare) {
        return head.compare_tutornames(to_compare.head);
    }

    //compare two tutor names with type string
    public int compare_tutornames(String to_compare) {
        return head.compare_tutornames(to_compare);
    }


    //public non recursive write function that calls the recursive write function
    public void write(PrintStream to_write) {
        if (head != null) {
            //base case is if head is not empty, then we must have something to write to a file
            write(head, to_write);
        }
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


}























