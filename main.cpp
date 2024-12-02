#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node {
    string date;
    vector<string> tasks;
    Node* left;
    Node* right;

    Node(const string& date) {
        this->date = date;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class TaskTree {
public:
    Node* root;

    TaskTree() {
        root = nullptr;
    }

    void Add(const string& date, const string& task) {
        root = Add(root, date, task);
    }

    void EditTask(const string& date, int taskIndex, const string& newTask) {
        Node* node = Search(root, date);
        if (node && taskIndex >= 0 && taskIndex < node->tasks.size()) {
            node->tasks[taskIndex] = newTask;
            cout << "Task updated." << endl;
        } else {
            cout << "Invalid task index or date." << endl;
        }
    }

    void DeleteTask(const string& date, int taskIndex) {
        Node* node = Search(root, date);
        if (node && taskIndex >= 0 && taskIndex < node->tasks.size()) {
            node->tasks.erase(node->tasks.begin() + taskIndex);
            cout << "Task deleted." << endl;
        } else {
            cout << "Invalid task index or date." << endl;
        }
    }

    void DisplayTasks(const string& date) {
        Node* node = Search(root, date);
        if (node) {
            cout << "Tasks for " << date << ":" << endl;
            for (int i = 0; i < node->tasks.size(); i++) {
                cout << i + 1 << ". " << node->tasks[i] << endl;
            }
        } else {
            cout << "No tasks for " << date << "." << endl;
        }
    }

    void DisplayAllTasks() {
        InOrder(root);
    }

    void DisplayAllTasksInMonth(int month, int year) {
        int daysInMonth = getDaysInMonth(month, year);
        for (int day = 1; day <= daysInMonth; day++) {
            string date = formatDate(year, month, day);
            DisplayTasks(date);
        }
    }

    Node* Search(Node* node, const string& date) {
        if (!node || node->date == date) {
            return node;
        }
        if (date < node->date) {
            return Search(node->left, date);
        }
        return Search(node->right, date);
    }

private:
    Node* Add(Node* node, const string& date, const string& task) {
        if (!node) {
            Node* newNode = new Node(date);
            newNode->tasks.push_back(task);
            return newNode;
        }

        if (date < node->date) {
            node->left = Add(node->left, date, task);
        } else if (date > node->date) {
            node->right = Add(node->right, date, task);
        } else {
            node->tasks.push_back(task);
        }
        return node;
    }

    void InOrder(Node* node) {
        if (node) {
            InOrder(node->left);
            cout << "Tasks for " << node->date << ":" << endl;
            for (int i = 0; i < node->tasks.size(); i++) {
                cout << "- " << node->tasks[i] << endl;
            }
            InOrder(node->right);
        }
    }

    // Check if a year is a leap year
    bool isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    // Get the number of days in a given month and year
    int getDaysInMonth(int month, int year) {
        switch (month) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                return 31;
            case 4: case 6: case 9: case 11:
                return 30;
            case 2:
                if (isLeapYear(year)) {
                    return 29;
                } else {
                    return 28;
                }
            default:
                return 0;
        }
    }

    // Format a date as "YYYY-MM-DD"
    string formatDate(int year, int month, int day) {
        char buffer[11];
        snprintf(buffer, sizeof(buffer), "%04d-%02d-%02d", year, month, day);
        return string(buffer);
    }
};

// Check if leap year
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Get the number of days in a given month/year
int getDaysInMonth(int month, int year) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            if (isLeapYear(year)) {
                return 29;
            } else {
                return 28;
            }
        default:
            return 0;
    }
}

// Get the start day of the week for a given month/year
int getStartDayOfMonth(int month, int year) {
    int totalDays = 0;

    for (int y = 1; y < year; y++) {
        if (isLeapYear(y)) {
            totalDays += 366;
        } else {
            totalDays += 365;
        }
    }

    for (int m = 1; m < month; m++) {
        totalDays += getDaysInMonth(m, year);
    }

    return (totalDays + 1) % 7;
}

// Format a date as "YYYY-MM-DD"
string formatDate(int year, int month, int day) {
    char buffer[11];
    snprintf(buffer, sizeof(buffer), "%04d-%02d-%02d", year, month, day);
    return string(buffer);
}

// Add a task for a specific date
void addTask(int year, int month, int day, const string& task, TaskTree& taskTree) {
    string date = formatDate(year, month, day);
    taskTree.Add(date, task);
    cout << "Task added for " << date << ": " << task << endl;
}

// Display tasks for a specific date
void displayTasks(int year, int month, int day, TaskTree& taskTree) {
    string date = formatDate(year, month, day);
    taskTree.DisplayTasks(date);
}

// Print the calendar for a given month and year
void printCalendar(int month, int year, TaskTree& taskTree) {
    const string months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    cout << "      " << months[month - 1] << " " << year << endl;
    cout << "Mo Tu We Th Fr Sa Su" << endl;

    int startDay = getStartDayOfMonth(month, year);
    int daysInMonth = getDaysInMonth(month, year);

    for (int i = 0; i < startDay; i++) {
        cout << "   ";
    }

    for (int day = 1; day <= daysInMonth; day++) {
        string date = formatDate(year, month, day);
        if (taskTree.Search(taskTree.root, date)) {
            cout << "[" << day << "]";
        } else {
            cout << " ";
            if (day < 10) {
                cout << " ";
            }
            cout << day << " ";
        }

        if ((startDay + day) % 7 == 0) {
            cout << endl;
        }
    }
    cout << endl;
}

int main() {
    TaskTree taskTree;
    int month, year, day;
    char choice;

    // Loop until the user wants to quit
    do {
        cout << "Enter the month (1-12): ";
        cin >> month;
        cout << "Enter the year: ";
        cin >> year;

        if (month < 1 || month > 12) {
            cout << "Invalid month. Try again." << endl;
            continue;
        }

        cout << "\nOptions: Add Task (a), View Tasks (v), Edit Task (e), Delete Task (d), View All Tasks in Month (m), Quit (q): ";
        cin >> choice;

        while (choice == 'a' || choice == 'v' || choice == 'e' || choice == 'd' || choice == 'm') {
            if (choice == 'a') {
                cout << "Enter day (1-31): ";
                cin >> day;
                cin.ignore(); 

                cout << "Enter task: ";
                string task;
                getline(cin, task);
                addTask(year, month, day, task, taskTree);

            } else if (choice == 'v') {
                cout << "Enter day (1-31): ";
                cin >> day;
                displayTasks(year, month, day, taskTree);

            } else if (choice == 'e') {
                cout << "Enter day (1-31): ";
                cin >> day;
                string date = formatDate(year, month, day);
                taskTree.DisplayTasks(date);

                cout << "Enter task number to edit: ";
                int taskIndex;
                cin >> taskIndex;
                cin.ignore(); 

                cout << "Enter new task description: ";
                string newTask;
                getline(cin, newTask);
                taskTree.EditTask(date, taskIndex - 1, newTask);
                
            } else if (choice == 'd') {
                cout << "Enter day (1-31): ";
                cin >> day;
                string date = formatDate(year, month, day);
                taskTree.DisplayTasks(date);

                cout << "Enter task number to delete: ";
                int taskIndex;
                cin >> taskIndex;
                taskTree.DeleteTask(date, taskIndex - 1);

            } else if (choice == 'm') {
                taskTree.DisplayAllTasksInMonth(month, year);
            }

            cout << "\nOptions: Add Task (a), View Tasks (v), Edit Task (e), Delete Task (d), View Tasks in Month (m), Quit (q): ";
            cin >> choice;
        }

    } while (choice != 'q');

    cout << "Goodbye!" << endl;
    return 0;
}
