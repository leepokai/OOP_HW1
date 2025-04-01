#include "../include/task.h"
#include "../include/basic_task.h"
#include <iostream>
Task::Task(const string* name, const string* category) : BasicTask(name, category){
    taskId = new int(*nowTaskid); 
    (*nowTaskid)++;
}

Task::~Task() {
    delete taskId;
}

int Task::getId() const {
    return *taskId;
}

void Task::displayDetails() const {
    cout << "ID: " << getId() 
         << " | Name: " << getName()
         << " | Category: " << getCategory()
         << " | Status: " << (isCompleted() ? "Completed" : "Pending")
         << endl;
}

void Task::setPriority(const int* priority){
    *(this->priority) = *priority;
}

int Task::getPriority() const{
    return *(this->priority);
}
