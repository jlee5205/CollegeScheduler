#include <iostream>
using namespace std;


class Course{
    public:
        Course();
        ~Course();
        Course(const Course& rhs);
        Course(string crn, string dept, string number, string name);
        void addStudent(string studentToAdd);
        void dropStudent(string studentToDrop);
        bool doesCourseExist(string bNumberToCheck);

        string getCRN();
        string* getBnumbers();
        int getQuantity();
        void getClassName();
        string getCourseID();
        string getCourseName();

        void showStudents(Course courseToShow);


        void resizeArray();
        void searchByCRN(string crn);

        friend bool operator == (const Course& c1, const Course& c2);
        friend ostream& operator << (ostream& out, const Course& c1);
        Course& operator = (const Course & rhs);

        //ourse& Course:: operator = (const Course & rhs);

    private:
        string CRN;
        string dept;
        string number;
        string name;

        int capacity;
        int currQuantity;
        //Student *registeredStudents;
        string* registeredStudents;
    //array [student] list of courses;
    //use bnumber
    //using a list of students in this class

};