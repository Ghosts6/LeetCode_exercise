class Solution:
    def minEatingSpeed(self, piles, h):
        def can_finish(speed):
            hours_spent = 0
            for pile in piles:
                hours_spent += -(-pile // speed)  
            return hours_spent <= h

        left, right = 1, max(piles)
        while left < right:
            mid = (left + right) // 2
            if can_finish(mid):
                right = mid
            else:
                left = mid + 1
        return left

# Test Cases
def test_koko_bananas():
    koko = Solution()

    # Case 1
    piles = [3, 6, 7, 11]
    h = 8
    print("Test Case 1:", koko.minEatingSpeed(piles, h) == 4)  

    # Case 2
    piles = [30, 11, 23, 4, 20]
    h = 5
    print("Test Case 2:", koko.minEatingSpeed(piles, h) == 30)  
