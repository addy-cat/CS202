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

Update for program 5 versus program 4:
This program now has a search/ edit history functionality as well. Via the use of an array of linked lists,
when you run the program as a student, you can view your recent tutor SEARCH history for a certain topic. If you
run the program as a tutor, you can view the recent EDIT history for a certain topic. Data is added into
the array of linked lists when: the student triggers the retrieve function via the search option, and when the tutor
triggers the retrieve function via their edit topic option. Basically a copy of the data they have retrieved is copied into
the array of linked list data structure "automatically" and the user does not have to specifically add these things to the history themselves.
