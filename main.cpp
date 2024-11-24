#include <iostream>
using namespace std;

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

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

int getStartDayOfMonth(int month, int year) {
    int totalDays = 0;

    //Calculate total number of days before the month
    for (int y = 1; y < year; y++) {
        totalDays += isLeapYear(y) ? 366 : 365;
    }

    for (int m = 1; m < month; m++) {
        totalDays += getDaysInMonth(m, year);
    }

    //Return day of the week 
    return (totalDays + 1) % 7;
}

void printCalendar(int month, int year) {
    const string months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    cout << "      " << months[month - 1] << " " << year << endl;
    cout << "Mo Tu We Th Fr Sa Su" << endl;

    int startDay = getStartDayOfMonth(month, year);
    int daysInMonth = getDaysInMonth(month, year);

    // Print leading spaces for the first week
    for (int i = 0; i < startDay; i++) {
        cout << "   ";
    }

    // Print the days of the month
    for (int day = 1; day <= daysInMonth; day++) {
        if (day < 10) {
            cout << " " << day << " ";
        } else {
            cout << day << " ";
        }

        if ((startDay + day) % 7 == 0) {
            cout << endl; // Start a new line after Saturday
        }
    }
    cout << endl;
}

int main() {
    int month, year;
    char choice;

    do {
        //User Input
        cout << "Enter the month (1-12): ";
        cin >> month;
        cout << "Enter the year: ";
        cin >> year;

        //Check if valid
        if (month < 1 || month > 12) {
            cout << "Invalid month. Please try again." << endl;
        } else {
            // Print calendar
            printCalendar(month, year);
        }

        // Ask if the user wants to try again
        cout << "Would you like to input another month and year? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y'); // Continue if user inputs 'y' or 'Y'

    cout << "Goodbye!" << endl;
    return 0;
}
