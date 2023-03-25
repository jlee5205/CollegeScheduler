#include "Student.h"
#include "StudentList.h"

StudentList::StudentList(){
    capacity = 1;
    currQuantity = 0;
    availableStudents = new Student[1]; //total students in univeristy
};

StudentList::~StudentList(){
    delete [] availableStudents;
}

void StudentList::addStudent(Student studentToAdd){
  

    if (!doesStudentExist(studentToAdd.getBNumber())){ //checks if student doesn't exist
        if (currQuantity == capacity){
            resizeArray();
        }
        availableStudents[currQuantity] = studentToAdd;
        currQuantity++;
        cout << "Success: enrolled student " << studentToAdd.getBNumber() << " (" << studentToAdd.getUserID() << ") " << studentToAdd.getLastName() << ", " << studentToAdd.getFirstName() << endl;

    }
    else{
        cout << "Fail: cannot enroll student, B Number exists" << endl;
    } //checks if student exist, if it does it cannot add
    

};

void StudentList::removeStudent(Student studentToRemove){
    Student *tempArray = new Student[capacity];

    if (doesStudentExist(studentToRemove.getBNumber())){ //if student exist, we can remove
        for(int i = 0; i<currQuantity;i++){
            if (studentToRemove.getBNumber() == availableStudents[i].getBNumber()){
                tempArray[i] = availableStudents[currQuantity-1];
            }
            else{
                tempArray[i] = availableStudents[i];

            }
        }
        currQuantity--;
    }
    delete [] availableStudents;
    availableStudents = tempArray;

};

bool StudentList::doesStudentExist(string bNumberToCheck){
    /* TESTED AND WORKS */
    for(int i = 0; i< capacity;i++){
        Student currentStudent = availableStudents[i];
        if (currentStudent.getBNumber() == bNumberToCheck){
           
            return 1;
        }

    }
    
    return 0;
};



bool operator == (const Student& s1, const Student& s2){
    return ((s1.fName == s2.fName) && (s1.lName == s2.lName) && (s1.userID == s2.userID) && (s1.bNumber == s2.bNumber));

    
};


Student* StudentList::searchByBnumber(string bNumber){ //return reference to student
    for(int i = 0; i < capacity;i++){
        if (availableStudents[i].getBNumber() == bNumber){
            return &availableStudents[i];
        }
  
    }
    return nullptr;

};

void StudentList::showStudent(string bNumber){
    for(int i = 0; i< currQuantity;i++){
        if (availableStudents[i].getBNumber() == bNumber){
            cout << availableStudents[i].getBNumber();
            availableStudents[i].getFullName();
        
            //return availableStudents[i];
        }
    }
}
void StudentList::resizeArray(){
    /* TESTED AND WORKS */
    this->capacity = this->capacity *2;
    Student* newArray = new Student[this->capacity];

    for(int i = 0; i < this->currQuantity; i++){
        newArray[i] = availableStudents[i];

    }
    delete [] availableStudents; //delete the old array
    availableStudents = newArray;
}

ostream& operator << (ostream& out, const Student& s1){
    out << s1.bNumber << s1.userID << s1.fName << s1.lName;
    return out;
}

int StudentList::getCapacity(){
    return this->capacity;
}
