COURSE = cs240
SEMESTER = spring2023
CP_NUMBER = 2
LASTNAME = Lee
GITUSERID = jlee5205
EXE = scheduler_cp2

REPODIR = ../$(COURSE)-$(SEMESTER)-cp$(CP_NUMBER)-$(GITUSERID)
TARFILE = CP$(CP_NUMBER)_$(LASTNAME)_$(USER)_$(GITUSERID).tar

FLAGS = -Wall -Wextra -g
# FLAGS = -Wall -O3
CC = g++
BIN = bin
OBJ = obj

all: $(BIN)/$(EXE)

$(BIN)/$(EXE): $(OBJ)/scheduler.o
	$(CC) $(FLAGS) $(OBJ)/scheduler.o $(OBJ)/Student.o $(OBJ)/Course.o $(OBJ)/StudentList.o $(OBJ)/CourseList.o -o $@

$(OBJ)/scheduler.o: scheduler.cpp $(OBJ)/CourseList.o $(OBJ)/StudentList.o
	$(CC) $(FLAGS) -c scheduler.cpp -o $@

$(OBJ)/Student.o: Student.cpp Student.h
	$(CC) $(FLAGS) -c Student.cpp -o $@

$(OBJ)/Course.o: Course.cpp Course.h
	$(CC) $(FLAGS) -c Course.cpp -o $@

$(OBJ)/StudentList.o: StudentList.cpp StudentList.h Student.h $(OBJ)/Student.o
	$(CC) $(FLAGS) -c StudentList.cpp -o $@

$(OBJ)/CourseList.o: CourseList.cpp CourseList.h Course.h $(OBJ)/Course.o
	$(CC) $(FLAGS) -c CourseList.cpp -o $@

tar:	clean
	tar cvvf $(TARFILE) $(REPODIR)
	gzip $(TARFILE)

clean:
	rm -f $(OBJ)/*.o $(BIN)/$(EXE) *.tar.gz
