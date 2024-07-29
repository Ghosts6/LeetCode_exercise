#include <stdio.h>

int numTeams(int* rating, int ratingSize) {
    int count = 0;
    for (int j = 0; j < ratingSize; ++j) {
        int left_less = 0, left_greater = 0, right_less = 0, right_greater = 0;
        
        for (int i = 0; i < j; ++i) {
            if (rating[i] < rating[j]) ++left_less;
            if (rating[i] > rating[j]) ++left_greater;
        }
        
        for (int k = j + 1; k < ratingSize; ++k) {
            if (rating[k] < rating[j]) ++right_less;
            if (rating[k] > rating[j]) ++right_greater;
        }
        
        count += left_less * right_greater + left_greater * right_less;
    }
    return count;
}
//  test case
int main() {
    int ratings[] = {2, 5, 3, 4, 1};
    int size = sizeof(ratings) / sizeof(ratings[0]);
    int result = numTeams(ratings, size);
    printf("number of teams: %d\n", result); 
    return 0;
}
