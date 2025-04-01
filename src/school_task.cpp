#include "../include/school_task.h"
#include "../include/task.h"
#include <iostream>
#include <limits>
SchoolTask::SchoolTask(const string* name, const string* category, 
                      const string* subject, const string* deadline, 
                      const int* priority) 
    : Task(name, category) {
    this->subject = new string(*subject);
    this->deadline = new string(*deadline);
    this->priority = new int(*priority);
}

SchoolTask::~SchoolTask() {
    delete subject;
    delete deadline;
    delete priority;
}

string SchoolTask::getSubject() const {
    return *subject;
}

string SchoolTask::getDeadline() const {
    return *deadline;
}


void SchoolTask::setSubject(const string* taskSubject) {
    *subject = *taskSubject;
}

void SchoolTask::setDeadline(const string* taskDeadline) {
    *deadline = *taskDeadline;
}

bool SchoolTask::editSpecificAttributes() {
    string tempInput;
    
    cout << "Current subject: " << *subject << "\nEnter new subject (or press Enter to keep current): ";
    getline(cin, tempInput);
    if (!tempInput.empty()) {
        *subject = tempInput;
    }
    
    cout << "Current deadline: " << *deadline << "\nEnter new deadline (or press Enter to keep current): ";
    tempInput.clear();
    getline(cin, tempInput);
    if (!tempInput.empty()) {
        *deadline = tempInput;
    }
    
    cout << "Current priority: " << *priority << "\nEnter new priority (1-10) (or press Enter to keep current): ";
    tempInput.clear();
    getline(cin, tempInput);
    if (!tempInput.empty()) {
        try {
            int newPriority = stoi(tempInput);
            if (newPriority >= 1 && newPriority <= 10) {
                *priority = newPriority;
            } else {
                cout << "Invalid priority. Value should be between 1-10. Keeping current value.\n";
            }
        } catch (...) {
            cout << "Invalid input. Keeping current priority.\n";
        }
    }
    
    return true;  
}

void SchoolTask::displayDetails() const {
    cout << "ID: " << getId() 
         << " | Name: " << getName()
         << " | Category: " << getCategory()
         << " | Subject: " << getSubject()
         << " | Deadline: " << getDeadline()
         << " | Priority: " << getPriority()
         << " | Status: " << (isCompleted() ? "Completed" : "Pending")
         << endl;
}