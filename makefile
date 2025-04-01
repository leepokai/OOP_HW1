CC = g++

CFLAGS = -std=c++11 -Wall

TARGET = todo_list

SOURCES = src/main.cpp src/basic_task.cpp src/task.cpp src/tasks_manager.cpp \
          src/school_task.cpp src/job_task.cpp

HEADERS = include/basic_task.h include/task.h include/tasks_manager.h include/job_task.h include/school_task.h

OBJECTS = $(SOURCES:.cpp=.o)

INCLUDES = -Iinclude

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


clean:
	del /Q $(subst /,\,$(OBJECTS)) $(TARGET).exe

run: $(TARGET)
	$(TARGET).exe