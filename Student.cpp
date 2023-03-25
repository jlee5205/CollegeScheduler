#include "Student.h"
#include "StudentList.h"


Student::Student(){
    //default constructor
    capacity = 1;
    currQuantity = 0;
    studentCourses = new string[capacity];
};

Student::~Student(){
    delete [] studentCourses;
}


Student::Student(const Student& rhs){
    this->bNumber = rhs.bNumber;
    this->userID = rhs.userID;
    this->fName = rhs.fName;
    this->lName = rhs.lName;

    this->capacity = rhs.capacity;
    this->currQuantity = rhs.currQuantity;
    studentCourses = new string[capacity];
    for (int i = 0; i< currQuantity;i++){
        studentCourses[i] = rhs.studentCourses[i];
    }
};

Student::Student(string bNumber, string userID, string fName, string lName){
    this->bNumber = bNumber;
    this->userID = userID;
    this->fName = fName;
    this->lName = lName;
    

    capacity = 1;
    currQuantity = 0;
    studentCourses = new string[1]; //string of CRNS
    
//explict constructor
};

Student& Student:: operator = (const Student & rhs){
    if (this != &rhs){
        bNumber = rhs.bNumber;
        userID = rhs.userID;
        fName = rhs.fName;
        lName = rhs.lName;

        //cout << "before dele" << endl;
        delete [] studentCourses;
        
        //cout << "after dele" << endl;
        studentCourses = new string[rhs.capacity];
        //registeredStudents = new string[rhs.capacity];
        
        for (int i = 0; i< currQuantity;i++){
            
            studentCourses[i] = rhs.studentCourses[i];
        }
        capacity = rhs.capacity;
        currQuantity = rhs.currQuantity;
        

    }
    return *this;

};

void Student::addCourses(string crnToAdd) {
    if (capacity == currQuantity){
        resizeArray();
    }
    studentCourses[currQuantity] = crnToAdd;
    currQuantity++;

}

void Student::dropCourses(string crnToDrop) {
    string* tempCourseList = new string[capacity];


    if (doesCourseExist(crnToDrop)){
        for(int i = 0; i<currQuantity;i++){
            if(studentCourses[i] == crnToDrop){
                tempCourseList[i] = studentCourses[currQuantity-1];


            }
            else{
                tempCourseList[i] = studentCourses[i];
            }
        }
        currQuantity--;

    }

    
    delete [] studentCourses;
    studentCourses = tempCourseList;
};

string* Student::getCRNS(){
   return studentCourses;
};

bool Student::doesCourseExist(string crnToCheck){
    for(int i = 0; i< capacity;i++){
        string currentCourse = studentCourses[i];
        if (currentCourse == crnToCheck){

            return 1;
        }
  
    }
    return 0;
    
};

void Student::resizeArray() {
    capacity*=2;
    //Course* newArray = new Course[capacity];
    string* newArray = new string[capacity];
    for(int i = 0; i<this->currQuantity;i++){
        newArray[i] = studentCourses[i];
    }
    delete [] studentCourses; //delete the old array
    studentCourses = newArray;
    

}

string Student::getBNumber(){
    return this->bNumber;
}

void Student::getFullName(){
    cout << " " << this->fName << " " << this->lName << endl;
}

string Student::getUserID(){
    return this->userID;
}
string Student::getFirstName(){
    return this->fName;
}
string Student::getLastName(){
    return this->lName;
}

int Student::getQuantity(){
    return currQuantity;
};


