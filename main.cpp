#include <iostream>
using namespace std;

int getDaysInMonth(int month, int year) { 
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return year % 4 == 0 ? 29 : 28;
        default:
            return 0;
    }
}

//Display the calendar
void printCalendar(int month, int year) {
    const string months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    cout << months[month - 1] << " " << year << endl;
    cout << "Mo Tu We Th Fr Sa Su" << endl;
    
    int startDay = (year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400 + 1;

    int daysInMonth = getDaysInMonth(month, year);

    //Printing the empty spaces before the first day
    for (int i = 0; i < startDay % 7; i++) {
        cout << "   ";
    }
    //Printing the days of the month
    for (int day = 1; day <= getDaysInMonth(month, year); day++) {
        cout << day << "  ";
        if ((startDay + day) % 7 == 0) {
            cout << endl;
        }
    }
    cout << endl;
}

int main() {
    int month, year;
    cout << "Enter the month (1-12): ";
    cin >> month;
    cout << "Enter the year: ";
    cin >> year;

    if  (month < 1 || month > 12) {
        cout << "Invalid month." << endl;
        return 1;
    }

    printCalendar(month, year);
    
    return 0;
}
