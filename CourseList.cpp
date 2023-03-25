#include "Course.h"
#include "CourseList.h"

//searchByCRN
//addCourse
//removeCourse
CourseList::CourseList(){
    capacity = 1;
    currListQuantity = 0;
    availableCourses = new Course[1];

};
CourseList::~CourseList(){
    delete [] availableCourses;
}

/*int CourseList::setQuantity(){
    this->quantity = 0;
}*/
void CourseList::addCourse(Course courseToAdd){
    if (!doesCourseExist(courseToAdd.getCRN())){ //if doesnt exist then we can add
        if (currListQuantity == capacity){
 
            resizeArray();
        }
        
        availableCourses[currListQuantity] = courseToAdd;
        //Success: built course CS240 (CRN: 123456): Data Structures and Algorithms
        cout << "Success: built course " << courseToAdd.getCourseID();
        cout << " (CRN: " << courseToAdd.getCRN() << "): " << courseToAdd.getCourseName();
        cout << endl;

       
      

        //CS240 (CRN: 123456): Data Structures and Algorithms"
        currListQuantity++;
        //incrementQuantity();
        //currQuantity = currQuantity + 1;
    }
    else{
        cout << "Fail: cannot build course ";
        courseToAdd.getCourseID();
        cout << "(CRN: " << courseToAdd.getCRN() << "): CRN exists";
        cout << endl;
    }
   

};

int CourseList::getCapacity(){
    return this->capacity;
}

int CourseList::incrementQuantity(){
    this->currListQuantity = this->currListQuantity + 1;
    return this->currListQuantity;
}

bool CourseList::doesCourseExist(string crnToCheck){
    /* TESTED AND WORKS */
    //cout << "in does course Exist" << endl;
    Course currentCourse; 
    for(int i = 0; i< currListQuantity;i++){
        //cout << "in loop" << endl;
        currentCourse = availableCourses[i];
       // cout << "under currenCOurs" << endl;
        if (currentCourse.getCRN() == crnToCheck){
            
            return 1;
        }
        //cout << "crn didnt exist" << endl;
    }
    return 0;
    
};

ostream& operator << (ostream& out, const Course& c1){
    out << c1.CRN << c1.dept << c1.number << c1.name;
    return out;
}

/*bool operator == (const Course& c1, const Course& c2){
    return ((c1.CRN == c2.CRN) && (c1.dept == c2.dept) && (c1.number == c2.number) && (c1.name == c2.name));

    
};*/



void CourseList::removeCourse(Course courseToRemove){
    //doesCourseExist(courseToRemove); //if course exists, it can remove;

    //copy into a new array, skipping over the old course, delete old array

    Course *tempArray = new Course[capacity];
    if (doesCourseExist(courseToRemove.getCRN())){
        for(int i = 0; i< currListQuantity-1;i++){
            if (availableCourses[i].getCRN() == courseToRemove.getCRN()){
                tempArray[i] = availableCourses[currListQuantity-1];
                
            }
            else{
                tempArray[i] = availableCourses[i];
            }
        }
        currListQuantity--;
    }
  
    delete[] availableCourses;
    availableCourses = tempArray;
    // cout << "showing total coursse" << endl;
    // cout << availableCourses->getCourseName() << endl;
  

};

void CourseList::resizeArray(){
    /* TESTED AND WORKS*/
    this->capacity = this->capacity *2;
    Course* newArray = new Course[this->capacity];

    for(int i = 0; i < this->currListQuantity; i++){
        newArray[i] = availableCourses[i];

    }
    delete [] availableCourses; //delete the old array
    availableCourses = newArray;

};

Course* CourseList::searchByCRN(string crn){
    for(int i = 0; i<capacity;i++){
        if (availableCourses[i].getCRN() == crn){
  
            return &availableCourses[i];
        }
    }
    return nullptr;

};


void CourseList::showCourse(string crn){
    for(int i = 0; i< capacity;i++){
        if (availableCourses[i].getCRN() == crn){
            cout << availableCourses[i].getCRN() << " " << availableCourses[i].getCourseID() << " " << availableCourses[i].getCourseName() << endl;
            
            //return availableStudents[i];
        }
    }
}