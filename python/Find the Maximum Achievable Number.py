class Solution:
    def theMaximumAchievableX(self, num: int, t: int) -> int:
        maxAchievable = num + 2 * t
        return maxAchievable