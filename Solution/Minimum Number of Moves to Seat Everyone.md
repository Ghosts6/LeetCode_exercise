# 📜 Minimum Number of Moves to Seat Everyone


# 💡Intuition
The problem is to minimize the total distance that students need to move to sit in their seats. The key insight is that sorting both the seats and the students arrays helps align each student with the closest seat. This is because sorting ensures that the smallest differences between corresponding elements are minimized.

# 🛠️Approach
1.  Sort Both Arrays: First, sort the seats and students arrays.
2.  Calculate Total Moves: Iterate through both sorted arrays and calculate the absolute difference between the corresponding elements (i.e., the distance a student needs to move to reach their seat). Sum these differences to get the total number of moves.

# ⏰Complexity
- Time complexity:
Sorting both arrays takes O(nlogn) and to calculate the total moves takes O(n) time the overall time complexity is O(nlogn).

- Space complexity:
The space complexity is O(1) for this case.

## 💻 Code
```c []
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int minMovesToSeat(int* seats, int seatsSize, int* students, int studentsSize) {
    if (seatsSize != studentsSize) {
        return -1; 
    }

    qsort(seats, seatsSize, sizeof(int), compare);
    qsort(students, studentsSize, sizeof(int), compare);

    int min_moves = 0;

    for (int i = 0; i < seatsSize; ++i) {
        min_moves += abs(seats[i] - students[i]);
    }

    return min_moves;
}
```
```c++ []
class Solution {
public:
    int minMovesToSeat(std::vector<int>& seats, std::vector<int>& students) {
        std::sort(seats.begin(), seats.end());
        std::sort(students.begin(), students.end());
        
        int min_moves = 0;

        for (int i = 0; i < seats.size(); ++i) {
            min_moves += abs(seats[i] - students[i]);
        }
        
        return min_moves;
    }
};
```