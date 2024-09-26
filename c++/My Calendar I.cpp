#include <iostream>
#include <vector>

class MyCalendar {
private:
    std::vector<std::pair<int, int>> bookings;

public:
    MyCalendar() {}

    bool book(int start, int end) {
        for (const std::pair<int, int>& event : bookings) {
            if (start < event.second && end > event.first) {
                return false;
            }
        }
        bookings.push_back({start, end});

        return true;
    }
};

// Test cases 
int main() {
    MyCalendar myCalendar;

    // case 1 true
    std::cout << (myCalendar.book(10, 20) ? "True" : "False") << std::endl;

    // case 2 false
    std::cout << (myCalendar.book(15, 25) ? "True" : "False") << std::endl;

    // case 3 true
    std::cout << (myCalendar.book(20, 30) ? "True" : "False") << std::endl;

    return 0;
}