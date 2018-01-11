/* Author: Ashley K. Smith (github.com/ashksmith)
 * Accelerated C++, Chapter 3, Exercise 3-5
 *
 * Write a program that will keep track of grades for several students at once.
*/

#include <iostream>
#include <vector>
#include <string>
#include <istream>

using std::vector;
using std::string;
using std::cout;
using std::vector;
using std::cin;
using std::endl;

int main(void){
	int num_homework = 5; // The expected number of grades per student
	vector<string> students;

	vector< vector<int> > grades;

	bool done = 0;

	while(!done){
		// Take a name
		string name;
		cout << "Enter student name: ";
		cin >> name;
		students.push_back(name);

		// Take grades for the student
		vector<int> student_grades;
		int x;
		for(int i = 0; i < num_homework; i++){
			cout << "Enter grade #" << i + 1 << ": ";
			cin >> x;
			student_grades.push_back(x);
		}
		grades.push_back(student_grades);

		// Take input for a command
		string input;
		cout << "Enter another student? y/n?: ";
		while(cin >> input){
			if(input == "n" || input == "N"){
				done = 1;
				break;
			} else if (input == "y" || input == "Y") {
				done = 0;
				break;
			} else {
				cout << "Input not recognised, try again.";
			}
		}

	}

	// Output entered students
	cout << endl;
	for(int i = 0; i < grades.size(); i++){
		cout << "Student name: " << students[i] << endl <<  " - grades: ";
		for(int j = 0; j < num_homework; j++)
			cout << grades[i][j] << " ";
		cout << endl << endl;
	}

	return 0;
}
