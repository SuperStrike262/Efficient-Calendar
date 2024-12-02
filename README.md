# Efficient-Calendar

Overview

The Interactive Weekly Planner is a graphical application built using the SFML library. It allows users to visually plan tasks for each
day of the week with an intuitive, interactive interface. The program provides functionality to add tasks to specific days or to a
general task list, and it also supports navigating between different weeks using arrow keys. The app displays a weekly calendar with
formatted dates and task lists, offering an easy way to organize personal schedules.

Features

This program allows users to manage their weekly tasks by adding them to specific days or to a general task area. Users can navigate
through weeks using left and right arrow keys. The current week is dynamically displayed, and tasks can be added by typing into a text
input field. Each day's tasks are stored and shown accordingly, and the app automatically adjusts the date display when/switching
between weeks.

Detailed Description

1. getWeekDates(int weekOffset)
The getWeekDates function generates the dates for a given week based on the weekOffset parameter. This offset determines which week is
displayed, where 0 corresponds to the current week, +1 for the next week, and -1 for the previous week. The function first calculates
the current day of the week and adjusts the date to the start of the week (Monday). Then, it adjusts the date based on the weekOffset,
either moving forward or backward by a number of weeks. After that, the function iterates through all seven days of the week, generating
a formatted date string for each day, such as "Jan 01". It returns a vector of these date strings to be used in the main program.

3. main()
The main function handles the core logic of the program. It sets up the graphical window using SFML, loads the background image and
font, and initializes variables for task management and user input. The window is created with a set size, and the planner background is
displayed at the correct scale. It also defines the positions where the dates will be shown and sets up an input box for adding tasks. A
loop continually processes user events, such as mouse clicks, keyboard input, and text entry. Tasks are added based on the user’s
selection of a specific day or the general task area, and the display updates accordingly to show the entered tasks. The user can
navigate between weeks using the left and right arrow keys, which updates the week’s task list and date display.

5. User Interaction and Input
The program listens for user input, both through mouse clicks and keyboard presses. When the user clicks on a specific day, the
corresponding day's tasks become the focus, allowing the user to add tasks for that day. The program also recognizes clicks on the
general task area, where tasks that are not tied to any specific day can be entered. The text input field captures user typing, and
tasks are added to the correct task list (either for a specific day or the general task list) when the user presses Enter. If the user
presses Backspace, the input text is edited. This interaction makes the app intuitive and allows for easy task management on the go.

7. Week Navigation
Week navigation is handled through the left and right arrow keys. When the user presses the left arrow key, the weekOffset is
decremented, showing the previous week’s tasks and dates. Conversely, pressing the right arrow key increments the weekOffset, displaying
the next week's tasks. The app recalculates the dates for the selected week and updates the task lists accordingly. This feature makes
it easy to track tasks across multiple weeks without needing to manually adjust the displayed dates.

9. Task Display and Layout
Tasks are displayed for each day of the week in specific areas beneath the date labels. Each task is shown in the order it was entered,
with a small vertical spacing between tasks. General tasks that are not tied to any specific day are displayed in a separate area of the
window. This separation of tasks by day and by general category helps users stay organized and manage their tasks effectively. The
layout is designed to be visually clear, with distinct sections for each day’s tasks and the general task area, making it easy to add,
view, and edit tasks.

*** How to Run
To run the Interactive Weekly Planner:
1. Ensure that you have the SFML library installed on your system.
2. Place the planner background image (planner.jpg) and the font file (Arial.ttf) in the appropriate directories.
3. Compile the program using a C++ compiler that supports SFML.
4. Run the compiled executable, and the planner will launch with the ability to interactively manage tasks.
5. Use left or right arrow key to go from week to week
6. Click on date or "to-do"(for general task) to add tasks
