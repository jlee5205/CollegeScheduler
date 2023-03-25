#include <string>
#include <iostream>



class StudentList{
    public:
        StudentList();
        ~StudentList();

        void addStudent(Student studentToAdd);
        void removeStudent(Student studentToRemove);
        void showStudent(string bNumber);

        int getCapacity();
 
        Student* searchByBnumber(string bNumber);
        bool doesStudentExist(string bNumberToCheck);
        void resizeArray();

    private:
        int capacity;
        int currQuantity;
        Student *availableStudents;

};
