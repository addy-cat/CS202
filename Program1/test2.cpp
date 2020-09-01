#include <iostream>
#include <cstring>
#include "module.h"
#include "TimeDate.h"
#include "node.h"

using namespace std;

int main() {

	Assignment_manager an_assignment_man;
	Assignment an_assignment;
	Assignment an_assignment2;
	Assignment an_assignment3;

	//for labs
	an_assignment.change_grade_desc();
	an_assignment.change_time_date();
	an_assignment.change_title("test");

	an_assignment_man.add_lab_assign(an_assignment);
	an_assignment_man.display_labs();

	//for bookwork
	an_assignment2.change_grade_desc();
        an_assignment2.change_time_date();
        an_assignment2.change_title("test2");

        an_assignment_man.add_bookwork_assign(an_assignment2);
        an_assignment_man.display_bookwork();

	//for exams

	an_assignment3.change_grade_desc();
        an_assignment3.change_time_date();
        an_assignment3.change_title("test3");

        an_assignment_man.add_take_home_exam(an_assignment3);
        an_assignment_man.display_take_home_exam();

	
}
