#include <iostream>
#include <string>
#include <limits>
#include "../include/tasks_manager.h"
using namespace std;

int* Task::nowTaskid = new int(0);

void displayMenu() {
    cout << "\n========== Todo List Management System ==========\n";
    cout << "1. Add Task\n";
    cout << "2. View All Tasks\n";
    cout << "3. Edit Task\n";
    cout << "4. Delete Task\n";
    cout << "0. Exit Program\n";
    cout << "=================================================\n";
    cout << "Please select a function (0-5): ";
}

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    TasksManager *manager = new TasksManager();
    int *choice = new int(0);
    string* name = new string("");
    string* category = new string("");
    int* taskId = new int(0);
    bool* completed = new bool(0);

    cout << "Welcome to Todo List Management System!\n";
    
    while(true) {
        displayMenu();
        
        if (!(cin >> *choice)) {
            cout << "Invalid input, please try again.\n";
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();
        
        switch (*choice) {
            case 0: 
                cout << "Thank you for using. Goodbye!\n";
                delete name;
                delete category;
                delete taskId;
                delete completed;
                delete Task::nowTaskid;
                return 0;
                
            case 1: 
                cout << "\n--- Add Task ---\n";
                cout << "Enter task name: ";
                getline(cin, *name);
                cout << "Enter task category: \n option 1: type school \n option 2: type job\n Enter your option : ";
                getline(cin, *category);
                manager->addTask(name, category);
                break;
                
            case 2: 
                cout << "\n--- View Tasks Arranged by priority---\n";
                cout << "1. View all tasks\n";
                cout << "2. View by category\n";
                cout << "3. View completed tasks\n";
                cout << "4. View pending tasks\n";
                cout << "Choose view option: ";
                
                int viewOption;
                if (!(cin >> viewOption)) {
                    cout << "Invalid option. Showing all tasks.\n";
                    clearInputBuffer();
                    manager->viewTasks();
                } else {
                    clearInputBuffer();
                    
                    switch (viewOption) {
                        case 1:
                            manager->viewTasks();
                            break;
                        case 2:
                            cout << "Enter category to filter by: ";
                            getline(cin, *category);
                            manager->viewTasksByCategory(category);
                            break;
                        case 3:
                            *completed = 1;
                            manager->viewTasksByStatus(completed);  
                            break;
                        case 4:
                            *completed = 0;
                            manager->viewTasksByStatus(completed);  
                            break;
                        default:
                            cout << "Invalid option. Showing all tasks.\n";
                            manager->viewTasks();
                    }
                }
                break;
                
            case 3: 
                cout << "\n--- Edit Task ---\n";
                cout << "Enter task ID to edit: ";
                cin >> *taskId;
                clearInputBuffer();
                
                cout << "Enter new task name: ";
                getline(cin, *name);
                cout << "Enter whether the task is complete, 0 is not complete, 1 is complete: ";
                cin>> *completed;
                clearInputBuffer();

                manager->editTask(taskId, name, completed);
                cout << "Task updated!\n";
                break;
                
            case 4: 
                cout << "\n--- Delete Task ---\n";
                cout << "Enter task ID to delete: ";
                cin >> *taskId;
                clearInputBuffer();
                
                manager->deleteTask(taskId);
                cout << "Task deleted!\n";
                break;
            default:
                cout << "Invalid choice, please try again.\n";
                break;
        }
    }
    
    return 0;
}