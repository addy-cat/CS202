This program is a to-do list-esque system, where there are three activities included. These activities 
each belong to their own derived class from the base class Activity. This program uses aspects of
dynamic binding so certain functions are matched with their correct definitions
at run time. This is achieved using virtual functions. In this file, the base class
pointer points to the derived class object in order to properly call functions. Derived classes
include coffee shop, study, and working. This program is specific to me regarding these classes:
I personally go to coffee shops often to work on my homework and to hang out, I often go to the PSU
and PCC campus to study (the study class implies you are at a physical location), and I work at the CAT at
PSU. The functions for these classes are specific to these personal to-do list plans of mine.
The program has a very simple hierarchy, where the base class has three derived classes, and a node
class and a activity manager class that are seperate. This file more specifically uses several menus to allow
the user to interact with every aspect of the program. RTTI is used for functions unique to a class (3).
