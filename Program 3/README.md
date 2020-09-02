This program allows the user to manage three different types of materials/ 
activities relating to a remote experience. A user can manage their meetings,
their websites they visit, and the videos they watch. These materials are implied
to belong to one of three different types: recreation, work, or school. Supported
is add, remove, edit and find functionality for each type of material. The char* 
data is managed by a string class, so char*'s are avoided. Dynamic binding for the
description function in all three derived classes is used as well. The data structure
is a BST whos nodes are objects. Data is added to, removed, and found by searching
for the name of a meterial. The base class is remote_info, which has four derived
classes node, websites, videos, and meetings. The string class creates and manages
a char* str, and the BST manager class contains functions that allow the user to
manpulate the data in the BST.
