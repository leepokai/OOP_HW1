#include "../include/job_task.h"
#include "../include/task.h"
#include <iostream>
#include <limits>
Jobtask::Jobtask(const string* name, const string* category,const string* client, const string* dueDate , const int* priority, const double* hours): Task(name,category){
    this->client = new string(*client);
    this->dueDate = new string(*dueDate);
    this->priority = new int(*priority);
    this->hours = new double(*hours);
}

Jobtask::~Jobtask(){
    //記得回來寫額外 新增的4個
    delete client;
    delete dueDate;
    delete priority;
    delete hours;
}

string Jobtask::getClient() const{
    return *client;
}

string Jobtask::getDueDate() const{
    return *dueDate;
}


double Jobtask::getHours() const{
    return *hours;
}

void Jobtask::setClient(const string* taskclient) {
    *client = *taskclient;
    return;
}

void Jobtask::setDueDate(const string* taskdueDate) {
    *dueDate = *taskdueDate;
    return;
}


void Jobtask::setHours(const double* taskhours) {
    *hours = *taskhours;
    return;
}


bool Jobtask::editSpecificAttributes() {
    string tempInput;
    
    cout << "Current client: " << *client << "\nEnter new client (or press Enter to keep current): ";
    getline(cin, tempInput);
    if (!tempInput.empty()) {
        *client = tempInput;
    }
    
    cout << "Current due date: " << *dueDate << "\nEnter new due date (or press Enter to keep current): ";
    tempInput.clear();
    getline(cin, tempInput);
    if (!tempInput.empty()) {
        *dueDate = tempInput;
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
    
    cout << "Current hours: " << *hours << "\nEnter new estimated hours (or press Enter to keep current): ";
    tempInput.clear();
    getline(cin, tempInput);
    if (!tempInput.empty()) {
        try {
            double newHours = stod(tempInput);
            if (newHours > 0) {
                *hours = newHours;
            } else {
                cout << "Invalid hours. Value should be positive. Keeping current value.\n";
            }
        } catch (...) {
            cout << "Invalid input. Keeping current hours.\n";
        }
    }
    
    return true;  
}

void Jobtask::displayDetails() const {
    cout << "ID: " << getId() 
         << " | Name: " << getName()
         << " | Category: " << getCategory()
         << " | Client: " << getClient()
         << " | Due Date: " << getDueDate()
         << " | Priority: " << getPriority()
         << " | Est. Hours: " << getHours()
         << " | Status: " << (isCompleted() ? "Completed" : "Pending")
         << endl;
}