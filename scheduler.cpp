#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <vector>
#include <regex>
#include "Student.h"
#include "Course.h"
#include "StudentList.h"
#include "CourseList.h"
using namespace std;


void showPrompt() {
   std::cout << "Enter [\"build <crn> <department> <number> <name>\"" << std::endl <<
                "       \"cancel <crn>\"" << std::endl <<
                "       \"enroll <bnumber> <userid> <first> <last>\"" << std::endl <<
                "       \"add <bnumber> <crn>\"" << std::endl <<
                "       \"drop <bnumber> <crn>\"" << std::endl <<
                "       \"roster <crn>\"" << std::endl <<
                "       \"schedule <bnumber>\"" << std::endl <<
                "       \"quit\"]" << endl <<
                ": ";
}

int main(){
    string userinput;
    string temp = "";
    vector<string> commands;
    CourseList totalCourses;
    StudentList totalStudents;
    while(true){
        commands.clear();
        showPrompt();
        getline(cin, userinput);
         if (userinput.length() == 0){
        cout << "Input is empty" << endl;
        return 1;
        }
        if (userinput == "quit") break;
        /*for(unsigned int i = 0; i< userinput.length();i++){
        
            if (userinput.at(i) == ' '){
                commands.push_back(temp); //add each word to vector commands
                //cout << temp << endl;
                temp = " ";
            }
            else{
                temp+= userinput.at(i); 
            }
        
        }
        commands.push_back(temp); */
        size_t currPos = 0;
        while((currPos = userinput.find(" "))!= std::string::npos){
            if(currPos!= 0){
                commands.push_back(userinput.substr(0, currPos));
                
            }
            //commands.push_back(userinput.substr(0, currPos));
            userinput.erase(0, currPos + 1);
            
      
        }
        commands.push_back(userinput);


        //[0-6]{1}[0-9]{2}
     
        if (commands.at(0) == "build"){
            if (commands.size() > 4 ){
                if (regex_match(commands.at(1), regex("^[0-9]{6}$"))){
                    if (regex_match(commands.at(2), regex("^[A-Z]{2,4}$"))){
                        if (regex_match(commands.at(3), regex("^(10[0-9]|1[1-9][0-9]|[2-6][0-9]{2}|700)$"))){
                            //build a course in courselist
                            string courseName = "";
                            size_t index = 0;
                            for(index = 4; index < commands.size(); index++){
                                courseName += commands.at(index);
                                if(index != commands.size() - 1){
                                courseName += " ";
                                }
                            }

                            Course newCourse = Course(commands.at(1), commands.at(2), commands.at(3), courseName); 
        
                            totalCourses.addCourse(newCourse);
                        }
                        else{
                            cout << "Input Error: Illegal Course Number" << endl;

                        }
                    }
                    else{
                        cout << "Input Error: Illegal Department" << endl;

                    }
                }
                else{
                    cout << "Input Error: Invalid CRN" << endl;

                }
            }
            else{
                cout << "Input Error: Too few arguments" << endl;
            }
                
        }
        else if (commands.at(0) == "cancel"){
                //Course* currCourse = (totalCourses.searchByCRN(commands.at(1)));
                if (commands.size() > 2){
                    cout << "Warning: ignoring extra argument(s)" << endl;
                }
                if (commands.size() > 1){
         
                    if (regex_match(commands.at(1), regex("^[0-9]{6}"))){


                     Course* currCourse(totalCourses.searchByCRN(commands.at(1)));
                 
                        if (currCourse != nullptr){
                            if (totalCourses.doesCourseExist(currCourse->getCRN())){
                        

                            string* newArray = currCourse->getBnumbers(); //array of bNumbers
                            
                            //Student* currStudent;
                                for (int i = 0; i< currCourse->getQuantity();i++){

                                    Student* currStudent(totalStudents.searchByBnumber(newArray[i]));
                       
                                    currStudent->dropCourses(commands.at(1));
                                    currCourse->dropStudent(newArray[i]);
                   
                                    
                                    
                                }


                                totalCourses.removeCourse(*currCourse);
                                    
                            }
                            cout << "Success: cancelled course " << commands.at(1) << endl;
                           
                        }
                        else{
                            cout<< "Fail: cannot cancel course, CRN does not exist" << endl;
                            
                            
                        }
                

                    }
                    else{
                        cout << "Error: Illegal CRN" << endl;
                    }
                    
                }
        
            
               

        }
        else if (commands.at(0) == "enroll"){
                if (commands.size() > 4){
                    if (regex_match(commands.at(1), regex("([B][0-9]{8})"))){
                        if(regex_match(commands.at(2), regex("^[a-z]{1}[a-z0-9]+$"))){
                            Student newStudent(commands.at(1), commands.at(2), commands.at(3), commands.at(4));
                            totalStudents.addStudent(newStudent);
                           

                        }
                        else{
                            cout << "Error: Illegal Username" << endl;
                        }
    
                            
                    }
                    else{
                        cout << "Error: Illegal B-Number" << endl;
                    }
                    
                    
                }
                else{
                    cout << "Input Error: Too few arguments" << endl;
                }
        

             
               

        }
        else if (commands.at(0) == "add"){
                if (commands.size() > 2){
                    if (regex_match(commands.at(1), regex("([B][0-9]{8})"))){
                        if (regex_match(commands.at(2), regex("^[0-9]{6}$"))){
                            Student* currStudent = (totalStudents.searchByBnumber(commands.at(1)));
                            Course* currCourse = (totalCourses.searchByCRN(commands.at(2)));
            
                            if ((currStudent != nullptr ) && (currCourse != nullptr)) {
                                currCourse->addStudent(currStudent->getBNumber());
                                currStudent->addCourses(currCourse->getCRN());

                            }
                            else{
                                cout << "Failed: Either Student is not yet enrolled or Course is not yet built" << endl;
                            }
                        }
                        else{
                            cout << "Error: Illegal CRN" << endl;
                        }
                    }
                    else{
                        cout << "Error: Illegal B-Number" << endl;
                    }

                }
                else{
                    cout << "Input Error: Too few arguments" << endl;
                }
        
               
        }
        else if (commands.at(0) == "drop"){
                if (commands.size() > 2){
                    if (commands.size() > 2){
                        if (regex_match(commands.at(1), regex("([B][0-9]{8})"))){
                            if (regex_match(commands.at(2), regex("^[0-9]{6}$"))){
                                Student* currStudent(totalStudents.searchByBnumber(commands.at(1)));
                                Course* currCourse(totalCourses.searchByCRN(commands.at(2)));
                                if ((currStudent != nullptr ) && (currCourse != nullptr)) {
                                    currCourse->dropStudent(currStudent->getBNumber());
                                    currStudent->dropCourses(currCourse->getCRN());
                                }
                                else{
                                    cout << "Failed: Either Student is not yet enrolled or Course is not yet built" << endl;
                                }
                            }
                            else{
                                cout << "Error: Illegal CRN" << endl;

                            }
                            
                        }
                        else{
                            cout << "Error: Illegal B-Number" << endl;

                        }
                    }
                    else{
                        cout << "Input Error: Too few arguments" << endl;
                    }
            }
                
        }
        else if (commands.at(0) == "roster"){

                if (commands.size() > 1){
                    if (regex_match(commands.at(1), regex("^[0-9]{6}$"))){
                        Course* currCourse(totalCourses.searchByCRN(commands.at(1))); //creates current course object
                   
                        if (currCourse != nullptr){
                            string* currBnumbers = currCourse->getBnumbers(); //returns array of students
                            cout << "CRN: " << currCourse->getCRN() << endl;
                            cout << "Students: " << currCourse->getQuantity() << endl;
                            for(int i = 0; i<currCourse->getQuantity();i++){

                                totalStudents.showStudent(currBnumbers[i]);

                            }

                        }
                        else{
                            cout << "Error: Class is not yet built" << endl;
                        }    
                        
                    }
                    else{
                        cout << "Error: Illegal CRN" << endl;
                    }
                }
                else{
                    cout << "Input Error: Too few arguments" << endl;
                }

        }
        else if (commands.at(0) == "schedule"){
                if (commands.size() > 1){
                    if (regex_match(commands.at(1), regex("([B][0-9]{8})"))){

                        Student* currStudent = (totalStudents.searchByBnumber(commands.at(1)));
                        string* currCRNS = currStudent->getCRNS();
            
                        //cout <<"current crn number is" << currCRNS[i] << endl;
                        cout << "Student: ";
                        cout << currStudent->getBNumber();
                        cout << ": ";
                        currStudent->getFullName();

                        for(int i = 0; i<currStudent->getQuantity();i++){
                            totalCourses.showCourse(currCRNS[i]);
                        }
                    }
                    else{
                        cout << "Error: Illegal B-Number" << endl;
                    }

                }
                else{
                    cout << "Input Error: Too few arguments" << endl;
                }
                
                
               
        }
        else{
            cout << "Command not recognized, please try again." << endl;
        }




    }
    


    /*vector<string> commands;
    size_t curr_position;
    while(curr_position = commands.find(" ") != string::npos){
        commands.push_back(userinput.substr(0, curr_position));
    }*/

}


//


//read line of user input
//split string by spaces
//use cond to do smthin
// functions needed: build, cancel, enroll, add, drop