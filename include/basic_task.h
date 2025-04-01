#ifndef BASIC_TASK_H
#define BASIC_TASK_H

#include <string>
using namespace std;
class BasicTask {
    protected:
        string* name;
        string* category;
        bool* completed;
    public:
        BasicTask(const string* name, const string* category);
        virtual ~BasicTask();
        
        string getName() const;
        string getCategory() const;
        bool isCompleted() const;

        void setName(const string* taskName);
        void setCategory(const string* taskCategory);
        void setCompleted(const bool* completed);
        
};
#endif 