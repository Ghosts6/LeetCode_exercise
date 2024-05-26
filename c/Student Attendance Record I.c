#include <stdbool.h>
#include <string.h>

bool checkRecord(char* s) {
    int absences = 0;
    int lateStreak = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'A') {
            absences++;
            if (absences >= 2) {
                return false;
            }
            lateStreak = 0;
        } else if (s[i] == 'L') {
            lateStreak++;
            if (lateStreak >= 3) {
                return false;
            }
        } else {
            lateStreak = 0;
        }
    }
    
    return true;
}
