#include <iostream>
#include <cstdlib>
#include <string>
// Arya HajiTaheri 


using namespace std;

class Student
{
public: Student();
		~Student();
		void InputData(); 
		void OutputData(); 
		void ResetCourses(); 
		Student& operator =(const Student& rightSide);

private:
	string name;
	int numCourses;
	string *courseList;
	int studentNumber = 0;
};


Student::Student() : name(""), numCourses(0), courseList(NULL)
{
}


Student::~Student()
{
	numCourses = 0;
	ResetCourses();
	name = "";
}


void Student::ResetCourses()
{
	if (courseList) {
		delete[] courseList;
		courseList = NULL;
		numCourses = 0;
	}
}


void Student::InputData()
{
	studentNumber++;
	ResetCourses();
	cout << "Enter student name: ";
	getline(cin, name);
	cout << "Enter number of courses: ";
	cin >> numCourses;
	cin.ignore(2, '\n'); 
	if (numCourses > 0) {
		
		courseList = new string[numCourses];
		
		for (int i = 0; i<numCourses; i++) {
			cout << "Enter name of course " << (i + 1) << " : ";
			getline(cin, courseList[i]);
		}
	}
	cout << endl;
}


void Student::OutputData()
{
	cout << "Number of Students created: " << studentNumber << endl << endl;
	cout << "Student "<< studentNumber <<": " << name << endl
		 << "Courses: ";
	for (int i = 0; i < numCourses; i++) {
		cout  << courseList[i]<< ", ";
	}
	cout << endl;
}

Student& Student::operator =(const Student& rightSide)
{
	ResetCourses();
	numCourses = rightSide.numCourses;
	if (numCourses > 0) {
		courseList = new string[numCourses];
		for (int i = 0; i < numCourses; i++) {
			courseList[i] = rightSide.courseList[i];
		}
	}

	return *this;
}


int main(){
	string redo;
	Student s1, s2;
	s1.InputData(); 
	bool tryagain = true;

	while (tryagain){
		cout << "Would you like to input a new student?<y/n>";
		getline(cin, redo);

		if (redo == "N" || redo == "n") {
			s1.OutputData();
			cout << endl;
			s1.ResetCourses();
			tryagain = false;

		// I had trouble outputing more than one students...
		}
		else if (redo == "Y" || redo == "y") {
			s1 = s2;
			s1.ResetCourses();
			s1.InputData();
		}
	}
	system("pause");
	return 0;
}