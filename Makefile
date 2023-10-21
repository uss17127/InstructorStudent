CFLAGS = -g
CC = g++

all: main


main: Student.h Instructor.h main.cpp Student.cpp Instructor.cpp
	$(CC) $(CFLAGS) main.cpp Student.cpp Instructor.cpp -o main

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@
