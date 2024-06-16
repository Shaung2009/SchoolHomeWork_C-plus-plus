// This program demonstrates the definition and usage of three related classes : UniversityStaff, Student, and ScienceStudent.
// It includes the implementation of constructors, accessor methods, and assignment operators for these classes.
// The program also includes a simple test driver program to test if each class's various properties are correctly implemented.
#include<iostream>
#include<string>

using namespace std;

class UniversityStaff {
public:
	//Constructors with copy constructor
	UniversityStaff();
	UniversityStaff(string theName);
	UniversityStaff(const UniversityStaff& theObject);
	//Accessor
	string getName() const;
	//Operator overloading of =, >>, <<
	UniversityStaff& operator=(const UniversityStaff& rtSide);
	friend istream& operator >>(istream& in, UniversityStaff& staffObject);
	friend ostream& operator <<(ostream& out, const UniversityStaff& staffObject);
private:
	string name;	//Name of the productor
};

class Student {
public:
	//Constructors
	Student();
	Student(const string& theUni, const UniversityStaff& theProductor, const int theNumber);
	//Copyconstructor
	Student(const Student& other);

	//Accessors
	string getUni() const;
	UniversityStaff getProductor() const;
	int getRegNumber() const;
	//Mutators => No need in this project

	//Overload assignment operator =
	Student& operator= (const Student& other);
private:
	string university;			//student's university
	UniversityStaff productor;	//student's productor
	int regNumber;				//Student's registration number
};

class ScienceStudent : public Student {
public:
	//Constructors
	ScienceStudent();
	ScienceStudent(const string& theUni, const UniversityStaff& theProductor, const int theNumber, const string& theDiscipline, const string& theCourse);
	//Copy constructors
	ScienceStudent(const ScienceStudent& other);

	//Accessors
	string getDiscipline() const;
	string getCourse() const;

	//Mutators => No need in this project

	//Overload assignment operator =
	ScienceStudent& operator= (const ScienceStudent& other);

private:
	string discipline;	//properties science discipline
	string course;		//undergraduate or postgraduate course
};

int main() {
	cout << "Testing for object's all method.\n\n";

	// Create a UniversityStaff object
	UniversityStaff staff1("Dr. Smith");

	// Test accessors of UniversityStaff
	cout << "University Staff Name: " << staff1.getName() << endl;

	// Create a Student object
	Student student1("Harvard", staff1, 12345);

	// Test accessors of Student
	cout << "\nStudent University: " << student1.getUni() << endl;
	cout << "Student Productor: " << student1.getProductor().getName() << endl;
	cout << "Student Registration Number: " << student1.getRegNumber() << endl;

	// Create a ScienceStudent object
	ScienceStudent sciStudent1("MIT", staff1, 67890, "Physics", "Undergraduate");

	// Test accessors of ScienceStudent
	cout << "\nScience Student University: " << sciStudent1.getUni() << endl;
	cout << "Science Student Productor: " << sciStudent1.getProductor().getName() << endl;
	cout << "Science Student Registration Number: " << sciStudent1.getRegNumber() << endl;
	cout << "Science Student Discipline: " << sciStudent1.getDiscipline() << endl;
	cout << "Science Student Course: " << sciStudent1.getCourse() << endl;

	return 0;
}

/* UniversityStaff */

UniversityStaff::UniversityStaff()
	:name("No name yet") {}
UniversityStaff::UniversityStaff(string theName)
	:name(theName){}
UniversityStaff::UniversityStaff(const UniversityStaff& theObject)
	:name(theObject.getName()){}
//Accessor
string UniversityStaff::getName() const {
	return name;
}
//Operator overloading of =, >>, <<
UniversityStaff& UniversityStaff::operator=(const UniversityStaff& rtSide) {
	if (this != &rtSide) {
		name = rtSide.name;
	}
	return *this;
}
istream& operator >>(istream& in, UniversityStaff& staffObject) {
	in >> staffObject.name;
	return in;
}
ostream& operator <<(ostream& out, const UniversityStaff& staffObject) {
	out << staffObject.name << endl;
	return out;
}

/* Student */

//Constructors
Student::Student()
	:university("No unniversity yet"), productor("No productor yet"), regNumber(0){}
Student::Student(const string& theUni, const UniversityStaff& theProductor, const int theNumber)
	:university(theUni), productor(theProductor), regNumber(theNumber) {}
//Copyconstructor
Student::Student(const Student& other)
	:university(other.getUni()), productor(other.getProductor()), regNumber(other.getRegNumber()) {}

//Accessors
string Student::getUni() const { return university; }
UniversityStaff Student::getProductor() const { return productor; }
int Student::getRegNumber() const { return regNumber; }
//Mutators => No need in this project

//Overload assignment operator =
Student& Student::operator= (const Student& other) {
	if (this != &other) {
		university = other.university;
		productor = other.productor;
		regNumber = other.regNumber;
	}
	return *this;
}

/* ScienceStudent*/

//Constructors
ScienceStudent::ScienceStudent()
	:Student(), discipline("No discipline yet"), course("No course yet"){}
ScienceStudent::ScienceStudent(const string& theUni, const UniversityStaff& theProductor, const int theNumber, const string& theDiscipline, const string& theCourse)
	:Student(theUni, theProductor, theNumber), discipline(theDiscipline), course(theCourse) {}
//Copy constructors
ScienceStudent::ScienceStudent(const ScienceStudent& other)
	:Student(other), discipline(other.discipline), course(other.course) {}
	
//Accessors
string ScienceStudent::getDiscipline() const {
	return discipline;
}
string ScienceStudent::getCourse() const {
	return course;
}

//Overload assignment operator =
ScienceStudent& ScienceStudent::operator= (const ScienceStudent& other) {
	if (this != &other) {
		*this = other;
		discipline = other.discipline;
		course = other.course;
	}
	return *this;
}