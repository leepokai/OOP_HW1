# pragma once
# include <string>
# include "task.h"
using namespace std;
class Jobtask : public Task{
    private:
        string* client;
        string* dueDate;
        double* hours;
    public:
        Jobtask(const string* name, const string* category,const string* client, const string* dueDate , const int* priority, const double* hours);
        virtual ~Jobtask();
 
        string getClient() const; 
        string getDueDate() const; 
        double getHours() const;
        
        void setClient(const string* taskclient); 
        void setDueDate(const string* taskdueDate); 
        void setHours(const double* taskhours);

        virtual void displayDetails() const override;
        virtual bool editSpecificAttributes() override;
};

