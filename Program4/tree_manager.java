/*
This file: tree_manager.java

What is in this file? :
This file contains the implementation of the add, retrieve, display and read and  write functions for the red black tree.
The data structure is a red black tree, which includes a root reference, red and black color indicators, and a black_nil
reference that acts as the null pointer for this class. When it comes to the add function for the tree, there are four
functions responsible for assisting this operation. The general add function adds the left and right references as
needed depending on cases, similar to the function of a BST. From there, the fix add function runs afterwards, which
fixes any violation that may have occurred in the addition of the node.
These violations include the parent of the added node could be red, or if we
need to color the root black. These are the only issues to fix.
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintStream;

public class tree_manager {

    private tree_node root;
    //the color of the NULL node is considered black
    private tree_node black_nil;

    //tree_manager constructor for making the black_null reference and setting the root to be black
    public tree_manager() {

        //cant set the normal nil to be black so make a node to treat as a nil reference
        black_nil = new tree_node();
        black_nil.set_color(Color.Black);
        root = black_nil;
    }

    //public non recursive display function to display the root
    public void display() {
        //if the root is empty there is nothing to display
        if (root == black_nil) {
            System.out.println("No data to display");
        } else
            display(root);
    }

    //private recursive display function
    private void display(tree_node root) {

        //if root isn't null, then:
        if (root != black_nil) {
            //do an inorder display of left, then the data in head, then right:
            display(root.go_left());
            root.display();
            System.out.println();
            display(root.go_right());
        }
    }

    //The first add function mimics a BST add function. The newly inserted
    //node is going to be red. This is the public add function that calls the recursive one
    //below it:
    public void add(list_node to_add) {

            add(to_add, root);
    }


    //recursive private add function for the tree:
    private void add(list_node to_add, tree_node root) {

        //if the root we are currently is in null:
        if (this.root == black_nil) {
            //then make a new node to add onto
            tree_node temp = new tree_node(to_add);
            //and initialize that new nodes left, right, and parent nodes:
            temp.connect_left(black_nil);
            temp.connect_right(black_nil);
            temp.connect_parent(black_nil);
            //the root of the tree is now the temp node we just created
            this.root = temp;
            //the function that fixes any violations is called on this root
            fix_add(this.root);
        }
        //in this case, the root has data in it already. Cases must be addressed:
        if (root != black_nil) {
            //if the subjects letters is equal to the subjects first letter in the root,
            //the we add it in the same element of the tree
            if(root.compare_subjects(to_add) == 0) {
                root.add_tutor(to_add);
            } else {
                //in this case, we need to go to the right of the tree and check for if
                //the subject is greater than roots subject
                if(root.go_right() == black_nil){
                    if(root.compare_subjects(to_add) > 0){
                        //in this case we add a new node
                        tree_node temp = new tree_node(to_add);
                        //and initialize it to be root
                        root.connect_right(temp);
                        //and initialize its left, right and parent nodes
                        temp.connect_parent(root);
                        temp.connect_right(black_nil);
                        temp.connect_left(black_nil);
                        //call the fix function in case any violations have happened
                        fix_add(temp);
                    }
                }
                //if root.go_right != black_nil:
                else{
                    //if the subject we are trying to add is
                    if(root.compare_subjects(to_add) > 0){
                        add(to_add, root.go_right());
                    }
                }
            }
            //do the same exact process as above, except we are checking if the subject we are
            //trying to add is less than the roots subject. This means we have to switch the
            //order of the left and right invocations:
                if (root.go_left() == black_nil) {
                    if (root.compare_subjects(to_add) < 0) {
                        tree_node temp = new tree_node(to_add);
                        root.connect_left(temp);
                        temp.connect_parent(root);
                        temp.connect_left(black_nil);
                        temp.connect_right(black_nil);
                        fix_add(temp);
                    }
                } else {
                    if (root.compare_subjects(to_add) < 0) {
                        add(to_add, root.go_left());
                    }
                }

            }

        //This code doesn't work but I wanted to keep it here
        /*
            tree_node added_node = new tree_node(to_add);
            //see if this root ==  null
            if (this.root == black_nil) {
                added_node.connect_parent(black_nil);
                this.root = added_node;
            } else if (root.go_parent() == this.root) {
                if (added_node.compare_subjects(this.root) < 0) {
                    this.root.connect_left(added_node);
                } else
                    this.root.connect_right(added_node);
                added_node.connect_parent(this.root);
            } else {
                added_node.connect_parent(root.go_parent());
                if (added_node.compare_subjects(root.go_parent()) < 0) {
                    root.go_parent().connect_left(added_node);
                } else
                    root.go_parent().connect_right(added_node);
            }

            added_node.connect_left(black_nil);
            added_node.connect_right(black_nil);
            fix_add(added_node);
        }

        */
         }


         //In case any violations have occured when we have added nodes using the above add node function,
        //this function is always run in any case. This functions will fix the colors associated with a node,
        //and will call the rotate functions are necessary. Most likely a node will need to be corrected
        //every time one is added near the middle or end of the tree:
    public void fix_add(tree_node to_add) {
        if (to_add.go_parent().get_color() == Color.Red) {
            if (to_add.go_parent() == to_add.go_parent().go_left()) {
                tree_node temp = to_add.go_parent().go_parent().go_right();

                //temp acts as a uncle reference ,and if it is red, then
                //we have to recolor the reference. This is case
                // 1. We do this by:
                if (temp.get_color() == Color.Red) {
                    //changing the color of the parent to black
                    to_add.go_parent().set_color(Color.Black);
                    //changing color of uncle node "temp" to black too
                    temp.set_color(Color.Black);
                    //change the color of the grandparent of the node
                    //we are trying to add, then we need to change
                    //to_add via a recursive call to repeat above
                    //two lines of code for a new node
                    to_add.go_parent().go_parent().set_color(Color.Red);
                    fix_add(to_add.go_parent().go_parent());

                    //in this case, the uncle node is black. We need to
                    //take into account to_add, to_add's parent, and
                    //to_add's grandparent:
                } else {
                    // else if the uncle is black, then we do either
                    //recoloring or a rotation. This is case 2 or case 3:

                    //case 2:
                    if (to_add == to_add.go_parent().go_right()) {
                        tree_node temp1 = to_add.go_parent();
                        transformLeft(temp1);
                        temp1.go_parent().set_color(Color.Black);
                        temp1.go_parent().go_parent().set_color(Color.Red);
                        transformRight(temp1.go_parent().go_parent());

                    } else {
                        //case 3:

                        //make the parent black
                        to_add.go_parent().set_color(Color.Black);
                        //make grandparent red
                        to_add.go_parent().go_parent().set_color(Color.Red);
                        transformRight(to_add.go_parent().go_parent());
                    }
                }
            } else {
                //The same process as above is happening here, except we
                //are referring to a left node instead of a right node. Here,
                //the to_adds parent is the right child.
                tree_node temp = to_add.go_parent().go_parent().go_left();

                if (temp.get_color() == Color.Red) {
                    to_add.go_parent().set_color(Color.Black);
                    temp.set_color(Color.Black);
                    to_add.go_parent().go_parent().set_color(Color.Red);
                    fix_add(to_add.go_parent().go_parent());
                } else {
                    if (to_add == to_add.go_parent().go_left()) {
                        tree_node temp2 = to_add.go_parent();
                        transformRight(temp2);
                        temp2.go_parent().set_color(Color.Black);
                        temp2.go_parent().go_parent().set_color(Color.Red);
                        transformLeft(temp2.go_parent().go_parent());
                    } else {
                        //make parent black
                        to_add.go_parent().set_color(Color.Black);
                        //make grandparent red
                        to_add.go_parent().go_parent().set_color(Color.Red);
                        transformLeft(to_add.go_parent().go_parent());
                    }

                }
            }
        } else
            //if the node we are trying to add's parent is not red:
              this.root.set_color(Color.Black);
    }


    //rotate the right side of the root in this case where this needs to happen:
    public void transformRight(tree_node to_transform) {
        //temp will be the new parent
        tree_node temp = to_transform.go_left();
        to_transform.connect_left(temp.go_right());

        if (temp.go_right() != black_nil) {
            temp.go_right().connect_parent(to_transform);
        }

        temp.connect_parent(to_transform.go_parent());

        if(to_transform.go_parent() == black_nil) {
            root = temp;
        } else if(to_transform == to_transform.go_parent().go_right()) {
            to_transform.go_parent().connect_right(temp);
        } else {
            to_transform.go_parent().connect_left(temp);
        }

        temp.connect_right(to_transform);
        to_transform.connect_parent(temp);
        //temp is now the new parent
    }

    //rotate the left side of the root in the case where this needs to happen
    public void transformLeft(tree_node to_transform) {
        //temp will be the new parent
        tree_node temp = to_transform.go_right();
        to_transform.connect_right(temp.go_left());

        //temps left must be black_nil
        if (temp.go_left() != black_nil) {
            temp.go_left().connect_parent(to_transform);
        }

        temp.connect_parent(to_transform.go_parent());

        if(to_transform.go_parent() == black_nil) {
            root = temp;
        } else if(to_transform == to_transform.go_parent().go_left()) {
            to_transform.go_parent().connect_left(temp);
        } else {
            to_transform.go_parent().connect_right(temp);
        }
        temp.connect_left(to_transform);
        to_transform.connect_parent(temp);
        //now temp is the new parent
    }

    //public non-recursive retrieve function that calls recursive functions
    public list_node retrieve (String to_retrieve) {
        if (root == black_nil) {
            return null;
        }
        return retrieve(root, to_retrieve);
    }

    //private retreieve function for the tree:
    private list_node retrieve(tree_node root, String to_retrieve) {

        //as long as we have something to look for:
        if (root != black_nil) {
            //temp will be the node we use to check for the existence of a root
            list_node temp;
            temp = root.retrieve(to_retrieve);

            if (temp != null) {
                return temp;
            } else {
                temp = retrieve(root.go_left(), to_retrieve);
                if (temp != null) {
                    return temp;
                } else {
                    return retrieve(root.go_right(), to_retrieve);
                }
            }
        } else
            return null;
    }

    //public write functions for writing data to a textfile
    public void write(PrintStream to_save) {
        write(root, to_save);
    }

    //private recursive write functions for writing tree data to the textfile
    private void write(tree_node root, PrintStream to_save) {
        if (root != null) {
            //save what is in root
            root.write(to_save);
            //then save what is in left and right recursively
            write(root.go_left(), to_save);
            write(root.go_right(), to_save);
        }
    }

    //read function for reading in data from a textfile into the red black tree
    public void read(BufferedReader to_read) throws IOException {

        String in;
        in = to_read.readLine();

        if (in != null) {
            //create a node that has the data to be read in it
            list_node to_add = null;

            if (in.equals ("M")) {
                to_add = new Math();
            } else if (in.equals ("C")) {
                to_add = new Chemistry();
            } else if (in.equals ("CS")) {
                to_add = new Computer_science();
            }

            if (to_add != null) {
                to_add.read(to_read);
                add(to_add);
                //recurse
                read(to_read);
            }
        }

    }

}

















