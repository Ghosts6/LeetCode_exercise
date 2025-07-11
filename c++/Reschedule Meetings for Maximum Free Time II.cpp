#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

class Solution {
public:
    int maxFreeTime(int eventTime, std::vector<int>& startTime, std::vector<int>& endTime) {
        int n = startTime.size();
        if (n == 0) {
            return eventTime;
        }
        std::vector<std::pair<int, int>> intervals;
        for (int i = 0; i < n; ++i) {
            intervals.emplace_back(startTime[i], endTime[i]);
        }

        std::sort(intervals.begin(), intervals.end());

        int max_free_time = 0;

        // Calculate initial max free time without rescheduling
        if (n > 0) {
            int initial_max_gap = intervals[0].first;
            for (int i = 1; i < n; ++i) {
                initial_max_gap = std::max(initial_max_gap, intervals[i].first - intervals[i - 1].second);
            }
            initial_max_gap = std::max(initial_max_gap, eventTime - intervals.back().second);
            max_free_time = initial_max_gap;
        } else {
            max_free_time = eventTime;
        }

        for (int i = 0; i < n; ++i) { // Meeting 'i' to be rescheduled
            int duration = intervals[i].second - intervals[i].first;
            
            std::vector<std::pair<int, int>> temp_intervals;
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                temp_intervals.push_back(intervals[j]);
            }

            if (temp_intervals.empty()) {
                if (eventTime >= duration) {
                    max_free_time = std::max(max_free_time, eventTime - duration);
                }
                continue;
            }

            std::vector<int> gaps;
            gaps.push_back(temp_intervals[0].first);
            for (size_t j = 1; j < temp_intervals.size(); ++j) {
                gaps.push_back(temp_intervals[j].first - temp_intervals[j - 1].second);
            }
            gaps.push_back(eventTime - temp_intervals.back().second);

            int max1 = 0, max2 = 0;
            for (int gap : gaps) {
                if (gap < 0) gap = 0;
                if (gap > max1) {
                    max2 = max1;
                    max1 = gap;
                } else if (gap > max2) {
                    max2 = gap;
                }
            }

            bool can_place_elsewhere = false;
            for (int gap : gaps) {
                if (gap != max1 && gap >= duration) {
                    can_place_elsewhere = true;
                    break;
                }
            }

            if (can_place_elsewhere) {
                max_free_time = std::max(max_free_time, max1);
            } else {
                if (max1 >= duration) {
                    max_free_time = std::max(max_free_time, std::max(max2, max1 - duration));
                }
            }
        }

        return max_free_time;
    }
};

int main() {
    Solution solution;

    int eventTime1 = 5;
    std::vector<int> startTime1 = {1, 3};
    std::vector<int> endTime1 = {2, 5};
    std::cout << "Result of test case 1 : " << solution.maxFreeTime(eventTime1, startTime1, endTime1) << std::endl; // Expected: 2

    int eventTime2 = 10;
    std::vector<int> startTime2 = {0, 7, 9};
    std::vector<int> endTime2 = {1, 8, 10};
    std::cout << "Result of test case 2 : " << solution.maxFreeTime(eventTime2, startTime2, endTime2) << std::endl; // Expected: 7

    int eventTime3 = 10;
    std::vector<int> startTime3 = {0, 3, 7, 9};
    std::vector<int> endTime3 = {1, 4, 8, 10};
    std::cout << "Result of test case 3 : "  << solution.maxFreeTime(eventTime3, startTime3, endTime3) << std::endl; // Expected: 6

    int eventTime4 = 5;
    std::vector<int> startTime4 = {0, 1, 2, 3, 4};
    std::vector<int> endTime4 = {1, 2, 3, 4, 5};
    std::cout << "Result of test case 4 : " <<solution.maxFreeTime(eventTime4, startTime4, endTime4) << std::endl; // Expected: 0

    return 0;
}