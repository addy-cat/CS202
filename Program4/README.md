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
