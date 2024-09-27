#include <iostream>
#include <vector>

class MyCalendarTwo {
private:
    std::vector<std::pair<int, int>> bookings; 
    std::vector<std::pair<int, int>> overlaps; 

public:
    MyCalendarTwo() {}

    bool book(int start, int end) {
        for (const std::pair<int, int>& overlap : overlaps) {
            if (start < overlap.second && end > overlap.first) {
                return false; 
            }
        }

        for (const std::pair<int, int>& booking : bookings) {
            if (start < booking.second && end > booking.first) {
                int overlap_start = std::max(start, booking.first);
                int overlap_end = std::min(end, booking.second);
                overlaps.push_back({overlap_start, overlap_end});
            }
        }

        bookings.push_back({start, end});
        return true; 
    }
};

// Test case
int main() {
    MyCalendarTwo myCalendarTwo;

    // Test case 1
    std::cout << (myCalendarTwo.book(10, 20) ? "True" : "False") << std::endl;  // Output: True

    // Test case 2
    std::cout << (myCalendarTwo.book(50, 60) ? "True" : "False") << std::endl;  // Output: True

    // Test case 3
    std::cout << (myCalendarTwo.book(10, 40) ? "True" : "False") << std::endl;  // Output: True

    // Test case 4
    std::cout << (myCalendarTwo.book(5, 15) ? "True" : "False") << std::endl;   // Output: False

    // Test case 5
    std::cout << (myCalendarTwo.book(5, 10) ? "True" : "False") << std::endl;   // Output: True

    // Test case 6
    std::cout << (myCalendarTwo.book(25, 55) ? "True" : "False") << std::endl;  // Output: True

    return 0;
}
