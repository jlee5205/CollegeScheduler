
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
	rm -f *.o main
	rm scheduler_main




# all: $(BIN)/$(EXE)

# $(BIN)/$(EXE): $(OBJ)/scheduler.o
# 	$(CC) $(FLAGS) $(OBJ)/scheduler.o $(OBJ)/Student.o $(OBJ)/Course.o $(OBJ)/StudentList.o $(OBJ)/CourseList.o -o $@

# $(OBJ)/scheduler.o: scheduler.cpp $(OBJ)/CourseList.o $(OBJ)/StudentList.o
# 	$(CC) $(FLAGS) -c scheduler.cpp -o $@

# $(OBJ)/Student.o: Student.cpp Student.h
# 	$(CC) $(FLAGS) -c Student.cpp -o $@

# $(OBJ)/Course.o: Course.cpp Course.h
# 	$(CC) $(FLAGS) -c Course.cpp -o $@

# $(OBJ)/StudentList.o: StudentList.cpp StudentList.h Student.h $(OBJ)/Student.o
# 	$(CC) $(FLAGS) -c StudentList.cpp -o $@

# $(OBJ)/CourseList.o: CourseList.cpp CourseList.h Course.h $(OBJ)/Course.o
# 	$(CC) $(FLAGS) -c CourseList.cpp -o $@

# tar:	clean
# 	tar cvvf $(TARFILE) $(REPODIR)
# 	gzip $(TARFILE)

# clean:
# 	rm -f $(OBJ)/*.o $(BIN)/$(EXE) *.tar.gz
