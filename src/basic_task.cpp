#include "../include/basic_task.h"

BasicTask::BasicTask(const string* name, const string* category){
    this->name = new string(*name);
    this->category = new string(*category);
    this->completed = new bool(false);
}

BasicTask::~BasicTask(){
    delete name;
    delete category;
    delete completed;
}

string BasicTask::getName() const{
    return *name;
}

string BasicTask::getCategory() const{
    return *category;
}

bool BasicTask::isCompleted() const{
    return *completed;
}

void BasicTask::setName(const string* taskname){
    *name = *taskname;
    return;
}

void BasicTask::setCategory(const string* taskCategory){
    *category = *taskCategory;
    return;
}

void BasicTask::setCompleted(const bool* isCompleted){
    *completed = *isCompleted;
    return;
}