#include "../include/tasks_manager.h"
#include "../include/task.h"
#include "../include/basic_task.h"
#include "../include/job_task.h"
#include "../include/school_task.h"
#include <iostream>
#include <algorithm>
#include <limits>
TasksManager::TasksManager(){
    tasks = new set<BasicTask*, TaskPriorityCompare>();
}
// for (BasicTask* task : *tasks) {
//     Task* derivedTask = dynamic_cast<Task*>(task);
//     if (derivedTask) {
//         derivedTask->displayDetails();
//     }
// }
TasksManager::~TasksManager(){
    for (auto it = tasks->begin(); it != tasks->end(); ++it) {
        delete *it;  
    }
    delete tasks;
}

void TasksManager::addTask(const string* name, const string* category){
    // BasicTask* new_task = new Task(name, category);
    //cout<<"test"<<"\n";
    string *lowerCategory = new string(*category); 
    transform(lowerCategory->begin(),lowerCategory->end(),lowerCategory->begin(),[](unsigned int c){return tolower(c);});
    if(*lowerCategory == "school"){
        string* subject = new string("");
        string* deadline = new string("");
        int* priority = new int(0);
        
        cout << "School task detected! Please provide additional information:\n";
        cout << "Enter subject: ";
        getline(cin, *subject);
        cout << "Enter deadline: ";
        getline(cin, *deadline);
        cout << "Enter priority (1-10): ";
        cin >> *priority;
        // there will be some problem when use clearInputBuffer 可能在 linker 那邊有問題
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        BasicTask* new_task = new SchoolTask(name, category, subject, deadline, priority);
        tasks->insert(new_task);
        
        delete subject;
        delete deadline;
        delete priority;
    }
    else if(*lowerCategory == "job"){
        string* client = new string("");
        string* dueDate = new string("");
        int* priority = new int(0);
        double* hours = new double(0.0);
        
        cout << "Job task detected! Please provide additional information:\n";
        cout << "Enter client: ";
        getline(cin, *client);
        cout << "Enter due date: ";
        getline(cin, *dueDate);
        cout << "Enter priority (1-10): ";
        cin >> *priority;
        //cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter estimated hours: ";
        cin >> *hours;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        
        BasicTask* new_task = new Jobtask(name, category, client, dueDate, priority, hours);
        tasks->insert(new_task);
        
        delete client;
        delete dueDate;
        delete priority;
        delete hours;
    }
    else{
        cout<<"no such a category type"<<"\n";
        return;
    }
}

void TasksManager::deleteTask(int* taskId){
    for(auto it=tasks->begin();it!=tasks->end();it++){
        Task* task = dynamic_cast<Task*>(*it);
        if(task && task->getId() == *taskId){
            delete task;
            tasks->erase(it);
            break;
        }
    }
}

void TasksManager::editTask(int* taskId, const string* newName,const bool* isCompleted) {
    for (auto it = tasks->begin(); it != tasks->end(); ++it) {
        Task* task = dynamic_cast<Task*>(*it);
        if (task && task->getId() == *taskId) {
            task->setName(newName);
            // 記得不能 set Category 因為我們的 school 和 job 是固定的
            task->setCompleted(isCompleted);
            task->editSpecificAttributes();
            cout<<"task Fix complete\n";
            break;
            // 記得之後在看看要步要做 針對 school task 和 job task 的 edit
        }
    }
}



void TasksManager::viewTasks() const {
    cout << "\n=== task list ===\n";
    if(tasks->empty()){
        cout<<"No tasks found."<<"\n";
        return;
    }
    
    for (auto it = tasks->begin(); it != tasks->end(); ++it) {
        Task* task = dynamic_cast<Task*>(*it);
        if(task){
            task->displayDetails();
        }
    }
}

void TasksManager::viewTasksByStatus(const bool* completed) const{
    cout << "\n=== " << (*completed ? "Completed" : "Pending") << " Tasks ===\n";

    bool found = false;
    
    for (auto it = tasks->begin(); it != tasks->end(); ++it) {
        Task* task = dynamic_cast<Task*>(*it);
        if (task && task->isCompleted() == *completed) {
            task->displayDetails();
            found = true;
        }
    }
    
    if (!found) {
        cout << "No " << (completed ? "completed" : "pending") << " tasks found.\n";
    }
}
void TasksManager::viewTasksByCategory(const string* category) const {
    cout << "\n=== Tasks in Category: " << *category << " ===\n";
    bool found = false;
    
    for (auto it = tasks->begin(); it != tasks->end(); ++it) {
        Task* task = dynamic_cast<Task*>(*it);
        if (task && task->getCategory() == *category) {
            task->displayDetails();
            found = true;
        }
    }
    
    if (!found) {
        cout << "No tasks found in this category.\n";
    }
}