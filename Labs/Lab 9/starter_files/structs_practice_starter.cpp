#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

//TODO:
//Define a struct "Course" with members:
//1) department is a string
//2) courseNum is an int

//TODO:
//Define a struct "Student" with members:
//1) age 			is an int.
//2) firstName 		is a string.
//3) lastName 		is a string.
//4) favoriteTree 	is a string.
//5) courses 		is a vector of Course.

void readData(vector<Student> &students);
void printStudents(vector<Student> &students);

int main() {
	//TODO: declarea  vector of Student to use with the following functions.
	
	readData(students);
	printStudents(students);
	
	return 0;
}


void printStudents(vector<Student> &students) {
	for (int i = 0; i < (int)students.size(); ++i) {
		cout << students.at(i).firstName << " " << students.at(i).lastName  << " is ";
		cout << students.at(i).age << " years old and their favorite tree is the ";
		cout << students.at(i).favoriteTree << "." << endl;

		cout << students.at(i).firstName << " is taking ";
		cout << students.at(i).courses.size() << " courses:" << endl;
		for (int j = 0; j < (int)students.at(i).courses.size(); ++j) {
			cout << j+1 << ") " << students.at(i).courses.at(j).department << " ";
			cout << students.at(i).courses.at(j).courseNum;
			if (j != (int)students.at(i).courses.size() - 1 ) {
				cout << ",";
			}
			else {
				cout << ".";		
			}
			cout << endl;
		}
	}
}

void readData(vector<Student> &students) {
	//open data file and check
	ifstream studentData("student_data.txt");
	
	if (studentData.fail()) {
		cerr << "failed to open data" << endl;
		exit(1);
	}

	Student temp;
	int numCourses;

	//while there are students in the file.
	while (studentData >> temp.firstName >> temp.lastName >>  temp.age >> temp.favoriteTree) {
		temp.courses.clear();
		Course tempCourse;
		studentData >> numCourses;
		for (int i = 0; i < numCourses; i++) {
			studentData >> tempCourse.department;
			studentData >> tempCourse.courseNum;
			temp.courses.push_back(tempCourse);
		}

		students.push_back(temp);
	}
}