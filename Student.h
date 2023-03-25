#include <string>
#include <iostream>


using namespace std;

class Student{

    public:
        Student();
        ~Student();
        
        Student(const Student& rhs);
        Student(string fName, string lName, string userID, string bNumber);
        Student& operator = (const Student & rhs);
        
        void addCourses(string courseToAdd);
        void dropCourses(string courseToDrop);
        bool doesCourseExist(string crnToCheck);

        string getBNumber();
        string* getCRNS();
        void getFullName();
        string getFirstName();
        string getLastName();
        string getUserID();
        int getQuantity();
        friend ostream& operator << (ostream& out, const Student& c1);


        void showCourses(string coursesToShow);
        void resizeArray();
        friend bool operator == (const Student& s1, const Student& s2);
     

    private:
        string fName;
        string lName;
        string userID;
        string bNumber;
        
        int capacity;
        int currQuantity;
        string* studentCourses;

};