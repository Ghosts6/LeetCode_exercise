class Solution:
    def checkRecord(self, s: str) -> bool:
        absences = 0
        late_streak = 0

        for c in s:
            if c == 'A':
                absences += 1
                if absences >= 2:
                    return False
                late_streak = 0
            elif c == 'L':
                late_streak += 1
                if late_streak >= 3:
                    return False
            else:
                late_streak = 0
        
        return True