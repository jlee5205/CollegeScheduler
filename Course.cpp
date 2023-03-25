#include "Course.h"
#include "CourseList.h"

Course::Course(){
    capacity = 1;
    currQuantity = 0;
    registeredStudents = new string[capacity];

};

Course::~Course(){
    delete [] registeredStudents;
}

Course::Course(const Course& rhs){
    this->CRN = rhs.CRN;
    this->dept = rhs.dept;
    this->number = rhs.number;
    this->name = rhs.name;

    this->capacity = rhs.capacity;
    this->currQuantity = rhs.currQuantity;
    registeredStudents = new string[capacity];
    for (int i = 0; i< currQuantity;i++){
        registeredStudents[i] = rhs.registeredStudents[i];
    }
};
Course::Course(string CRN, string dept, string number, string name){
    this->CRN = CRN;
    this->dept = dept;
    this->number = number;
    this->name = name;

    capacity = 1;
    currQuantity = 0;
    registeredStudents = new string[1]; //bnumbers of students in the course
};

string Course::getCRN(){

    return CRN;
};

string* Course::getBnumbers(){
   return registeredStudents;
};

int Course::getQuantity(){
    return currQuantity;
};
string Course::getCourseID(){
    string courseID = dept + " " + number;
    
    return courseID;
};

string Course::getCourseName(){
    
    return name;
};
void Course::getClassName(){
    cout << this->CRN << ": " << this->name << endl;
};

void Course::addStudent(string studentToAdd) {
    if (capacity == currQuantity){
        resizeArray();
    }
    if (!doesCourseExist(studentToAdd)){
        registeredStudents[currQuantity] = studentToAdd;
        cout << "Sucess: added student " << studentToAdd << " into course " << this->CRN << endl;
        
        currQuantity++;

    }
    else{
        cout << "Failed: cannot add, student " << studentToAdd << " already enrolled in course " << this->CRN << endl;
    }

};

void Course::dropStudent(string studentToDrop) {
    //remove student Bnumber from registered students array
    string *tempArray = new string[capacity];

    if(doesCourseExist(studentToDrop)){
        for(int i = 0; i < currQuantity;i++){
            if (registeredStudents[i] == studentToDrop){
                tempArray[i] = registeredStudents[currQuantity-1];
            }
            else{
                tempArray[i] = registeredStudents[i];
            }
        }
        currQuantity--;
    }
    delete [] registeredStudents;
    registeredStudents = tempArray;
};

bool Course::doesCourseExist(string bNumberToCheck){
   for(int i = 0; i< currQuantity;i++){
        if (registeredStudents[i] == bNumberToCheck){
            return 1;
        }
    }
    return 0;
};


void Course::resizeArray() {
    this->capacity = this->capacity * 2;
    string* newArray = new string[this->capacity];
    for(int i = 0; i<this->currQuantity;i++){
        newArray[i] = registeredStudents[i];
    }
    delete[] registeredStudents; //delete the old array
    registeredStudents = newArray;
    

};

Course& Course:: operator = (const Course & rhs){

    if (this != &rhs){
        CRN = rhs.CRN;
        dept = rhs.dept;
        number = rhs.number;
        name = rhs.name;

        //cout << "before dele" << endl;
        delete [] registeredStudents;
        
        //cout << "after dele" << endl;
        registeredStudents = new string[rhs.capacity];
        //registeredStudents = new string[rhs.capacity];
        
        for (int i = 0; i< currQuantity;i++){
            
            registeredStudents[i] = rhs.registeredStudents[i];
        }
        capacity = rhs.capacity;
        currQuantity = rhs.currQuantity;
        

    }
    return *this;
    
    
    
};



