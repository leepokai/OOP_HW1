#ifndef TASK_H
#define TASK_H

#include "basic_task.h"

class Task : public BasicTask{
    private: 
        int* taskId;
    protected:
        int* priority;
    public:
        static int* nowTaskid;
        Task(const string* name, const string* category);
        virtual ~Task();
        
        int getPriority() const;
        virtual int getId() const;

        void setPriority(const int* taskPriority);

        virtual void displayDetails() const;
        virtual bool editSpecificAttributes(){return false;}; 

        
    
};
#endif