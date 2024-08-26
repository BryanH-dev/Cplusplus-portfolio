#include <iostream>
#include <iomanip>

using namespace std;

class Clock {
private:
    int hours;
    int minutes;
    int seconds;

public:
    // Constructor to initialize time
    Clock(int h = 0, int m = 0, int s = 0) : hours(h), minutes(m), seconds(s) {}

    // Function to add one hour
    void addOneHour() {
        hours = (hours + 1) % 24;
    }

    // Function to add one minute
    void addOneMinute() {
        minutes = (minutes + 1) % 60;
        if (minutes == 0) {
            addOneHour();
        }
    }

    // Function to add one second
    void addOneSecond() {
        seconds = (seconds + 1) % 60;
        if (seconds == 0) {
            addOneMinute();
        }
    }

    // Function to display 12-hour format
    void display12HourClock() const {
        int hours12 = (hours % 12 == 0) ? 12 : hours % 12;
        string period = (hours >= 12) ? "PM" : "AM";
        cout << "*    " << setw(2) << setfill('0') << hours12 << ":"
            << setw(2) << setfill('0') << minutes << ":"
            << setw(2) << setfill('0') << seconds << " " << period << "    *";
    }

    // Function to display 24-hour format
    void display24HourClock() const {
        cout << "*    " << setw(2) << setfill('0') << hours << ":"
            << setw(2) << setfill('0') << minutes << ":"
            << setw(2) << setfill('0') << seconds << "    *";
    }
};

// Function to display both clocks
void displayClocks(const Clock& clock) {
    cout << "*********************  **********************" << endl;
    cout << "    12-Hour Clock           24-Hour Clock " << endl;
    cout << "*     ";
    clock.display12HourClock();
    cout << "  ";
    clock.display24HourClock();
    cout << "*    *" << endl;
    cout << "*********************  **********************" << endl;
}

// Function to display the menu
void displayMenu() {
    cout << "****************************" << endl;
    cout << "* 1 - Add One Hour         *" << endl;
    cout << "* 2 - Add One Minute       *" << endl;
    cout << "* 3 - Add One Second       *" << endl;
    cout << "* 4 - Exit Program         *" << endl;
    cout << "****************************" << endl;
    cout << "Enter your choice: ";
}

int main() {
    // Initialize the clock with a starting time
    Clock clock(12, 0, 0);

    int choice;

    while (true) {
        displayClocks(clock);
        displayMenu();

        cin >> choice;

        switch (choice) {
        case 1:
            clock.addOneHour();
            break;
        case 2:
            clock.addOneMinute();
            break;
        case 3:
            clock.addOneSecond();
            break;
        case 4:
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    }

    return 0;
}

