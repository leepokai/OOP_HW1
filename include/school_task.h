#pragma once
#include <string>
#include "task.h"
using namespace std;

class SchoolTask : public Task {
    private:
        string* subject;      
        string* deadline;           
        
    public:
        SchoolTask(const string* name, const string* category, 
                  const string* subject, const string* deadline, 
                  const int* priority);
        virtual ~SchoolTask();
        
        string getSubject() const;
        string getDeadline() const;

        
        void setSubject(const string* taskSubject);
        void setDeadline(const string* taskDeadline);


        virtual void displayDetails() const override;
        virtual bool editSpecificAttributes() override;
};