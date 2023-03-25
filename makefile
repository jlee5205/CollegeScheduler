
all: clean scheduler.o
	g++ scheduler.o Student.o Course.o StudentList.o CourseList.o -o scheduler_main

scheduler.o: scheduler.cpp CourseList.o StudentList.o
	g++ -std=c++11 -c scheduler.cpp -o scheduler.o

Student.o: Student.cpp Student.h
	g++ -std=c++11 -c Student.cpp -o Student.o

Course.o: Course.cpp Course.h
	g++ -std=c++11 -c Course.cpp -o Course.o

StudentList.o: StudentList.cpp StudentList.h Student.h Student.o
	g++ -std=c++11 -c StudentList.cpp -o StudentList.o

CourseList.o: CourseList.cpp CourseList.h Course.h Course.o
	g++ -std=c++11 -c CourseList.cpp -o CourseList.o

clean:
	rm -f *.o main scheduler_main
