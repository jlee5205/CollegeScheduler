#include <iostream>
using namespace std;


class CourseList{
    public:
        CourseList();
        ~CourseList();
        
        void addCourse(Course courseToAdd);
        void removeCourse(Course courseToRemove);
        Course* searchByCRN(string CRN);
        string getCRN(Course courseToUse);

        void showCourse(string crn);
        
        int getCapacity();

        int incrementQuantity();

        void resizeArray();
        bool doesCourseExist(string crnToCheck);
        //friend bool operator == (const Course& c1, const Course& c2);

    
    private:
        int capacity = 0;
        int currListQuantity = 0;
        Course *availableCourses;


        
};