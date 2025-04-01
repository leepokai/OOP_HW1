#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include <vector>
#include <set>
#include "task.h"
#include "school_task.h"
#include "job_task.h"
using namespace std;

struct TaskPriorityCompare
{
    bool operator() (const BasicTask* task1, const BasicTask* task2){
        const Task* t1 = dynamic_cast<const Task*>(task1);
        const Task* t2 = dynamic_cast<const Task*>(task2);
        
        if(t1 && t2){
            int p1 = t1->getPriority();
            int p2 = t2->getPriority();
            if(p1 == p2){ 
                return t1->getId() < t2->getId();
            }
            return p1 > p2;
        }
        return 1;
    }
};


class TasksManager {
    private:
        set<BasicTask*, TaskPriorityCompare> *tasks;
    public:
        TasksManager();
        ~TasksManager();

        void addTask(const string* name, const string *catergory);
        void viewTasks() const;
        void viewTasksByCategory(const string* category) const;
        void viewTasksByStatus(const bool* completed) const;
        void editTask(int* taskId, const string* newName,const bool* completed);
        void deleteTask(int* taskId);
        // void markTaskAsCompleted(int* taskId);
};
#endif