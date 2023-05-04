# What is CollegeScheduler?
This is a program that allows the user to create courses and enroll students for a academic institute or academy. Users can enroll students with an Student ID, Student username, first and last name. The user can also create courses for the institute with class CRN, department abbreviation, course number, and course name, as well as deleting these courses. The user can use these add or drop students from courses, find the schedule of a particular student, and find the roster of students for a particular course. The students and courses are stored in memory until you end the program. 

# Compiling and Running the Program
After cloning the repo, you can complile the program by typing ***make***, which creates an executable named ***scheduler_main***. Run ./scheduler_main to see displayed prompt. See the makefile for more details.

# Plans for the Future
Since this program saves the data only until the program ends, it will be up for more practical use if I were to implment a way to store data from the program into a database. Also, although I already have a function to delete courses, I do not have one yet to unenroll students. 
