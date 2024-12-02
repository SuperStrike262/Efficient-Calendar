# Efficient-Calendar

Overview

This program provides a task management system where users can manage tasks by adding, viewing, editing, and deleting them. It also
allows viewing tasks by month and year, integrating a binary search tree (BST) to store tasks by date. The program also includes a basic
calendar system to display tasks on specific days and evaluate performance through timing tasks.
The core functionality of the program is provided by the TaskTree class, which manages tasks associated with dates, as well as various
utility functions to handle tasks and dates.

Features

1. Add Task: Allows the user to add tasks to specific dates.
2. View Tasks: Displays tasks associated with a specific date.
3. Edit Task: Enables the user to edit an existing task for a given date.
4. Delete Task: Removes a specific task from the list for a given date.
5. View Tasks for a Month: Displays all tasks for a specified month and year.
6. Display Calendar: Prints a calendar for a specified month and year, with task markers on the corresponding days.
7. Performance Measurement: Measures and displays the time taken for certain operations, such as viewing tasks for a month.

Structure

The program consists of the following components:

1. Node Struct: Represents a single node in the binary search tree. 
Each node contains:
- date: The date associated with the tasks (in "YYYY-MM-DD" format).
- tasks: A vector of tasks associated with that date.
- left and right: Pointers to the left and right children in the binary search tree.

2. TaskTree Class: Manages the binary search tree of tasks. It allows for:
- Add: Adding tasks to the tree.
- Search: Searching for a node by date.
- Edit and Delete: Editing or deleting tasks for a given date.
- In-Order Traversal: Displays all tasks in ascending date order.
- Display Tasks: Displays tasks for a given date or all tasks for a month.

3. Utility Functions:
- getDaysInMonth: Returns the number of days in a month, considering leap years.
- isLeapYear: Checks if a year is a leap year.
- getStartDayOfMonth: Determines the starting day of the week for a given month and year.
- formatDate: Formats a date as a string in "YYYY-MM-DD" format.
- printCalendar: Prints a calendar for a given month and year, marking days with tasks.
- Performance Measurement: Measures the time taken to execute operations like displaying tasks for a month.


Classes and Methods
Node
  Properties:
- string date: Stores the date in "YYYY-MM-DD" format.
- vector<string> tasks: Stores tasks for that date.
- Node* left, right: Pointers to the left and right child nodes in the tree.
  Constructor:
- Node(const string& date): Initializes a new node with the specified date.

TaskTree
  Properties:
- Node* root: Pointer to the root node of the binary search tree.
  Methods:
- void Add(const string& date, const string& task): Adds a task to the tree for the specified date.
- void EditTask(const string& date, int taskIndex, const string& newTask): Edits an existing task for a specified date.
- void DeleteTask(const string& date, int taskIndex): Deletes a task from the tree for a specified date.
- void DisplayTasks(const string& date): Displays tasks for a given date.
- void DisplayAllTasks(): Displays all tasks in the tree in ascending date order.
- void DisplayAllTasksInMonth(int month, int year): Displays all tasks for a given month and year.
- Node* Search(Node* node, const string& date): Searches for a node with a specific date.
- Node* Add(Node* node, const string& date, const string& task): Recursively adds a task to the tree.
- void InOrder(Node* node): Performs an in-order traversal to display all tasks.
- bool isLeapYear(int year): Checks if the given year is a leap year.
- int getDaysInMonth(int month, int year): Returns the number of days in a given month.
- string formatDate(int year, int month, int day): Formats a date as "YYYY-MM-DD".

How to Run code:
1: 
